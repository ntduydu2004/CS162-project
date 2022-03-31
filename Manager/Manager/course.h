#pragma once

#include <stdio.h>
#include <iostream>
#include <string>

#include "user.h"
#include "CustomTime.h"
#include "Linkedlist.h"

using namespace std;

const int maxNum = 50;

struct Session{
    string weekday;
    Time time;
};
struct course{
    string ID;
    string name;
    Staff teacher;
    Session session;
    Date startday, endday;
    // student List...
<<<<<<< HEAD:course.h
    Node <Student>* Student = NULL;
=======
    Student student;
>>>>>>> 7573cc529352ea07d5aaa294b9b918981d5db865:Manager/Manager/course.h
    int numStudent;
};
struct result{
    string courseID;
    float thuchanh;
    float quiz;
    float giuaky;
    float cuoiky;
};
