#pragma once

#include "gl_app.h"
#include "glm/glm.hpp"

class GLLightApp : public GLBaseApp
{
    public:
        GLLightApp(){};
        ~GLLightApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};

    private:
        //3 for pos 
        GLfloat mVertices[3*8]=
        {
            //pos
            0.5f, 0.5f, -0.5f, 
            0.5f,-0.5f, -0.5f, 
           -0.5f,-0.5f, -0.5f, 
           -0.5f, 0.5f, -0.5f, 

            0.5f, 0.5f, 0.5f, 
            0.5f,-0.5f, 0.5f, 
           -0.5f,-0.5f, 0.5f, 
           -0.5f, 0.5f, 0.5f, 
        };
        GLuint mIndices[6*2*3]=
        {
            0,1,2,
            0,3,2,
            0,1,5,
            0,4,5,
            0,3,7,
            0,4,7,
            1,2,6,
            1,5,6,
            2,3,7,
            2,6,7,
            4,5,6,
            4,7,6,
        };

        GLuint mCubeVAO;
        GLuint mLightVAO;
        GLuint mEBO;
        GLuint mVBO;
        GLuint mProgramCube;
        GLuint mProgramLight;
        float  mRotation;
    };