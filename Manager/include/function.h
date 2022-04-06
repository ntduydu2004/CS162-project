#pragma once
#include "user.h"
#include "course.h"
void mainMenu();
void studentFunc(student p);
void inputStudent(Node<student> *&p);
void staffFunc();
void inputStaff(Node<user> *&p);
void loadClass(string className, Node<student> *pStudentHead, int &numStudent);
void loadCourse(string courseID, course &cCourse);
void outputClass(string className);
void outputCourse(string courseID);
