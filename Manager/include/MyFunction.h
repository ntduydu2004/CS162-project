#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
using namespace std;
template <class T>
struct node
{
    T data;
    node* next = nullptr;
};
struct date
{
    short day{ -1 }, month{ -1 };
    int year{ -1 };
};
struct result
{
    string courseID;
    string type;
    float lab;
    float quiz;
    float midterm;
    float finalterm;
    float average;
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
    result rResult[5];
    short courseView;
    short semesterStatus = -1;
    void getFirstYear()
    {
        firstYear = stoi(Class.substr(0, 2)) + 2000;
    }
    void getAverageResult(int i)
    {
        if (rResult[i].quiz >= 0 && rResult[i].lab >= 0 && rResult[i].midterm >= 0 && rResult[i].finalterm >= -1.0)
            rResult[i].average = rResult[i].quiz * 0.1 + rResult[i].lab * 0.2 + rResult[i].midterm * 0.3 + rResult[i].finalterm * 0.4;
        else if (rResult[i].quiz == -2.0)
            rResult[i].average = -2.0;
        else rResult[i].average = -1.0;
        if (rResult[i].average == -2.0)
            rResult[i].type = "Not";
        else if (rResult[i].average == -1)
            rResult[i].type = "None";
        else if (rResult[i].average < 5.0)
            rResult[i].type = "None";
        else if (rResult[i].average < 6.0)
            rResult[i].type = "D";
        else if (rResult[i].average < 7.0)
            rResult[i].type = "C";
        else if (rResult[i].average < 8.0)
            rResult[i].type = "B";
        else if (rResult[i].average < 9.0)
            rResult[i].type = "A";
        else rResult[i].type = "A+";
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
    void getSTime()
    {
        sTime = "";
        if (weekday == "\0" || weekday == "")
            sTime += "None ";
        else
            sTime += weekday + " ";

        string strHour, strMin;

        if (tTimeStart.hour > 9 || tTimeStart.hour == -1)
            strHour = to_string(tTimeStart.hour);
        else
            strHour = "0" + to_string(tTimeStart.hour);

        if (tTimeStart.min > 9 || tTimeStart.min == -1)
            strMin = to_string(tTimeStart.min);
        else
            strMin = "0" + to_string(tTimeStart.min);

        sTime += strHour + ":" + strMin + " - ";

        if (tTimeEnd.hour > 9 || tTimeEnd.hour == -1)
            strHour = to_string(tTimeEnd.hour);
        else
            strHour = "0" + to_string(tTimeEnd.hour);

        if (tTimeEnd.min > 9 || tTimeEnd.min == -1)
            strMin = to_string(tTimeEnd.min);
        else
            strMin = "0" + to_string(tTimeEnd.min);

        sTime += strHour + ":" + strMin;

    }
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

struct Course
{
    string ID;
    string name;
    session sSession[2];
    string lecturer;
    int maxStudent = 0, numStudent = 0, classAllowed = 0;
    string nameClassAllowed[10];
    date startDay, endDay;
    string sDay;
    node<student>* nStudentHead = nullptr;
    void getSDay()
    {
        sDay = "";
        string strDay, strMonth, strYear;

        if (startDay.day > 9 || startDay.day < 0)
            strDay = to_string(startDay.day);
        else
            strDay = "0" + to_string(startDay.day);

        if (startDay.month > 9 || startDay.day < 0)
            strMonth = to_string(startDay.month);
        else
            strMonth = "0" + to_string(startDay.month);

        strYear = to_string(startDay.year);

        sDay += strDay + "/" + strMonth + "/" + strYear + " - ";

        if (endDay.day > 9 || endDay.day < 0)
            strDay = to_string(endDay.day);
        else
            strDay = "0" + to_string(endDay.day);

        if (endDay.month > 9 || endDay.month < 0)
            strMonth = to_string(endDay.month);
        else
            strMonth = "0" + to_string(endDay.month);

        strYear = to_string(endDay.year);

        sDay += strDay + "/" + strMonth + "/" + strYear;
    }
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

void loadFileStaff(node<user>*& pHead, int& n);
void deleteListStaff(node<user>*& pHead, int n);
bool checkStafflogin(user& uStaff);
void loadFileDetailOfStaff(node<user>*& pHead, int& n);
void detailOfStaff(user& uStaff);


void loadFileStudent(node<student>*& pHead, int& n);
void deleteListStudent(node<student>*& pHead, int n);
bool checkStudentLogin(student& sStudent);
void loadFileClass(node<student>*& pHead, string className, int& n);
void detailOfStudent(student& sStudent);
void loadFileCourseOfClass(node<student>*& pHead, student& sStudent, int& n);
void checkStudentCourse(student& sStudent);
void loadFileCourse(string courseID, Course& cCourse, student& sStudent);
void registerCourse(student& sStudent, Course& cCourse);
void unregisterCourse(student& sStudent, Course& cCourse);
bool checkFileExist(student& sStudent, short CourseOrResult);
void checkStudentResult(student& sStudent, Course& cCourse);
void updateFileCourse(student& sStudent, Course& cCourse, bool isRegister);
void updateFileCourseOfClass(student& sStudent, node<student>* pHead, int& n);
void updateFileStaff(node<user>* pHead, int n);
void updateFileStudent(node<student>* pHead, int n);

void createSchoolYear(short& numSchoolYear); // Add a new schoool year succeeding the current year

void RemoveCourse(student& sStudent, Course& course, string name[], int& dummy);
