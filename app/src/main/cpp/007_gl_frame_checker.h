#pragma once

#include "gl_app.h"
class GLFrameCheckerApp : public GLBaseApp
{
    public:
        GLFrameCheckerApp(){};
        ~GLFrameCheckerApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};

    private:
        GLfloat mVertices[3*60];
        int frameCount = 0;
        GLuint mProgramObject;
};