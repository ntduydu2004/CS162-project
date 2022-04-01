#include <iostream>
#include <fstream>
#include <string>
#include "CustomTime.h"
#include "user.h"
#include "course.h"
#include "Linkedlist.h"
#include "function.h"

using namespace std;
void mainMenu()
{
    user uStaff;
    student uStudent;
    system("cls");
    
    cout << "1. Dang nhap" << '\n';
    cout << "2. Thoat" << '\n';
    cout << "Nhap 1 so: ";
    int t;
    cin >> t;
    while (t < 1 || t > 2)
    {
        cout << "Invalid input! Please enter again: ";
        cin >> t;
    }
    if (t == 1)
    {
        cout << "Choose your role (0: Staff, 1: Student): ";
        int x;
        cin >> x;
        if (x == 0)
        {
            staffLogin(uStaff);
            Node<user>* pUserHead = NULL;
            if (pUserHead == NULL)
            {
                Node<user>* cur = pUserHead;
                ifstream fin;
                int n;
                fin.open("listofstaffs.txt");
                fin >> n;
                for (int i = 0; i < n; i++)
                {
                    Node<user>* tmp = new Node<user>;
                    fin >> tmp->data.ID >> tmp->data.password;
                    tmp->next = NULL;
                    if (pUserHead == NULL)
                    {
                        pUserHead = tmp;
                        cur = tmp;
                    }
                    else
                    {
                        cur->next = tmp;
                        cur = cur->next;
                    }
                }
                fin.close();
            }
            checkStaffLogin(uStaff, pUserHead);
            staffFunc();
        }
        else
        {
            studentLogin(uStudent);
            Node<student>* pUserHead = NULL;
            if (pUserHead == NULL)
            {
                Node<student>* cur = pUserHead;
                ifstream fin;
                int n;
                fin.open("listofstudents.txt");
                fin >> n;
                for (int i = 0; i < n; i++)
                {
                    Node<student>* tmp = new Node<student>;
                    fin >> tmp->data.student.ID >> tmp->data.student.password >> tmp->data.Class;
                    tmp->next = NULL;
                    if (pUserHead == NULL)
                    {
                        pUserHead = tmp;
                        cur = tmp;
                    }
                    else
                    {
                        cur->next = tmp;
                        cur = cur->next;
                    }
                }
                fin.close();
            }
            checkStudentLogin(uStudent, pUserHead);
            studentFunc();
        }
    }
    else
        exit(0);
}
void outputstudent(student p)
{
    cout << "Class: " << p.Class << endl;
    cout << "Student ID: " << p.student.ID << endl;
    cout << "Full name: " << p.student.fullname << endl;
    cout << "Gender: ";
    if (p.student.gender == 'm')
        cout << "Male" << endl;
    else if (p.student.gender == 'f')
        cout << "Female" << endl;
    else 
        cout << "Another" << endl;
    cout << "Date of Birth: ";
    cout << p.student.dob.day << "/" << p.student.dob.month << "/" << p.student.dob.year << endl;
}

void loadClass(string className, Node<student>* pStudentHead, int& numStudent)
{
    Node<student>* pStudentHead;
    ifstream fin;
    string str = className + ".txt";
    fin.open(str);
    fin >> n;
    fin.get();
    Node<student>* pStudentCur = pStudentHead;
    for (int i = 0;i < n;i++)
    {
        pStudentCur->next = new Node<student>;
        pStudentCur->data.Class = className;
        getline(fin, pStudentCur->data.student.ID, ',');
        fin.get();
        getline(fin, pStudentCur->data.student.fullname, ',');
        fin.get();
        fin >> pStudentCur->data.student.gender;
        fin.get();
        fin.get();
        string input_date;
        getline(fin, input_date, ',');
        pStudentCur->data.student.getDoB(input_date);
        fin.get();
        getline(fin, pStudentCur->data.student.SocialID, '\n');
        pStudentCur = pStudentCur->next;
    }
    delete pStudentCur;
    fin.close();
}

void loadCourse(string courseID, course& cCourse)
{
    ifstream fin;
    string str = courseID + ".txt";
    fin.open(str);
    getline(fin, cCourse.ID, '\n');
    getline(fin, cCourse.name, '\n');
    getline(fin, cCourse.lecturer.fullname, '\n');
    string input_date;
    getline(fin, input_date, '\n');
    cCourse.getStartDayOfCourse(input_date);
    getline(fin, input_date, '\n');
    cCourse.getEndDayOfCourse(input_date);
    getline(fin, cCourse.session[0].weekday, ',');
    fin.get();
    getline(fin, input_date, '\n');
    cCourse.session[0].getTimeOfCourse(input_date);
    getline(fin, cCourse.session[1].weekday, ',');
    fin.get();
    getline(fin, input_date, '\n');
    cCourse.session[1].getTimeOfCourse(input_date);
    int n;
    fin >> n;
    cCourse.nStudentHead = new Node<student>;
    Node<student>* nStudentCur = cCourse.nStudentHead;
    for (int i = 0;i < n;i++)
    {
        nStudentCur->next = new Node<student>;
        getline(fin, cCourse.nStudentHead->data.Class, ' ');
        getline(fin, cCourse.nStudentHead->data.student.ID, '\n');
        nStudentCur = nStudentCur->next;
    }
    delete nStudentCur;
    fin.close();
}

void studentFunc()
{
    /*
     * This function reads the CSV file containing new classes followed by their student list. The
     * file should be of the below format:
     *
     * Class, Student ID, First name, Last name, Gender, Date of Birth, Social ID
     *
     * Sample input:
     * 21APCS1, 21125118, Minh, Bui Vu Bao, 1, 07/07/2003, ABCDEFGH
     *
     * Note:
     * - Default input file for 1st Year students is "New_Classes.txt"
     */
    system("cls");
    cout << "1. View profile" << '\n';
    cout << "2. View courses" << '\n';
    cout << "3. Register courses" << '\n';
    cout << "4. Log out" << '\n';
    cout << "Enter a number: ";
    int m;
    cin >> m;
    while (m < 1 || m > 4)
    {
        cout << "Invalid Input! Please enter again: ";
        cin >> m;
    }
    inputstudent(infoX);
    if (m == 1)
    {
        system("cls");
        cout << "Your profile: ";
        outputstudent(infoX);
        cout << "Enter a number to back to menu: ";
        cin >> m;
        studentFunc();
    }
    else if (m == 2)
    {


        cout << "Enter a number to back to menu: ";
        cin >> m;
        studentFunc();
    }
    else if (m == 3)
    {


        cout << "Enter a number to back to menu: ";
        cin >> m;
        studentFunc();
    }
    else
    {
        menuchinh();
    }
}
void inputstudent(Student& p)
{
    ifstream fin;
    string s = x.locate + ".txt";
    fin.open(s);
    int n;
    fin >> n;
    p.Class = x.locate;
    for (int i = 0; i < n; i++)
    {
        fin >> p.ID;
        getline(fin, p.ID, ',');
        fin.ignore(2);
        getline(fin, p.firstName, ',');
        fin.ignore(2);
        getline(fin, p.lastName, ',');
        fin.ignore(2);
        fin >> p.gender;
        fin.ignore(2);
        getline(fin, p.SocialID);
        if (p.ID == x.ID)
            break;
    }
    fin.close();
}
void outputstaff(Staff p)
{
}
void staffFunc()
{
}
void inputstaff(Staff& p)
{
}