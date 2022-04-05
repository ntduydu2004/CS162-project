#pragma once

#include <stdio.h>
#include <iostream>
#include <string>

#include "user.h"
#include "CustomTime.h"
#include "Linkedlist.h"

using namespace std;

const int maxNum = 50;

struct Session
{
    string weekday;
    Time time;
    Session()
    {
        weekday = "Unknown";
        time.hour = -1;
        time.min = -1;
    }
    void getTimeOfCourse(string &input_date)
    {
        string s = input_date.substr(0, 2);
        time.hour = stoi(s);
        s = input_date.substr(3, 2);
        time.min = stoi(s);
    }
};

struct result
{
    string courseID;
    float thuchanh;
    float quiz;
    float giuaky;
    float cuoiky;
};
struct course
{
    string ID;
    string name;
    Session session[2];
    string lecturer;
    //  student List...
    Node<student> *nStudentHead = NULL;
    int numStudent;
    Date startDay, endDay;
    void getStartDayOfCourse(string &input_date)
    {
        string s = input_date.substr(0, 2); // get the day
        startDay.day = stoi(s);
        s = input_date.substr(3, 2); // get the month
        startDay.month = stoi(s);
        s = input_date.substr(6, 4); // get the year
        startDay.year = stoi(s);
    }
    void getEndDayOfCourse(string &input_date)
    {
        string s = input_date.substr(0, 2); // get the day
        endDay.day = stoi(s);
        s = input_date.substr(3, 2); // get the month
        endDay.month = stoi(s);
        s = input_date.substr(6, 4); // get the year
        endDay.year = stoi(s);
    }
};
