cmake_minimum_required(VERSION 3.16)
project(cpp_course)

add_definitions(-D_UNICODE)
remove_definitions(-D_MBCS)

set(CMAKE_CXX_STANDARD 14)
# 指定 google test 编译版本，不指定会导致 google test 编译失败
set(GOOGLETEST_VERSION 1.10.0)

# 添加子目录
add_subdirectory(external/googletest)

# 添加 include 文件
include_directories(include external/googletest/include)

# 添加可执行类
add_executable(cpp_course source/main.cpp source/first_stage.cpp source/second_stage.cpp source/third_stage.cpp)
add_executable(test_main tests/demo_test.cpp)

# 链接类库
target_link_libraries(cpp_course gtest_main)
target_link_libraries(test_main gtest_main)
