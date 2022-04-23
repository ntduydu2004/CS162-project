// Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../include/menu.h"
using namespace std;
int main()
{
    const int screenHeight = 600;
    const int screenWidth = 1200;
    InitWindow(screenWidth, screenHeight, "COURSE MANAGEMENT");
    SetTargetFPS(60);
    short menu = -2;
    Vector2 mousePosition;
    Vector2 touchPosition;
    char a[17] = "\0", b[17] = "\0", bStar[17] = "\0";
    short idCount = 0, passwordCount = 0, role = 0;
    char oldPass[17] = "\0", newPass[17] = "\0", confirmPass[17] = "\0", oldPassStar[17] = "\0", newPassStar[17] = "\0", confirmPassStar[17] = "\0";
    short oldPassCount = 0, newPassCount = 0, confirmPassCount = 0;
    int count = 0, dummy = 0;
    char **droppedFiles = {0};
    string Class;
    Course cCourse;
    Rectangle rec_Role[] =
        {
            {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 60, 300, 60},
            {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 20, 300, 60}};

    Rectangle rec_Login[] =
        {
            {GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 40 - 10, 340, 60},
            {GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 + 40 - 10, 340, 60},
            {GetScreenWidth() / 2 - 130, GetScreenHeight() / 2 + 150 - 10, 140, 60},
            {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_Main[] =
        {
            {GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 100 - 10, 260, 50},
            {GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 50 - 10, 260, 50},
            {GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 0 - 10, 260, 50},
            {GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 + 50 - 10, 260, 50}};

    Rectangle rec_Profile[] = {
        {30, GetScreenHeight() - 70, 140, 60},
        {30, 390, 400, 60}};

    Rectangle rec_StudentCourse[] =
        {
            {50, GetScreenHeight() / 2 - 130 - 10, GetScreenWidth() - 100, 50},
            {50, GetScreenHeight() / 2 - 80 - 10, GetScreenWidth() - 100, 50},
            {50, GetScreenHeight() / 2 - 30 - 10, GetScreenWidth() - 100, 50},
            {50, GetScreenHeight() / 2 + 20 - 10, GetScreenWidth() - 100, 50},
            {50, GetScreenHeight() / 2 + 70 - 10, GetScreenWidth() - 100, 50},
            {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_detailOfCourseMenu[] =
        {
            {450, 285, 220, 50},
            {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_StudentSchoolYear[] =
        {
            {200, 100, 200, 50},
            {800, 100, 200, 50},
            {200, 200, 200, 50},
            {800, 200, 200, 50},
            {200, 300, 200, 50},
            {800, 300, 200, 50},
            {30, GetScreenHeight() - 70, 140, 60}};
    Rectangle rec_StaffSchoolYear[] =
        {
            {100, 100, 200, 50},
            {500, 100, 200, 50},
            {900, 100, 200, 50},
            {100, 200, 200, 50},
            {500, 200, 200, 50},
            {900, 200, 200, 50},
            {100, 300, 200, 50},
            {500, 300, 200, 50},
            {900, 300, 200, 50},
            {30, GetScreenHeight() - 70, 140, 60},
            {GetScreenWidth() - 330, GetScreenHeight() - 70, 300, 60}};
    Rectangle rec_changePass[] =
        {
            {GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 120 - 10, 340, 60},
            {GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 40 - 10, 340, 60},
            {GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 + 40 - 10, 340, 60},
            {GetScreenWidth() / 2 - 130, GetScreenHeight() / 2 + 150 - 10, 160, 60},
            {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_StudentSemester[] =
        {
            {480, GetScreenHeight() / 2 - 80, 240, 50},
            {480, GetScreenHeight() / 2 - 30, 240, 50},
            {480, GetScreenHeight() / 2 + 20, 240, 50},
            {30, GetScreenHeight() - 70, 140, 60}};
    Rectangle rec_classInput[] = {
        {GetScreenWidth() - 170, GetScreenHeight() - 70, 140, 60},
        {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_StaffViewSchoolyearDetail[]
    {
        {100, 200, 400, 200},
        {700, 200, 400, 200},
        {30, GetScreenHeight() - 70, 140, 60}, //BACK button
    };

    Rectangle rec_listClass[53];
    for (int i = 0;i < 50;i++)
    {
        rec_listClass[i].x = 70;
        rec_listClass[i].y = 70 + 60 * i;
        rec_listClass[i].width = GetScreenWidth() - rec_listClass[i].x - 30;
        rec_listClass[i].height = 60;
    }
    rec_listClass[51].y = 270;
    rec_listClass[51].x = 5;
    rec_listClass[51].width = 60;
    rec_listClass[51].height = 60;
    rec_listClass[52].y = 10;
    rec_listClass[52].x = 50;
    rec_listClass[52].width = 230;
    rec_listClass[52].height = 40;
    student sStudent;
    user uStaff;
    short indexMouse = -1, indexTouch = -1, choose;
    short numSchoolYear = 0;
    string name[50];
    node<student> *pCur= nullptr;
    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();
        touchPosition = GetTouchPosition(0);
        SetMouseCursor(0);
        switch (menu)
        {
        case -2: // Choose Role Menu
            chooseRoleMenu(mousePosition, touchPosition, indexMouse, menu, role, rec_Role);
            break;
        case -1: // Login Menu
            logInMenu(mousePosition, touchPosition, indexMouse, indexTouch, a, b, bStar, menu, true, idCount, passwordCount, uStaff, sStudent, role, rec_Login);
            break;
        case 0: // Main Menu
            mainMenu(mousePosition, touchPosition, indexMouse, menu, b, bStar, passwordCount, sStudent, uStaff, role, rec_Main, choose, numSchoolYear);
            break;
        case 1: // View Profile Menu
            viewProfileMenu(mousePosition, touchPosition, indexMouse, sStudent, uStaff, menu, role, rec_Profile);
            break;
        case 2: // Course Student Menu
            courseOrResultStudentMenu(mousePosition, touchPosition, indexMouse, sStudent, menu, cCourse, rec_StudentCourse, choose);
            break;
        case 3: // Detail of Course
            detailOfCourseMenu(mousePosition, touchPosition, indexMouse, cCourse, sStudent, menu, rec_detailOfCourseMenu, dummy, name, role);
            break;
        case 4: // SchoolYear Student Menu
            schoolYearStudentMenu(mousePosition, touchPosition, indexMouse, sStudent, menu, rec_StudentSchoolYear, numSchoolYear);
            break;
        case 5: // Semester Student Menu
            semesterStudentMenu(mousePosition, touchPosition, indexMouse, sStudent, menu, rec_StudentSemester, choose, name, dummy, role);
            break;
        case 6: // Change Password
            changePassword(mousePosition, touchPosition, indexMouse, indexTouch, oldPass, newPass, confirmPass, oldPassStar, newPassStar, confirmPassStar, oldPassCount, newPassCount, confirmPassCount, sStudent, uStaff, menu, role, rec_changePass, true);
            break;
        case 11: // List of Schoolyears and Add Schoolyear option Menu for Staff
            schoolYearStaffMenu(mousePosition, touchPosition, indexMouse, sStudent, menu, rec_StaffSchoolYear, numSchoolYear);
            break;
        case 12:
            classInput(mousePosition, touchPosition, indexMouse, sStudent, menu, rec_classInput, count, droppedFiles, name, dummy);
            break;
        case 13:
            StaffViewSchoolyearDetail(mousePosition, touchPosition, indexMouse, sStudent, menu, numSchoolYear, rec_StaffViewSchoolyearDetail, name, dummy, choose);
            break;
        case 20: // White Menu
            studentWhiteMenu(mousePosition, touchPosition, indexMouse, menu, rec_Profile, choose);
            break;
        case 21: // List of Class
            viewListClassOrCourse(mousePosition, touchPosition, sStudent, cCourse, indexMouse, menu, rec_listClass, name, dummy, choose);
            break;
        case 22:
            viewClassProfileMenu(mousePosition, touchPosition, indexMouse, sStudent, cCourse, menu, rec_listClass, pCur, choose);
            break;
        }
    }
    CloseWindow();
    return 0;
}