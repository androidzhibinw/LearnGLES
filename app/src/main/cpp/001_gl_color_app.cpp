#include <GLES3/gl3.h>
#include "001_gl_color_app.h"

void GLColorApp::Render()
{
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}