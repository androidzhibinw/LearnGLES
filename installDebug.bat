adb uninstall com.example.native_activity
adb install -r app\build\outputs\apk\debug\app-debug.apk
adb push res_files\files\ /sdcard/Android/data/com.example.native_activity/files/