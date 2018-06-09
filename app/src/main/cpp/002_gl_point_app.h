#pragma once

#include "gl_app.h"
class GLPointApp : public GLBaseApp
{
    public:
        GLPointApp(){};
        ~GLPointApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};

    private:
        GLfloat mVertices[3];
};