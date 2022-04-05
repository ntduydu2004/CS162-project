#pragma once
#include "user.h"
#include "course.h"
void mainMenu();
void studentFunc();
void outputStudent(student p);
void inputstudent(student &p);
void staffFunc();
void outputstaff(user p);
void inputstaff(user &p);
void loadClass(string className, Node<student> *pStudentHead, int &numStudent);
void loadCourse(string courseID, course &cCourse);
void outputClass(string className);
void outputCourse(string courseID);
