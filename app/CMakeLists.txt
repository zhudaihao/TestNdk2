#TODO 1 配置cmake版本
cmake_minimum_required(VERSION 3.4.1)

#在cmake打印日子 （括号打印内容 todo 注意看日志在Build的Build里面）
#message("测试在cmake打印日志")
#message("当前cmake的路径, ${CMAKE_SOURCE_DIR}")

#批量导入源文件
file(GLOB allCpp *.cpp)

#TODO 2 导入库源文件 (库名 库类型（静态/动态） 源文件)
add_library(
        native-lib
        SHARED
        src/main/cpp/native-lib.cpp
        #        ${allCpp}
)

#TODO  导入自己打包的库或者 第三方库

#1 导入静态库(自定义库名  库的类型  导入库的方式（一般是 IMPORTED）)
#这个自定义的库名是在代码中引用时用的（类似java变量名）
#静态库
#add_library(get STATIC IMPORTED)
#动态库
add_library(get SHARED IMPORTED)



#2 设置目标属性 (添加自定义的库名 PROPERTIES IMPORTED_LOCATION $导入库的路径 )
#静态库
#TODO ${CMAKE_SOURCE_DIR}表示cmake路径 ，如果使用这个 需要把cmke放到cpp文件夹下面 ；如果把cmak放到cpp文件夹里面注意修改build.gradle里面path路径
#set_target_properties(get PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libget.a)
#简单粗暴 直接配置路径
#set_target_properties(get PROPERTIES IMPORTED_LOCATION  E:/dongnan/TeamTalk-master/TestNdk2/app/src/main/cpp/libget.a)

#动态库 注意需要新建一个对应打包的平台的文件夹，再把动态库放进新建文件夹
#如果使用这个配置需要把cmake放到cpp文件夹里面
#set_target_properties(get PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}/libget.so)
#简单粗暴 直接配置路径
set_target_properties(get PROPERTIES IMPORTED_LOCATION E:/dongnan/TeamTalk-master/TestNdk2/app/src/main/jniLibs/armeabi-v7a/libget.so)


#3在链接添加 自定义的库名
#todo 注意动态库多一步 ，需要在static里面的总库前面添加动态库（activity里面）
#TODO 导入自己打包的库配置完成

#申明变量名 只能找系统的
find_library(
        log-lib
        log)


#TODO 3 链接
target_link_libraries(
        native-lib
        ${log-lib}
        get

)