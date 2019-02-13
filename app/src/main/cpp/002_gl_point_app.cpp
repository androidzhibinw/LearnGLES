#include <GLES3/gl3.h>
#include <android/log.h>
#include "002_gl_point_app.h"
#include "utils.h"


void GLPointApp::Initialize()
{
    mVertices[0] = 0.5f;
    mVertices[1] = 0.0f;
    mVertices[2] = 0.0f;

     const char* vShaderStr=
     {
        #include "shaders/include/002_v.glsl.in"
     };


     const char* fShaderStr=
     {
        #include "shaders/include/002_f.glsl.in"
     };
 

    GLuint shaderProgram = linkShader2Program(vShaderStr,fShaderStr);

    glUseProgram(shaderProgram);

    //using VBO
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    checkGLError("Initialize");
}

void GLPointApp::Render()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_POINTS, 0, 1);

}