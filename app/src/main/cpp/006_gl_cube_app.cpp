#include <GLES3/gl3.h>
#include <cmath>
#include "006_gl_cube_app.h"
#include "utils.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#define PI 3.1415926
void GLCubeApp::Initialize()
{


    //float x = PI/4.0f;
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.01f, 100.f);
    glm::mat4 View       = glm::lookAt(
                                glm::vec3(4,3,-3), // Camera is at (4,3,-3), in World Space
                                glm::vec3(0,0,0), // and looks at the origin
                                glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                           );
    glm::mat4 Model      = glm::mat4(1.0f);

    glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around


    const char* vShaderStr=
    "#version 300 es                            \n"
    "layout(location = 0) in vec3 vPosition;    \n"
    "layout(location = 1) in vec3 vertexColor;  \n"
    "out vec3 fragmentColor;                    \n"
    "uniform mat4 MVP;                          \n"
    "void main()                                \n"
    "{                                          \n"
    "    gl_Position = MVP * vec4(vPosition,1.0);\n"
    "    fragmentColor = vertexColor;           \n"
    "}                                          \n"
    "                                           \n";

     const char* fShaderStr=
    "#version 300 es                             \n"
    "out vec3 fragColor;                         \n"
    "in vec3 fragmentColor;                      \n"
    "void main()                                 \n"
    "{                                           \n"
    "  fragColor = fragmentColor;                \n"
    "}                                           \n";

    //Rotate(PI/6);
    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mEBO);
    glGenBuffers(1, &mVBOPosition);
    glGenBuffers(1, &mVBOColor);

    glBindVertexArray(mVAO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndices), mIndices, GL_STATIC_DRAW);

    //LOGI("size is :%d, size GLuint is %d",sizeof(mIndices),sizeof(GLuint));

    glBindBuffer(GL_ARRAY_BUFFER, mVBOPosition);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, mVBOColor);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mColors), mColors, GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);


    GLuint shaderProgram = linkShader2Program(vShaderStr,fShaderStr);
    glUseProgram(shaderProgram);

    GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
    LOGI("glGetUniformLocation: MVP pos is %d",MatrixID);//it is 0
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    squareViewport();
    queryAttributes();
    checkGLError("Initialize");

}

void GLCubeApp::Render()
{
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 12*3, GL_UNSIGNED_INT, 0 );
    checkGLError("Render");
}

//Rotate an angle to make cube visible
void GLCubeApp::Rotate(float angle)
{
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);
    GLfloat x=0.0,y=0.0,z=0.0;
    for(int i=0;i<8;i++)
    {
        y = mVertices[i*3+1];
        z = mVertices[i*3+2];
        mVertices[i*3+1] = y*cos_angle - z*sin_angle;
        mVertices[i*3+2] = y*sin_angle + z*cos_angle;
        LOGE("z=%f",mVertices[i*3+2]);

        x=mVertices[i*3+0];
        z=mVertices[i*3+2];
        mVertices[i*3+0] = x*cos_angle - z*sin_angle;
        mVertices[i*3+2] = x*sin_angle +z*cos_angle;
        LOGE("z=%f",mVertices[i*3+2]);

    }
}