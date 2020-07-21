//
// Created by Kevin on 2020/7/18.
//

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

/**
 * 变量
 */
TEST(name, varibles) {
    //变量的定义
    //语法：数据类型  变量名 = 初始值
    int a = 10;

    cout << "a = " << a << endl;
}

#define day 7

/**
 * 常量
 */
TEST(name, contants) {
    cout << "一周里总共有 " << day << " 天" << endl;

    // day = 8; // 报错， 宏常量不可以修改

    // 2. const 修改时变量
    const int month = 12;
    cout << "一年里总共有 " << month << " 个月份" << endl;
    // month = 24; // 报错，常量是不可以修改的
}

/**
 * sizeof
 * 作用： 利用sizeof关键字可以统计数据类型所占内存大小
 * 语法： sizeof( 数据类型 / 变量)
 */
TEST(name, test_sizeof) {
    cout << "short 类型所占内存空间为： " << sizeof(short) << endl;

    cout << "int 类型所占内存空间为： " << sizeof(long) << endl;

    cout << "long 类型所占内存空间为： " << sizeof(long) << endl;

    cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;
}

/**
 * float 4个字节 7位有效数字
 * double 8个字节 15~16位有效数字
 */
TEST(name, test_float) {
    float f1 = 3.14f;
    double d1 = 3.14;

    cout << f1 << endl;
    cout << d1 << endl;

    cout << "float sizeof = " << sizeof(f1) << endl;
    cout << "double sizeof = " << sizeof(d1) << endl;

    float f2 = 3e2; // 3 * 10 ^ 2
    cout << "f2 = " << f2 << endl;

    float f3 = 3e-2; // 3 * 0.1 ^ 2;
    cout << "f3 = " << f3 << endl;
}

/**
 * char 1个字节
 */
TEST(name, test_char) {
    char ch = 'a';
    cout << ch << endl;
    cout << sizeof(char) << endl;

    //ch = "abcde"; //错误，不可以用双引号
    //ch = 'abcde'; //错误，单引号内只能引用一个字符

    cout << (long) ch << endl;
    ch = 97;
    cout << ch << endl;
}

/**
 * 转义字符
 */
TEST(name, test_char_transalation) {
    cout << "\\" << endl;
    cout << "\tHello" << endl;
    cout << "\n" << endl;
    cout << "\\" << endl;
}

# include <string>

/**
 * 字符串
 */
TEST(name, test_string) {
    // C 风格字符串
    char str1[] = "八重樱";
    cout << str1 << endl;
    cout << "sizeof = " << sizeof(str1) << endl;

    char str2[] = "apple";
    cout << str2 << endl;
    cout << "sizeof = " << sizeof(str2) << endl;

    // C++ 风格字符串
    string str = "八重樱";
    cout << str << endl;
    cout << "sizeof = " << sizeof(str) << endl;
}

/**
 * bool类型只有两个值
 * true 1
 * false 0
 */
TEST(name, test_boolean) {
    bool flag = true;
    cout << flag << endl; // 1

    flag = false;
    cout << flag << endl; // 0

    cout << "size of bool = " << sizeof(flag) << endl;
}

/**
 * 数据的输入
 */
TEST(name, test_intput) {
    // 整型输入
    int a = 0;
    cout << "请输入整型变量：" << endl;
    cin >> a;
    cout << a << endl;

    // 浮点型输入
    double d = 0;
    cout << "请输入浮点型变量：" << endl;
    cin >> d;
    cout << d << endl;

    // 字符型输入
    char ch = 0;
    cout << "请输入字符类型变量：" << endl;
    cin >> ch;
    cout << ch << endl;

    // 字符串类型输入
    string str;
    cout << "请输入字符串类型变量" << endl;
    cin >> str;
    cout << str << endl;

    // 布尔类型输入
    bool flag = true;
    cout << "请输入布尔型变量：" << endl;
    cin >> flag;
    cout << flag << endl;
}

/**
 * 三元运算
 */
