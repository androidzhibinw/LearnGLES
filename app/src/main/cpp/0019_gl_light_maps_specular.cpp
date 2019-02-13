#include <GLES3/gl3.h>
#include <android/log.h>
#include "0019_gl_light_maps_specular.h"
#include "utils.h"
#include "stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


void GLLightMapsSpecularApp::Initialize()
{
    mRotation = 0.0f;

    glEnable(GL_DEPTH_TEST);

     const char* vCubeShaderStr=
     {
        #include "shaders/include/0019_cube_v.glsl.in"
     };

    const char* vLightShaderStr=
     {
        #include "shaders/include/0019_light_v.glsl.in"
     };

     const char* fCubeShaderStr=
     {
        #include "shaders/include/0019_cube_f.glsl.in"
     };
 
    const char* fLightShaderStr=
     {
        #include "shaders/include/0019_light_f.glsl.in"
     };

    glGenVertexArrays(1, &mCubeVAO);
    glGenBuffers(1, &mVBO);
    glGenTextures(1, &mTexture);
    glGenTextures(1, &mTextureSpecular);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

    glBindVertexArray(mCubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));

    glEnableVertexAttribArray(2); //texCoords
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (void*)(6*sizeof(GLfloat)));


    glGenVertexArrays(1, &mLightVAO);

    glBindVertexArray(mLightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), 0);
   

    glBindTexture(GL_TEXTURE_2D, mTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //load textures
    int width, height, chnnels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("/sdcard/Android/data/com.example.native_activity/files/container.jpg", &width, &height, &chnnels, 0);
    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        LOGE("Fail to load image!");
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, mTextureSpecular);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    data = stbi_load("/sdcard/Android/data/com.example.native_activity/files/container_specular.jpg", &width, &height, &chnnels, 0);
    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        LOGE("Fail to load image!");
    }
    stbi_image_free(data);

    mProgramCube = linkShader2Program(vCubeShaderStr, fCubeShaderStr);
    mProgramLight= linkShader2Program(vLightShaderStr, fLightShaderStr);



    squareViewport();
    checkGLError("Initialize");

}

void GLLightMapsSpecularApp::Render()
{

    mRotation += 0.2f;

    if (mRotation > 360)
    {
        mRotation = 0.0f;
    }

    glClearColor(0.2,0.2,0.2,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glUseProgram(mProgramCube);

    //glUniform3f(glGetUniformLocation(mProgramCube, "material.ambient"), mGoldAmbient.x, mGoldAmbient.y, mGoldAmbient.z);
    //glUniform3f(glGetUniformLocation(mProgramCube, "material.diffuse"), 0.5f, 0.5f, 0.5f);
    glUniform1i(glGetUniformLocation(mProgramCube, "material.diffuse"), 0);
    glUniform1i(glGetUniformLocation(mProgramCube, "material.specular"), 1);
    //glUniform3f(glGetUniformLocation(mProgramCube, "material.specular"),mGoldSpecular.x, mGoldSpecular.y,mGoldSpecular.z);
    glUniform1f(glGetUniformLocation(mProgramCube, "material.shininess"), mGoldShininess);
    glUniform3f(glGetUniformLocation(mProgramCube, "light.ambient"), mLightAmbient.x, mLightAmbient.y, mLightAmbient.z);
    glUniform3f(glGetUniformLocation(mProgramCube, "light.diffuse"), mLightDiffuse.x, mLightDiffuse.y, mLightDiffuse.z);
    glUniform3f(glGetUniformLocation(mProgramCube, "light.specular"), mLightSpecular.x, mLightSpecular.y, mLightSpecular.z);
    glUniform3f(glGetUniformLocation(mProgramCube, "light.position"), mLightPos.x, mLightPos.y,mLightPos.z);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

    glm::vec3 targetP(0.0, 0.0, 0.0);
    glm::vec3 cameraUp(0.0, 1.0, 0.0);
    glm::mat4 view = glm::lookAt(mViewPos, targetP,cameraUp);

    glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(mRotation), glm::vec3(0.0f,1.0f,0.0f));

    //model = glm::scale(model, glm::vec3(2.0f));


    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mTexture);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, mTextureSpecular);

    glUniform3f(glGetUniformLocation(mProgramCube, "viewPos"), mViewPos.x, mViewPos.y,mViewPos.z);

    glUniformMatrix4fv(glGetUniformLocation(mProgramCube, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(mProgramCube, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(mProgramCube, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(mCubeVAO);
    glDrawArrays(GL_TRIANGLES,0, 36);

    //light
    glUseProgram(mProgramLight);
    glUniform3f(glGetUniformLocation(mProgramLight, "lightColor"), mLightColor.x, mLightColor.y, mLightColor.z);

    glUniformMatrix4fv(glGetUniformLocation(mProgramLight, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(mProgramLight, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    glm::mat4 model2 = glm::mat4(1.0f);
    model2 = glm::rotate(glm::mat4(1.0f), glm::radians(mRotation), mLightPos);
    model2 = glm::translate(model2, mLightPos);
    model2 = glm::scale(model2, glm::vec3(0.2f));

    glUniformMatrix4fv(glGetUniformLocation(mProgramLight, "model"), 1, GL_FALSE, glm::value_ptr(model2));

    glBindVertexArray(mLightVAO);
    glDrawArrays(GL_TRIANGLES,0, 36);

    checkGLError("draw");
}