#include <bits/stdc++.h>
#include "course.h"
#include "time.h"
using namespace std;
const int maxCourse = 5;
struct Student{
    string ID;
    string firstName;
    string lastName;
    string Class;
    bool gender;// 0 là nam, 1 là nữ
    Date dob;
    string SocialID;
    // mark
    result Result[20];
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
Nodeuser* pUserHead;
void dangnhap(user x);
void checkuser(user &x);
