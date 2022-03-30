#include <iostream>
#include <fstream>
#include <string>
#include "CustomTime.h"
#include "user.h"
#include "course.h"
#include "Linkedlist.h"
using namespace std;
void menuchinh()
{
    system("cls");
    Node<user> *pUserHead = NULL;
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
        dangnhap(x);

        if (pUserHead == NULL)
        {
            Node<user> *cur = pUserHead;
            ifstream fin;
            int n;
            fin.open("listofusers.txt");
            fin >> n;
            for (int i = 0; i < n; i++)
            {
                Node<user> *tmp = new Node <user>;
                fin >> tmp->data.ID >> tmp->data.matkhau >> tmp->data.chucvu >> tmp->data.locate;
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
        checkuser(x, pUserHead);
    }
    else
        exit(0);

    if (x.chucvu == 0)
    {
        studentFunc();
    }
    else if (x.chucvu == 1)
    {
        staffFunc();
    }
}
void outputstudent(Student p)
{
    cout << "Class: " << p.Class << endl;
    cout << "Student ID: " << p.ID << endl;
    cout << "Full name: " << p.lastName << " " << p.firstName << endl;
    cout << "Gender: ";
    if (p.gender)
        cout << "Male" << endl;
    else
        cout << "Female" << endl;
    cout << "Date of Birth: ";
    cout << p.dob.day << "/" << p.dob.month << "/" << p.dob.year << endl;
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
void inputstudent(Student &p)
{
    ifstream fin;
    string s = x.locate + ".txt";
    fin.open(s);
    int n;
    fin >> n;
    Student p;
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
void inputstaff(Staff &p)
{
}