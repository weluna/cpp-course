//
// Created by Kevin on 2020/7/18.
//

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

// 全局变量
int g_a = 10;
int g_b = 10;

// 全局常量
const int c_g_a = 10;
const int c_g_b = 10;

/**
 * 变量地址测试
 * C++中在程序运行前分为全局区和代码区
 * 代码区特点是共享和只读
 * 全局区中存放全局变量、静态变量、常量
 * 常量区中存放 const修饰的全局常量 和 字符串常量
 *
 * 局部变量存放在栈区
 * 全局变量和静态变量存放在全局区
 * 常量区
 * 局部常量存放在栈区
 */
TEST(s, memory_test) {
    //局部变量
    int a = 10;
    int b = 10;

    //打印地址
    cout << "局部变量a地址为： " << (long) &a << endl;
    cout << "局部变量b地址为： " << (long) &b << endl;

    cout << "全局变量g_a地址为： " << (long) &g_a << endl;
    cout << "全局变量g_b地址为： " << (long) &g_b << endl;

    //静态变量
    static int s_a = 10;
    static int s_b = 10;

    cout << "静态变量s_a地址为： " << (long) &s_a << endl;
    cout << "静态变量s_b地址为： " << (long) &s_b << endl;

    cout << "字符串常量地址为： " << (long) &"hello world" << endl;
    cout << "字符串常量地址为： " << (long) &"hello world1" << endl;

    cout << "全局常量c_g_a地址为： " << (long) &c_g_a << endl;
    cout << "全局常量c_g_b地址为： " << (long) &c_g_b << endl;

    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "局部常量c_l_a地址为： " << (long) &c_l_a << endl;
    cout << "局部常量c_l_b地址为： " << (long) &c_l_b << endl;
}

int * func() {
    int a = 10;
    return &a;
}

/**
 * 栈区：由编译器自动分配释放, 存放函数的参数值,局部变量等
 */
TEST(t, test_stack) {
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
}

int * func2() {
    int *a = new int(10);
    return a;
}

/**
 * 堆：由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
 */
TEST(t, test_heap) {
    int *p = func2();
    cout << *p << endl;
    cout << *p << endl;
}

/**
 * new
 */
TEST(t, test_new) {
    int *p = func2();
    cout << *p << endl;
    cout << *p << endl;
    // 利用delete释放堆区数据
    delete p;

    // cout << *p << endl; // 报错，释放的空间不可访问
}

TEST(t, test_new_arry) {
    int *arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 100;
    }

    for (int j = 0; j < 10; ++j) {
        cout << arr[j] << endl;
    }

    delete arr;
}

/**
 * 引用
 */
TEST(t, test_reference) {
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

/**
 * 引用必须初始化
 * 引用在初始化后，不可以改变
 */
TEST(t, test_reference_01) {
    int a = 10;
    int b = 20;
    // int &c; // 错误，引用必须初始化
    int &c = a; // 一旦初始化后，就不可以更改
    c = b; // 这是赋值操作，不是更改引用；

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}