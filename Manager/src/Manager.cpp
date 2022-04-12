// Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../include/menu.h"
int main()
{
    const int screenHeight = 600;
    const int screenWidth = 1200;
    char* ch = nullptr;
    InitWindow(screenWidth, screenHeight, "Menu");
    SetTargetFPS(60);
    short menu = -2;
    Vector2 mousePosition;
    Vector2 touchPosition;
    char a[17] = "\0", b[17] = "\0", bStar[17] = "\0";
    short idCount = 0, passwordCount = 0, role = 0;
    string  Class;
    Rectangle rec_Role[] =
    {
        { GetScreenWidth() / 2 - 150,GetScreenHeight() / 2 - 60,300,60 },
        { GetScreenWidth() / 2 - 150,GetScreenHeight() / 2 + 20,300,60 }
    };

    Rectangle rec_Login[] =
    {
        { GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 40 - 10, 340, 60 },
        { GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 + 40 - 10, 340, 60 },
        { GetScreenWidth() / 2 - 130, GetScreenHeight() / 2 + 150 - 10, 140, 60 },
        { 30, GetScreenHeight() - 70, 140, 60 }
    };

    Rectangle rec_Main[] =
    {
        { GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 100 - 10, 260, 50 },
        { GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 60 - 10, 260, 50 },
        { GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 20 - 10, 260, 50 },
        { GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 + 20 - 10, 260, 50 }
    };

    Rectangle rec_Profile{ 30, GetScreenHeight() - 70, 140, 60 };

    student sStudent;
    user uStaff;
    short indexMouse = 0, indexTouch = 0;
    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();
        touchPosition = GetTouchPosition(0);
        SetMouseCursor(0);
        if (menu == -2) // Choose Role Menu
            chooseRoleMenu(mousePosition, touchPosition, indexMouse, menu, role, rec_Role);
        if (menu == -1) // Login Menu
            logInMenu(mousePosition, touchPosition, indexMouse, indexTouch, a, b, bStar, menu, true, idCount, passwordCount, uStaff, sStudent, role, rec_Login);
        if (menu == 0) // Main Menu
            mainMenu(mousePosition, touchPosition, indexMouse, menu, b, bStar, passwordCount, role, rec_Main);
        if (menu == 2) // View Profile Menu
            viewProfileMenu(mousePosition, touchPosition, indexMouse, sStudent, uStaff, menu, role, rec_Profile, ch);
    }
    CloseWindow();
    return 0;
}