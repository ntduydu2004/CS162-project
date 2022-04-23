#include "../include/menu.h"
#include "../include/MyFunction.h"
#include <fstream>
#include <cstring>
#include <direct.h>
const int currentSchoolYear = 2021;
void chooseRoleMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, short &role, Rectangle rec_Role[])
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

void logInMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &indexTouch, char a[], char b[], char bStar[], short &menu, bool flag,
               short &idCount, short &passwordCount, user &uStaff, student &sStudent, short role, Rectangle rec_Login[])
{
    if (CheckCollisionPointRec(mousePosition, rec_Login[0]))
    {
        indexMouse = 0;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_Login[1]))
    {
        indexMouse = 1;
        SetMouseCursor(2);
    }
    else if (CheckCollisionPointRec(mousePosition, rec_Login[2]))
        indexMouse = 2;
    else if (CheckCollisionPointRec(mousePosition, rec_Login[3]))
        indexMouse = 3;
    else
        indexMouse = -1;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(touchPosition, rec_Login[0]))
            indexTouch = 0;
        else if (CheckCollisionPointRec(touchPosition, rec_Login[1]))
            indexTouch = 1;
        else if (CheckCollisionPointRec(touchPosition, rec_Login[2]))
            indexTouch = 2;
        else if (CheckCollisionPointRec(touchPosition, rec_Login[3]))
            indexTouch = 3;
        else
            indexTouch = -1;
    }
    if (indexTouch == 0)
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
            if (idCount < 0)
                idCount = 0;
            a[idCount] = '\0';
        }
    }
    else if (indexTouch == 1)
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
            if (passwordCount < 0)
                passwordCount = 0;
            b[passwordCount] = '\0';
            bStar[passwordCount] = '\0';
        }
    }
    if (indexTouch == 2 || IsKeyPressed(KEY_ENTER))
    {
        if (role == -1)
        {
            uStaff.id = string(a);
            uStaff.password = string(b);
            if (checkStafflogin(uStaff))
            {
                menu = 0;
                indexTouch = -1;
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
                indexTouch = -1;
                return;
            }
        }
        flag = false;
        indexTouch = 2;
    }
    else if (indexTouch == 3)
    {
        menu = -2;
        indexTouch = -1;
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
        DrawRectangleLines(rec_Login[0].x, rec_Login[0].y, rec_Login[0].width, rec_Login[0].height, BLACK);
        DrawRectangleLines(rec_Login[1].x, rec_Login[1].y, rec_Login[1].width, rec_Login[1].height, BLACK);
        if (indexTouch == 0 || indexTouch == 1)
            DrawRectangleLines(rec_Login[indexTouch].x, rec_Login[indexTouch].y, rec_Login[indexTouch].width, rec_Login[indexTouch].height, GREEN);
    }
    DrawRectangleLines(rec_Login[indexMouse].x, rec_Login[indexMouse].y, rec_Login[indexMouse].width, rec_Login[indexMouse].height, GREEN);
    EndDrawing();
}

void mainMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, char b[], char bStar[], short &passwordCount, student &sStudent,
              user &uStaff, short role, Rectangle rec_Main[], short &CourseOrResult, short &numSchoolYear) // menu = 0
{
    if (role == 0) // Student
    {
        if (CheckCollisionPointRec(mousePosition, rec_Main[0]))
            indexMouse = 0;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[1]))
            indexMouse = 1;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[2]))
            indexMouse = 2;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[3]))
            indexMouse = 3;
        else
            indexMouse = -1;

        if (IsMouseButtonPressed(0))
        {
            if (CheckCollisionPointRec(touchPosition, rec_Main[0]))
                menu = 1; // Profile Menu
            if (CheckCollisionPointRec(touchPosition, rec_Main[1]) || CheckCollisionPointRec(touchPosition, rec_Main[2]))
            {
                int n;
                ifstream fin;
                fin.open("../data/SchoolYear.txt");
                fin >> n;
                fin.close();
                numSchoolYear = n - (sStudent.firstYear - 2020);
                menu = 4; // SchoolYear Student Menu
                CourseOrResult = indexMouse - 1;
            }
            if (CheckCollisionPointRec(touchPosition, rec_Main[3]))
            {
                menu = -1; // Login Menu
                b[0] = '\0';
                bStar[0] = '\0';
                passwordCount = 0;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Menu", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 - 200, 50, BLACK);
        DrawText("View Profile", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 100, 30, BLACK);
        DrawText("Year", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 - 50, 30, BLACK);
        DrawText("Result", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 - 0, 30, BLACK);
        DrawText("Log out", GetScreenWidth() / 2 - 57, GetScreenHeight() / 2 + 50, 30, BLACK);
        if (indexMouse >= 0)
            DrawRectangleLines(rec_Main[indexMouse].x, rec_Main[indexMouse].y, rec_Main[indexMouse].width, rec_Main[indexMouse].height, BLACK);
        EndDrawing();
    }
    else if (role == -1) // Staff
    {
        if (CheckCollisionPointRec(mousePosition, rec_Main[0]))
            indexMouse = 0;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[1]))
            indexMouse = 1;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[2]))
            indexMouse = 2;
        else if (CheckCollisionPointRec(mousePosition, rec_Main[3]))
            indexMouse = 3;
        else
            indexMouse = -1;

        if (IsMouseButtonPressed(0))
        {
            if (CheckCollisionPointRec(touchPosition, rec_Main[0]))
                menu = 1;
            if (CheckCollisionPointRec(touchPosition, rec_Main[1]))
            {
                ifstream fin("../data/SchoolYear.txt");
                fin >> numSchoolYear;
                fin.close();
                menu = 11;
            }
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
        DrawText("School Year", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 50, 30, BLACK);
        DrawText("View Result", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 0, 30, BLACK);
        DrawText("Log out", GetScreenWidth() / 2 - 62, GetScreenHeight() / 2 + 50, 30, BLACK);
        if (indexMouse >= 0)
            DrawRectangleLines(rec_Main[indexMouse].x, rec_Main[indexMouse].y, rec_Main[indexMouse].width, rec_Main[indexMouse].height, BLACK);
        EndDrawing();
    }
}

void viewProfileMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student sStudent, user uStaff, short &menu, short role,
                     Rectangle rec_Profile[]) // menu = 1
{

    if (CheckCollisionPointRec(mousePosition, rec_Profile[0]))
        indexMouse = 0;
    else if (CheckCollisionPointRec(mousePosition, rec_Profile[1]))
        indexMouse = 1;
    else
        indexMouse = 2;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_Profile[0]))
        {
            menu = 0;
            return;
        }
        if (CheckCollisionPointRec(mousePosition, rec_Profile[1]))
        {
            menu = 6;
            return;
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (indexMouse < 2)
        DrawRectangleLines(rec_Profile[indexMouse].x, rec_Profile[indexMouse].y, rec_Profile[indexMouse].width, rec_Profile[indexMouse].height, BLACK);
    DrawText("ID", 60, 70, 35, BLACK);
    DrawText("Fullname", 60, 130, 35, BLACK);
    DrawText("Gender", 60, 190, 35, BLACK);
    DrawText("Birthday", 60, 250, 35, BLACK);
    DrawText("Email", 60, 310, 35, BLACK);
    DrawText("Change Password", 45, 400, 40, GREEN);
    if (role == -1)
    {
        DrawText(uStaff.id.c_str(), 320, 70, 35, BLACK);
        DrawText(uStaff.fullname.c_str(), 320, 130, 35, BLACK);
        DrawText(uStaff.gender.c_str(), 320, 190, 35, BLACK);
        DrawText(uStaff.sDate.c_str(), 320, 250, 35, BLACK);
        DrawText(uStaff.email.c_str(), 320, 310, 35, BLACK);
    }
    if (role == 0)
    {
        DrawText(sStudent.schoolYear.c_str(), 70, 30, 30, BLACK);
        DrawText(sStudent.id.c_str(), 320, 70, 35, BLACK);
        DrawText(sStudent.fullname.c_str(), 320, 130, 35, BLACK);
        DrawText(sStudent.gender.c_str(), 320, 190, 35, BLACK);
        DrawText(sStudent.sDate.c_str(), 320, 250, 35, BLACK);
        DrawText(sStudent.email.c_str(), 320, 310, 35, BLACK);
    }
    EndDrawing();
}

void schoolYearStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
                           Rectangle rec_StudentSchoolYear[], short &numSchoolYear) // menu = 4
{

    if (CheckCollisionPointRec(mousePosition, rec_StudentSchoolYear[6]))
        indexMouse = 6;
    else
        indexMouse = -1;
    for (int i = 0; i <= numSchoolYear; i++)
    {
        if (CheckCollisionPointRec(mousePosition, rec_StudentSchoolYear[i]))
            indexMouse = i;
    }
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(touchPosition, rec_StudentSchoolYear[6]))
            menu = 0; // Main Menu
        if (indexMouse >= 0 && indexMouse != 6 && CheckCollisionPointRec(touchPosition, rec_StudentSchoolYear[indexMouse]))
        {
            menu = 5; // Semester Menu
            sStudent.schoolYear = to_string(sStudent.firstYear - 2000 + indexMouse) + "-" + to_string(sStudent.firstYear - 2000 + 1 + indexMouse);
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleLines(rec_StudentSchoolYear[indexMouse].x, rec_StudentSchoolYear[indexMouse].y, rec_StudentSchoolYear[indexMouse].width, rec_StudentSchoolYear[indexMouse].height, BLACK);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    for (int i = 0; i <= numSchoolYear; i++)
        DrawText(TextFormat("%i - %i", sStudent.firstYear + i, sStudent.firstYear + 1 + i), rec_StudentSchoolYear[i].x + 10, rec_StudentSchoolYear[i].y + 15, 30, BLACK);
    EndDrawing();
}

void semesterStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
                         Rectangle rec_StudentSemester[], short &CourseOrResult, string name[], int& dummy, short& role) // menu = 5
{
    if (CheckCollisionPointRec(mousePosition, rec_StudentSemester[0]))
        indexMouse = 0;
    else if (CheckCollisionPointRec(mousePosition, rec_StudentSemester[1]))
        indexMouse = 1;
    else if (CheckCollisionPointRec(mousePosition, rec_StudentSemester[2]))
        indexMouse = 2;
    else if (CheckCollisionPointRec(mousePosition, rec_StudentSemester[3]))
        indexMouse = 3;
    else
        indexMouse = -1;
    if (IsMouseButtonPressed(0))
    {
        if (indexMouse == 3)
        {
            if (role == 0)
                menu = 4; // School Year Student Menu
            else
                menu = 13;
        }
        if (indexMouse >= 0 && indexMouse < 3 && CheckCollisionPointRec(touchPosition, rec_StudentSemester[indexMouse]))
        {
            sStudent.semeter = "HK" + to_string(indexMouse + 1);
            if (role == 0)
            {
                if (CourseOrResult == 0 && checkFileExist(sStudent, CourseOrResult))
                {
                    checkStudentCourse(sStudent);
                    menu = 2; // Course Student Menu
                }
                else if (CourseOrResult == 1 && checkFileExist(sStudent, CourseOrResult))
                {
                    checkStudentResult(sStudent);
                    menu = 2; // Result Student Menu
                }
                else
                    menu = 20;
            }
            else
            {
                menu = 21;
                ifstream fin;
                fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/Courses.txt");
                fin >> dummy;
                fin.get();
                for (int i = 0;i < dummy;i++)
                    getline(fin, name[i], '\n');
                fin.close();
            }
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleLines(rec_StudentSemester[indexMouse].x, rec_StudentSemester[indexMouse].y, rec_StudentSemester[indexMouse].width, rec_StudentSemester[indexMouse].height, BLACK);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    DrawText("SEMESTER 1", rec_StudentSemester[0].x + 15, rec_StudentSemester[0].y + 14, 30, BLACK);
    DrawText("SEMESTER 2", rec_StudentSemester[1].x + 15, rec_StudentSemester[1].y + 14, 30, BLACK);
    DrawText("SEMESTER 3", rec_StudentSemester[2].x + 15, rec_StudentSemester[2].y + 14, 30, BLACK);
    EndDrawing();
}

void courseOrResultStudentMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, short& menu, Course& cCourse,
    Rectangle rec_StudentCourse[], short& courseOrResult) // menu = 2
{
    if (CheckCollisionPointRec(mousePosition, rec_StudentCourse[0]))
        indexMouse = 0;
    else if (CheckCollisionPointRec(mousePosition, rec_StudentCourse[1]))
        indexMouse = 1;
    else if (CheckCollisionPointRec(mousePosition, rec_StudentCourse[2]))
        indexMouse = 2;
    else if (CheckCollisionPointRec(mousePosition, rec_StudentCourse[3]))
        indexMouse = 3;
    else if (CheckCollisionPointRec(mousePosition, rec_StudentCourse[4]))
        indexMouse = 4;
    else if (CheckCollisionPointRec(mousePosition, rec_StudentCourse[5]))
        indexMouse = 5;
    else
        indexMouse = -1;

    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(touchPosition, rec_StudentCourse[5]))
            menu = 5; // Semester Student Menu
        if (indexMouse >= 0 && indexMouse <= 4 && CheckCollisionPointRec(touchPosition, rec_StudentCourse[indexMouse]))
        {
            if (courseOrResult == 0)
            {
                menu = 3; // Detail of Course
                loadFileCourse(sStudent.courseID[indexMouse], cCourse, sStudent);
                sStudent.courseView = indexMouse;
            }
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (courseOrResult == 0)
    {
        DrawText("Course", 70, GetScreenHeight() / 2 - 180, 30, BLACK);
        DrawText(sStudent.nameCourse[0].c_str(), 70, GetScreenHeight() / 2 - 130, 30, BLACK);
        DrawText(sStudent.nameCourse[1].c_str(), 70, GetScreenHeight() / 2 - 80, 30, BLACK);
        DrawText(sStudent.nameCourse[2].c_str(), 70, GetScreenHeight() / 2 - 30, 30, BLACK);
        DrawText(sStudent.nameCourse[3].c_str(), 70, GetScreenHeight() / 2 + 20, 30, BLACK);
        DrawText(sStudent.nameCourse[4].c_str(), 70, GetScreenHeight() / 2 + 70, 30, BLACK);
        DrawText("Status", GetScreenWidth() - 300, GetScreenHeight() / 2 - 180, 30, BLACK);
        DrawText(sStudent.isRegistered[0].c_str(), GetScreenWidth() - 300, GetScreenHeight() / 2 - 130, 30, BLACK);
        DrawText(sStudent.isRegistered[1].c_str(), GetScreenWidth() - 300, GetScreenHeight() / 2 - 80, 30, BLACK);
        DrawText(sStudent.isRegistered[2].c_str(), GetScreenWidth() - 300, GetScreenHeight() / 2 - 30, 30, BLACK);
        DrawText(sStudent.isRegistered[3].c_str(), GetScreenWidth() - 300, GetScreenHeight() / 2 + 20, 30, BLACK);
        DrawText(sStudent.isRegistered[4].c_str(), GetScreenWidth() - 300, GetScreenHeight() / 2 + 70, 30, BLACK);
        if (indexMouse >= 0)
            DrawRectangleLines(rec_StudentCourse[indexMouse].x, rec_StudentCourse[indexMouse].y, rec_StudentCourse[indexMouse].width, rec_StudentCourse[indexMouse].height, BLACK);
    }
    else
    {
        DrawText("", 80, GetScreenHeight() / 2 - 180, 25, BLACK);
        DrawText("Course", 300, GetScreenHeight() / 2 - 180, 25, BLACK);
        DrawText("Quiz", 640, GetScreenHeight() / 2 - 180, 25, BLACK);
        DrawText("Lab", 722, GetScreenHeight() / 2 - 180, 25, BLACK);
        DrawText("Mid", 810, GetScreenHeight() / 2 - 180, 25, BLACK);
        DrawText("Final", 890, GetScreenHeight() / 2 - 180, 25, BLACK);
        DrawText("Average", 970, GetScreenHeight() / 2 - 180, 25, BLACK);
        DrawText("Type", 1084, GetScreenHeight() / 2 - 180, 25, BLACK);
        if (indexMouse < 5)
            DrawRectangle(rec_StudentCourse[indexMouse].x, rec_StudentCourse[indexMouse].y, rec_StudentCourse[indexMouse].width, rec_StudentCourse[indexMouse].height, LIGHTGRAY);
        else if (indexMouse == 5)
            DrawRectangleLines(rec_StudentCourse[indexMouse].x, rec_StudentCourse[indexMouse].y, rec_StudentCourse[indexMouse].width, rec_StudentCourse[indexMouse].height, BLACK);
        DrawRectangleLines(rec_StudentCourse[0].x, rec_StudentCourse[0].y - 50, rec_StudentCourse[0].width, 300, BLACK);
        for (int i = 0; i < 5; i++)
        {
            DrawLine(50, rec_StudentCourse[i].y, GetScreenWidth() - 50, rec_StudentCourse[i].y, BLACK);
            sStudent.getAverageResult(i);
            if (sStudent.rResult[i].quiz == -2.0)
                DrawRectangle(rec_StudentCourse[i].x, rec_StudentCourse[i].y, rec_StudentCourse[i].width, rec_StudentCourse[i].height, RED);
            if (sStudent.rResult[i].quiz >= 0)
                DrawText(TextFormat("%.2f", sStudent.rResult[i].quiz), 640, rec_StudentCourse[i].y + 10, 25, BLACK);
            if (sStudent.rResult[i].lab >= 0)
                DrawText(TextFormat("%.2f", sStudent.rResult[i].lab), 723, rec_StudentCourse[i].y + 10, 25, BLACK);
            if (sStudent.rResult[i].midterm >= 0)
                DrawText(TextFormat("%.2f", sStudent.rResult[i].midterm), 807, rec_StudentCourse[i].y + 10, 25, BLACK);
            if (sStudent.rResult[i].finalterm >= 0)
                DrawText(TextFormat("%.2f", sStudent.rResult[i].finalterm), 893, rec_StudentCourse[i].y + 10, 25, BLACK);
            if (sStudent.rResult[i].average >= 0)
                DrawText(TextFormat("%.2f", sStudent.rResult[i].average), 995, rec_StudentCourse[i].y + 10, 25, BLACK);
            if (sStudent.rResult[i].type != "Not" && sStudent.rResult[i].type != "None")
                DrawText(sStudent.rResult[i].type.c_str(), 1100, rec_StudentCourse[i].y + 10, 25, BLACK);
            DrawText(sStudent.nameCourse[i].c_str(), 110, rec_StudentCourse[i].y + 8, 25, BLACK);
            DrawText(TextFormat("%i", i + 1), 70, rec_StudentCourse[i].y + 10, 25, BLACK);
        }
        DrawLine(100, rec_StudentCourse[0].y - 50, 100, rec_StudentCourse[0].y + 250, BLACK);
        DrawLine(627, rec_StudentCourse[0].y - 50, 627, rec_StudentCourse[0].y + 250, BLACK);
        DrawLine(705, rec_StudentCourse[0].y - 50, 705, rec_StudentCourse[0].y + 250, BLACK);
        DrawLine(785, rec_StudentCourse[0].y - 50, 785, rec_StudentCourse[0].y + 250, BLACK);
        DrawLine(870, rec_StudentCourse[0].y - 50, 870, rec_StudentCourse[0].y + 250, BLACK);
        DrawLine(960, rec_StudentCourse[0].y - 50, 960, rec_StudentCourse[0].y + 250, BLACK);
        DrawLine(1080, rec_StudentCourse[0].y - 50, 1080, rec_StudentCourse[0].y + 250, BLACK);
    }
    EndDrawing();
}

void detailOfCourseMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, Course &cCourse, student &sStudent, short &menu,
                        Rectangle rec_detailOfCourseMenu[], short& role) // menu = 3
{
    if (CheckCollisionPointRec(mousePosition, rec_detailOfCourseMenu[0]))
        indexMouse = 0;
    else if (CheckCollisionPointRec(mousePosition, rec_detailOfCourseMenu[1]))
        indexMouse = 1;
    else
        indexMouse = -1;

    if (IsMouseButtonPressed(0))
    {
        if (indexMouse == 1)
        {
            deleteListStudent(cCourse.nStudentHead, cCourse.numStudent);
            if (role == 0)
                menu = 2; // Student Course Menu
            else menu = 21;
        }
        if (indexMouse == 0)
        {
            if (role == 0)
            {
                if (sStudent.isRegistered[sStudent.courseView] == "Not Registered" && cCourse.numStudent < cCourse.maxStudent)
                    registerCourse(sStudent, cCourse);
                else if (sStudent.isRegistered[sStudent.courseView] == "Registered")
                    unregisterCourse(sStudent, cCourse);
            }
            else
                menu = 22;
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("ID", 70, 60, 23, BLACK);
    DrawText(cCourse.ID.c_str(), 250, 60, 23, BLACK);
    DrawText("Course", 70, 100, 23, BLACK);
    DrawText(cCourse.name.c_str(), 250, 100, 23, BLACK);
    DrawText("Lecturer", 70, 140, 23, BLACK);
    DrawText(cCourse.lecturer.c_str(), 250, 140, 23, BLACK);
    DrawText("Date", 70, 180, 23, BLACK);
    DrawText(cCourse.sDay.c_str(), 250, 180, 23, BLACK);
    DrawText("Timetable", 70, 220, 23, BLACK);
    for (int i = 0; i < 2; i++)
    {
        if (cCourse.sSession[i].weekday != "None")
        {
            DrawText(cCourse.sSession[i].weekday.c_str(), 250, 220 + 40 * i, 23, BLACK);
            DrawText(cCourse.sSession[i].sTime.c_str(), 310, 220 + 40 * i, 23, BLACK);
        }
    }
    DrawRectangle(rec_detailOfCourseMenu[0].x, rec_detailOfCourseMenu[0].y, rec_detailOfCourseMenu[0].width, rec_detailOfCourseMenu[0].height, LIGHTGRAY);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    DrawText(TextFormat("Registered: %i / %i", cCourse.numStudent, cCourse.maxStudent), 70, 300, 25, BLACK);
    DrawRectangleLines(rec_detailOfCourseMenu[indexMouse].x, rec_detailOfCourseMenu[indexMouse].y, rec_detailOfCourseMenu[indexMouse].width, rec_detailOfCourseMenu[indexMouse].height, BLACK);
    if (role == 0)
    {
        if (sStudent.isRegistered[sStudent.courseView] == "Registered")
            DrawText("REGISTERED", 460, 295, 30, RED);
        else if (cCourse.numStudent < cCourse.maxStudent)
            DrawText("  REGISTER", 460, 295, 30, LIME);
        else
            DrawText("     FULL", 460, 295, 30, RED);
    }
    else
        DrawText(" Student List", 460, 295, 30, RED);


    EndDrawing();
}

void changePassword(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &indexTouch,
                    char oldPass[], char newPass[], char confirmPass[],
                    char oldPassStar[], char newPassStar[], char confirmPassStar[],
                    short &oldPassCount, short &newPassCount, short &confirmPassCount,
                    student &sStudent, user &uStaff, short &menu, short role, Rectangle rec_changePass[], bool flag)
{
    indexMouse = -1;
    for (int i = 0; i < 5; i++)
        if (CheckCollisionPointRec(mousePosition, rec_changePass[i]))
        {
            indexMouse = i;
            if (indexMouse < 3)
                SetMouseCursor(2);
            break;
        }

    if (IsMouseButtonPressed(0))
        for (int i = 0; i < 5; i++)
            if (CheckCollisionPointRec(touchPosition, rec_changePass[i]))
            {
                indexTouch = i;
                break;
            }

    if (indexTouch == 0)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (oldPassCount < 16))
            {
                oldPass[oldPassCount] = (char)key;
                oldPass[oldPassCount + 1] = '\0';
                oldPassStar[oldPassCount] = '*';
                oldPassStar[oldPassCount + 1] = '\0';
                oldPassCount++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            oldPassCount--;
            if (oldPassCount < 0)
                oldPassCount = 0;
            oldPass[oldPassCount] = '\0';
            oldPassStar[oldPassCount] = '\0';
        }
    }
    if (indexTouch == 1)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (newPassCount < 16))
            {
                newPass[newPassCount] = (char)key;
                newPass[newPassCount + 1] = '\0';
                newPassStar[newPassCount] = '*';
                newPassStar[newPassCount + 1] = '\0';
                newPassCount++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            newPassCount--;
            if (newPassCount < 0)
                newPassCount = 0;
            newPass[newPassCount] = '\0';
            newPassStar[newPassCount] = '\0';
        }
    }
    if (indexTouch == 2)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (confirmPassCount < 16))
            {
                confirmPass[confirmPassCount] = (char)key;
                confirmPass[confirmPassCount + 1] = '\0';
                confirmPassStar[confirmPassCount] = '*';
                confirmPassStar[confirmPassCount + 1] = '\0';
                confirmPassCount++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            confirmPassCount--;
            if (confirmPassCount < 0)
                confirmPassCount = 0;
            confirmPass[confirmPassCount] = '\0';
            confirmPassStar[confirmPassCount] = '\0';
        }
    }
    if (indexTouch == 3 || IsKeyPressed(KEY_ENTER))
    {
        if (role == -1)
        {
            if (oldPass != "\0" && uStaff.password == oldPass && strcmp(newPass, confirmPass) == 0)
            {
                node<user> *pHead = NULL;
                int n;
                loadFileStaff(pHead, n);
                node<user> *p = pHead;
                while (p->data.id != uStaff.id)
                    p = p->next;
                p->data.password = newPass;
                updateFileStaff(pHead, n);
                uStaff.password = newPass;
                menu = 1;
                indexTouch = -1;
                oldPass[0] = '\0';
                newPass[0] = '\0';
                confirmPass[0] = '\0';
                oldPassStar[0] = '\0';
                newPassStar[0] = '\0';
                confirmPassStar[0] = '\0';
                oldPassCount = 0;
                newPassCount = 0;
                confirmPassCount = 0;
                return;
            }
        }
        else if (role == 0)
        {
            if (oldPass != "\0" && oldPass == sStudent.password && strcmp(newPass, confirmPass) == 0)
            {
                node<student> *pHead = NULL;
                int n;
                loadFileStudent(pHead, n);
                node<student> *p = pHead;
                while (p->data.id != sStudent.id)
                    p = p->next;
                p->data.password = newPass;
                updateFileStudent(pHead, n);
                sStudent.password = newPass;
                menu = 1;
                indexTouch = -1;
                oldPass[0] = '\0';
                newPass[0] = '\0';
                confirmPass[0] = '\0';
                oldPassStar[0] = '\0';
                newPassStar[0] = '\0';
                confirmPassStar[0] = '\0';
                oldPassCount = 0;
                newPassCount = 0;
                confirmPassCount = 0;
                return;
            }
        }
        flag = false;
        indexTouch = 3;
    }
    if (indexTouch == 4)
    {
        menu = 1;
        indexTouch = -1;
        oldPass[0] = '\0';
        newPass[0] = '\0';
        confirmPass[0] = '\0';
        oldPassStar[0] = '\0';
        newPassStar[0] = '\0';
        confirmPassStar[0] = '\0';
        oldPassCount = 0;
        newPassCount = 0;
        confirmPassCount = 0;
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Old Pass   : ", GetScreenWidth() / 2 - 10 * 40, GetScreenHeight() / 2 - 120, 40, BLACK);
    DrawText("New Pass   : ", GetScreenWidth() / 2 - 10 * 40, GetScreenHeight() / 2 - 40, 40, BLACK);
    DrawText("Confirm : ", GetScreenWidth() / 2 - 10 * 40, GetScreenHeight() / 2 + 40, 40, BLACK);
    DrawText(oldPassStar, rec_changePass[0].x + 10, rec_changePass[0].y + 10, 40, BLACK);
    DrawText(newPassStar, rec_changePass[1].x + 10, rec_changePass[1].y + 10, 40, BLACK);
    DrawText(confirmPassStar, rec_changePass[2].x + 10, rec_changePass[2].y + 10, 40, BLACK);
    DrawRectangle(rec_changePass[3].x, rec_changePass[3].y, rec_changePass[3].width, rec_changePass[3].height, GREEN);
    DrawText("Change", GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 + 150, 40, WHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (flag == false)
    {
        DrawRectangleLines(rec_changePass[0].x, rec_changePass[0].y, rec_changePass[0].width, rec_changePass[0].height, RED);
        DrawRectangleLines(rec_changePass[1].x, rec_changePass[1].y, rec_changePass[1].width, rec_changePass[1].height, RED);
        DrawRectangleLines(rec_changePass[2].x, rec_changePass[2].y, rec_changePass[2].width, rec_changePass[2].height, RED);
        DrawText("Passwords do not match", GetScreenWidth() / 2 - 32 * 20 / 2, GetScreenHeight() / 2 + 100, 20, RED);
    }
    else
    {
        DrawRectangleLines(rec_changePass[0].x, rec_changePass[0].y, rec_changePass[0].width, rec_changePass[0].height, BLACK);
        DrawRectangleLines(rec_changePass[1].x, rec_changePass[1].y, rec_changePass[1].width, rec_changePass[1].height, BLACK);
        DrawRectangleLines(rec_changePass[2].x, rec_changePass[2].y, rec_changePass[2].width, rec_changePass[2].height, BLACK);
        if (indexTouch == 0 || indexTouch == 1 || indexTouch == 2)
            DrawRectangleLines(rec_changePass[indexTouch].x, rec_changePass[indexTouch].y, rec_changePass[indexTouch].width, rec_changePass[indexTouch].height, GREEN);
    }
    DrawRectangleLines(rec_changePass[indexMouse].x, rec_changePass[indexMouse].y, rec_changePass[indexMouse].width, rec_changePass[indexMouse].height, GREEN);
    EndDrawing();
}
void classInput(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, Rectangle rec_classInput[], int &count, char **droppedFiles)
{
    if (IsFileDropped())
    {
        droppedFiles = GetDroppedFiles(&count);
    }
    indexMouse = -1;
    if (CheckCollisionPointRec(touchPosition, rec_classInput[0]))
    {
        indexMouse = 0;
        std::cerr << count << ' ';
        if (IsMouseButtonPressed(0) && count != 0)
        {
            for (int i = 0; i < count; i++)
            {
                ifstream fin;
                fin.open(droppedFiles[i]);
                int n;
                node<student> *pHead = NULL;
                if (fin.is_open())
                {
                    fin >> n;
                    fin.get();
                    node<student> *pCur = nullptr;
                    for (int j = 0; j < n + 1; j++)
                    {
                        if (pHead == nullptr)
                        {
                            pHead = new node<student>;
                            pCur = pHead;
                        }
                        else
                        {
                            pCur->next = new node<student>;
                            pCur = pCur->next;
                        }
                        getline(fin, pCur->data.id, ',');
                        getline(fin, pCur->data.fullname, ',');
                        getline(fin, pCur->data.gender, ',');
                        getline(fin, pCur->data.sDate, ',');
                        getline(fin, pCur->data.email, '\n');
                    }
                }
                fin.close();
                ofstream fout;
                string classname = GetFileName(droppedFiles[i]);
                fout.open("../data/detailofeachclass/" + classname);
                fout << n << '\n';
                fout << "ID,Full Name,Gender,Birthday,Email\n";
                node<student> *p = pHead->next;
                while (p)
                {
                    fout << p->data.id << ',' << p->data.fullname << ',' << p->data.gender << ','
                         << p->data.sDate << ',' << p->data.email << '\n';
                    p = p->next;
                }
                deleteListStudent(pHead, n);
                fout.close();
            }
            ClearDroppedFiles();
            count = 0;
            **droppedFiles = {0};
        }
    }
    if (CheckCollisionPointRec(touchPosition, rec_classInput[1]))
    {
        indexMouse = 1;
        if (IsMouseButtonPressed(0))
            menu = 11;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (count == 0)
        DrawText("Drop your files to this window! (CSV format)", 100, 40, 20, DARKGRAY);
    else
    {
        DrawText("Dropped files:", 100, 40, 20, DARKGRAY);

        for (int i = 0; i < count; i++)
        {
            if (i % 2 == 0)
                DrawRectangle(0, 85 + 40 * i, 1200, 40, Fade(LIGHTGRAY, 0.5f));
            else
                DrawRectangle(0, 85 + 40 * i, 1200, 40, Fade(LIGHTGRAY, 0.3f));

            DrawText(droppedFiles[i], 120, 100 + 40 * i, 10, GRAY);
        }

        DrawText("Drop new files...", 100, 110 + 40 * count, 20, DARKGRAY);
    }

    DrawRectangle(rec_classInput[0].x, rec_classInput[0].y, rec_classInput[0].width, rec_classInput[0].height, GREEN);
    DrawText("SUBMIT", GetScreenWidth() - 160, GetScreenHeight() - 50, 30, WHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (indexMouse >= 0)
        DrawRectangleLines(rec_classInput[indexMouse].x, rec_classInput[indexMouse].y, rec_classInput[indexMouse].width, rec_classInput[indexMouse].height, BLACK);
    EndDrawing();
}
void studentWhiteMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, Rectangle rec_white[], short CourseOrResult)
{
    if (CheckCollisionPointRec(mousePosition, rec_white[0]))
        indexMouse = 0;
    else
        indexMouse = -1;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(touchPosition, rec_white[0]))
            menu = 5; // Semester Student Menu
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (CourseOrResult == 0)
        DrawText("No Course", 530, 300, 40, LIGHTGRAY);
    else if (CourseOrResult == 1)
        DrawText("No Result", 530, 300, 40, LIGHTGRAY);
    if (indexMouse == 0)
        DrawRectangleLines(rec_white[0].x, rec_white[0].y, rec_white[0].width, rec_white[0].height, BLACK);
    EndDrawing();
}

void schoolYearStaffMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, short& menu,
    Rectangle rec_StaffSchoolYear[], short& numSchoolYear, short&iYear) // menu = 11
{
    indexMouse = -1;
    for (int i = 0; i <= numSchoolYear; i++)
    {
        if (CheckCollisionPointRec(mousePosition, rec_StaffSchoolYear[i]))
            indexMouse = i;
    }
    if (CheckCollisionPointRec(mousePosition, rec_StaffSchoolYear[9]))
        indexMouse = 9;
    if (CheckCollisionPointRec(mousePosition, rec_StaffSchoolYear[10]))
        indexMouse = 10;
    if (CheckCollisionPointRec(mousePosition, rec_StaffSchoolYear[11]))
        indexMouse = 11;
    if (IsMouseButtonPressed(0))
    {
        switch (indexMouse)
        {
        case 9:
            menu = 0;
            break;
        case 10:
            menu = 12;
            break;
        case 11:
            createSchoolYear(numSchoolYear);
            break;
        default:
            if (indexMouse >= 0 && indexMouse < 9)
            {
                menu = 13;
                sStudent.firstYear = 2020 + indexMouse;
                sStudent.schoolYear = to_string(20 + indexMouse) + "-" + to_string(21 + indexMouse);
            }
            break;
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    DrawText("ADD CLASS", GetScreenWidth() - 330 + 15, GetScreenHeight() - 120, 28, GREEN);
    DrawText("CREATE NEW YEAR", GetScreenWidth() - 330 + 15, GetScreenHeight() - 60, 28, GREEN);
    if (indexMouse >= 0)
        DrawRectangleLines(rec_StaffSchoolYear[indexMouse].x, rec_StaffSchoolYear[indexMouse].y, rec_StaffSchoolYear[indexMouse].width, rec_StaffSchoolYear[indexMouse].height, BLACK);
    for (int i = 0; i <= numSchoolYear; i++)
        DrawText(TextFormat("%i - %i", 2020 + i, 2021 + i), rec_StaffSchoolYear[i].x + 10, rec_StaffSchoolYear[i].y + 15, 30, BLACK);
    EndDrawing();
}

void StaffViewSchoolyearDetail(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, short& menu,
    short& numSchoolYear, Rectangle rec_StaffViewSchoolyearDetail[], string name[], int& dummy, short& ClassOrCourse) // menu = 13
{
    indexMouse = -1;
    for (int i = 0; i < 3; i++)
    {
        if (CheckCollisionPointRec(mousePosition, rec_StaffViewSchoolyearDetail[i]))
            indexMouse = i;
    }
    if (IsMouseButtonPressed(0))
    {
        ifstream fin;
        switch (indexMouse)
        {
        case 0:
            ClassOrCourse = 0;
            menu = 5;
            break;
        case 1:
            ClassOrCourse = 1;
            fin.open("../data/" + sStudent.schoolYear + "/Classes.txt");
            fin >> dummy;
            fin.get();
            for (int i = 0;i < dummy;i++)
                getline(fin, name[i], '\n');
            fin.close();
            menu = 21;
            break;
        case 2:
            menu = 11;
            break;
        default:
            break;
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("SHOOLYEAR: %i - %i", sStudent.firstYear, sStudent.firstYear + 1), 100, 100, 40, BLACK);
    DrawText("SEMESTERS", 165, 275, 40, BLACK);
    DrawText("CLASSES", 815, 275, 40, BLACK);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (indexMouse >= 0)
        DrawRectangleLines(rec_StaffViewSchoolyearDetail[indexMouse].x, rec_StaffViewSchoolyearDetail[indexMouse].y, rec_StaffViewSchoolyearDetail[indexMouse].width, rec_StaffViewSchoolyearDetail[indexMouse].height, BLACK);
    EndDrawing();
}

void viewListClassOrCourse(Vector2& mousePosition, Vector2& touchPosition, student& sStudent, Course& cCourse, short& indexMouse, short& menu,
    Rectangle rec_listClass[], string name[], int& dummy, short& ClassOrCourse) // menu = 21
{
    indexMouse = -1;
    if (CheckCollisionPointRec(mousePosition, rec_listClass[51]))
        indexMouse = 51;
    for (int i = 0;i <= dummy;i++)
    {
        if (CheckCollisionPointRec(mousePosition, rec_listClass[i]))
            indexMouse = i;
    }
    if (GetMouseWheelMove())
        if ((rec_listClass[dummy].y > GetScreenHeight() - 140 || GetMouseWheelMove() > 0) && (rec_listClass[0].y < 70 || GetMouseWheelMove() < 0))
        {
            for (int i = 0;i <= dummy;i++)
                rec_listClass[i].y += GetMouseWheelMove() * 20;
        }
    if (IsMouseButtonPressed(0))
    {
        if (indexMouse > 0)
        {
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
            if (indexMouse == 51)
            {
                if (ClassOrCourse == 1)
                    menu = 13;
                else
                    menu = 5;
            }
            else
            {
                if (ClassOrCourse == 1)
                {
                    menu = 22;
                    loadFileClass(cCourse.nStudentHead, name[indexMouse - 1], cCourse.numStudent);
                    return;
                }
                if (ClassOrCourse == 0)
                {
                    loadFileCourse(name[indexMouse - 1], cCourse, sStudent);
                    menu = 3;
                }
            }
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (indexMouse > 0 && indexMouse < 51)
        DrawRectangle(rec_listClass[indexMouse].x, rec_listClass[indexMouse].y, rec_listClass[indexMouse].width, rec_listClass[indexMouse].height, LIGHTGRAY);
    else 
        DrawRectangleLines(rec_listClass[indexMouse].x, rec_listClass[indexMouse].y, rec_listClass[indexMouse].width, rec_listClass[indexMouse].height, BLACK);
    if (ClassOrCourse)
        DrawText(TextFormat("LIST OF CLASSES"), rec_listClass[0].x + 10, rec_listClass[0].y + 10, 30, BLACK);
    else
        DrawText(TextFormat("LIST OF COURSES"), rec_listClass[0].x + 10, rec_listClass[0].y + 10, 30, BLACK);
    DrawRectangleLines(rec_listClass[0].x, rec_listClass[0].y, rec_listClass[0].width, rec_listClass[0].height, BLACK);
    for (int i = 1;i <= dummy;i++)
    {
        DrawText(name[i - 1].c_str(), rec_listClass[i].x + 10, rec_listClass[i].y + 12, 33, BLACK);
        DrawRectangleLines(rec_listClass[i].x, rec_listClass[i].y, rec_listClass[i].width, rec_listClass[i].height, BLACK);
    }
    DrawText("<<", 15, 280, 50, RED);
    EndDrawing();
}

void viewClassProfileMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, student& sStudent, Course& cCourse, short& menu,
    Rectangle rec_listClass[], node<student>*& pCur, short& ClassOrCourse) // menu = 22
{
    indexMouse = -1;
    if (CheckCollisionPointRec(mousePosition, rec_listClass[51]))
        indexMouse = 51;
    for (int i = 0;i <= cCourse.numStudent;i++)
    {
        if (CheckCollisionPointRec(mousePosition, rec_listClass[i]))
            indexMouse = i;
    }
    if (GetMouseWheelMove())
        if ((rec_listClass[cCourse.numStudent].y > GetScreenHeight() - 140 || GetMouseWheelMove() > 0) && (rec_listClass[0].y < 70 || GetMouseWheelMove() < 0))
        {
            for (int i = 0;i <= cCourse.numStudent;i++)
                rec_listClass[i].y += GetMouseWheelMove() * 20;
        }

    if (IsMouseButtonPressed(0))
    {
        if (indexMouse == 51)
        {
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
            if (ClassOrCourse == 1)
            {
                deleteListStudent(cCourse.nStudentHead, cCourse.numStudent + 1);
                menu = 21;
            }
            else
                menu = 3;
        }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (indexMouse > 0 && indexMouse < 51)
        DrawRectangle(rec_listClass[indexMouse].x, rec_listClass[indexMouse].y, rec_listClass[indexMouse].width, rec_listClass[indexMouse].height, LIGHTGRAY);
    else
        DrawRectangleLines(rec_listClass[indexMouse].x, rec_listClass[indexMouse].y, rec_listClass[indexMouse].width, rec_listClass[indexMouse].height, BLACK);
    DrawRectangleLines(rec_listClass[0].x, rec_listClass[0].y, rec_listClass[0].width, rec_listClass[0].height, BLACK);
    pCur = cCourse.nStudentHead;
    if (ClassOrCourse == 1)
    {
        for (int i = 0;i <= cCourse.numStudent && pCur;i++)
        {
            DrawText(pCur->data.id.c_str(), 75, rec_listClass[i].y + 12, 25, BLACK);
            DrawText(pCur->data.fullname.c_str(), 185, rec_listClass[i].y + 12, 25, BLACK);
            DrawText(pCur->data.gender.c_str(), 520, rec_listClass[i].y + 12, 25, BLACK);
            DrawText(pCur->data.sDate.c_str(), 615, rec_listClass[i].y + 12, 25, BLACK);
            DrawText(pCur->data.email.c_str(), 795, rec_listClass[i].y + 12, 25, BLACK);
            pCur = pCur->next;
            DrawRectangleLines(rec_listClass[i].x, rec_listClass[i].y, rec_listClass[i].width, rec_listClass[i].height, BLACK);
        }
        DrawLine(180, rec_listClass[0].y, 180, rec_listClass[cCourse.numStudent].y + 60, BLACK);
        DrawLine(515, rec_listClass[0].y, 515, rec_listClass[cCourse.numStudent].y + 60, BLACK);
        DrawLine(610, rec_listClass[0].y, 610, rec_listClass[cCourse.numStudent].y + 60, BLACK);
        DrawLine(790, rec_listClass[0].y, 790, rec_listClass[cCourse.numStudent].y + 60, BLACK);
    }
    else {
        DrawText("Class", 75, rec_listClass[0].y + 12, 25, BLACK);
        DrawText("ID", 700, rec_listClass[0].y + 12, 25, BLACK);
        for (int i = 1;i <= cCourse.numStudent && pCur;i++)
        {
            DrawText(pCur->data.Class.c_str(), 75, rec_listClass[i].y + 12, 25, BLACK);
            DrawText(pCur->data.id.c_str(), 700, rec_listClass[i].y + 12, 25, BLACK);
            pCur = pCur->next;
            DrawRectangleLines(rec_listClass[i].x, rec_listClass[i].y, rec_listClass[i].width, rec_listClass[i].height, BLACK);
            DrawLine(515, rec_listClass[0].y, 515, rec_listClass[cCourse.numStudent].y + 60, BLACK);
        }
    }
    DrawText("<<", 15, 280, 50, RED);
    EndDrawing();
}











