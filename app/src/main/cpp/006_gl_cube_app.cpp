#include <GLES3/gl3.h>
#include <cmath>
#include "006_gl_cube_app.h"
#include "utils.h"

#define PI 3.1415926
void GLCubeApp::Initialize()
{
    const char* vShaderStr=
    "#version 300 es                            \n"
    "layout(location = 0) in vec3 vPosition;    \n"
    "void main()                                \n"
    "{                                          \n"
    "    gl_Position = vec4(vPosition,1.0);     \n"
    "}                                          \n"
    "                                           \n";

     const char* fShaderStr=
    "#version 300 es                             \n"
    "out vec4 fragColor;                         \n"
    "void main()                                 \n"
    "{                                           \n"
    "  fragColor = vec4(1.0, 0.0, 0.0, 1.0);     \n"
    "}                                           \n";

    Rotate(PI/6);
    glGenBuffers(1, &mEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndices), mIndices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, mVertices);


    GLuint shaderProgram = linkShader2Program(vShaderStr,fShaderStr);
    glUseProgram(shaderProgram);
    squareViewport();
    glLineWidth(5.0);
    checkGLError("Initialize");

}

void GLCubeApp::Render()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    //glDrawArrays(GL_LINE_LOOP, 0, 8);
    glDrawElements(GL_LINES, 24,GL_UNSIGNED_INT,0);
    checkGLError("Render");
}

//Rotate an angle to make cube visible
void GLCubeApp::Rotate(float angle)
{
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);
    GLfloat x=0.0,y=0.0,z=0.0;
    for(int i=0;i<8;i++)
    {
        y = mVertices[i*3+1];
        z = mVertices[i*3+2];
        mVertices[i*3+1] = y*cos_angle - z*sin_angle;
        mVertices[i*3+2] = y*sin_angle + z*cos_angle;

        x=mVertices[i*3+0];
        z=mVertices[i*3+2];
        mVertices[i*3+0] = x*cos_angle - z*sin_angle;
        mVertices[i*3+2] = x*sin_angle +z*cos_angle;

    }
}