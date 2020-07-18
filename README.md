# C++课程
## Google Test 引入
* 下载 Google Test 最新 release 版本。 
* [下载地址](https://github.com/google/googletest/releases/)
* 解压下载好的压缩包，进入目录，拷贝 googletest 目录到项目的 external 目录下。
* 配置 CmakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.16)
project(cpp_course)

set(CMAKE_CXX_STANDARD 14)
# 指定 google test 编译版本，不指定会导致 google test 编译失败
set(GOOGLETEST_VERSION 1.10.0)

add_subdirectory(external/googletest)

include_directories(include external/googletest/include)

# 添加可执行类
add_executable(cpp_course source/main.cpp)
add_executable(test_main tests/demo_test.cpp)

# 链接类库
target_link_libraries(cpp_course gtest_main)
target_link_libraries(test_main gtest_main)
```
* 编写测试方法
```c++
#include <iostream>
#include "gtest/gtest.h"

TEST(name, c1) {
    std::cout << "Hello Google Test." << std::endl;
}
```
* 接下来你就可以通过 clion 自带的 google test 插件进行当个函数的测试啦！