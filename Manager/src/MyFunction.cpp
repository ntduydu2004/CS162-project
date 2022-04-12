#include "../include/MyFunction.h"

void loadFileStaff(node<user>*& pHead, int& n)
{
    ifstream fin;
    fin.open("listofstaff.txt");
    fin >> n;
    fin.get();
    node<user>* pCur = nullptr;
    for (int i = 0;i < n;i++)
    {
        if (pHead == nullptr)
        {
            pHead = new node<user>;
            pCur = pHead;
        }
        else
        {
            pCur->next = new node<user>;
            pCur = pCur->next;
        }
        getline(fin, pCur->data.id, ' ');
        getline(fin, pCur->data.password, '\n');
    }
    fin.close();
}

void deleteListStaff(node<user>*& pHead, int n)
{
    for (int i = 0;i < n;i++)
    {
        node<user>* pDel = pHead;
        pHead = pHead->next;
        delete pDel;
    }
}

bool checkStafflogin(user& uStaff)
{
    node<user>* pHead = nullptr;
    int n = 0;
    loadFileStaff(pHead, n);
    node<user>* pCur = pHead;
    for (int i = 0;i < n;i++)
    {
        if (pCur->data.id == uStaff.id && pCur->data.password == uStaff.password)
        {
            deleteListStaff(pHead, n);
            detailOfStaff(uStaff);
            return true;
        }
        pCur = pCur->next;
    }
    deleteListStaff(pHead, n);
    return false;
}

void loadFileStudent(node<student>*& pHead, int& n)
{
    ifstream fin;
    fin.open("listofstudent.txt");
    fin >> n;
    fin.get();
    node<student>* pCur = nullptr;
    for (int i = 0;i < n;i++)
    {
        if (pHead == nullptr)
        {
            pHead = new node<student>;
            pCur = pHead;
        }
        else
        {
            pCur->next = new node<student>;
            pCur = pCur->next;
        }
        getline(fin, pCur->data.id, ' ');
        getline(fin, pCur->data.password, ' ');
        getline(fin, pCur->data.Class, '\n');
    }
    fin.close();
}

void deleteListStudent(node<student>*& pHead, int n)
{
    for (int i = 0;i < n;i++)
    {
        node<student>* pDel = pHead;
        pHead = pHead->next;
        delete pDel;
    }
}

bool checkStudentLogin(student& sStudent)
{
    node<student>* pHead = nullptr;
    int n = 0;
    loadFileStudent(pHead, n);
    node<student>* pCur = pHead;
    for (int i = 0;i < n;i++)
    {
        if (pCur->data.id == sStudent.id && pCur->data.password == sStudent.password)
        {
            sStudent.Class = pCur->data.Class;
            deleteListStudent(pHead, n);
            detailOfStudent(sStudent);
            return true;
        }
        pCur = pCur->next;
    }
    deleteListStudent(pHead, n);
    return false;
}
void loadFileDetailOfStaff(node<user>*& pHead, int& n)
{
    ifstream fin;
    fin.open("DetailOfStaff.csv");
    if (fin.is_open())
    {
        fin >> n;
        fin.get();
        node<user>* pCur = nullptr;
        for (int i = 0; i < n + 1; i++)
        {
            if (pHead == nullptr)
            {
                pHead = new node<user>;
                pCur = pHead;
            }
            else
            {
                pCur->next = new node<user>;
                pCur = pCur->next;
            }
            getline(fin, pCur->data.id, ',');
            getline(fin, pCur->data.fullname, ',');
            getline(fin, pCur->data.gender, ',');
            getline(fin, pCur->data.sDate, ',');
            getline(fin, pCur->data.email, '\n');
        }
    }
    fin.close();
}

void loadFileClass(node<student>*& pHead, string className, int& n)
{
    ifstream fin;
    string str = className + ".csv";
    fin.open(str);
    if (fin.is_open())
    {
        fin >> n;
        fin.get();
        node<student>* pCur = nullptr;
        string input_date;
        for (int i = 0; i < n + 1; i++)
        {
            if (pHead == nullptr)
            {
                pHead = new node<student>;
                pCur = pHead;
            }
            else
            {
                pCur->next = new node<student>;
                pCur = pCur->next;
            }
            getline(fin, pCur->data.id, ',');
            getline(fin, pCur->data.fullname, ',');
            getline(fin, pCur->data.gender, ',');
            getline(fin, pCur->data.sDate, ',');
            getline(fin, pCur->data.email, '\n');
        }
    }
    fin.close();
}

void detailOfStaff(user& uStaff)
{
    node<user>* pHead = nullptr;
    int n;
    loadFileDetailOfStaff(pHead, n);
    node<user>* pCur = pHead;
    for (int i = 0;i < n + 1;i++)
    {
        if (uStaff.id == pCur->data.id)
        {
            uStaff.fullname = pCur->data.fullname;
            uStaff.gender = pCur->data.gender;
            uStaff.sDate = pCur->data.sDate;
            uStaff.email = pCur->data.email;
            deleteListStaff(pHead, n + 1);
            return;
        }
        pCur = pCur->next;
    }
}

void detailOfStudent(student& sStudent)
{
    node<student>* pHead = nullptr;
    int n;
    loadFileClass(pHead, sStudent.Class, n);
    node<student>* pCur = pHead;
    for (int i = 0;i < n + 1;i++)
    {
        if (sStudent.id == pCur->data.id)
        {
            sStudent.fullname = pCur->data.fullname;
            sStudent.gender = pCur->data.gender;
            sStudent.sDate = pCur->data.sDate;
            sStudent.email = pCur->data.email;
            deleteListStudent(pHead, n + 1);
            return;
        }
        pCur = pCur->next;
    }
}

