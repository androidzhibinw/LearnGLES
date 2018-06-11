#pragma once

#include "gl_app.h"
class GLRegularPolygonsApp : public GLBaseApp
{
    public:
        GLRegularPolygonsApp(){};
        ~GLRegularPolygonsApp(){};
        void Initialize();
        void Render();
        void ShutDown(){};

    private:
        GLfloat* mVertices;
        GLuint sides;
        GLfloat radius;
        GLfloat* genRegularPolygons(GLuint sides, GLfloat radius);
};