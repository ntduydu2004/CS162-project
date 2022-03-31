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
