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
						Rectangle rec_detailOfCourseMenu[]);
void semesterStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
						 Rectangle rec_StudentSemester[], short &CourseOrResult);
void schoolYearStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
						   Rectangle rec_StudentSchoolYear[], short &numSchoolYear);
void changePassword(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &indexTouch,
					char oldPass[], char newPass[], char confirmPass[],
					char oldPassStar[], char newPassStar[], char confirmPassStar[],
					short &oldPassCount, short &newPassCount, short &confirmPassCount,
					student &sStudent, user &uStaff, short &menu, short role, Rectangle rec_changePass[], bool flag);
void studentWhiteMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, Rectangle rec_white[], short CourseOrResult);
void schoolYearStaffMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
						 Rectangle rec_StaffSchoolYear[], short &numSchoolYear, short& iYear);
void classInput(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, Rectangle rec_classInput[], int &count, char **droppedFiles);
void StaffViewSchoolyearDetail(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, short& menu,
	short& numSchoolYear, short& iYear);