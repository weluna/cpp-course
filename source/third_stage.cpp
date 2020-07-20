//
// Created by Kevin on 2020/7/19.
//

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

template<typename T>
void my_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

TEST(t, my_swap) {
    int a = 10;
    int b = 20;

    my_swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    double i = 0.1;
    double j = 0.2;

    my_swap(i, j);

    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
}

template<class T>
void my_sort(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        if (max != i) {
            my_swap(arr[max], arr[i]);
        }
    }
}

template<typename T>
void print_array(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

TEST(t, test_my_sort) {
    char char_array[] = "bdcfeagh";
    int len = sizeof(char_array) / sizeof(char);
    my_sort(char_array, len);
    print_array(char_array, len);
}

int my_add_01(int a, int b) {
    return a + b;
}

template<class T>
T my_add_02(T a, T b) {
    return a + b;
}

TEST(t, test_template_type) {
    int a = 10;
    int b = 20;
    char c = 'c';

    cout << my_add_01(a, c) << endl;

    // my_add_02(a, c);
    cout << my_add_02<int>(a, c) << endl;
}