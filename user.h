#pragma once
#include "course.h"

#include <string>

using namespace std;

const int maxCourse = 5;

struct Student{
    string ID;
    string firstName;
    string lastName;
    string Class;
    bool gender;// 1 là nam, 0 là nữ
    Date dob;
    string SocialID;
    // mark
    result Result[20];
    // Info related functions
    void getDoB(string& input_date) // get a student's DoB from an input string "dd/mm/yyyy"
    {
        string s = input_date.substr(0, 2); // get the day
        this->dob.day = stoi(s);
        s = input_date.substr(3, 2); // get the month
        this->dob.month = stoi(s);
        s = input_date.substr(6, 4); // get the year
        this->dob.year = stoi(s);
    }
};
struct Staff{
    string ID;
    string firstName;
    string lastName;
    bool gender;// 0 là nam, 1 là nữ
    Date dob;
    string SocialID;
};
struct user{
    string ID;
    string matkhau;
    short chucvu; // 0 là student, 1 là staff, -1 la khong co user hop le
};
void dangnhap(user x);
void checkuser(user &x);
