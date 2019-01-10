#pragma once

#include "gl_app.h"
#include "glm/glm.hpp"

class GLCoordinateApp : public GLBaseApp
{
    public:
        GLCoordinateApp(){};
        ~GLCoordinateApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};

    private:
        //3 for pos , 2 for text coordinates
        GLfloat mVertices[5*8]= 
        {
            //pos                       //texture coordinate
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f, //top right
            0.5f,-0.5f, -0.5f, 1.0f, 0.0f, //bot right
           -0.5f,-0.5f, -0.5f, 0.0f, 0.0f, //bot left
           -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, //top left

            0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
            0.5f,-0.5f, 0.5f, 0.0f, 1.0f,
           -0.5f,-0.5f, 0.5f, 1.0f, 1.0f,
           -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
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
        GLuint mVAO;
        GLuint mEBO;
        GLuint mVBO;
        GLuint mTexture0;
        GLuint mTexture1;
        GLuint mProgramObject;
        glm::mat4 mTranslate;
        glm::mat4 mProjection;
        glm::mat4 mView;
        glm::mat4 mModel;
        float     mRotation;
        unsigned int mCount = 0;
    };