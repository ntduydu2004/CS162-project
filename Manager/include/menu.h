#pragma once
#include "MyFunction.h"
#include <raylib.h>

void chooseRoleMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, short &role, Rectangle rec_Role[]);
void logInMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &indexTouch, char a[], char b[], char bStar[], short &menu, bool flag,
			   short &idCount, short &passwordCount, user &uStaff, student &sStudent, short role, Rectangle rec_Login[]);
void mainMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, char b[], char bStar[], short &passwordCount, student &sStudent,
			  user &uStaff, short role, Rectangle rec_Main[], short &CourseOrResult, short &numSchoolYear);
void viewProfileMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student sStudent, user uStaff, short &menu, short role,
					 Rectangle rec_Profile[]);
void courseOrResultStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu, Course &cCourse,
							   Rectangle rec_StudentCourse[], short &courseOrResult);
void detailOfCourseMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, Course &cCourse, student &sStudent, short &menu,
						Rectangle rec_detailOfCourseMenu[], int& dummy, string name[], short& role);
void semesterStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
						 Rectangle rec_StudentSemester[], short &CourseOrResult, string name[], int& dummy, short& role);
void schoolYearStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
						   Rectangle rec_StudentSchoolYear[], short &numSchoolYear);
void changePassword(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &indexTouch,
					char oldPass[], char newPass[], char confirmPass[],
					char oldPassStar[], char newPassStar[], char confirmPassStar[],
					short &oldPassCount, short &newPassCount, short &confirmPassCount,
					student &sStudent, user &uStaff, short &menu, short role, Rectangle rec_changePass[], bool flag);
void studentWhiteMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, Rectangle rec_white[], short CourseOrResult);
void schoolYearStaffMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
						 Rectangle rec_StaffSchoolYear[], short &numSchoolYear);
void classInput(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student& sStudent, short &menu,
	Rectangle rec_classInput[], int &count, char **droppedFiles, string name[], int& dummy);
void StaffViewSchoolyearDetail(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, short& menu,
	short& numSchoolYear, Rectangle rec_StaffViewSchoolyearDetail[], string className[], int& dummy, short& ClassOrCourse);
void viewListClassOrCourse(Vector2& mousePosition, Vector2& touchPosition, student& sStudent, Course& cCourse, short& indexMouse, short& menu,
	Rectangle rec_listClass[], string name[], int& dummy, short& ClassOrCourse);

void viewClassProfileMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, Course& cCourse, short& menu,
	Rectangle rec_listClass[], node<student>*& pCur, short& ClassOrCourse);

void addCourseMenu(Vector2& mousePosition, Vector2& touchPosition, student& sStudent, Course& cCourse, short& indexMouse, short& indexTouch,
	short& menu, Rectangle rec_addCourseMenu[], string name[], bool isChosen[], int& dummy, short& ClassOrCourse, string& dateInput);
void chooseClass(Vector2& mousePosition, Vector2& touchPosition, student& sStudent, Course& cCourse, short& indexMouse, short& indexTouch,
	short& menu, Rectangle rec_chooseClass[], string name[], bool isChosen[], int& dummy, short& ClassOrCourse, string& dateInput);