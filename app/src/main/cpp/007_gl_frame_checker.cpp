#include <GLES3/gl3.h>
#include <android/log.h>
#include "007_gl_frame_checker.h"
#include "utils.h"


void GLFrameCheckerApp::Initialize()
{
    for(int i=0;i<60;i++)
    {
        mVertices[i*3+0] =  ((i%6)*2-5)/(6.0f);
        mVertices[i*3+1] =  (i/6*2-9)/(10.0f);
        mVertices[i*3+2] = 0.0f;
    }
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
    "precision mediump float;                    \n"
    "out vec4 fragColor;                         \n"
    "void main()                                 \n"
    "{                                           \n"
    "  fragColor = vec4(1.0,0.0,0.0,1.0);        \n"
    "}                                           \n";

    mProgramObject = linkShader2Program(vShaderStr,fShaderStr);

    glUseProgram(mProgramObject);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, mVertices);
    checkGLError("Initialize");
}

void GLFrameCheckerApp::Render()
{
    frameCount++;
    if(frameCount>60)
    {
        frameCount-=60;
    }
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_POINTS, frameCount-1, frameCount);

}