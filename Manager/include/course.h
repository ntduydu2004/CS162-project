#pragma once
#include "CustomTime.h"
#include "Linkedlist.h"
struct session
{
    string weekday;
    string sTime;
    Time tTime;
    session()
    {
        weekday = "Unknown";
        tTime.hour = -1;
        tTime.min = -1;
    }
    void getTimeOfCourse()
    {
        string s = sTime.substr(0, 2);
        tTime.hour = stoi(s);
        s = sTime.substr(3, 2);
        tTime.min = stoi(s);
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
    session sSession[2];
    string lecturer;
    int numStudent;
    Date startDay, endDay;
    string sStartDay, sEndDay;
    Node<student> *nStudentHead = nullptr;
    void getStartDayOfCourse()
    {
        string s = sStartDay.substr(0, 2); // get the day
        startDay.day = stoi(s);
        s = sStartDay.substr(3, 2); // get the month
        startDay.month = stoi(s);
        s = sStartDay.substr(6, 4); // get the year
        startDay.year = stoi(s);
    }
    void getEndDayOfCourse()
    {
        string s = sEndDay.substr(0, 2); // get the day
        endDay.day = stoi(s);
        s = sEndDay.substr(3, 2); // get the month
        endDay.month = stoi(s);
        s = sEndDay.substr(6, 4); // get the year
        endDay.year = stoi(s);
    }
};
