#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
struct node
{
    T data;
    node *next = nullptr;
};
struct date
{
    short day, month;
    int year;
};

struct user
{
    string id;
    string password;
    string fullname;
    string gender;
    date dob;
    string sDate;
    string email;
    void getDoB() // get a student's DoB from an input string "dd/mm/yyyy"
    {
        dob.day = stoi(sDate.substr(0, 2));
        dob.month = stoi(sDate.substr(3, 2));
        dob.year = stoi(sDate.substr(6, 4));
    }
};
struct student : user
{
    int firstYear;
    string schoolYear;
    string semeter;
    string Class;
    string isRegistered[5];
    string courseID[5];
    string nameCourse[5];
    short courseView;
    void getFirstYear()
    {
        firstYear = stoi(Class.substr(0, 2)) + 2000;
    }
};
struct Time
{
    short hour = -1, min = -1;
};
struct session
{
    string weekday = "\0";
    string sTime = "\0";
    Time tTimeStart, tTimeEnd;
    void getStartTimeOfCourse()
    {
        string s = sTime.substr(0, 2);
        tTimeStart.hour = stoi(s);
        s = sTime.substr(3, 2);
        tTimeStart.min = stoi(s);
    }
    void getEndTimeOfCourse()
    {
        string s = sTime.substr(8, 2);
        tTimeEnd.hour = stoi(s);
        s = sTime.substr(11, 2);
        tTimeEnd.min = stoi(s);
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
struct Course
{
    string ID;
    string name;
    session sSession[2];
    string lecturer;
    int maxStudent = 0, numStudent = 0;
    date startDay, endDay;
    string sDay;
    node<student> *nStudentHead = nullptr;
    void getStartDayOfCourse()
    {
        string s = sDay.substr(0, 2); // get the day
        startDay.day = stoi(s);
        s = sDay.substr(3, 2); // get the month
        startDay.month = stoi(s);
        s = sDay.substr(6, 4); // get the year
        startDay.year = stoi(s);
    }
    void getEndDayOfCourse()
    {
        string s = sDay.substr(13, 2); // get the day
        endDay.day = stoi(s);
        s = sDay.substr(16, 2); // get the month
        endDay.month = stoi(s);
        s = sDay.substr(19, 4); // get the year
        endDay.year = stoi(s);
    }
};

void loadFileStaff(node<user> *&pHead, int &n);
void deleteListStaff(node<user> *&pHead, int n);
bool checkStafflogin(user &uStaff);
void loadFileDetailOfStaff(node<user> *&pHead, int &n);
void detailOfStaff(user &uStaff);

void loadFileStudent(node<student> *&pHead, int &n);
void deleteListStudent(node<student> *&pHead, int n);
bool checkStudentLogin(student &sStudent);
void loadFileClass(node<student> *&pHead, string className, int &n);
void detailOfStudent(student &sStudent);
void loadFileCourseOfClass(node<student> *&pHead, student &sStudent, int &n);
void checkStudentCourse(student &sStudent);
void loadFileCourse(string courseID, Course &cCourse, student &sStudent);
void registerCourse(student &sStudent, Course &cCourse);
bool checkFileExist(student &sStudent);
