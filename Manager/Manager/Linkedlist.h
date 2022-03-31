//#include <bits/stdc++.h>
#pragma once

#include "user.h"
#include "course.h"

using namespace std;
template <class T>
struct Node {
    T data;
    Node* next = NULL, * prev = NULL;
<<<<<<< HEAD:Linkedlist.h
    Node<T> (const T& x){
        data = x;
    };
=======
>>>>>>> 7573cc529352ea07d5aaa294b9b918981d5db865:Manager/Manager/Linkedlist.h
};

template <class T>
struct Linkedlist {
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
<<<<<<< HEAD:Linkedlist.h
    void Insert(T x);
};
#include "Linkedlist.hpp"
=======
};
>>>>>>> 7573cc529352ea07d5aaa294b9b918981d5db865:Manager/Manager/Linkedlist.h
