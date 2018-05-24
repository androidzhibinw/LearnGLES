# LearnGLES 

## 介绍 
这个项目用来记录学习 OpenGLES 的一些点滴，平台使用 Android 平台。

使用 https://github.com/googlesamples/android-ndk/tree/master/native-activity 作为基础框架，这个基于Android 的 NativeActivity， 并使用native_app_glue 库（用来封装Activity 生命周期相关回调），这个工程本身基于 Android NDK 实现 OpenGLES 应用的框架。

我对这个框架进行了一些修改(然后作为自己实现 OpenGLES 应用程序的框架)：

1. OpenGLES 版本有2.0 改为 3.0 
2. 构建 `GLBaseApp` 作为 app 的基类， `GLBaseApp` 提供了 `Initialize()` `Render()` 和 `Shutdown` 回调接口，子类可通过这三个方法实现具体的功能。`Initialize()` 在应用启动是被调用， `Render()` 在应用的主循环里被重复调用，`Shutdown`在应用退出时被调用。
3. 在框架中使用 `CreateGLApp` 创建 app 实例， 在应用启动时调用 app 的 `Initialize()`， 主循环里面重复调用 app 的 `Render()`, 在结束时调用 app 的 `Shutdown()`
4. 仅保留 armeabi armeabi-v7a arm64-v8a 三个ABI (去掉x86,mips等）
5. 链接库使用 GLESv3, 去掉 GLESv1_CM。

计划是创建很多个 OpenGLES 示例, 每个示例会创建一个 `GLESApp` 来实现。每个 `GLESApp` 继承自 `GLBaseApp` 并在 `Render()` 方法里面实现具体的功能代码。
