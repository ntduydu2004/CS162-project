//#include <bits/stdc++.h>
#pragma once

#include "user.h"
#include "course.h"

using namespace std;
template <class T>
struct Node {
    T data;
    Node* next = NULL, * prev = NULL;
};