#pragma once

#include "gl_app.h"
#include "glm/glm.hpp"

class GLLightMaterialApp : public GLBaseApp
{
    public:
        GLLightMaterialApp(){};
        ~GLLightMaterialApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};

    private:
        //3 for pos, 3 for normals
        GLfloat mVertices[6*6*6]=
        {
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, //-Z
             0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, //Z front
             0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, //-X left
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

             0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, //X right
             0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, //-Y down
             0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, //Y up
             0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };
        GLuint mCubeVAO;
        GLuint mLightVAO;
        GLuint mVBO;
        GLuint mProgramCube;
        GLuint mProgramLight;
        float  mRotation;
        glm::vec3 mLightPos   = glm::vec3(0.8f, 0.0f, 1.2f);
        glm::vec3 mLightColor = glm::vec3(1.0f, 1.0f, 1.0f);
        glm::vec3 mCubeColor  = glm::vec3(1.0f, 0.5f, 0.0f);
        glm::vec3 mViewPos    = glm::vec3(0.2f, 1.0f, 3.5f);

        //using gold http://devernay.free.fr/cours/opengl/materials.html 
        glm::vec3 mGoldAmbient = glm::vec3(0.24725, 0.1995, 0.0745);
        glm::vec3 mGoldDiffuse = glm::vec3(0.75164, 0.60648, 0.22648);
        glm::vec3 mGoldSpecular = glm::vec3(0.628281, 0.555802, 0.366065);
        float mGoldShininess   = 0.4f * 128;

        glm::vec3 mLightAmbient = mLightColor * glm::vec3(0.2f);
        glm::vec3 mLightDiffuse = mLightColor * glm::vec3(0.5f);
        glm::vec3 mLightSpecular = mLightColor;
    };