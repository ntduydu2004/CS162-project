//#pragma once
//#include <string>
//#include "MyFunction.h"
//using namespace std;
//
//struct Time
//{
//    short hour = -1, min = -1;
//};
//struct session
//{
//    string weekday = "\0";
//    string sTime = "\0";
//    Time tTimeStart, tTimeEnd;
//    void getStartTimeOfCourse()
//    {
//        string s = sTime.substr(0, 2);
//        tTimeStart.hour = stoi(s);
//        s = sTime.substr(3, 2);
//        tTimeStart.min = stoi(s);
//    }
//    void getEndTimeOfCourse()
//    {
//        string s = sTime.substr(8, 2);
//        tTimeEnd.hour = stoi(s);
//        s = sTime.substr(11, 2);
//        tTimeEnd.min = stoi(s);
//    }
//};
//
//struct result
//{
//    string courseID;
//    float thuchanh;
//    float quiz;
//    float giuaky;
//    float cuoiky;
//};
//struct Course
//{
//    string ID;
//    string name;
//    session sSession[2];
//    string lecturer;
//    int maxStudent = 0, numStudent = 0;
//    date startDay, endDay;
//    string sDay;
//    node<student>* nStudentHead = nullptr;
//    void getStartDayOfCourse()
//    {
//        string s = sDay.substr(0, 2); // get the day
//        startDay.day = stoi(s);
//        s = sDay.substr(3, 2); // get the month
//        startDay.month = stoi(s);
//        s = sDay.substr(6, 4); // get the year
//        startDay.year = stoi(s);
//    }
//    void getEndDayOfCourse()
//    {
//        string s = sDay.substr(13, 2); // get the day
//        endDay.day = stoi(s);
//        s = sDay.substr(16, 2); // get the month
//        endDay.month = stoi(s);
//        s = sDay.substr(19, 4); // get the year
//        endDay.year = stoi(s);
//    }
//};
