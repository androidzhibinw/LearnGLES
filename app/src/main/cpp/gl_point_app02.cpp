#include <GLES3/gl3.h>
#include <android/log.h>
#include "gl_point_app.h"
#include "utils.h"


void GLPointApp::Initialize()
{
    mVertices[0] = 0.5f;
    mVertices[1] = 0.0f;
    mVertices[2] = 0.0f;

     const char* vShaderStr=
    "#version 300 es                            \n"
    "layout(location = 0) in vec3 vPosition;    \n"
    "void main()                                \n"
    "{                                          \n"
    "    gl_Position = vec4(vPosition,1.0);     \n"
    "    gl_PointSize = 100.0;                  \n"
    "}                                          \n"
    "                                           \n";

     const char* fShaderStr=
    "#version 300 es                             \n"
    "out vec4 fragColor;                         \n"
    "void main()                                 \n"
    "{                                           \n"
    "  fragColor = vec4(1.0, 0.0, 0.0, 1.0);     \n"
    "}                                           \n";

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vShaderStr, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderStr, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, mVertices);
    checkGLError("glVertexAttribPointer");
}

void GLPointApp::Render()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_POINTS, 0, 1);

}