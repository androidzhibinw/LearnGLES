#pragma once

#include "gl_app.h"
class GLTriangleApp : public GLBaseApp
{
    public:
        GLTriangleApp(){};
        ~GLTriangleApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};
    private:
        GLfloat mVertices[6*3]=
        {
             1.0, 0.0, 0.0,
             1.0, 1.0, 0.0,
             0.0, 1.0, 0.0,
            -1.0, 0.0, 0.0,
            -1.0,-1.0, 0.0,
             0.0,-1.0, 0.0,

        };
};