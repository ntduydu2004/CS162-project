#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "CustomTime.h"
#include "user.h"
#include "course.h"
#include "Linkedlist.h"
#include "function.h"

using namespace std;
void mainMenu()
{
    staff uStaff;
    student uStudent;
    system("cls");

    cout << "1. Dang nhap" << '\n';
    cout << "2. Thoat" << '\n';
    cout << "Nhap 1 so: ";
    int t;
    cin >> t;
    while (t < 1 || t > 2)
    {
        cout << "Invalid input! Please enter again\n";
        cin >> t;
    }
    if (t != 1)
        exit(0);
    cout << "Choose your role (0: Staff, 1: Student): ";
    int x;
    cin >> x;
    if (x == 0)
    {
        staffLogin(uStaff);
        Node<user> *pUserHead = NULL;
        if (pUserHead == NULL)
        {
            Node<user> *cur = pUserHead;
            ifstream fin;
            int n;
            fin.open("../data/listofstaffs.txt");
            fin >> n;
            for (int i = 0; i < n; i++)
            {
                Node<user> *tmp = new Node<user>;
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
        Node<student> *pUserHead = NULL;
        if (pUserHead == NULL)
        {
            Node<student> *cur = pUserHead;
            ifstream fin;
            int n;
            fin.open("../data/listofstudents.txt");
            fin >> n;
            for (int i = 0; i < n; i++)
            {
                Node<student> *tmp = new Node<student>;
                fin >> tmp->data.ID >> tmp->data.password >> tmp->data.Class;
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
void outputStudent(student p)
{
    cout << "Class: " << p.Class << '\n';
    cout << "Student ID: " << p.ID << '\n';
    cout << "Full name: " << p.fullname << '\n';
    cout << "Gender: ";
    cout << (p.gender == 'm' ? "Male" : (p.gender == 'f' ? "Female" : "Other")) << '\n';
    cout << "Date of Birth: ";
    cout << p.dob.day << "/" << p.dob.month << "/" << p.dob.year << '\n';
}

void loadClass(string className, Node<student> *pStudentHead, int &numStudent)
{
    ifstream fin;
    string str = className + ".txt";
    fin.open(str);
    fin >> numStudent;
    fin.get();
    Node<student> *pStudentCur = pStudentHead;
    for (int i = 0; i < numStudent; i++)
    {
        pStudentCur->next = new Node<student>;
        pStudentCur->data.Class = className;
        getline(fin, pStudentCur->data.ID, ',');
        fin.get();
        getline(fin, pStudentCur->data.fullname, ',');
        fin.get();
        fin >> pStudentCur->data.gender;
        fin.get();
        fin.get();
        string input_date;
        getline(fin, input_date, ',');
        pStudentCur->data.getDoB(input_date);
        fin.get();
        getline(fin, pStudentCur->data.SocialID, '\n');
        pStudentCur = pStudentCur->next;
    }
    delete pStudentCur;
    fin.close();
}

void loadCourse(string courseID, course &cCourse)
{
    ifstream fin;
    string str = courseID + ".txt";
    fin.open(str);
    getline(fin, cCourse.ID, '\n');
    getline(fin, cCourse.name, '\n');
    getline(fin, cCourse.lecturer, '\n');
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
    Node<student> *nStudentCur = cCourse.nStudentHead;
    for (int i = 0; i < n; i++)
    {
        nStudentCur->next = new Node<student>;
        getline(fin, cCourse.nStudentHead->data.Class, ' ');
        getline(fin, cCourse.nStudentHead->data.ID, '\n');
        nStudentCur = nStudentCur->next;
    }
    delete nStudentCur;
    fin.close();
}

void outputClass(string className)
{
    Node<student> *pStudentHead = new Node<student>;
    int numStudent = 0;
    loadClass(className, pStudentHead, numStudent);
    cout << className << '\n';
    for (int i = 0; i < numStudent; i++)
    {
        cout << setprecision(10) << pStudentHead->data.ID << "  ";
        cout << setprecision(30) << pStudentHead->data.fullname << "  ";
        cout << setprecision(12) << (pStudentHead->data.gender == 'm' ? "Male" : (pStudentHead->data.gender == 'f' ? "Female" : "Another")) << "  ";
        int time = pStudentHead->data.dob.day;
        if (time >= 10)
            cout << time << "/";
        else
            cout << "0" << time << "/";
        time = pStudentHead->data.dob.month;
        if (time >= 10)
            cout << time << "/";
        else
            cout << "0" << time << "/";
        cout << pStudentHead->data.dob.year << "  ";
        cout << setprecision(15) << pStudentHead->data.SocialID << '\n';
    }
    for (Node<student> *pCur = pStudentHead; pCur != NULL; pCur = pCur->next)
        delete pCur;
}

void outputCourse(string courseID)
{
    course cCourse;
    int numStudent = 0;
    loadCourse(courseID, cCourse);
    cout << cCourse.ID << '\n';
    cout << cCourse.name << '\n';
    cout << "Lecturer: " << cCourse.lecturer << '\n';
    int time = cCourse.startDay.day;
    cout << "Start: " << cCourse.startDay.day << "/" << cCourse.startDay.day << "/" << cCourse.startDay.day << '\n';
    cout << "End  : " << cCourse.endDay.day << "/" << cCourse.endDay.day << "/" << cCourse.endDay.day << '\n';
    cout << "Time: " << cCourse.session[0].weekday << "  " << cCourse.session[0].time.hour << ":" << cCourse.session[0].time.min << ",  ";
    cout << cCourse.session[0].weekday << "  " << cCourse.session[0].time.hour << ":" << cCourse.session[0].time.min << ",  ";
    Node<student> *pCur = cCourse.nStudentHead;
    for (int i = 0; i < cCourse.numStudent; i++)
    {
        cout << pCur->data.Class << "  " << pCur->data.ID << '\n';
        pCur = pCur->next;
    }
    for (Node<student> *pDel = cCourse.nStudentHead; pDel != NULL; pDel = pDel->next)
        delete pDel;
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
    student curr;
    inputstudent(curr);
    switch (m)
    {
    case 1:
        system("cls");
        cout << "Your profile: ";
        outputStudent(curr);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        mainMenu();
        break;
    }

    cout << "Enter a number to back to menu: ";
    cin >> m;
    studentFunc();
}
void inputstudent(student &p)
{
    ifstream fin;
    fin.open("../data/listofstudents.txt");
    int n;
    fin >> n;
    student temp;
    for (int i = 0; i < n; i++)
    {
        fin >> temp.ID;
        getline(fin, temp.ID, ',');
        fin.ignore(2);
        getline(fin, temp.fullname, ',');
        fin.ignore(2);
        fin >> temp.gender;
        fin.ignore(2);
        getline(fin, temp.SocialID);
        if (temp.ID == p.ID)
            break;
    }
    fin.close();
}
void outputstaff(staff p)
{
}
void staffFunc()
{
}
void inputstaff(staff &p)
{
}