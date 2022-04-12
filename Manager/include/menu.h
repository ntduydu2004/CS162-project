#pragma once
#include "MyFunction.h"


void chooseRoleMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, short& role, Rectangle rec_Role[]);
void logInMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& indexTouch, char a[], char b[], char bStar[], short& menu, bool flag,
	short& idCount, short& passwordCount, user& uStaff, student& sStudent, short role, Rectangle rec_Login[]);
void mainMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, char b[], char bStar[], short& passwordCount, short role,
	Rectangle rec_Main[]);
void viewProfileMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student sStudent, user uStaff, short& menu, short role, 
	Rectangle rec_Profile, char* ch);