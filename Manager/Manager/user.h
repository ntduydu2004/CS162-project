#pragma once
#include <iostream>
#include <string>

#include "CustomTime.h"
#include "course.h"


using namespace std;

const int maxCourse = 5;

struct user
{
    // Personal Infomation
    string ID;
    string firstName;
    string lastName;
    char gender; // 'm' = male, 'f' = female, 'u' = unknown
    Date dob;
    string SocialID;
    // Account information
    string password;
    char role; // 'p' = pupil (student), 's' = staff,
    void getDoB(string& input_date) // get a student's DoB from an input string "dd/mm/yyyy"
    {
        string s = input_date.substr(0, 2); // get the day
        dob.day = stoi(s);
        s = input_date.substr(3, 2); // get the month
        dob.month = stoi(s);
        s = input_date.substr(6, 4); // get the year
        dob.year = stoi(s);
    }
};
struct student
{
    user student;
    string Class;
    int numCourse;
    Node<result>* Result{};  
};
void studentLogin(student& x);
void checkStudentLogin(student& x, Node <student>*& pHead);
void staffLogin(user& x);
void checkStaffLogin(user& x, Node <user>*& pHead);
