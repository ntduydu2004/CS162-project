#include "../include/menu.h"


void chooseRoleMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, short& role, Rectangle rec_Role[])
{

    if (CheckCollisionPointRec(mousePosition, rec_Role[0]))
        indexMouse = 1;
    else if (CheckCollisionPointRec(mousePosition, rec_Role[1]))
        indexMouse = 2;
    else
        indexMouse = 0;

    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(touchPosition, rec_Role[0]))
        {
            role = -1;
            menu = -1;
        }
        if (CheckCollisionPointRec(touchPosition, rec_Role[1]))
        {
            role = 0;
            menu = -1;
        }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("CHOOSE YOUR ROLE", GetScreenWidth() / 2 - 240, GetScreenHeight() / 2 - 230, 50, BLACK);
    DrawText(" Staff ", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 50, 50, BLACK);
    DrawText("Student", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 30, 50, BLACK);
    if (indexMouse == 1)
        DrawRectangleLines(rec_Role[0].x, rec_Role[0].y, rec_Role[0].width, rec_Role[0].height, BLACK);
    if (indexMouse == 2)
        DrawRectangleLines(rec_Role[1].x, rec_Role[1].y, rec_Role[1].width, rec_Role[1].height, BLACK);
    EndDrawing();
}

void logInMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& indexTouch, char a[], char b[], char bStar[], short& menu, bool flag,
    short& idCount, short& passwordCount, user& uStaff, student& sStudent, short role, Rectangle rec_Login[])
{
    if (CheckCollisionPointRec(mousePosition, rec_Login[0]))
    {
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_Login[1]))
    {
        indexMouse = 2;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_Login[2]))
        indexMouse = 3;
    else if (CheckCollisionPointRec(mousePosition, rec_Login[3]))
        indexMouse = 4;
    else
        indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(touchPosition, rec_Login[0]))
            indexTouch = 1;
        else if (CheckCollisionPointRec(touchPosition, rec_Login[1]))
            indexTouch = 2;
        else if (CheckCollisionPointRec(touchPosition, rec_Login[2]))
            indexTouch = 3;
        else if (CheckCollisionPointRec(touchPosition, rec_Login[3]))
            indexTouch = 4;
        else indexTouch = 0;
    }
    if (indexTouch == 1)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (idCount < 16))
            {
                a[idCount] = (char)key;
                a[idCount + 1] = '\0';
                idCount++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            idCount--;
            if (idCount < 0) idCount = 0;
            a[idCount] = '\0';
        }
    }
    if (indexTouch == 2)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (passwordCount < 16))
            {
                b[passwordCount] = (char)key;
                b[passwordCount + 1] = '\0';
                bStar[passwordCount] = '*';
                bStar[passwordCount + 1] = '\0';
                passwordCount++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            passwordCount--;
            if (passwordCount < 0) passwordCount = 0;
            b[passwordCount] = '\0';
            bStar[passwordCount] = '\0';
        }
    }
    if (indexTouch == 3 || IsKeyPressed(KEY_ENTER))
    {
        if (role == -1)
        {
            uStaff.id = string(a);
            uStaff.password = string(b);
            if (checkStafflogin(uStaff))
            {
                menu = 0;
                indexTouch = 0;
                return;
            }
        }
        else if (role == 0)
        {
            sStudent.id = string(a);
            sStudent.password = string(b);
            if (checkStudentLogin(sStudent))
            {
                menu = 0;
                indexTouch = 0;
                return;
            }
        }
        flag = false;
        indexTouch = 3;
    }
    else if (indexTouch == 4)
    {
        menu = -2;
        indexTouch = 0;
        a[0] = '\0';
        b[0] = '\0';
        bStar[0] = '\0';
        idCount = 0;
        passwordCount = 0;
        return;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("User ID   : ", GetScreenWidth() / 2 - 10 * 40, GetScreenHeight() / 2 - 40, 40, BLACK);
    DrawText("Password : ", GetScreenWidth() / 2 - 10 * 40, GetScreenHeight() / 2 + 40, 40, BLACK);
    DrawText(a, rec_Login[0].x + 10, rec_Login[0].y + 10, 40, BLACK);
    DrawText(bStar, rec_Login[1].x + 10, rec_Login[1].y + 10, 40, BLACK);
    DrawRectangle(rec_Login[2].x, rec_Login[2].y, rec_Login[2].width, rec_Login[2].height, GREEN);
    DrawText("Log in", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 + 150, 40, WHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (flag == false)
    {
        DrawRectangleLines(rec_Login[0].x, rec_Login[0].y, rec_Login[0].width, rec_Login[0].height, RED);
        DrawRectangleLines(rec_Login[1].x, rec_Login[1].y, rec_Login[1].width, rec_Login[1].height, RED);
        DrawText("User ID or password is incorrect", GetScreenWidth() / 2 - 32 * 20 / 2, GetScreenHeight() / 2 + 100, 20, RED);
    }
    else
    {
        if (indexTouch == 1 || indexTouch == 2)
        {
            indexTouch == 1 ? DrawRectangleLines(rec_Login[0].x, rec_Login[0].y, rec_Login[0].width, rec_Login[0].height, GREEN) : DrawRectangleLines(rec_Login[1].x, rec_Login[1].y, rec_Login[1].width, rec_Login[1].height, GREEN);
            indexTouch == 1 ? DrawRectangleLines(rec_Login[1].x, rec_Login[1].y, rec_Login[1].width, rec_Login[1].height, BLACK) : DrawRectangleLines(rec_Login[0].x, rec_Login[0].y, rec_Login[0].width, rec_Login[0].height, BLACK);
        }
        else
        {
            DrawRectangleLines(rec_Login[0].x, rec_Login[0].y, rec_Login[0].width, rec_Login[0].height, BLACK);
            DrawRectangleLines(rec_Login[1].x, rec_Login[1].y, rec_Login[1].width, rec_Login[1].height, BLACK);
            if (indexMouse == 1)
                DrawRectangleLines(rec_Login[0].x, rec_Login[0].y, rec_Login[0].width, rec_Login[0].height, GREEN);
            else if (indexMouse == 2)
                DrawRectangleLines(rec_Login[1].x, rec_Login[1].y, rec_Login[1].width, rec_Login[1].height, GREEN);
            else if (indexMouse == 3)
                DrawRectangleLines(rec_Login[2].x, rec_Login[2].y, rec_Login[2].width, rec_Login[2].height, BLACK);
            else if (indexMouse == 4)
                DrawRectangleLines(rec_Login[3].x, rec_Login[3].y, rec_Login[3].width, rec_Login[3].height, BLACK);
        }
    }
    EndDrawing();
}

void mainMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& menu, char b[], char bStar[], short& passwordCount, short role,
    Rectangle rec_Main[])
{
    if (role == 0)
    {
        if (CheckCollisionPointRec(mousePosition, rec_Main[0]))
            indexMouse = 1;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[1]))
            indexMouse = 2;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[2]))
            indexMouse = 3;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[3]))
            indexMouse = 4;
        else indexMouse = 0;

        if (IsMouseButtonPressed(0))
        {
            if (CheckCollisionPointRec(touchPosition, rec_Main[0]))
                menu = 2;
            if (CheckCollisionPointRec(touchPosition, rec_Main[1]))
                menu = 3;
            if (CheckCollisionPointRec(touchPosition, rec_Main[2]))
                menu = 4;
            if (CheckCollisionPointRec(touchPosition, rec_Main[3]))
            {
                menu = -1;
                b[0] = '\0';
                bStar[0] = '\0';
                passwordCount = 0;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Menu", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 - 200, 50, BLACK);
        DrawText("View Profile", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 100, 30, BLACK);
        DrawText("Register", GetScreenWidth() / 2 - 65, GetScreenHeight() / 2 - 60, 30, BLACK);
        DrawText("Course", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 - 20, 30, BLACK);
        DrawText("Log out", GetScreenWidth() / 2 - 62, GetScreenHeight() / 2 + 20, 30, BLACK);
        switch (indexMouse)
        {
        case 1:
            DrawRectangleLines(rec_Main[0].x, rec_Main[0].y, rec_Main[0].width, rec_Main[0].height, BLACK);
            break;
        case 2:
            DrawRectangleLines(rec_Main[1].x, rec_Main[1].y, rec_Main[1].width, rec_Main[1].height, BLACK);
            break;
        case 3:
            DrawRectangleLines(rec_Main[2].x, rec_Main[2].y, rec_Main[2].width, rec_Main[2].height, BLACK);
            break;
        case 4:
            DrawRectangleLines(rec_Main[3].x, rec_Main[3].y, rec_Main[3].width, rec_Main[3].height, BLACK);
            break;
        }
        EndDrawing();
    }
    else if (role == -1)
    {
        if (CheckCollisionPointRec(mousePosition, rec_Main[0]))
            indexMouse = 1;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[1]))
            indexMouse = 2;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[2]))
            indexMouse = 3;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[3]))
            indexMouse = 4;
        else indexMouse = 0;

        if (IsMouseButtonPressed(0))
        {
            if (CheckCollisionPointRec(touchPosition, rec_Main[0]))
                menu = 2;
            if (CheckCollisionPointRec(touchPosition, rec_Main[1]))
                menu = 3;
            if (CheckCollisionPointRec(touchPosition, rec_Main[2]))
                menu = 4;
            if (CheckCollisionPointRec(touchPosition, rec_Main[3]))
            {
                menu = -1;
                b[0] = '\0';
                bStar[0] = '\0';
                passwordCount = 0;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Menu", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 - 200, 50, BLACK);
        DrawText("View Profile", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 100, 30, BLACK);
        DrawText("New Course", GetScreenWidth() / 2 - 88, GetScreenHeight() / 2 - 60, 30, BLACK);
        DrawText("View Courses", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 20, 30, BLACK);
        DrawText("Log out", GetScreenWidth() / 2 - 62, GetScreenHeight() / 2 + 20, 30, BLACK);
        switch (indexMouse)
        {
        case 1:
            DrawRectangleLines(rec_Main[0].x, rec_Main[0].y, rec_Main[0].width, rec_Main[0].height, BLACK);
            break;
        case 2:
            DrawRectangleLines(rec_Main[1].x, rec_Main[1].y, rec_Main[1].width, rec_Main[1].height, BLACK);
            break;
        case 3:
            DrawRectangleLines(rec_Main[2].x, rec_Main[2].y, rec_Main[2].width, rec_Main[2].height, BLACK);
            break;
        case 4:
            DrawRectangleLines(rec_Main[3].x, rec_Main[3].y, rec_Main[3].width, rec_Main[3].height, BLACK);
            break;
        }
        EndDrawing();
    }

}

void viewProfileMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student sStudent, user uStaff, short& menu, short role, Rectangle rec_Profile, char* ch)
{

    if (CheckCollisionPointRec(mousePosition, rec_Profile))
        indexMouse = 1;
    else indexMouse = 0;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_Profile))
        {
            menu = 0;
            return;
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (indexMouse == 1)
        DrawRectangleLines(rec_Profile.x, rec_Profile.y, rec_Profile.width, rec_Profile.height, BLACK);
    DrawText("ID", 60, 70, 35, BLACK);
    DrawText("Fullname", 60, 130, 35, BLACK);
    DrawText("Gender", 60, 190, 35, BLACK);
    DrawText("Birthday", 60, 250, 35, BLACK);
    DrawText("Email", 60, 310, 35, BLACK);
    if (role == -1)
    {
        ch = (char*)uStaff.id.c_str();
        DrawText(ch, 320, 70, 35, BLACK);
        ch = (char*)uStaff.fullname.c_str();
        DrawText(ch, 320, 130, 35, BLACK);
        ch = (char*)uStaff.gender.c_str();
        DrawText(ch, 320, 190, 35, BLACK);
        ch = (char*)uStaff.sDate.c_str();
        DrawText(ch, 320, 250, 35, BLACK);
        ch = (char*)uStaff.email.c_str();
        DrawText(ch, 320, 310, 35, BLACK);
    }
    if (role == 0)
    {
        ch = (char*)sStudent.id.c_str();
        DrawText(ch, 320, 70, 35, BLACK);
        ch = (char*)sStudent.fullname.c_str();
        DrawText(ch, 320, 130, 35, BLACK);
        ch = (char*)sStudent.gender.c_str();
        DrawText(ch, 320, 190, 35, BLACK);
        ch = (char*)sStudent.sDate.c_str();
        DrawText(ch, 320, 250, 35, BLACK);
        ch = (char*)sStudent.email.c_str();
        DrawText(ch, 320, 310, 35, BLACK);
    }
    EndDrawing();
}

