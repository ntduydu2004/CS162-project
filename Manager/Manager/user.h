#pragma once
#include <iostream>
#include <string>
#include "CustomTime.h"
#include "course.h"


using namespace std;

const int maxCourse = 5;

class User
{
private:
    // Personal Infomation
    string ID;
    string firstName;
    string lastName;
    char gender; // 'm' = male, 'f' = female, 'u' = unknown
    Date dob;
    string SocialID;
    // Account information
    string password;
    char role; // 'p' = pupil (student), 's' = staff, 'u' = unknown
public:
    User() // Default Constructor
    {
        ID = "Unknown";
        firstName = "Unknown";
        lastName = "Unknown";
        gender = 'u';
        SocialID = "Unknown";
        password = "1";
        role = 'u';
    }
    // Full Constructor
    User(string ID, string firstName, string lastName, char gender, Date dob, string SocialID, char role)
    {
        this->ID = ID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->gender = gender;
        this->dob = dob;
        this->SocialID = SocialID;
        this->role = role;
        this->password = "1";
    };
    // Setters
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
    void setGender(char gender)
    {
        this->gender = gender;
    }
    void setDoB(Date dob)
    {
        this->dob = dob;
    }
    void setDoB(int day, int month, int year)
    {
        this->dob = Date(day, month, year);
    }
    void setSocialID(string SocialID)
    {
        this->SocialID = SocialID;
    }
    void setPassword(string password)
    {
        this->password = password;
    }
    void setRole(char role)
    {
        this->role = role;
    }
    // Getters
    string getID()
    {
        return this->ID;
    }
    string getFirstName()
    {
        return this->firstName;
    }
    string getLastName()
    {
        return this->lastName;
    }
    char getGender()
    {
        return this->gender;
    }
    Date getDob()
    {
        return this->dob;
    }
    string getSocialID()
    {
        return this->SocialID;
    }
    char getRole()
    {
        return this->role;
    }
    string getPassword()
    {
        return this->password;
    }
};
class Student : public User
{
private:
    string Class;
    int numCourse;
    Node<result>* Result{};
public:
    Student() : User()
    {
        Class = "Unknown";
        numCourse = 0;
        setRole('p');
        setPassword("1");
    }
    Student(string ID, string firstName, string lastName, char gender, Date dob, string SocialID, int numCourse)
        : User(ID, firstName, lastName, gender, dob, SocialID, 'p')
    {
        this->numCourse = numCourse;
    }

    
};
void dangnhap(User x);
void checkuser(User& x, Node <User>*& phead);
extern User x;
