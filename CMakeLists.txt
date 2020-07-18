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
