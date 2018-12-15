# LearnGLES 

## 介绍 
这个项目用来记录学习 OpenGLES 的一些点滴， Android 平台。

使用 https://github.com/googlesamples/android-ndk/tree/master/native-activity 作为基础框架，这个基于Android 的 NativeActivity， 并使用native_app_glue 库（用来封装Activity 生命周期相关回调），这个工程本身基于 Android NDK 实现 OpenGLES 应用的框架。

我对这个框架进行了一些修改(然后作为自己实现 OpenGLES 应用程序的框架)：

1. OpenGLES 版本有2.0 改为 3.0 
2. 构建 `GLBaseApp` 作为 app 的基类， `GLBaseApp` 提供了 `Initialize()` `Render()` 和 `Shutdown` 回调接口，子类可通过这三个方法实现具体的功能。`Initialize()` 在应用启动是被调用， `Render()` 在应用的主循环里被重复调用，`Shutdown`在应用退出时被调用。
3. 在框架中使用 `CreateGLApp` 创建 app 实例， 在应用启动时调用 app 的 `Initialize()`， 主循环里面重复调用 app 的 `Render()`, 在结束时调用 app 的 `Shutdown()`
4. 仅保留 armeabi armeabi-v7a arm64-v8a 三个ABI (去掉x86,mips等）
5. 链接库使用 GLESv3, 去掉 GLESv1_CM。

计划是创建很多个 OpenGLES 示例, 每个示例会创建一个 `GLESApp` 来实现。每个 `GLESApp` 继承自 `GLBaseApp` 并在 `Render()` 方法里面实现具体的功能代码。

## 环境配置

* Android SDK 
* Android NDK

## 编译运行

编译： ./buildDebug.bat 

安装： ./installDebug.bat


## 示例功能介绍 

| 示例代码文件 | 功能介绍 |截图 |
| ------------- | ------------- |-----------|
|[001_gl_color_app.cpp][cpp001]|为整个屏幕填充一种颜色(红色)|<img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/001_color.png?raw=true" width="144" height="256"/>| 
|[002_gl_point_app.cpp][cpp002]|画一个点(可控制大小）|<img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/002_point.png?raw=true" width="144" height="256">
|[003_gl_lines_app.cpp][cpp003]|画线(GL_LINES) | <img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/003_lines.png?raw=true" width="144" height="256"/>
|[003_gl_lines_app.cpp][cpp003]|画线(GL_LINE_STRIP) | <img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/003_line_strip.png?raw=true" width="144" height="256"/>
|[003_gl_lines_app.cpp][cpp003]|画线(GL_LINE_LOOP) | <img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/003_line_loop.png?raw=true" width="144" height="256"/>
|[004_gl_triangle.cpp][cpp004]|画三角形(GL_TRIANGLES) | <img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/004_triangles.png?raw=true" width="144" height="256"/>
|[004_gl_triangle.cpp][cpp004]|画三角形(GL_TRIANGLE_STRIP) | <img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/004_triangle_strip.png?raw=true" width="144" height="256"/>
|[004_gl_triangle.cpp][cpp004]|画三角形(GL_TRIANGLE_FAN) | <img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/004_triangle_fan.png?raw=true" width="144" height="256"/>
|[005_gl_regular_polygons.cpp][cpp005]|画任意正多边形 | n=12 <img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/005_regular_polygons.png?raw=true" width="144" height="256"/>
|[006_gl_cube_app.cpp][cpp006]|立方体(正交投影)| <img src="https://github.com/androidzhibinw/LearnGLES/blob/master/screenshots/006_cube.png?raw=true" width="144" height="256"/>

[cpp001]:https://github.com/androidzhibinw/LearnGLES/blob/master/app/src/main/cpp/001_gl_color_app.cpp
[cpp002]:https://github.com/androidzhibinw/LearnGLES/blob/master/app/src/main/cpp/002_gl_point_app.cpp
[cpp003]:https://github.com/androidzhibinw/LearnGLES/blob/master/app/src/main/cpp/003_gl_lines_app.cpp
[cpp004]:https://github.com/androidzhibinw/LearnGLES/blob/master/app/src/main/cpp/004_gl_triangle.cpp
[cpp005]:https://github.com/androidzhibinw/LearnGLES/blob/master/app/src/main/cpp/005_gl_regular_polygons.cpp
[cpp006]:https://github.com/androidzhibinw/LearnGLES/blob/de6945cd0f2d99c17a3ec540786f4fc1ecc28ea3/screenshots/006_cube.png

