#pragma once
#include <iostream>
#include <string>


#include "course.h"


using namespace std;

const int maxCourse = 5;

class User
{
private:
    string ID;
    string firstName;
    string lastName;
    string Class;
    char gender; // "m" = male, "f" = female, "u" = unknown
    Date dob;
    string SocialID;
public:
    User() // Default Constructor
    {
        ID = "Unknown";
        firstName = "Unknown";
        lastName = "Unknown";
        Class = "Unknown";
        gender = 'u';
        SocialID = "Unknown";
    }
    // Full Constructor
    User(string ID, string firstName, string lastName, string Class, char gender, Date dob, string SocialID)
    {
        this->ID = ID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->Class = Class;
        this->gender = gender;
        this->dob = dob;
        this->SocialID = SocialID;
    }
    void setID(string ID)
    {
        this->ID = ID;
    }
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }

};

struct Student {
    string ID;
    string firstName;
    string lastName;
    string Class;
    short gender = -1;// 1 là nam, 0 là nữ, -1 là chưa xác định được danh tính
    Date dob;
    string SocialID;
    // mark
    short numCourse; //
    result Result[20];
    // Constructor
    Student() {};
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
struct Staff {
    string ID;
    string firstName;
    string lastName;
    short gender;// 0 là nam, 1 là nữ, -1 la chưa xác định được danh tính
    Date dob;
    string SocialID;
};
struct user {
    string ID;
    string matkhau;
    short chucvu; // 0 là student, 1 là staff, -1 la khong co user hop le
    string locate; //lưu class
};
void dangnhap(user x);
void checkuser(user& x, Node <user>*& phead);
extern user x;
extern Student infoX;
extern Staff infoY;
