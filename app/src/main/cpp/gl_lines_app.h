#pragma once

#include "gl_app.h"
class GLLinesApp : public GLBaseApp
{
    public:
        GLLinesApp(){};
        ~GLLinesApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};

    private:
        GLfloat mVertices[4*3];
};