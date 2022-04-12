#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "../include/raylib.h"
#include "raygui.h"
using namespace std;


template <class T>
struct node
{
    T data;
    node* next = NULL;
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
        string s = sDate.substr(0, 2); // get the day
        dob.day = stoi(s);
        s = sDate.substr(3, 2); // get the month
        dob.month = stoi(s);
        s = sDate.substr(6, 4); // get the year
        dob.year = stoi(s);
    }
};
struct student : user
{
    string Class;
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