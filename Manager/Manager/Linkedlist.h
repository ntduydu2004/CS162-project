//#include <bits/stdc++.h>
#pragma once

#include "user.h"
#include "course.h"

using namespace std;
template <class T>
class Node {
private:
    T data;
    Node* next;
    Node* prev;
public:
    Node<T> (T data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    };
};

template <class T>
class Linkedlist {
public:
    Node<T>* head;
    Node<T>* tail;
    
};
#include "Linkedlist.hpp"
