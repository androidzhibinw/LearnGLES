#include <GLES3/gl3.h>
#include <android/log.h>
#include "utils.h"

int checkGLError(const char* msg)
{

    int success = glGetError();

    if (success != GL_NO_ERROR){
        //LOGE("%s, %x",msg, success);
        switch(success)
        {
            case GL_INVALID_ENUM:
                LOGE("%s, invalid enum ",msg);
                break;
            case GL_INVALID_VALUE:
                LOGE("%s, invalid value ",msg);
                break;
            case GL_INVALID_OPERATION:
                LOGE("%s, invalid operation",msg);
                break;
            case GL_OUT_OF_MEMORY:
                LOGE("%s, out of memory",msg);
                break;
            default:
                LOGE("%s, %x",msg, success);
        }
    }
    return success;
}