TEST(name, three_unit) {
    int a = 10, b = 20, c = 0;

    c = a > b ? a : b;
    cout << "c = " << c << endl;

    (a > b ? a : b) = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

# include <ctime>

/**
 * switch
 */
TEST(name, test_switch) {
    srand((unsigned int) time(NULL));
    int score = rand() % 11;
    cout << score << endl;
    switch (score) {
        case 10:
        case 9:
            cout << "经典" << endl;
            break;
        case 8:
            cout << "非常好" << endl;
            break;
        case 7:
        case 6:
            cout << "一般" << endl;
            break;
        default:
            cout << "烂片" << endl;
            break;
    }
}

/**
 * while
 */
TEST(name, test_while) {
    int num = 0;
    while (num < 10) {
        cout << "num = " << num << endl;
        num++;
    }
}

TEST(name, test_do_while) {
    int num = 0;
    do {
        cout << "num = " << num << endl;
        num++;
    } while (num < 10);
}

#include <math.h>
/**
 * 打印水仙花数字
 */
TEST(name, daffodil_number) {
    int i = 99;
    int sum;
    do {
        i++;
        sum = pow(i / 100 % 10, 3) + pow(i / 10 % 10, 3) + pow(i / 1 % 10, 3);
        if (i == sum) {
            cout << i << endl;
        }
    } while (i <= 999);
}

/**
 * 嵌套循环打印
 */
TEST(name, for_print) {
    int size = 10;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; ++j) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

/**
 * 打印乘法口诀表
 */
TEST(name, test_9x9) {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << j << " x " << i << " = " << j * i << " ";
        }
        cout << endl;
    }
}

/**
 * continue
 */
TEST(name, print_odd) {
    for (int i = 0; i < 100; ++i) {
        if (i % 2 == 0) {
            continue;
        }
        cout << i << endl;
    }
}

/*
 * goto
 */
TEST(name, test_goto) {
    cout << "1" << endl;

    goto FLAG;

    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;

    FLAG:

    cout << "5" << endl;
}

/**
 * 数组
 */
TEST(name, test_array) {
    //数组名用途
    //1、可以获取整个数组占用内存空间大小
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
    cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
    cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;

    //2、可以通过数组名获取到数组首地址
    cout << "数组首地址为： " << (long) arr << endl;
    cout << "数组中第一个元素地址为： " << (long) &arr[0] << endl;
    cout << "数组中第二个元素地址为： " << (long) &arr[1] << endl;

    //arr = 100; 错误，数组名是常量，因此不可以赋值
}

/**
 * 冒泡排序
 */
TEST(name, bubble_sort) {
    int arr[10] = {4, 2, 8, 0, 5, 7, 1, 3, 9, 6};

    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < 10; ++k) {
        cout << arr[k] << endl;
    }
}

/**
 * 打印二维数组
 * @param arr
 */
void print_double_array(int arr[2][3]) {
    cout << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * 二维数组
 */
TEST(name, double_array) {
    // 方式1
    int arr[2][3];
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;

    print_double_array(arr);

    // 方式2
    int arr2[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };
    print_double_array(arr2);

    // 方式3
    int arr3[2][3] = {1, 2, 3, 4, 5, 6};
    print_double_array(arr3);

    // 方式4
    int arr4[][3] = {1, 2, 3, 4, 5, 6};
    print_double_array(arr4);
}

/**
 * 二维数组地址
 */
TEST(name, double_array_address) {
    int arr[2][3] = {1, 2, 3, 4, 5, 6};

    cout << "二维数组大小：" << sizeof(arr) << endl;
    cout << "二维数组一行大小：" << sizeof(arr[0]) << endl;
    cout << "二维数组元素大小：" << sizeof(arr[0][0]) << endl;

    cout << "二维数组行数： " << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "二维数组列数： " << sizeof(arr[0]) / sizeof(arr[0][0])<< endl;

    //地址
    cout << "二维数组首地址：" << (long) arr << endl;
    cout << "二维数组第一行地址：" << (long) arr[0] << endl;
    cout << "二维数组第二行地址：" << (long) arr[1] << endl;

    cout << "二维数组第一个元素地址：" << (long) &arr[0][0] << endl;
    cout << "二维数组第二个元素地址：" << (long) &arr[0][1] << endl;
}

/**
 * 二维数组应用
 */
TEST(name, double_array_demo) {
    int scores[3][3] = {
            {100, 100, 100},
            {90,  50,  100},
            {60,  70,  80},
    };

    string names[3] = {"张三", "李四", "王五"};

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += scores[i][j];
        }
        cout << names[i] << "同学总成绩为： " << sum << endl;
    }
}

