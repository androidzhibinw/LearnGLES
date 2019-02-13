#include <GLES3/gl3.h>
#include "004_gl_triangle_app.h"
#include "utils.h"

void GLTriangleApp::Initialize()
{
     const char* vShaderStr=
     {
        #include "shaders/include/004_v.glsl.in"
     };

     const char* fShaderStr=
     {
        #include "shaders/include/004_f.glsl.in"
     };


    GLuint shaderProgram = linkShader2Program(vShaderStr,fShaderStr);

    glUseProgram(shaderProgram);

    //using VBO
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    //pass 0 as stride also work as data tightly packed.
    //pass 3*sizeof(float), means each vertex data has a size of 3*sizeof(float)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (void*)0);
    //LOGI("sizeof mVertices = %d",sizeof(mVertices));
    //LOGI("sizeof flaot :=%d",sizeof(GLfloat));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));
    checkGLError("Initialize");
    squareViewport();
}
void GLTriangleApp::Render()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    //glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
    //glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
}