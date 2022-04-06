#pragma once
#include <iostream>
#include <string>

#include "CustomTime.h"
#include "Linkedlist.h"
//#include "course.h"

using namespace std;

const int maxCourse = 5;

struct user
{
    // Personal Infomation
    string ID;
    string fullname;
    char gender; // 'm' = male, 'f' = female, 'a' = Another
    Date dob;
    string SocialID;
    // Account information
    string password;
    char role;                      // 'p' = pupil (student), 's' = staff,
    void getDoB(string &input_date) // get a student's DoB from an input string "dd/mm/yyyy"
    {
        string s = input_date.substr(0, 2); // get the day
        dob.day = stoi(s);
        s = input_date.substr(3, 2); // get the month
        dob.month = stoi(s);
        s = input_date.substr(6, 4); // get the year
        dob.year = stoi(s);
    }
    void displayProfile()
    {
        cout << "Full Name: " << fullname << "\n";
        cout << "ID: " << ID << "\n";
        cout << "Role: ";
        cout << (role == 'p' ? "Student" : "Staff") << '\n';
        cout << "Gender: ";
        cout << (gender == 'm' ? "Male" : (gender == 'f' ? "Female" : "Other")) << '\n';
        cout << "DOB: ";
        cout << dob.day << "/" << dob.month << "/" << dob.year << "\n";
        cout << "Social ID: " << SocialID << '\n';
    };
};
struct student : user
{
    string Class;
    int numCourse;
    // Node<course> *Course{};
    // Node<result> *Result{};
    void displayStuProfile()
    {
        cout << "Class: " << Class << "\n";
        displayProfile();
        cout << "Courses enrolled: " << numCourse << "\n";
    }
};

struct staff : user
{
};

void login(user &x);
template <class T>
void checkLogin(T &x, Node<T> *&pHead) // lưu danh sách users vô hàm main trước
{
    do
    {
        Node<T> *cur = pHead;
        while (cur != NULL)
        {
            if (cur->data.ID == x.ID && cur->data.password == x.password)
            {
                x = cur->data;
                return;
            }
            cur = cur->next;
        }
        cout << "Ten dang nhap hoac mat khau khong dung!";
        login(x);
    } while (1);
}
