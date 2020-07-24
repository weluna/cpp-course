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
TEST(t, memory_test) {
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

int *func() {
    int a = 10;
    //return &a;
    return new int(a);
}

/**
 * 栈区：由编译器自动分配释放, 存放函数的参数值,局部变量等
 */
TEST(t, test_stack) {
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
}

int *func2() {
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

    delete[] arr;
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

/**
 * 值传递
 * @param a
 * @param b
 */
void mySwap01(int a, int b) {
    int temp = 0;
    a = b;
    b = temp;
}

/**
 * 地址传递
 * @param a
 * @param b
 */
void mySwap02(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 引用传递
 * @param a
 * @param b
 */
void mySwap03(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

TEST(t, test_sawp) {
    int a = 10;
    int b = 20;

    mySwap01(a, b);
    cout << "a :" << a << " b:" << b << endl;
    mySwap02(&a, &b);
    cout << "a :" << a << " b:" << b << endl;
    mySwap03(a, b);
    cout << "a :" << a << " b:" << b << endl;
}

void func03(int &ref) {
    ref = 100;
}

TEST(t, test_ref) {
    int a = 10;

    // 自动转换为 int *const ref0 = &a; 指针常量是指指针指向不可改变，也说明为什么引用不可改变
    int &ref = a;
    ref = 20; // 内部发现是引用，自动帮我们转换为：*ref = 20;

    cout << "a: " << a << endl;
    cout << "ref:" << ref << endl;
    func03(a);
}

void showValue(const int &v) {
    // v += 10;
    cout << v << endl;
}

TEST(t, test_const) {
    // int &ref = 10; 引用本身需要一个合法内存空间，因此这行错误
    // 加入 const 就可以了，编译器优化代码，int temp = 10; const int &ref = temp;
    const int &ref = 10;

    cout << ref << endl;

    int a = 10;
    showValue(a);
}

int func04(int a, int b = 10, int c = 10) {
    return a + b + c;
}

void func05(int a, int) {
    cout << "This is func" << endl;
}

void olf() {
    cout << "olf() " << endl;
}

void olf(int a) {
    cout << "olf(int a)" << endl;
}

void olf(double a) {
    cout << "olf(double a)" << endl;
}

void olf(int a, double b) {
    cout << "olf(int a, double b)" << endl;
}

void olf(double a, int b) {
    cout << "olf(double a, int b)" << endl;
}

void func(int &a) {
    cout << "func(int &a)" << endl;
}

void func(const int &a) {
    cout << "func(const int &a)" << endl;
}

void func2(int a, int b = 10) {
    cout <<  "func2(int a, int b = 10)" << endl;
}

void func2(int a) {
    cout << "func2(int a)" << endl;
}

TEST(t, test_overload_ref) {
    int a = 10;
    func(a);
    func(10);

    // func2(10);

}

TEST(t, test_func) {
    int sum = func04(10);
    cout << sum << endl;
    func05(10, 10);

    olf();
    olf(10);
    olf(3.14);
    olf(10, 3.14);
    olf(3.14, 10);
}

const double PI = 3.14;

class Circle {
public:
    int r;
    double perimeter() {
        return 2 * PI * r;
    }
};

TEST(t, test_circle) {
    Circle c1{};
    c1.r = 10;

    cout << "圆的周长为：" << c1.perimeter() << endl;
}

class Student {
public:
    void setName(string name) {
        this->name = name;
    }
    void setId(int id) {
        this->id = id;
    }
    void print() {
        cout << "Student id: " << id << ", name: " << name << "." << endl;
    }
private:
    string name;
    int id;
};

class Person {
public:
    string name;
protected:
    string car;
private:
    int password;
public:
    void func() {
        name = "芽衣";
        car = "法拉利";
        password = 123456;
    }
    void print() {
        cout << "Person name: " << name << ", car: " << car << ", password: " << password << endl;
    }
};

TEST(t, test_class) {
    Student student{};
    student.setId(101);
    student.setName("八重樱");

    student.print();

    Person person;
    person.func();
    person.name = "琪亚娜";
    person.print();
}

class C1 {
    int a;
};

struct C2 {
    int a;
};

TEST(t, test_calss2) {
    C1 c1;

    C2 c2;
    c2.a = 10;
}

class Foo {
public:
    Foo() {
        cout << "构造函数" << endl;
    }
    ~Foo() {
        cout << "析构函数" << endl;
    }
};

void testFoo() {
    Foo foo;
}

TEST(t, testFoo) {
    testFoo();
}

