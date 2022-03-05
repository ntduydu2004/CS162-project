#include <bits/stdc++.h>
#include "user.h"
#include "course.h"
using namespace std;
struct Nodestudent{
    student data;
    Nodestudent* next;
};
struct Nodecourse{
    course data;
    Nodecourse* next;
};
struct Linkedliststudent{
    Nodestudent* head = NULL;
    Nodestudent* tail = NULL;
};
struct Linkedlistcourse{
    Nodecourse* head = NULL;
    Nodecourse* tail = NULL;
};


