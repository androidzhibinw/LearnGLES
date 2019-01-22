
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

- 计算透视投影矩阵 `glm::mat4 perspective(float fovy, float aspect, float zNear, float zFar)` 
  - fovy:
  - aspect:
  - zNear:
  - zFar:
- 计算Camera 矩阵 `glm::mat4 lookAt(glm::vec3 cameraPosition, glm::vec3 targetPosition, glm::vec3 cameraUp)`
- 角度转弧度 `glm::radians(float degree)`
- 计算旋转矩阵 `glm::mat4 rotate(glm::mat4 m, float angle, glm::vec3 axies)`
- 计算平移矩阵  `glm::mat4 translate(glm::mat4 matrix, glm::vec3 translationV)`
- 计算缩放矩阵  `glm::mat4 scale(glm::mat4 m, glm::vec3 factors)`
- 返回指针地址 `glm::value_ptr`

