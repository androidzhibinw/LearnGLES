#pragma once

#include "gl_app.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
class GLTransform2App : public GLBaseApp
{
    public:
        GLTransform2App(){};
        ~GLTransform2App(){};
        void Initialize();
        void Render();
        void ShutDown(){};

    private:
        //3 for pos , 3 for colors, 3 for text coordinates
        GLfloat mVertices[8*4]= 
        {
            //pos             //colors          //texture coordinate
            1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, //top right
            1.0f,-1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, //bot right
            -1.0f,-1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //bot left
            -1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, //top left
        };
        GLuint mIndices [3*2] = 
        {
            0,1,3,
            1,2,3,
        };
        GLuint mVAO;
        GLuint mEBO;
        GLuint mVBO;
        GLuint mTexture0;
        GLuint mTexture1;
        GLuint mProgramObject;
        glm::mat4 mTransform;
        unsigned int mCount = 0;
        const unsigned int kMaxCount = 200;
        const float kTranslateBegin = -1.0f;
        const float kTranslateEnd   =  1.0f;
        const float kTranslateStep  = (kTranslateEnd - kTranslateBegin)*2/kMaxCount;
        float mTranslate   = kTranslateBegin;

        const float kScaleBegin     = 0.5f;
        const float kScaleEnd       = 1.0f;
        const float kScaleStep      = (kScaleEnd - kScaleBegin) * 2/kMaxCount;
        float mScale                = kScaleBegin;

        const float kRotateBegin    = 0.0f;
        const float kRotateEnd      = 360.0f;
        const float kRotateStep     = (kRotateEnd - kRotateBegin) * 2/kMaxCount;
        float mRotate               = kRotateBegin;

    };