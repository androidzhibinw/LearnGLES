#include <GLES3/gl3.h>
#include <android/log.h>
#include "0015_gl_light_diffuse.h"
#include "utils.h"
#include "stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


void GLLightDiffApp::Initialize()
{
    mRotation = 0.0f;

    glEnable(GL_DEPTH_TEST);

     const char* vCubeShaderStr=
     {
        #include "shaders/include/0015_cube_v.glsl.in"
     };

    const char* vLightShaderStr=
     {
        #include "shaders/include/0015_light_v.glsl.in"
     };

     const char* fCubeShaderStr=
     {
        #include "shaders/include/0015_cube_f.glsl.in"
     };
 
    const char* fLightShaderStr=
     {
        #include "shaders/include/0015_light_f.glsl.in"
     };

    glGenVertexArrays(1, &mCubeVAO);
    glGenBuffers(1, &mVBO);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

    glBindVertexArray(mCubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));


    glGenVertexArrays(1, &mLightVAO);

    glBindVertexArray(mLightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), 0);
   
    mProgramCube = linkShader2Program(vCubeShaderStr, fCubeShaderStr);
    mProgramLight= linkShader2Program(vLightShaderStr, fLightShaderStr);

    squareViewport();
    checkGLError("Initialize");

}

void GLLightDiffApp::Render()
{

    mRotation += 0.2f;

    if (mRotation > 360)
    {
        mRotation = 0.0f;
    }

    glClearColor(0.2,0.2,0.2,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glUseProgram(mProgramCube);

    glUniform3f(glGetUniformLocation(mProgramCube, "cubeColor"), mCubeColor.x, mCubeColor.y, mCubeColor.z);
    glUniform3f(glGetUniformLocation(mProgramCube, "lightColor"), mLightColor.x, mLightColor.y, mLightColor.z);
    glUniform3f(glGetUniformLocation(mProgramCube, "lightPos"), mLightPos.x, mLightPos.y,mLightPos.z);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

    glm::vec3 targetP(0.0, 0.0, 0.0);
    glm::vec3 cameraUp(0.0, 1.0, 0.0);
    glm::mat4 view = glm::lookAt(glm::vec3(1.5f, 2.0f, 5.0f), targetP,cameraUp);

    glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(mRotation), glm::vec3(0.0f,1.0f,0.0f));

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