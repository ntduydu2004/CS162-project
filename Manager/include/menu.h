#pragma once
#include "MyFunction.h"

void chooseRoleMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, short& role, Rectangle rec_Role[]);
void logInMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& indexTouch, char a[], char b[], char bStar[], short& menu, bool flag,
	short& idCount, short& passwordCount, user& uStaff, student& sStudent, short role, Rectangle rec_Login[]);
void mainMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, char b[], char bStar[], short& passwordCount, student& sStudent,
	user& uStaff, short role, Rectangle rec_Main[]);
void viewProfileMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student sStudent, user uStaff, short& menu, short role, 
	Rectangle rec_Profile, char* ch);
void courseStudentMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, short& menu, Course& cCourse,
	Rectangle rec_StudentCourse[], char* ch);
void detailOfCourseMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, Course& cCourse, student& sStudent, short& menu,
	Rectangle rec_detailOfCourseMenu[], char* ch);
void semesterStudentMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, short& menu,
	Rectangle rec_StudentSemester[]);
void schoolYearStudentMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, short& menu,
	Rectangle rec_StudentSchoolYear[], int& numSchoolYear);
void whiteMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, Rectangle rec_white);