void swap(int num1, int num2) {
    cout << "交换前：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}

/**
 * 函数值传递
 */
TEST(name, value_args) {
    int a = 10;
    int b = 20;
    swap(a, b);
    cout << "main中的 a = " << a << endl;
    cout << "main中的 b = " << b << endl;
}

// 申明可以多次， 定义只能一次
int max(int a, int b);

int max(int a, int b);

int max(int a, int b) {
    return a > b ? a : b;
}

TEST(name, function_01) {
    int a = 100;
    int b = 200;

    cout << max(a, b) << endl;
}

/**
 * 指针
 */
TEST(name, test_point) {
    // 1.指针的定义
    int a = 10;
    // 指针定义语法：数据类型 * 变量名
    int *p;

    // 指针变量赋值
    p = &a; // 指针指向变量 a 的地址
    cout << &a << endl; // 打印数据 a 的地址
    cout << p << endl; // 打印指针变量 p

    // 2.指针的使用
    cout << "*p = " << *p << endl; // 通过 * 操作指针变量指向的内存
}

/**
 * 指针所占内存空间
 */
TEST(name, point_size) {
    int a = 10;
    int *p;
    p = &a;

    cout << *p << endl; // * 解引用
    cout << sizeof(p) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(float *) << endl;
    cout << sizeof(double *) << endl;
}

/**
 * 空指针
 */
TEST(name, null_point) {
    // 指针变量 p 指向内存地址编号为0的空间
    int *p = NULL;

    // 访问空指针报错
    // 内存编号0~255为系统占用内存，不允许用户访问
    cout << *p << endl;
}

/**
 * 野指针
 */
TEST(name, strange_point) {
    // 指针变量p指向内存地址编号为0x1100的空间
    int *p = (int *) 0x1100;
    // 访问野指针
    cout << *p << endl;
}

/**
 * 常量修饰符和指针
 */
TEST(name, const_point) {
    int a = 10;
    int b = 10;

    // const 修饰的是指针，指针指向可以改，指针指向的值不可以更改
    const int *p1 = &a;
    p1 = &b; // 正确
    // *p1 = 100; 错误

    // const 修饰的是常量，指针指向不可以改，指针指向的值可以更改
    int *const p2 = &a;
    // p2 = &b; // 错误
    *p2 = 100;

    // const 既修饰指针又修饰常量
    const int *const p3 = &a;
    // p3 = &b;
    // *p3 = 100;
}

/**
 * 指针和数组
 */
TEST(name, point_array) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *p = arr; // 指向数组的指针

    cout << "第一个元素：" << arr[0] << endl;
    cout << "指针访问第一个元素：" << *p << endl;

    for (int i = 0; i < 10; ++i) {
        // 利用指针遍历数组
        cout << *p << endl;
        p++;
    }
}

void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/**
 * 指针和函数
 */
TEST(name, point_function) {
    int a = 10;
    int b = 20;
    swap1(a, b); // 值传递不会改变实参

    swap2(&a, &b); // 地址传递会改变实参

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void bubble_sort(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << endl;
    }
}

/**
 * 测试冒泡排序
 */
TEST(name, test_bubble_sort) {
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);
    print_array(arr, len);
}

struct student {
    string name;
    int age;
    int score;
};

void print_student(struct student stu) {
    cout << "姓名：" << stu.name << " 年龄：" << stu.age << " 分数：" << stu.score << endl;
}

/**
 * 结构体变量
 */
TEST(name, test_struct) {
    // 结构体变量创建方式 1
    struct student stu1; // struct 关键字可以省略

    stu1.name = "八重樱";
    stu1.age = 18;
    stu1.score = 100;
    print_student(stu1);

    // 结构体变量创建方式 2
    struct student stu2 = {"德丽莎", 19, 85};
    print_student(stu2);
    // 结构体变量创建方式 3

    struct student {
        string name = "琪亚娜";
        int age = 16;
        int score = 60;
    } stu3;

    cout << "姓名：" << stu3.name << " 年龄：" << stu3.age << " 分数：" << stu3.score << endl;
}

/**
 * 结构体数组
 */
TEST(name, test_struct_array) {
    struct student arr[] = {
            {"八重樱", 18, 90},
            {"德丽莎", 19, 85},
            {"琪亚娜", 16, 60}
    };

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        print_student(arr[i]);
    }
}

/**
 * 结构体指针
 */
TEST(name, test_struct_point) {
    struct student stu = {"芽衣", 18, 100};
    struct student *p = &stu;
    p->score = 80; // 指针通过 -> 操作符可以访问成员
    print_student(stu);
}

struct teacher {
    int id;
    string name;
    int age;
    struct student stu;
};

TEST(name, test_nest_struct) {
    struct teacher t1;
    t1.id = 10000;
    t1.name = "姬子";
    t1.age = 32;

    t1.stu.name = "布兰妮亚";
    t1.stu.age = 14;
    t1.stu.score = 100;

    cout << "教师 职工编号：" << t1.id << " 姓名：" << t1.name << " 年龄：" << t1.age << endl;

    print_student(t1.stu);
}

void change(student stu) {
    stu.name = "神恩颂歌";
}

void change(student *stu) {
    stu->name = "神恩颂歌";
}

TEST(name, struct_varaible) {
    struct student stu = {"德丽莎", 45, 90};
    print_student(stu);
    change(stu);
    print_student(stu);
    change(&stu);
    print_student(stu);
}