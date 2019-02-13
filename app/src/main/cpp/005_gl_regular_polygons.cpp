#include <GLES3/gl3.h>
#include <android/log.h>
#include <cmath>
#include "005_gl_regular_polygons.h"
#include "utils.h"

#define PI 3.1415926

void GLRegularPolygonsApp::Initialize()
{
    sides = 12;
    radius = 1.0;
    mVertices = genRegularPolygons(sides,radius);
     const char* vShaderStr=
     {
        #include "shaders/include/005_v.glsl.in"
     };

     const char* fShaderStr=
     {
        #include "shaders/include/005_f.glsl.in"
     };

    GLuint shaderProgram = linkShader2Program(vShaderStr,fShaderStr);

    glUseProgram(shaderProgram);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sides*3*sizeof(GLfloat), mVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    checkGLError("Initialize");
    glLineWidth(5.0);
    squareViewport();
}

void GLRegularPolygonsApp::Render()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_LINE_LOOP, 0, sides);
}

GLfloat* GLRegularPolygonsApp::genRegularPolygons(GLuint sides, GLfloat radius)
{
    GLfloat* vertices=NULL;
    if(sides <3)
    {
       return NULL;
    }
    if(radius>1.0 || radius<0.0)
    {
        return NULL;
    }

    vertices = new GLfloat[sides*3];
    GLfloat offset = 0.0;
    if(sides%2){
        offset = -PI;
    }
    for(int i=0; i < sides; i++)
    {
        vertices[i*3+0] = sin(PI/sides+i*2*PI/sides+offset);
        vertices[i*3+1] = cos(PI/sides+i*2*PI/sides+offset);
        vertices[i*3+2] = 0.0;
    }
    return vertices;

}