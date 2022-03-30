#include <iostream>
#include "Linkedlist.h"
using namespace std;
template <class T>
void Linkedlist<T>:: Insert(T x){
    Node<T>* p(x);
    if (head == NULL){
        head = tail = p;
    }
    else{
        tail->next = p;
        p->prev = tail;
        tail = tail->next;
    }
}