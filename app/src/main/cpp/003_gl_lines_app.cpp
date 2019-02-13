#include <GLES3/gl3.h>
#include <android/log.h>
#include "003_gl_lines_app.h"
#include "utils.h"


void GLLinesApp::Initialize()
{
    mVertices[0] =  0.5f;
    mVertices[1] =  0.5f;
    mVertices[2] =  0.0f;

    mVertices[3] =  0.5f;
    mVertices[4] = -0.5f;
    mVertices[5] =  0.0f;

    mVertices[6] = -0.5f;
    mVertices[7] = -0.5f;
    mVertices[8] =  0.0f;

    mVertices[9] = -0.5f;
    mVertices[10]=  0.5f;
    mVertices[11]=  0.0f;

     const char* vShaderStr=
     {
        #include "shaders/include/003_v.glsl.in"
     };

     const char* fShaderStr=
     {
        #include "shaders/include/003_f.glsl.in"
     };


    GLuint shaderProgram = linkShader2Program(vShaderStr,fShaderStr);

    glUseProgram(shaderProgram);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    checkGLError("Initialize");
    glLineWidth(10.0);
    //squareViewport();
}

void GLLinesApp::Render()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_LINES, 0, 4);
    //glDrawArrays(GL_LINE_STRIP, 0, 4);
    //glDrawArrays(GL_LINE_LOOP, 0, 4);
}