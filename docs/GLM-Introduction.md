
## OpenGL Mathematics (GLM) 简介

OpenGL Mathematics (GLM) 是一个符合 OpenGL Shading Language (GLSL) 规范的数学运算库，C++ 语言写成，用来支持图形(主要是OpenGL)学中的数学计算。

GLM 是一个 header only 的库， 只需要 include 头文件即可使用。

### GLM 链接

官网： https://glm.g-truc.net

Github 代码： https://github.com/g-truc/glm

### GLM 常用数据类型

- vector (常用 四维，三维，二维)

       glm::vec4, glm::vec3, glm::vec2

- matrix （常用 4x4, 3x3, 2x2,）

      glm::mat4 //(4x4), glm::mat3 //(3x3), glm::mat2 //(2x2)


### GLM 常用函数

- `glm::mat4 perspective(float fovy, float aspect, float zNear, float zFar)`
- `glm::mat4 lookAt(vec3 cameraPosition, vec3 targetPosition, vec3 cameraUp)`
- `glm::mat4 rotate`
- `glm::mat4 translate(mat4 matrix, vec3 translationV)`
- `glm::mat4 scale`

