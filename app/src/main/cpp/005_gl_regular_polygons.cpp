#include <GLES3/gl3.h>
#include <android/log.h>
#include "005_gl_regular_polygons.h"
#include "utils.h"


void GLRegularPolygonsApp::Initialize()
{
    sides = 10;
    radius = 1.0;
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

    GLuint shaderProgram = linkShader2Program(vShaderStr,fShaderStr);

    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, mVertices);
    checkGLError("Initialize");
    glLineWidth(10.0);
    squareViewport();
}

void GLRegularPolygonsApp::Render()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    //glDrawArrays(GL_LINE_LOOP, 0, 4);
}