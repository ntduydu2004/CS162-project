//#include <bits/stdc++.h>
#pragma once

#include "user.h"
#include "course.h"

using namespace std;
template <class T>
struct Node {
    T data;
    Node* next = NULL, * prev = NULL;
    Node<T> (const T& x){
        data = x;
    };
};

template <class T>
struct Linkedlist {
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    void Insert(T x);
};
#include "Linkedlist.hpp"