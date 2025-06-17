cmake_minimum_required(VERSION 3.16)
project(EZres)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
