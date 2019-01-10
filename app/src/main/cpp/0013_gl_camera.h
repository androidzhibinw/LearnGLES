#pragma once

#include "gl_app.h"
#include "glm/glm.hpp"

class GLCameraApp : public GLBaseApp
{
    public:
        GLCameraApp(){};
        ~GLCameraApp(){};
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

        glm::vec3 mPos[10] = 
        {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(1.2f, 0.0f, 1.5f),
            glm::vec3(-1.3f,1.0f, -1.0f),
            glm::vec3(1.3f,2.0f, 3.0f),
            glm::vec3(-2.3f, -1.4f, -2.0f),
            glm::vec3(-1.0f, 2.0f, 0.0f),
            glm::vec3(3.2f, 3.0f, 1.5f),
            glm::vec3(-3.3f,1.0f, -1.0f),
            glm::vec3(2.3f,-2.0f, 3.0f),
            glm::vec3(2.3f, 1.4f, -2.0f),
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