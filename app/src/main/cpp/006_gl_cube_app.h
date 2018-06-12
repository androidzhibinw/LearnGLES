#pragma once

#include "gl_app.h"
class GLCubeApp : public GLBaseApp
{
    public:
        GLCubeApp(){};
        ~GLCubeApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};
        void Rotate(float angle);
    private:
        //we need 8 points for cube
        GLfloat mVertices[8*3]=
        {
             0.5, 0.5, 0.0,
            -0.5, 0.5, 0.0,
            -0.5,-0.5, 0.0,
             0.5,-0.5, 0.0,

             0.5, 0.5, 0.5,
            -0.5, 0.5, 0.5,
            -0.5, -0.5,0.5,
             0.5,-0.5, 0.5,

        };

        GLuint mIndices[12*2]=
        {
            0,1,
            1,2,
            2,3,
            3,0,
            4,5,
            5,6,
            6,7,
            7,4,
            0,4,
            1,5,
            2,6,
            3,7,

        };
        GLuint mEBO;
};