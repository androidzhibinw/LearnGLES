#include <GLES3/gl3.h>
#include <android/log.h>
#include "0012_gl_coordinate.h"
#include "utils.h"
#include "stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


void GLCoordinateApp::Initialize()
{

    glEnable(GL_DEPTH_TEST);
    //glm::mat4 trans; wrong! uninitialized data is dirty
    //glm::mat4 trans = glm::mat4(1.0f); correct initialized as identity matrix
    mTranslate =  glm::mat4(1.0f); //correct initialized as identity matrix
    //logMatrix(trans);
    mModel     = glm::mat4(1.0f);

    mView      = glm::mat4(1.0f);

    mProjection = glm::mat4(1.0f);

    mRotation = 0.0f;

    //note the order, the order of multiple is translate->rotate->scale
    //but the multiple with vector(position) is from right to left scale->rotate->translate
    //trans = glm::translate(trans, glm::vec3(0.5,0,0));

    //trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0f,0.0f,1.0f));

    //trans = glm::scale(trans, glm::vec3(0.5,0.5,0.5));

    mProjection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

    mView = glm::translate(mView, glm::vec3(0.0f, 0.0f, -3.0f));


     const char* vShaderStr=
     {
        #include "shaders/0012_v.glsl.in"
     };


     const char* fShaderStr=
     {
        #include "shaders/0012_f.glsl.in"
     };
 

    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mEBO);
    glGenBuffers(1, &mVBO);


    glBindVertexArray(mVAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndices), mIndices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));


    //load image
    glGenTextures(1, &mTexture0);
    glGenTextures(1, &mTexture1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mTexture0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, chnnels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("/sdcard/Android/data/com.example.native_activity/files/cat2.jpg", &width, &height, &chnnels, 0);
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

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, mTexture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    data = stbi_load("/sdcard/Android/data/com.example.native_activity/files/lake.jpg", &width, &height, &chnnels, 0);
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

    mProgramObject = linkShader2Program(vShaderStr,fShaderStr);
    glUseProgram(mProgramObject);
    glUniform1i(glGetUniformLocation(mProgramObject, "ourTexture1"), 0);
    glUniform1i(glGetUniformLocation(mProgramObject, "ourTexture2"), 1);
    checkGLError("Initialize");
    squareViewport();

}

void GLCoordinateApp::Render()
{

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mCount++;

    mRotation += 1.0f;
    if (mRotation >= 360)
    {
        mRotation = 0;
    }

    mModel = glm::rotate(glm::mat4(1.0f), glm::radians(mRotation), glm::vec3(0.5f,1.0f,0.0f));

    glUniformMatrix4fv(glGetUniformLocation(mProgramObject, "model"), 1, GL_FALSE, glm::value_ptr(mModel));
    glUniformMatrix4fv(glGetUniformLocation(mProgramObject, "view"), 1, GL_FALSE, glm::value_ptr(mView));
    glUniformMatrix4fv(glGetUniformLocation(mProgramObject, "projection"), 1, GL_FALSE, glm::value_ptr(mProjection));

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    checkGLError("draw");
}