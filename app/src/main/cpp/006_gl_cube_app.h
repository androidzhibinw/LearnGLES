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
            /*
             0.5, 0.5, 0.0,
            -0.5, 0.5, 0.0,
            -0.5,-0.5, 0.0,
             0.5,-0.5, 0.0,

             0.5, 0.5, 0.5,
            -0.5, 0.5, 0.5,
            -0.5, -0.5,0.5,
             0.5,-0.5, 0.5,
             */
            -1.0f,-1.0f,-1.0f,
             1.0f,-1.0f,-1.0f,
             1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,


            -1.0f,-1.0f, 1.0f,
             1.0f,-1.0f, 1.0f,
             1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,

        };

        GLfloat mColors [8*3] = 
        {
            0,0,0,
            0,0,1,
            0,1,0,
            0,1,1,
            1,0,0,
            1,0,1,
            1,1,0,
            1,1,1
        };

        GLuint mIndices[6*2*3]=
        {
            0,1,2,
            0,3,2,
            0,1,5,
            0,4,5,
            0,3,7,
            0,4,7,
            4,5,6,
            4,7,6,
            1,2,6,
            1,5,6,
            2,3,7,
            2,6,7
        };
        GLuint mEBO;
};