#pragma once
#include "user.h"
void menuchinh();
void studentFunc();
void outputstudent(student p);
void inputstudent(student& p);
void staffFunc();
void outputstaff(user p);
void inputstaff(user& p);
void loadClass(string className, Node<student>* pStudentHead, int& numStudent);
void loadCourse(string courseID, course& cCourse);