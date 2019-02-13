#include <GLES3/gl3.h>
#include <android/log.h>
#include "0010_gl_transform.h"
#include "utils.h"
#include "stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


void GLTransformApp::Initialize()
{
    //glm::mat4 trans; wrong! uninitialized data is dirty
    //glm::mat4 trans = glm::mat4(1.0f); correct initialized as identity matrix
    glm::mat4 trans(1.0f); //correct initialized as identity matrix
    //logMatrix(trans);

    //note the order, the order of multiple is translate->rotate->scale
    //but the multiple with vector(position) is from right to left scale->rotate->translate
    trans = glm::translate(trans, glm::vec3(0.5,0,0));

    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0f,0.0f,1.0f));

    trans = glm::scale(trans, glm::vec3(0.5,0.5,0.5));


     const char* vShaderStr=
     {
        #include "shaders/include/0010_v.glsl.in"
     };


     const char* fShaderStr=
     {
        #include "shaders/include/0010_f.glsl.in"
     };
 

    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mEBO);
    glGenBuffers(1, &mVBO);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndices), mIndices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (void*)(6*sizeof(GLfloat)));


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
    GLuint location = glGetUniformLocation(mProgramObject, "transform");
    if (location != -1)
    {
        //LOGE("uniform location %d",location);
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(trans));

    } 
    else 
    {
        LOGE("not able to find transform!");
    }
    checkGLError("Initialize");
    squareViewport();
}

void GLTransformApp::Render()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}