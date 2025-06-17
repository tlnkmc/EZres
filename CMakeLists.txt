cmake_minimum_required(VERSION 3.16)
project(EZres VERSION 1.0.0 DESCRIPTION "Screen Resolution and Scaling Management Tool")

# 设置项目信息
set(PROJECT_AUTHOR "Your Name")
set(PROJECT_COPYRIGHT "Copyright (C) 2024 ${PROJECT_AUTHOR}")
set(PROJECT_LICENSE "GPL v3")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加版本定义
add_compile_definitions(
    PROJECT_VERSION="${PROJECT_VERSION}"
    PROJECT_COPYRIGHT="${PROJECT_COPYRIGHT}"
    PROJECT_LICENSE="${PROJECT_LICENSE}"
)

# 检查编译器
if(WIN32)
    if(MSVC)
        # Visual Studio编译器
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
    elseif(MINGW)
        # MinGW编译器
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")
    endif()
endif()

# 添加可执行文件
add_executable(EZres main.cpp)

# 链接Windows库
target_link_libraries(EZres user32 advapi32)

# 设置输出目录
set_target_properties(EZres PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
