#include "../include/MyFunction.h"

#include <direct.h>
#include <stdio.h>

void loadFileStaff(node<user> *&pHead, int &n)
{
    ifstream fin;
    fin.open("../data/listofstaff.txt");
    fin >> n;
    fin.get();
    node<user> *pCur = nullptr;
    for (int i = 0; i < n; i++)
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

void deleteListStaff(node<user> *&pHead, int n)
{
    for (int i = 0; i < n; i++)
    {
        node<user> *pDel = pHead;
        pHead = pHead->next;
        delete pDel;
    }
}

bool checkStafflogin(user &uStaff)
{
    node<user> *pHead = nullptr;
    int n = 0;
    loadFileStaff(pHead, n);
    node<user> *pCur = pHead;
    for (int i = 0; i < n; i++)
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

void loadFileStudent(node<student> *&pHead, int &n)
{
    ifstream fin;
    fin.open("../data/listofstudent.txt");
    fin >> n;
    fin.get();
    node<student> *pCur = nullptr;
    for (int i = 0; i < n; i++)
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

void deleteListStudent(node<student> *&pHead, int n)
{
    for (int i = 0; i < n; i++)
    {
        node<student> *pDel = pHead;
        pHead = pHead->next;
        delete pDel;
    }
}

bool checkStudentLogin(student &sStudent)
{
    node<student> *pHead = nullptr;
    int n = 0;
    loadFileStudent(pHead, n);
    node<student> *pCur = pHead;
    for (int i = 0; i < n; i++)
    {
        if (pCur->data.id == sStudent.id && pCur->data.password == sStudent.password)
        {
            sStudent.Class = pCur->data.Class;
            deleteListStudent(pHead, n);
            detailOfStudent(sStudent);
            sStudent.getFirstYear();
            return true;
        }
        pCur = pCur->next;
    }
    deleteListStudent(pHead, n);
    return false;
}
void loadFileDetailOfStaff(node<user> *&pHead, int &n)
{
    ifstream fin;
    fin.open("../data/DetailOfStaff.csv");
    if (fin.is_open())
    {
        fin >> n;
        fin.get();
        node<user> *pCur = nullptr;
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

void loadFileClass(node<student> *&pHead, string className, int &n)
{
    ifstream fin;
    fin.open("../data/detailofeachclass/" + className + ".csv");
    if (fin.is_open())
    {
        fin >> n;
        while(fin.get() != '\n');
        node<student> *pCur = nullptr;
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

void detailOfStaff(user &uStaff)
{
    node<user> *pHead = nullptr;
    int n;
    loadFileDetailOfStaff(pHead, n);
    node<user> *pCur = pHead;
    for (int i = 0; i < n + 1; i++)
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

void detailOfStudent(student &sStudent)
{
    node<student> *pHead = nullptr;
    int n;
    loadFileClass(pHead, sStudent.Class, n);
    node<student> *pCur = pHead;
    for (int i = 0; i < n + 1; i++)
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

void loadFileCourseOfClass(node<student> *&pHead, student &sStudent, int &n)
{
    ifstream fin;
    fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/CourseOf" + sStudent.Class + ".csv");
    if (fin.is_open())
    {
        fin >> n;
        fin.get();

        string s;
        getline(fin, s, ',');
        getline(fin, sStudent.courseID[0], ',');
        getline(fin, sStudent.courseID[1], ',');
        getline(fin, sStudent.courseID[2], ',');
        getline(fin, sStudent.courseID[3], ',');
        getline(fin, sStudent.courseID[4], '\n');
        getline(fin, s, ',');
        getline(fin, sStudent.nameCourse[0], ',');
        getline(fin, sStudent.nameCourse[1], ',');
        getline(fin, sStudent.nameCourse[2], ',');
        getline(fin, sStudent.nameCourse[3], ',');
        getline(fin, sStudent.nameCourse[4], '\n');
        node<student> *pCur = nullptr;
        for (int i = 0; i < n; i++)
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
            getline(fin, pCur->data.isRegistered[0], ',');
            getline(fin, pCur->data.isRegistered[1], ',');
            getline(fin, pCur->data.isRegistered[2], ',');
            getline(fin, pCur->data.isRegistered[3], ',');
            getline(fin, pCur->data.isRegistered[4], '\n');
        }
    }
    fin.close();
}

void loadFileCourse(string courseID, Course &cCourse, student &sStudent)
{
    cCourse.ID = courseID;
    ifstream fin;
    fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/" + courseID + ".txt");
    getline(fin, cCourse.name, '\n');
    getline(fin, cCourse.lecturer, '\n');
    getline(fin, cCourse.sDay, '\n');
    getline(fin, cCourse.sSession[0].weekday, ' ');
    getline(fin, cCourse.sSession[0].sTime, '\n');
    getline(fin, cCourse.sSession[1].weekday, ' ');
    getline(fin, cCourse.sSession[1].sTime, '\n');
    fin >> cCourse.maxStudent;
    fin.get();
    fin >> cCourse.numStudent;
    fin.get();
    node<student> *nStudentCur = nullptr;
    for (int i = 0; i < cCourse.numStudent; i++)
    {
        if (cCourse.nStudentHead == nullptr)
        {
            cCourse.nStudentHead = new node<student>;
            nStudentCur = cCourse.nStudentHead;
        }
        else
        {
            nStudentCur->next = new node<student>;
            nStudentCur = nStudentCur->next;
        }
        getline(fin, nStudentCur->data.Class, ' ');
        getline(fin, nStudentCur->data.id, ' ');
        fin >> nStudentCur->data.rResult[sStudent.courseView].quiz;
        fin.get();
        fin >> nStudentCur->data.rResult[sStudent.courseView].lab;
        fin.get();
        fin >> nStudentCur->data.rResult[sStudent.courseView].midterm;
        fin.get();
        fin >> nStudentCur->data.rResult[sStudent.courseView].finalterm;
        fin.get();
        fin >> nStudentCur->data.rResult[sStudent.courseView].average;
        fin.get();
        getline(fin, nStudentCur->data.rResult[sStudent.courseView].type, '\n');
    }
    fin.close();
}

void checkStudentCourse(student &sStudent)
{
    int n = 0;
    node<student> *pHead = nullptr;
    loadFileCourseOfClass(pHead, sStudent, n);
    node<student> *pCur = pHead;
    for (int i = 0; i < n; i++)
    {
        if (sStudent.id == pCur->data.id)
        {
            for (int j = 0; j < 5; j++)
                sStudent.isRegistered[j] = pCur->data.isRegistered[j];
            deleteListStudent(pHead, n);
            return;
        }
        pCur = pCur->next;
    }
}
void checkStudentResult(student &sStudent, Course& cCourse)
{
    int n = 0;
    node<student> *pHead = nullptr;
    loadFileCourseOfClass(pHead, sStudent, n);
    node<student> *pCur = pHead;
    for (int i = 0; i < n; i++)
    {
        if (sStudent.id == pCur->data.id)
        {
            for (int j = 0; j < 5; j++)
            {
                sStudent.isRegistered[j] = pCur->data.isRegistered[j];
                if (sStudent.isRegistered[j] == "Registered")
                {
                    loadFileCourse(sStudent.courseID[j], cCourse, sStudent);
                    node<student>* p = cCourse.nStudentHead;
                    for (int k = 0;k < cCourse.numStudent;k++)
                    {
                        if (p->data.id == sStudent.id && p->data.Class == sStudent.Class)
                        {
                            sStudent.rResult[j].quiz = pCur->data.rResult[j].quiz;
                            sStudent.rResult[j].lab = pCur->data.rResult[j].lab;
                            sStudent.rResult[j].midterm = pCur->data.rResult[j].midterm;
                            sStudent.rResult[j].finalterm = pCur->data.rResult[j].finalterm;
                            sStudent.rResult[j].average = pCur->data.rResult[j].average;
                            sStudent.rResult[j].type = pCur->data.rResult[j].type;
                            deleteListStudent(cCourse.nStudentHead, cCourse.numStudent);
                            break;
                        }
                        p = p->next;
                    }
                }
                else
                {
                    sStudent.rResult[j].type = "None";
                    sStudent.rResult[j].quiz = -2;
                }
            }
            deleteListStudent(pHead, n);
            return;
        }
        pCur = pCur->next;
    }
}

void loadFileResultOfClass(node<student> *&pHead, student &sStudent, int &n)
{
    ifstream fin;
    fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/ResultOf" + sStudent.Class + ".csv");
    if (fin.is_open())
    {
        fin >> n;
        fin.get();
        string s;
        getline(fin, s, ',');
        getline(fin, sStudent.courseID[0], ',');
        fin.get();
        fin.get();
        fin.get();
        getline(fin, sStudent.courseID[1], ',');
        fin.get();
        fin.get();
        fin.get();
        getline(fin, sStudent.courseID[2], ',');
        fin.get();
        fin.get();
        fin.get();
        getline(fin, sStudent.courseID[3], ',');
        fin.get();
        fin.get();
        fin.get();
        getline(fin, sStudent.courseID[4], '\n');
        getline(fin, s, ',');
        getline(fin, sStudent.nameCourse[0], ',');
        fin.get();
        fin.get();
        fin.get();
        getline(fin, sStudent.nameCourse[1], ',');
        fin.get();
        fin.get();
        fin.get();
        getline(fin, sStudent.nameCourse[2], ',');
        fin.get();
        fin.get();
        fin.get();
        getline(fin, sStudent.nameCourse[3], ',');
        fin.get();
        fin.get();
        fin.get();
        getline(fin, sStudent.nameCourse[4], '\n');
        node<student> *pCur = nullptr;
        for (int i = 0; i < n; i++)
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
            for (int j = 0; j < 5; j++)
            {
                fin >> pCur->data.rResult[j].quiz;
                fin.get();
                fin >> pCur->data.rResult[j].lab;
                fin.get();
                fin >> pCur->data.rResult[j].midterm;
                fin.get();
                fin >> pCur->data.rResult[j].finalterm;
                fin.get();
            }
        }
    }
    fin.close();
}

void registerCourse(student &sStudent, Course &cCourse)
{
    sStudent.isRegistered[sStudent.courseView] = "Registered";
    cCourse.numStudent++;
    int n;
    node<student> *pHead = nullptr;
    loadFileCourseOfClass(pHead, sStudent, n);
    updateFileCourseOfClass(sStudent, pHead, n);
    deleteListStudent(pHead, n);
    updateFileCourse(sStudent, cCourse, true);
}

void unregisterCourse(student &sStudent, Course &cCourse)
{
    sStudent.isRegistered[sStudent.courseView] = "Not Registered";
    cCourse.numStudent--;
    int n = 3;
    node<student> *pHead = nullptr;
    loadFileCourseOfClass(pHead, sStudent, n);
    updateFileCourseOfClass(sStudent, pHead, n);
    deleteListStudent(pHead, n);
    updateFileCourse(sStudent, cCourse, false);
}

bool checkFileExist(student &sStudent, short CourseOrResult)
{
    ifstream fin;
    if (CourseOrResult == 0) // File Course
        fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/CourseOf" + sStudent.Class + ".csv");
    else if (CourseOrResult == 1) // File Result
        fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/ResultOf" + sStudent.Class + ".csv");
    if (fin.good())
    {
        fin.close();
        return true;
    }
    fin.close();
    return false;
}

void updateFileCourse(student &sStudent, Course &cCourse, bool isRegister)
{
    node<student> *p = cCourse.nStudentHead;
    ofstream fout;
    fout.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/" + cCourse.ID + ".txt");
    fout << cCourse.name << endl;
    fout << cCourse.lecturer << endl;
    fout << cCourse.sDay << endl;
    fout << cCourse.sSession[0].weekday << " " << cCourse.sSession[0].sTime << endl;
    fout << cCourse.sSession[1].weekday << " " << cCourse.sSession[1].sTime << endl;
    fout << cCourse.maxStudent << endl
         << cCourse.numStudent << endl;
    if (isRegister == true)
    {
        if (p)
        {
            for (int i = 0; i < cCourse.numStudent - 1; i++)
            {
                fout << p->data.Class << " " << p->data.id << " -1 -1 -1 -1 -1 None" << endl;
                if (i < cCourse.numStudent - 2)
                    p = p->next;
            }
            p->next = new node<student>;
            p = p->next;
        }
        else
        {
            cCourse.nStudentHead = new node<student>;
            p = cCourse.nStudentHead;
        }
        p->data.Class = sStudent.Class;
        p->data.id = sStudent.id;
        fout << p->data.Class << " " << p->data.id << " -1 -1 -1 -1 -1 None" << endl;
    }
    else
    {
        if (cCourse.nStudentHead->data.Class == sStudent.Class && cCourse.nStudentHead->data.id == sStudent.id)
        {
            node<student> *pDel = cCourse.nStudentHead;
            cCourse.nStudentHead = cCourse.nStudentHead->next;
            delete pDel;
            p = cCourse.nStudentHead;
        }
        for (int i = 0; i < cCourse.numStudent; i++)
        {
            if (p->next && p->next->data.Class == sStudent.Class && p->next->data.id == sStudent.id)
            {
                node<student> *pDel = p->next;
                p->next = p->next->next;
                delete pDel;
            }
            fout << p->data.Class << " " << p->data.id << " -1 -1 -1 -1 -1 None" << endl;
            p = p->next;
        }
    }
    fout.close();
}

void updateFileCourseOfClass(student &sStudent, node<student> *pHead, int &n)
{
    ofstream fout;
    fout.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/CourseOf" + sStudent.Class + ".csv");
    fout << n << endl;
    fout << "ID";
    for (int i = 0; i < 5; i++)
        fout << "," << sStudent.courseID[i];
    fout << endl
         << "ID";
    for (int i = 0; i < 5; i++)
        fout << "," << sStudent.nameCourse[i];
    node<student> *pCur = pHead;
    for (int i = 0; i < n; i++)
    {
        if (pCur->data.id == sStudent.id)
            pCur->data.isRegistered[sStudent.courseView] = sStudent.isRegistered[sStudent.courseView];
        fout << endl
             << pCur->data.id;
        for (int j = 0; j < 5; j++)
            fout << "," << pCur->data.isRegistered[j];
        pCur = pCur->next;
    }
    fout.close();
}

void updateFileResultOfClass(student &sStudent, node<student> *pHead, int &n)
{
    ofstream fout;
    fout.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/ResultOf" + sStudent.Class + ".csv");
    fout << n << endl;
    fout << "ID," << sStudent.courseID[0];
    for (int i = 1; i < 5; i++)
        fout << ",,,," << sStudent.courseID[i];
    fout << endl
         << "ID," << sStudent.nameCourse[0];
    for (int i = 1; i < 5; i++)
        fout << ",,,," << sStudent.nameCourse[i];
    node<student> *pCur = pHead;
    for (int i = 0; i < n; i++)
    {
        if (pCur->data.id == sStudent.id)
            pCur->data.rResult[sStudent.courseView] = sStudent.rResult[sStudent.courseView];
        fout << endl
             << pCur->data.id;
        for (int j = 0; j < 5; j++)
        {
            fout << "," << pCur->data.rResult[j].quiz;
            fout << "," << pCur->data.rResult[j].lab;
            fout << "," << pCur->data.rResult[j].midterm;
            fout << "," << pCur->data.rResult[j].finalterm;
            ;
        }
        pCur = pCur->next;
    }
    fout.close();
}

void updateFileStaff(node<user> *pHead, int n)
{
    node<user> *p = pHead;
    ofstream fout;
    fout.open("../data/listofstaff.txt");
    fout << n << '\n';
    while (p)
    {
        fout << p->data.id << ' ' << p->data.password << '\n';
        p = p->next;
    }
    fout.close();
    deleteListStaff(pHead, n);
}

void updateFileStudent(node<student> *pHead, int n)
{
    node<student> *p = pHead;
    ofstream fout;
    fout.open("../data/listofstudent.txt");
    fout << n << '\n';
    while (p)
    {
        fout << p->data.id << ' ' << p->data.password << ' ' << p->data.Class << '\n';
        p = p->next;
    }
    fout.close();
    deleteListStudent(pHead, n);
}

void createSchoolYear(short& numSchoolYear)
{
    numSchoolYear++;
    string newYear, prevYear;
    ofstream fout;
    ifstream fin;
    fout.open("../data/SchoolYear.txt");
    fout << numSchoolYear;
    fout.close();
    newYear = to_string(2020 - 2000 + numSchoolYear) + "-" + to_string(2021 - 2000 + numSchoolYear);
    prevYear = to_string(2020 - 2000 + numSchoolYear - 1) + "-" + to_string(2021 - 2000 + numSchoolYear - 1);
    _mkdir((const char*)("../data/" + newYear).c_str());
    fin.open("../data/" + prevYear + "/Classes.txt");
    fout.open("../data/" + newYear + "/Classes.txt");
    int numClassNewYear = 0;
    int n = 0;
    fin >> n;
    fout << 0 << "\n";
    fout.seekp(0, ios::end);
    fin.get();
    for (int i = 0; i < n; i++)
    {
        string className;
        getline(fin, className);
        if (stoi(className.substr(0, 2)) >= 2020 - 2000 + numSchoolYear - 4)
        {
            fout << className << "\n";
            numClassNewYear++;
        }
    }
    fout.seekp(0);
    fout << numClassNewYear;
    fin.close();
    fout.close();
    for (int i = 1; i <= 3; i++)
    {
        string filename = "../data/" + newYear + "/HK" + to_string(i);
        _mkdir((filename).c_str());
        fout.open(filename + "/Courses.txt");
        fout << 0 << "\n";
        fout.close();
    }
        
}

void RemoveCourse(student& sStudent, Course& cCourse, string name[], int& dummy)
{
    dummy--;
    ofstream fout("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/Courses.txt");
    fout << dummy << "\n";
    for (int i = 0; i < dummy; i++)
    {
        if (i >= sStudent.courseView)
            name[i] = name[i + 1];
        fout << name[i] + "\n";
    }
    fout.close();

    int k = remove(("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/" + cCourse.ID + ".txt").c_str());
}