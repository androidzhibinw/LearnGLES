#include <cstdlib>
#include <GLES3/gl3.h>
#include <android/log.h>
#include "utils.h"

/*
* check GL API error, print message in logcat
*/
GLuint checkGLError(const char* msg)
{

    GLuint success = glGetError();

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

/*
*compile shader from source
*/
GLuint loadShader(GLenum type, const char* shaderSrc)
{
    GLuint shader;
    GLint compileSuccess;

    shader = glCreateShader(type);
    if(!shader)
    {
        LOGE("glCreateShader failed: %x  %s",type,shaderSrc);
        return 0;
    }

    glShaderSource(shader, 1, &shaderSrc, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileSuccess);

    if(!compileSuccess)
    {
        GLint infoLen = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
        if(infoLen > 1)
        {
            char* infoLog = (char*) malloc(sizeof (char) * infoLen);
            glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
            LOGE("Error compiling shader: \n %s",infoLog);
            free(infoLog);
        }
        glDeleteShader(shader);
        return 0;

    }
    return shader;
}

/**
* link vertex shader and  fragment shader to program object
*/
GLuint linkShader2Program(const char* vShader, const char* fShader)
{
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vShader);
    if(!vertexShader)
    {
        return 0;
    }
    GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fShader);
    if(!fragmentShader)
    {
        return 0;
    }

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLint linkSuccess;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkSuccess);
    if(!linkSuccess)
    {
        GLint infoLen = 0;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLen);
        if(infoLen > 1)
        {
            char* infoLog = (char*)malloc(sizeof(char) * infoLen);
            glGetProgramInfoLog(shaderProgram, infoLen, NULL, infoLog);
            LOGE("Error link program: \n %s", infoLog);
            free(infoLog);
        }
        glDeleteProgram(shaderProgram);
        return 0;
    }
    return shaderProgram;
}

/**
* Change viewport to square
**/
GLuint squareViewport()
{
    GLint  viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    if(checkGLError("squareViewport"))
    {
        return 1;
    }
    GLint x = viewport[0];
    GLint y = viewport[1];
    GLint width = viewport[2];
    GLint height = viewport[3];
    if(x!=0 || y!=0){
        LOGE("viewport has been set to x=%d,y=%d,width=%d,height=%d",x,y,width,height);
        return 1;
    }
    if(width < height)
    {
        glViewport(0, (height-width)/2,width,width);
    }
    else
    {
        glViewport((width - height)/2,0,height,height);
    }
    return 0;
}