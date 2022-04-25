#include "../include/menu.h"


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
            if (indexMouse == 0)
                menu = 1; // Profile Menu
            if (indexMouse == 1 || indexMouse == 2)
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

void semesterStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, Course& cCourse, short &menu,
                         Rectangle rec_StudentSemester[], short &CourseOrResult, string name[], int &dummy, short &role) // menu = 5
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
        if (indexMouse >= 0 && indexMouse < 3)
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
                    checkStudentResult(sStudent, cCourse);
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
                cout << dummy << endl;
                fin.get();
                for (int i = 0; i < dummy; i++)
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

void courseOrResultStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu, Course &cCourse,
                               Rectangle rec_StudentCourse[], short &courseOrResult) // menu = 2
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
        if (indexMouse == 5)
            menu = 5; // Semester Student Menu
        if (indexMouse >= 0 && indexMouse <= 4)
        {
            if (courseOrResult == 0)
            {
                menu = 3; // Detail of Course
                sStudent.courseView = indexMouse;
                loadFileCourse(sStudent.courseID[indexMouse], cCourse, sStudent);
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
            if (sStudent.rResult[i].type != "None")
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
                        Rectangle rec_detailOfCourseMenu[], int& dummy, string name[], short& role) // menu = 3
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
            else
                menu = 21;
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
        if (role == -1 && CheckCollisionPointRec(mousePosition, { 750, 285, 280, 50 }))
        {
            indexMouse = 2;
            if (IsMouseButtonPressed(0))
            {
                RemoveCourse(sStudent, cCourse, name, dummy);
                menu = 21;
            }
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
    DrawText("Class", 200, 350, 30, BLACK);
    for (int i = 0;i < cCourse.classAllowed;i++)
        DrawText(cCourse.nameClassAllowed[i].c_str(), 400 + (i % 4) * 100, 350 + (i / 4) * 50, 30, DARKBLUE);DrawRectangleLines(rec_detailOfCourseMenu[indexMouse].x, rec_detailOfCourseMenu[indexMouse].y, rec_detailOfCourseMenu[indexMouse].width, rec_detailOfCourseMenu[indexMouse].height, BLACK);
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
    {
        DrawText(" Student List", 460, 295, 30, RED);
        DrawText(" Remove Course", 760, 295, 30, DARKBLUE);
        if (CheckCollisionPointRec(mousePosition,{ 750, 285, 280, 50 }))
            DrawRectangleLines(750, 285, 280, 50, DARKBLUE);
    }
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
void classInput(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student& sStudent, Course& cCourse, short &menu,
    Rectangle rec_classInput[], int &count, char **droppedFiles, string name[], int& dummy, short& ClassOrCourse)
{
    if (IsFileDropped())
    {
        droppedFiles = GetDroppedFiles(&count);
    }
    indexMouse = -1;
    if (CheckCollisionPointRec(mousePosition, rec_classInput[0]))
        indexMouse = 0;
    if (CheckCollisionPointRec(mousePosition, rec_classInput[1]))
        indexMouse = 1;
    if (IsMouseButtonPressed(0))
    {
        if (indexMouse == 0)
        {
            if (count != 0)
            {
                if (ClassOrCourse == 1)
                {
                    for (int i = 0; i < count; i++)
                    {
                        ifstream fin;
                        name[dummy + i] = GetFileNameWithoutExt(droppedFiles[i]);
                        fin.open(droppedFiles[i]);
                        int n;
                        node<student>* pHead = nullptr;
                        node<student>* pCur = nullptr;
                        if (fin.is_open())
                        {
                            string s;
                            getline(fin, s, ' ');
                            fin >> n;
                            while (fin.get() != '\n');
                            while (fin.get() != '\n');
                            for (int j = 0; j < n; j++)
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

                        fout.open("../data/detailofeachclass/" + name[dummy + i] + ".csv");
                        fout << n << '\n';
                        fout << "ID,Full Name,Gender,Birthday,Email\n";
                        node<student>* p = pHead;
                        while (p)
                        {
                            fout << p->data.id << ',' << p->data.fullname << ',' << p->data.gender << ','
                                << p->data.sDate << ',' << p->data.email << '\n';
                            p = p->next;
                        }
                        int add = n;
                        node<student>* p2 = nullptr;
                        loadFileStudent(p2, n);
                        pCur = p2;
                        for (int j = 0;j < n - 1;j++)
                            pCur = pCur->next;
                        if (p2)
                        {
                            pCur->next = pHead;
                            pCur = pCur->next;
                        }
                        else
                        {
                            p2 = pHead;
                            pCur = p2;
                        }
                        for (int j = 0;j < add;j++)
                        {
                            pCur->data.Class = name[dummy + i];
                            pCur->data.password = '1';
                            pCur = pCur->next;
                        }
                        updateFileStudent(p2, n + add);
                        fout.close();
                        for (int j = 1;j < 4;j++)
                        {
                            fout.open("../data/" + sStudent.schoolYear + "/HK" + to_string(j) + "/CourseOf" + name[dummy + i] + ".csv");
                            fout << "ID,none,none,none,none,none" << endl << "ID,none,none,none,none,none" << endl;
                            fout.close();
                        }
                    }
                    dummy += count;
                    ofstream fout;
                    fout.open("../data/" + sStudent.schoolYear + "/Classes.txt");
                    fout << dummy << endl;
                    for (int j = 0;j < dummy;j++)
                    {
                        fout << name[j] << endl;
                    }
                    fout.close();
                    ClearDroppedFiles();
                    menu = 21;
                    count = 0;
                }
                else
                {
                    for (int i = 0;i < count;i++)
                    {
                        string s;
                        node<student>* pCur = cCourse.nStudentHead;
                        ifstream fin;
                        fin.open(droppedFiles[i]);
                        if (fin.is_open())
                        {
                            getline(fin, s, '\n');
                            for (int j = 0; j < cCourse.numStudent; j++)
                            {
                                getline(fin, pCur->data.Class, ',');
                                getline(fin, pCur->data.id, ',');
                                getline(fin, s, ',');
                                if (s == "")
                                    sStudent.rResult[sStudent.courseView].quiz = -1;
                                else sStudent.rResult[sStudent.courseView].quiz = stof(s);
                                getline(fin, s, ',');
                                if (s == "")
                                    sStudent.rResult[sStudent.courseView].lab = -1;
                                else sStudent.rResult[sStudent.courseView].lab = stof(s);
                                getline(fin, s, ',');
                                if (s == "")
                                    sStudent.rResult[sStudent.courseView].midterm = -1;
                                else sStudent.rResult[sStudent.courseView].midterm = stof(s);
                                getline(fin, s, ',');
                                if (s == "")
                                    sStudent.rResult[sStudent.courseView].finalterm = -1;
                                else sStudent.rResult[sStudent.courseView].finalterm = stof(s);
                                getline(fin, s, ',');
                                if (s == "")
                                    sStudent.rResult[sStudent.courseView].average = -1;
                                else sStudent.rResult[sStudent.courseView].average = stof(s);
                                getline(fin, sStudent.rResult[sStudent.courseView].type, '\n');
                                pCur = pCur->next;
                            }
                        }
                        fin.close();
                        ofstream fout;
                        fout.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/" + cCourse.ID + ".txt");
                        fout << cCourse.name << endl;
                        fout << cCourse.lecturer << endl;
                        fout << cCourse.sDay << endl;
                        fout << cCourse.sSession[0].weekday << " " << cCourse.sSession[0].sTime << endl;
                        fout << cCourse.sSession[1].weekday << " " << cCourse.sSession[1].sTime << endl;
                        fout << cCourse.maxStudent << endl
                            << cCourse.numStudent << endl;
                        pCur = cCourse.nStudentHead;
                        for (int j = 0;j < cCourse.numStudent;++j)
                        {
                            fout << pCur->data.Class << " " << pCur->data.id << " "
                                << pCur->data.rResult[sStudent.courseView].quiz << " "
                                << pCur->data.rResult[sStudent.courseView].lab << " "
                                << pCur->data.rResult[sStudent.courseView].midterm << " "
                                << pCur->data.rResult[sStudent.courseView].finalterm << " "
                                << pCur->data.rResult[sStudent.courseView].average << " ";
                            if (pCur->data.rResult[sStudent.courseView].type == "")
                                pCur->data.rResult[sStudent.courseView].type = "None";
                            fout << pCur->data.rResult[sStudent.courseView].type << endl;
                        }
                        fout.close();
                        ClearDroppedFiles();
                        count = 0;
                        menu = 22;
                    }
                    
                }
            }
        }
        if (indexMouse == 1)
        {
            ClearDroppedFiles();
            count = 0;
            menu = 22 - ClassOrCourse;
        }
        if (ClassOrCourse == 1 && CheckCollisionPointRec(mousePosition, rec_classInput[2]))
        {
            menu = 40;
            ClearDroppedFiles();
            count = 0;
        }
    }
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (count == 0)
        DrawText("Drop your files to this window! (CSV format)", 100, 40, 20, DARKGRAY);
    else
    {
        DrawText("Dropped files: (filename is also the classname)", 100, 40, 20, DARKGRAY);

        for (int i = 0; i < count; i++)
        {
            if (i % 2 == 0)
                DrawRectangle(0, 85 + 40 * i, 1200, 40, Fade(LIGHTGRAY, 0.5f));
            else
                DrawRectangle(0, 85 + 40 * i, 1200, 40, Fade(LIGHTGRAY, 0.3f));

            DrawText(droppedFiles[i], 120, 95 + 40 * i, 25, BLACK);
        }

        DrawText("Drop new files...", 100, 110 + 40 * count, 20, DARKGRAY);
    }

    DrawRectangle(rec_classInput[0].x, rec_classInput[0].y, rec_classInput[0].width, rec_classInput[0].height, GREEN);
    DrawText("SUBMIT", GetScreenWidth() - 160, GetScreenHeight() - 50, 30, WHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    if (ClassOrCourse == 1)
    {
        DrawRectangle(rec_classInput[2].x, rec_classInput[2].y, rec_classInput[2].width, rec_classInput[2].height, BLACK);
        DrawText("Export CSV Format File", rec_classInput[2].x + 15, rec_classInput[2].y + 15, 30, WHITE);
    }
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

void schoolYearStaffMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
                         Rectangle rec_StaffSchoolYear[], short &numSchoolYear) // menu = 11
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
    if (IsMouseButtonPressed(0))
    {
        switch (indexMouse)
        {
        case 9:
            menu = 0;
            break;
        case 10:
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
    DrawText("CREATE NEW YEAR", GetScreenWidth() - 330 + 15, GetScreenHeight() - 60, 28, GREEN);
    if (indexMouse >= 0)
        DrawRectangleLines(rec_StaffSchoolYear[indexMouse].x, rec_StaffSchoolYear[indexMouse].y, rec_StaffSchoolYear[indexMouse].width, rec_StaffSchoolYear[indexMouse].height, BLACK);
    for (int i = 0; i <= numSchoolYear; i++)
        DrawText(TextFormat("%i - %i", 2020 + i, 2021 + i), rec_StaffSchoolYear[i].x + 10, rec_StaffSchoolYear[i].y + 15, 30, BLACK);
    EndDrawing();
}

void StaffViewSchoolyearDetail(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
           short &numSchoolYear, Rectangle rec_StaffViewSchoolyearDetail[], string name[], int &dummy, short &ClassOrCourse) // menu = 13
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
            for (int i = 0; i < dummy; i++)
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

void viewListClassOrCourse(Vector2 &mousePosition, Vector2 &touchPosition, student &sStudent, Course &cCourse, short &indexMouse, short &menu,
                           Rectangle rec_listClass[], string name[], int &dummy, short &ClassOrCourse) // menu = 21
{
    indexMouse = -1;
    if (CheckCollisionPointRec(mousePosition, rec_listClass[51]))
        indexMouse = 51;
    if (CheckCollisionPointRec(mousePosition, rec_listClass[52]))
        indexMouse = 52;
    for (int i = 0; i <= dummy; i++)
    {
        if (CheckCollisionPointRec(mousePosition, rec_listClass[i]))
            indexMouse = i;
    }
    if (GetMouseWheelMove())
        if ((rec_listClass[dummy].y > GetScreenHeight() - 140 || GetMouseWheelMove() > 0) && (rec_listClass[0].y < 70 || GetMouseWheelMove() < 0))
        {
            for (int i = 0; i <= dummy; i++)
                rec_listClass[i].y += GetMouseWheelMove() * 20;
            rec_listClass[52].y += GetMouseWheelMove() * 20;
        }
    if (IsMouseButtonPressed(0))
    {
        if (indexMouse > 0)
        {
            for (int i = 0; i < 50; i++)
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
            rec_listClass[52].width = 180;
            rec_listClass[52].height = 40;
            if (indexMouse == 51)
            {
                if (ClassOrCourse == 1)
                    menu = 13;
                else
                    menu = 5;
            }
            else if (indexMouse == 52)
            {
                if (ClassOrCourse == 1)
                    menu = 12;
                else
                {
                    cCourse.ID = "";
                    cCourse.name = "";
                    cCourse.lecturer = "";
                    cCourse.maxStudent = 0;
                    cCourse.startDay.day = -1;
                    cCourse.startDay.month = -1;
                    cCourse.startDay.year = -1;
                    cCourse.endDay.day = -1;
                    cCourse.endDay.month = -1;
                    cCourse.endDay.year = -1;
                    cCourse.sDay = "";
                    cCourse.sSession[0].weekday = "";
                    cCourse.sSession[0].tTimeStart.hour = -1;
                    cCourse.sSession[0].tTimeStart.min = -1;
                    cCourse.sSession[0].tTimeEnd.hour = -1;
                    cCourse.sSession[0].tTimeEnd.min = -1;
                    cCourse.sSession[0].sTime = "";
                    cCourse.sSession[1].weekday = "";
                    cCourse.sSession[1].tTimeStart.hour = -1;
                    cCourse.sSession[1].tTimeStart.min = -1;
                    cCourse.sSession[1].tTimeEnd.hour = -1;
                    cCourse.sSession[1].tTimeEnd.min = -1;
                    cCourse.sSession[1].sTime = "";
                    menu = 14; // Add a Course Menu
                }
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
                    sStudent.courseView = indexMouse - 1;
                    loadFileCourse(name[indexMouse - 1], cCourse, sStudent);
                    menu = 3;
                }
            }
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(rec_listClass[52].x, rec_listClass[52].y, rec_listClass[52].width, rec_listClass[52].height, GREEN);
    if (indexMouse > 0 && indexMouse < 51)
        DrawRectangle(rec_listClass[indexMouse].x, rec_listClass[indexMouse].y, rec_listClass[indexMouse].width, rec_listClass[indexMouse].height, LIGHTGRAY);
    else
        DrawRectangleLines(rec_listClass[indexMouse].x, rec_listClass[indexMouse].y, rec_listClass[indexMouse].width, rec_listClass[indexMouse].height, BLACK);
    if (ClassOrCourse == 1)
    {
        DrawText("ADD CLASSES", rec_listClass[52].x + 12, rec_listClass[52].y + 8, 27, WHITE);
        DrawText(TextFormat("LIST OF CLASSES"), rec_listClass[0].x + 10, rec_listClass[0].y + 10, 30, BLACK);
    }
    else
    {
        DrawText(TextFormat("LIST OF COURSES"), rec_listClass[0].x + 10, rec_listClass[0].y + 10, 30, BLACK);
        DrawText("ADD COURSES", rec_listClass[52].x + 12, rec_listClass[52].y + 8, 27, WHITE);
    }
    DrawRectangleLines(rec_listClass[0].x, rec_listClass[0].y, rec_listClass[0].width, rec_listClass[0].height, BLACK);
    for (int i = 1; i <= dummy; i++)
    {
        DrawText(name[i - 1].c_str(), rec_listClass[i].x + 10, rec_listClass[i].y + 12, 33, BLACK);
        DrawRectangleLines(rec_listClass[i].x, rec_listClass[i].y, rec_listClass[i].width, rec_listClass[i].height, BLACK);
    }
    DrawText("<<", 15, 280, 50, RED);
    EndDrawing();
}

void viewClassProfileMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, Course &cCourse, short &menu,
                          Rectangle rec_listClass[], node<student> *&pCur, short &ClassOrCourse) // menu = 22
{
    indexMouse = -1;
    if (CheckCollisionPointRec(mousePosition, rec_listClass[51]))
        indexMouse = 51;
    if (ClassOrCourse == 0 && CheckCollisionPointRec(mousePosition, rec_listClass[52]))
        indexMouse = 52;
    for (int i = 0; i <= cCourse.numStudent; i++)
    {
        if (CheckCollisionPointRec(mousePosition, rec_listClass[i]))
            indexMouse = i;
    }
    if (GetMouseWheelMove())
        if ((rec_listClass[cCourse.numStudent].y > GetScreenHeight() - 140 || GetMouseWheelMove() > 0) && (rec_listClass[0].y < 70 || GetMouseWheelMove() < 0))
        {
            for (int i = 0; i <= cCourse.numStudent; i++)
                rec_listClass[i].y += GetMouseWheelMove() * 20;
        }

    if (IsMouseButtonPressed(0))
    {
        if (indexMouse == 51)
        {
            for (int i = 0; i < 50; i++)
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
            rec_listClass[52].width = 180;
            rec_listClass[52].height = 40;
            if (ClassOrCourse == 1)
            {
                deleteListStudent(cCourse.nStudentHead, cCourse.numStudent + 1);
                menu = 21;
            }
            else
                menu = 3;
        }
        if (indexMouse == 52)
            menu = 12;
        if (ClassOrCourse != 1 && CheckCollisionPointRec(mousePosition, { rec_listClass[52].x + 490, rec_listClass[52].y, rec_listClass[52].width, rec_listClass[52].height }))
            menu = 40;
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
        for (int i = 0; i <= cCourse.numStudent && pCur; i++)
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
    else
    {
        DrawRectangle(rec_listClass[52].x, rec_listClass[52].y, rec_listClass[52].width, rec_listClass[52].height, GREEN);
        DrawText("Add result", rec_listClass[52].x + 10, rec_listClass[52].y + 10, 25, WHITE);
        DrawRectangle(rec_listClass[52].x + 490, rec_listClass[52].y, rec_listClass[52].width, rec_listClass[52].height, GREEN);
        DrawText("Export File", rec_listClass[52].x + 500, rec_listClass[52].y + 10, 25, WHITE);
        DrawText("Class", 75, rec_listClass[0].y + 12, 25, BLACK);
        DrawText("ID", 700, rec_listClass[0].y + 12, 25, BLACK);
        for (int i = 1; i <= cCourse.numStudent && pCur; i++)
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

void exportFileMenu(Vector2& mousePosition, Vector2& touchPosition, short& indexMouse, short& indexTouch, student& sStudent,
    Course& cCourse, short& menu, Rectangle rec_exportFile[], char path[], short& pathCount, short& ClassOrCourse)
{
    if (CheckCollisionPointRec(mousePosition, rec_exportFile[0]))
        indexMouse = 0;
    else if (CheckCollisionPointRec(mousePosition, rec_exportFile[1]))
        indexMouse = 1;
    else if (CheckCollisionPointRec(mousePosition, rec_exportFile[2]))
        indexMouse = 2;
    else indexMouse = -1;
    if (IsMouseButtonPressed(0))
    {
        if (indexMouse == 0)
            indexTouch = 0;
        else indexTouch = -1;
        
        if (indexMouse == 1)
        {
            ofstream fout;
            string s = path;
            if (ClassOrCourse == 1)
            {
                menu = 12;
                fout.open(s + "classname.csv");
                fout << "NumberOfStudent: " << endl;
                fout << "ID,Full name,Gender,Date Of Birth,Email" << endl;
            }
            else
            {
                menu = 22;
                fout.open(s + cCourse.ID + ".csv");
                fout << "Class,ID,Quiz,Lab,Midterm,Finalterm,Average,Type" << endl;
                node<student>* pCur = cCourse.nStudentHead;
                for (int i = 0;i < cCourse.numStudent;i++)
                    fout << pCur->data.Class << "," << pCur->data.id << endl;
            }
            fout.close();
            indexTouch = -1;
            pathCount = 0;
            path[0] = '\0';
        }
        if (indexMouse == 2)
        {
            indexTouch = -1;
            pathCount = 0;
            path[0] = '\0';
            if (ClassOrCourse == 1)
                menu = 12;
            else menu = 22;
        }
    }if (indexTouch == 0)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125))
            {
                path[pathCount] = (char)key;
                path[pathCount + 1] = '\0';
                pathCount++;
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            pathCount--;
            if (pathCount < 0)
                pathCount = 0;
            path[pathCount] = '\0';
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (indexMouse > 0)
        DrawRectangleLines(rec_exportFile[indexMouse].x, rec_exportFile[indexMouse].y, rec_exportFile[indexMouse].width, rec_exportFile[indexMouse].height, BLACK);
    if (indexMouse == 0 || indexTouch == 0)
        DrawRectangleLines(rec_exportFile[0].x, rec_exportFile[0].y, rec_exportFile[0].width, rec_exportFile[0].height, GREEN);
    else
        DrawRectangleLines(rec_exportFile[0].x, rec_exportFile[0].y, rec_exportFile[0].width, rec_exportFile[0].height, BLACK);
    DrawRectangle(rec_exportFile[1].x, rec_exportFile[1].y, rec_exportFile[1].width, rec_exportFile[1].height, GREEN);
    DrawText(" EXPORT", rec_exportFile[1].x + 15, rec_exportFile[1].y + 12, 40, WHITE);
    DrawText("ENTER FILE PATH (Ex: C:\\User\\Desktop\\...)", rec_exportFile[0].x + 20, rec_exportFile[0].y - 60, 25, BLACK);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    DrawText(path, rec_exportFile[0].x + 15, rec_exportFile[0].y + 15, 30, DARKBLUE);
    EndDrawing();
}

void addCourseMenu(Vector2& mousePosition, Vector2& touchPosition, student& sStudent, Course& cCourse, short& indexMouse, short& indexTouch,
    short& menu, Rectangle rec_addCourseMenu[], string name[], bool isChosen[], int& dummy, short& ClassOrCourse, string& dateInput)
{
    
    indexMouse = -1;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText(("ADD A COURSE TO " + sStudent.semeter + ", " + sStudent.schoolYear).c_str(), 100, 50, 50, BLUE);
    DrawText("Course Name: ", 100, 150, 30, BLACK);
    DrawText(cCourse.name.c_str(), 350, 150, 30, BLACK);
    DrawText("Course ID: ", 100, 200, 30, BLACK);
    DrawText(cCourse.ID.c_str(), 350, 200, 30, BLACK);
    DrawText("Course Lecturer: ", 100, 250, 30, BLACK);
    DrawText(cCourse.lecturer.c_str(), 420, 250, 30, BLACK);
    DrawText("Start Date:       /       /               End Date:       /       /", 100, 300, 30, BLACK);
    if (cCourse.startDay.day >= 0)
        DrawText(to_string(cCourse.startDay.day).c_str(), 300, 300, 30, BLACK);
    if (cCourse.startDay.month >= 0)
        DrawText(to_string(cCourse.startDay.month).c_str(), 395, 300, 30, BLACK);
    if (cCourse.startDay.year >= 0)
        DrawText(to_string(cCourse.startDay.year).c_str(), 515, 300, 30, BLACK);
    if (cCourse.endDay.day >= 0)
        DrawText(to_string(cCourse.endDay.day).c_str(), 825, 300, 30, BLACK);
    if (cCourse.endDay.month >= 0)
        DrawText(to_string(cCourse.endDay.month).c_str(), 935, 300, 30, BLACK);
    if (cCourse.endDay.year >= 0)
        DrawText(to_string(cCourse.endDay.year).c_str(), 1045, 300, 30, BLACK);
    DrawText("Session 1:                Time:       :        to         :       ", 100, 350, 30, BLACK);
    DrawText(cCourse.sSession[0].weekday.c_str(), 265, 350, 30, BLACK);
    if (cCourse.sSession[0].tTimeStart.hour > 0)
        DrawText(to_string(cCourse.sSession[0].tTimeStart.hour).c_str(), 515, 350, 30, BLACK);
    if (cCourse.sSession[0].tTimeStart.min > 0)
        DrawText(to_string(cCourse.sSession[0].tTimeStart.min).c_str(), 615, 350, 30, BLACK);
    if (cCourse.sSession[0].tTimeEnd.hour > 0)
        DrawText(to_string(cCourse.sSession[0].tTimeEnd.hour).c_str(), 755, 350, 30, BLACK);
    if (cCourse.sSession[0].tTimeEnd.min > 0)
        DrawText(to_string(cCourse.sSession[0].tTimeEnd.min).c_str(), 855, 350, 30, BLACK);

    DrawText("Session 2:               Time:       :        to         :       ", 100, 400, 30, BLACK);
    DrawText(cCourse.sSession[1].weekday.c_str(), 265, 400, 30, BLACK);
    if (cCourse.sSession[1].tTimeStart.hour > 0)
        DrawText(to_string(cCourse.sSession[1].tTimeStart.hour).c_str(), 515, 400, 30, BLACK);
    if (cCourse.sSession[1].tTimeStart.min > 0)
        DrawText(to_string(cCourse.sSession[1].tTimeStart.min).c_str(), 615, 400, 30, BLACK);
    if (cCourse.sSession[1].tTimeEnd.hour > 0)
        DrawText(to_string(cCourse.sSession[1].tTimeEnd.hour).c_str(), 755, 400, 30, BLACK);
    if (cCourse.sSession[1].tTimeEnd.min > 0)
        DrawText(to_string(cCourse.sSession[1].tTimeEnd.min).c_str(), 855, 400, 30, BLACK);
    DrawText("Max Students: ", 100, 450, 30, BLACK);
    DrawText(to_string(cCourse.maxStudent).c_str(), 335, 450, 30, BLACK);
    DrawText("Classes Allowed: ", 100, 500, 30, BLACK);
    DrawText("FINISH", 547, 553, 40, GREEN);
    DrawText("Edit", 475, 497, 40, DARKGRAY);
    DrawText("<<", 15, 280, 50, RED);

    for (int i = 0; i < 20; i++)
    {
        DrawRectangleLines(rec_addCourseMenu[i].x, rec_addCourseMenu[i].y, rec_addCourseMenu[i].width, rec_addCourseMenu[i].height, BLACK);
    }
    DrawRectangleLines(rec_addCourseMenu[21].x, rec_addCourseMenu[21].y, rec_addCourseMenu[21].width, rec_addCourseMenu[21].height, GREEN);
    DrawRectangleLines(rec_addCourseMenu[22].x, rec_addCourseMenu[22].y, rec_addCourseMenu[22].width, rec_addCourseMenu[22].height, DARKGRAY);

    for (int i = 0; i < 23; i++)
        if (CheckCollisionPointRec(mousePosition, rec_addCourseMenu[i]))
        {
            if (i < 20)
                SetMouseCursor(2);
            indexMouse = i;
        }


    switch (indexMouse)
    {
    case 21: // FINISH 
        DrawRectangleRec(rec_addCourseMenu[21], GREEN);
        DrawText("FINISH", 547, 553, 40, WHITE);
        break;
    case 20:// BACK
        DrawRectangleLines(rec_addCourseMenu[20].x, rec_addCourseMenu[20].y, rec_addCourseMenu[20].width, rec_addCourseMenu[20].width, RED);
        break;
    case 22:
        DrawRectangleRec(rec_addCourseMenu[22], DARKGRAY);
        DrawText("Edit", 475, 497, 40, WHITE);
        break;
    default:
        break;
    }
    

    if (IsMouseButtonPressed(0))
    {
        if (indexMouse != indexTouch) // Reset input string
            dateInput.clear();
        switch (indexMouse)
        {
        case 20: // BACK
        {
            menu = 21;
            // RESET DATA
            for (int i = 0; i < dummy; i++)
            {
                name[i] = "";
                isChosen[i] = false;
            }

            ifstream fin;
            fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/Courses.txt");
            fin >> dummy;
            fin.get();
            for (int i = 0; i < dummy; i++)
                getline(fin, name[i], '\n');
            fin.close();

            dateInput = "";
            cCourse.ID = "";
            cCourse.name = "";
            cCourse.lecturer = "";
            cCourse.maxStudent = 0;
            cCourse.startDay.day = -1;
            cCourse.startDay.month = -1;
            cCourse.startDay.year = -1;
            cCourse.endDay.day = -1;
            cCourse.endDay.month = -1;
            cCourse.endDay.year = -1;
            cCourse.sDay = "";
            cCourse.sSession[0].weekday = "";
            cCourse.sSession[0].tTimeStart.hour = -1;
            cCourse.sSession[0].tTimeStart.min = -1;
            cCourse.sSession[0].tTimeEnd.hour = -1;
            cCourse.sSession[0].tTimeEnd.min = -1;
            cCourse.sSession[0].sTime = "";
            cCourse.sSession[1].weekday = "";
            cCourse.sSession[1].tTimeStart.hour = -1;
            cCourse.sSession[1].tTimeStart.min = -1;
            cCourse.sSession[1].tTimeEnd.hour = -1;
            cCourse.sSession[1].tTimeEnd.min = -1;
            cCourse.sSession[1].sTime = "";
            break;
        }
        case 21: // FINISH
        {
            ofstream fout;
            fout.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/" + cCourse.ID + ".txt");
            fout << cCourse.name << endl;
            fout << cCourse.lecturer << endl;
            cCourse.getSDay();
            fout << cCourse.sDay << "\n";
            cCourse.sSession[0].getSTime();
            cCourse.sSession[1].getSTime();
            fout << cCourse.sSession[0].sTime << endl;
            fout << cCourse.sSession[1].sTime << endl;
            cCourse.classAllowed = 0;
            for (int i = 0;i < dummy;i++)
                if (isChosen[i])
                    cCourse.classAllowed++;
            fout << cCourse.classAllowed << endl;
            for (int i = 0;i < dummy;i++)
                if (isChosen[i])
                    fout << name[i] << endl;
            fout << cCourse.maxStudent << endl
                << 0 << endl;
            fout.close();
            for (int i = 0; i < dummy; i++)
                if (isChosen[i])
                {
                    string filename = "../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/CourseOf" + name[i] + ".csv";
                    ifstream fin(filename);
                    string temp1[5], temp2[5];
                    getline(fin, temp1[0], ',');
                    for (int j = 0; j < 5; j++)
                    {
                        if (j == 4) getline(fin, temp1[j], '\n');
                        else getline(fin, temp1[j], ',');
                        if (temp1[j] == "none")
                        {
                            temp1[j] = cCourse.ID;
                            break;
                        }
                    }
                    if (temp1[4] == "") getline(fin, temp2[0], '\n');
                    getline(fin, temp2[0], ',');
                    for (int j = 0;j < 5;j++)
                    {
                        if (j == 4) getline(fin, temp2[j], '\n');
                        else getline(fin, temp2[j], ',');
                        if (temp2[j] == "none")
                        {
                            temp2[j] = cCourse.name;
                            break;
                        }
                    }
                    fin.close();
                    ofstream fout(filename);
                    fout << "ID,";
                    for (int j = 0; j < 4; j++)
                        if (temp1[j] != "")
                            fout << temp1[j] << ",";
                        else
                            fout << "none,";
                    if (temp1[4] != "")
                        fout << temp1[4] << "\nID,";
                    else
                        fout << "none\nID,";

                    for (int j = 0; j < 4; j++)
                        if (temp2[j] != "")
                            fout << temp2[j] << ",";
                        else
                            fout << "none,";
                    if (temp2[4] != "")
                        fout << temp2[4] << "\n";
                    else
                        fout << "none\n";
                    fout.close();
                }
            menu = 21;
            // RESET DATA
            for (int i = 0; i < dummy; i++)
            {
                name[i] = "";
                isChosen[i] = false;
            }
            ifstream fin;
            fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/Courses.txt");
            fin >> dummy;
            fin.get();
            for (int i = 0; i < dummy; i++)
                getline(fin, name[i], '\n');
            fin.close();

            name[dummy] = cCourse.ID;
            dummy++;
            fout.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/Courses.txt");
            fout << dummy << endl;
            for (int i = 0;i < dummy;i++)
                fout << name[i] << endl;
            fout.close();

            fin.open("../data/" + sStudent.schoolYear + "/" + sStudent.semeter + "/Courses.txt");
            fin >> dummy;
            fin.get();
            for (int i = 0; i < dummy; i++)
                getline(fin, name[i], '\n');
            fin.close();

            dateInput = "";
            cCourse.ID = "";
            cCourse.name = "";
            cCourse.lecturer = "";
            cCourse.maxStudent = 0;
            cCourse.startDay.day = -1;
            cCourse.startDay.month = -1;
            cCourse.startDay.year = -1;
            cCourse.endDay.day = -1;
            cCourse.endDay.month = -1;
            cCourse.endDay.year = -1;
            cCourse.sDay = "";
            cCourse.sSession[0].weekday = "";
            cCourse.sSession[0].tTimeStart.hour = -1;
            cCourse.sSession[0].tTimeStart.min = -1;
            cCourse.sSession[0].tTimeEnd.hour = -1;
            cCourse.sSession[0].tTimeEnd.min = -1;
            cCourse.sSession[0].sTime = "";
            cCourse.sSession[1].weekday = "";
            cCourse.sSession[1].tTimeStart.hour = -1;
            cCourse.sSession[1].tTimeStart.min = -1;
            cCourse.sSession[1].tTimeEnd.hour = -1;
            cCourse.sSession[1].tTimeEnd.min = -1;
            cCourse.sSession[1].sTime = "";
            break;
        }
            
        case 22: // EDIT
        {
            menu = 15;
            ifstream fin("../data/" + sStudent.schoolYear + "/Classes.txt");
            fin >> dummy;
            fin.get();
            for (int i = 0; i < dummy; i++)
                getline(fin, name[i]);
            fin.close();
            break;
        }
        default:
            if (indexMouse < 20)
                indexTouch = indexMouse;
            break;
        }
    }
    int key = -1;
    if (indexTouch >= 0 && indexTouch < 20)
        DrawRectangleLines(rec_addCourseMenu[indexTouch].x, rec_addCourseMenu[indexTouch].y, rec_addCourseMenu[indexTouch].width, rec_addCourseMenu[indexTouch].height, GREEN);
    switch (indexTouch)
    {
    // the cout commands are for debugging
    case 0: // Course Name
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125))
            {
                cCourse.name += (char)key;
            }
            cout << cCourse.name << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!cCourse.name.empty()))
        {
                cCourse.name.pop_back();
                cout << cCourse.name << endl;
        }
        break;
    case 1: // Course ID
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125))
            {
                cCourse.ID += (char)key;
            }
            key = GetCharPressed();
            cout << cCourse.ID << endl;
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!cCourse.ID.empty()))
        {
            cCourse.ID.pop_back();
            cout << cCourse.ID << endl;
        }
        break;
    case 2: // Course lecturer
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125))
            {
                cCourse.lecturer += (char)key;
            }
            key = GetCharPressed();
            cout << cCourse.lecturer << endl;
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!cCourse.lecturer.empty()))
        {
            cCourse.lecturer.pop_back();
            cout << cCourse.lecturer << endl;
        }
        break;
    case 3: // Course startDay day
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.startDay.day = stoi(dateInput);
            }
            cout << cCourse.startDay.day << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.startDay.day = stoi(dateInput);
            else
                cCourse.startDay.day = -1;
            cout << cCourse.startDay.day << endl;
        }
        break;
    case 4: // Course startDay month
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.startDay.month = stoi(dateInput);
            }
            cout << cCourse.startDay.month << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.startDay.month = stoi(dateInput);
            else
                cCourse.startDay.month = -1;
            cout << cCourse.startDay.month << endl;
        }
        break;
    case 5: // Course startDay Year
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.startDay.year = stoi(dateInput);
            }
            cout << cCourse.startDay.year << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.startDay.year = stoi(dateInput);
            else
                cCourse.startDay.year = -1;
            cout << cCourse.startDay.year << endl;
        }
        break;
    case 6: // Course endDay day
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.endDay.day = stoi(dateInput);
            }
            cout << cCourse.endDay.day << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.endDay.day = stoi(dateInput);
            else
                cCourse.endDay.day = -1;
            cout << cCourse.endDay.day << endl;
        }
        break;
    case 7: // Course endDay month
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.endDay.month = stoi(dateInput);
            }
            cout << cCourse.endDay.month << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.endDay.month = stoi(dateInput);
            else
                cCourse.endDay.month = -1;
            cout << cCourse.endDay.month << endl;
        }
        break;
    case 8: // Course endDay Year
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.endDay.year = stoi(dateInput);
            }
            cout << cCourse.endDay.year << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.endDay.year = stoi(dateInput);
            else
                cCourse.endDay.year = -1;
            cout << cCourse.endDay.year << endl;
        }
        break;
    case 9: // Course 1stSession weekday
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125))
            {
                cCourse.sSession[0].weekday += (char)key;
            }
            cout << cCourse.sSession[0].weekday << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!cCourse.sSession[0].weekday.empty()))
        {
            cCourse.sSession[0].weekday.pop_back();
            cout << cCourse.sSession[0].weekday << endl;
        }
        break;
    case 10: // Course 1stSession startTime hour
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.sSession[0].tTimeStart.hour = stoi(dateInput);
            }
            cout << cCourse.sSession[0].tTimeStart.hour << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.sSession[0].tTimeStart.hour = stoi(dateInput);
            else
                cCourse.sSession[0].tTimeStart.hour = -1;
            cout << cCourse.sSession[0].tTimeStart.hour << endl;
        }
        break;
    case 11: // Course 1stSession startTime min
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.sSession[0].tTimeStart.min = stoi(dateInput);
            }
            cout << cCourse.sSession[0].tTimeStart.min << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.sSession[0].tTimeStart.min = stoi(dateInput);
            else
                cCourse.sSession[0].tTimeStart.min = -1;
            cout << cCourse.sSession[0].tTimeStart.min << endl;
        }
        break;
    case 12: // Course 1stSession endTime hour
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.sSession[0].tTimeEnd.hour = stoi(dateInput);
            }
            cout << cCourse.sSession[0].tTimeEnd.hour << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.sSession[0].tTimeEnd.hour = stoi(dateInput);
            else
                cCourse.sSession[0].tTimeEnd.hour = -1;
            cout << cCourse.sSession[0].tTimeEnd.hour << endl;
        }
        break;
    case 13: // Course 1stSession endTime min
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.sSession[0].tTimeEnd.min = stoi(dateInput);
            }
            cout << cCourse.sSession[0].tTimeEnd.min << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.sSession[0].tTimeEnd.min = stoi(dateInput);
            else
                cCourse.sSession[0].tTimeEnd.min = -1;
            cout << cCourse.sSession[0].tTimeEnd.min << endl;
        }
        break;
    case 14: // Course 2ndSession weekday
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125))
            {
                cCourse.sSession[1].weekday += (char)key;
            }
            cout << cCourse.sSession[1].weekday << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!cCourse.sSession[1].weekday.empty()))
        {
            cCourse.sSession[1].weekday.pop_back();
            cout << cCourse.sSession[1].weekday << endl;
        }
        break;
    case 15: // Course 2ndSession startTime hour
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.sSession[1].tTimeStart.hour = stoi(dateInput);
            }
            cout << cCourse.sSession[1].tTimeStart.hour << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.sSession[1].tTimeStart.hour = stoi(dateInput);
            else
                cCourse.sSession[1].tTimeStart.hour = -1;
            cout << cCourse.sSession[1].tTimeStart.hour << endl;
        }
        break;
    case 16: // Course 2ndSession startTime min
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.sSession[1].tTimeStart.min = stoi(dateInput);
            }
            cout << cCourse.sSession[1].tTimeStart.min << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.sSession[1].tTimeStart.min = stoi(dateInput);
            else
                cCourse.sSession[1].tTimeStart.min = -1;
            cout << cCourse.sSession[1].tTimeStart.min << endl;
        }
        break;
    case 17: // Course 2ndSession endTime hour
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.sSession[1].tTimeEnd.hour = stoi(dateInput);
            }
            cout << cCourse.sSession[1].tTimeEnd.hour << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.sSession[1].tTimeEnd.hour = stoi(dateInput);
            else
                cCourse.sSession[1].tTimeEnd.hour = -1;
            cout << cCourse.sSession[1].tTimeEnd.hour << endl;
        }
        break;
    case 18: // Course 2ndSession endTime min
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.sSession[1].tTimeEnd.min = stoi(dateInput);
            }
            cout << cCourse.sSession[1].tTimeEnd.min << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.sSession[1].tTimeEnd.min = stoi(dateInput);
            else
                cCourse.sSession[1].tTimeEnd.min = -1;
            cout << cCourse.sSession[1].tTimeEnd.min << endl;
        }
        break;
    case 19: // Course 2ndSession endTime min
        key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 48) && (key <= 57))
            {
                dateInput += (char)key;
                cCourse.maxStudent = stoi(dateInput);
            }
            cout << cCourse.maxStudent << endl;
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && (!dateInput.empty()))
        {
            dateInput.pop_back();
            if (!dateInput.empty())
                cCourse.maxStudent = stoi(dateInput);
            else
                cCourse.maxStudent = 0;
            cout << cCourse.maxStudent << endl;
        }
        break;
    default:
        break;
    }
    EndDrawing();
}
void chooseClass(Vector2& mousePosition, Vector2& touchPosition, student& sStudent, Course& cCourse, short& indexMouse, short& indexTouch,
    short& menu, Rectangle rec_chooseClass[], string name[], bool isChosen[], int& dummy, short& ClassOrCourse, string& dateInput)
{

    indexMouse = -1;
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (int i = 0; i < dummy; i++)
    {
        if (!name[i].empty())
        {
            DrawRectangleLines(rec_chooseClass[i].x, rec_chooseClass[i].y, rec_chooseClass[i].width, rec_chooseClass[i].height, BLACK);
            DrawText(name[i].c_str(), rec_chooseClass[i].x + 5, rec_chooseClass[i].y + 5, 30, BLACK);
        }
    }
    DrawText("<<", 15, 280, 50, RED);
    for (int i = 0; i < dummy; i++)
    {
        if (CheckCollisionPointRec(mousePosition, rec_chooseClass[i]))
            indexMouse = i;
        if (isChosen[i])
        {
            DrawRectangleRec(rec_chooseClass[i], ORANGE);
            DrawText(name[i].c_str(), rec_chooseClass[i].x + 5, rec_chooseClass[i].y + 5, 30, BLACK);
        }
    }
    if (indexMouse >= 0 && indexMouse < 16)
    {
        DrawRectangleRec(rec_chooseClass[indexMouse], GRAY);
        DrawText(name[indexMouse].c_str(), rec_chooseClass[indexMouse].x + 5, rec_chooseClass[indexMouse].y + 5, 30, WHITE);
    }
    if (CheckCollisionPointRec(mousePosition, rec_chooseClass[15]))
        DrawRectangleLines(rec_chooseClass[15].x, rec_chooseClass[15].y, rec_chooseClass[15].width, rec_chooseClass[15].height, RED);

    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(mousePosition, rec_chooseClass[15]))
            menu = 14;
        else
        {
            if (isChosen[indexMouse] == false)
                isChosen[indexMouse] = true;
            else
                isChosen[indexMouse] = false;
        }

    }
    EndDrawing();
}