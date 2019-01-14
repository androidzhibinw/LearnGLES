#pragma once
#include <android/log.h>
#include "glm/glm.hpp"

#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "LearnOpenGLES", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "LearnOpenGLES", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "LearnOpenGLES", __VA_ARGS__))

GLuint checkGLError(const char* msg);
GLuint loadShader(GLenum type, const char* shaderSrc);
GLuint linkShader2Program(const char* vShader, const char* fShader);
GLuint squareViewport();
void   queryAttributes();
void   logMatrix(glm::mat4 &mat);
void   logAnisotropy();


