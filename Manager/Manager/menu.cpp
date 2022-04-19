#include "../include/menu.h"
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
    if (indexTouch == 1)
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
              user &uStaff, short role, Rectangle rec_Main[]) // menu = 0
{
    if (role == 0)
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
            if (CheckCollisionPointRec(touchPosition, rec_Main[1]))
                menu = 4; // SchoolYear Student Menu
            if (CheckCollisionPointRec(touchPosition, rec_Main[2]))
                menu = 0;
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
    else if (role == -1)
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
        DrawText("School Year", GetScreenWidth() / 2 - 90, GetScreenHeight() / 2 - 50, 30, BLACK);
        DrawText("View Result", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 0, 30, BLACK);
        DrawText("Log out", GetScreenWidth() / 2 - 62, GetScreenHeight() / 2 + 50, 30, BLACK);
        if (indexMouse >= 0)
            DrawRectangleLines(rec_Main[indexMouse].x, rec_Main[indexMouse].y, rec_Main[indexMouse].width, rec_Main[indexMouse].height, BLACK);
        EndDrawing();
    }
}

void viewProfileMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student sStudent, user uStaff, short &menu, short role,
                     Rectangle rec_Profile, char *ch) // menu = 1
{

    if (CheckCollisionPointRec(mousePosition, rec_Profile))
        indexMouse = 1;
    else
        indexMouse = 0;
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
        ch = (char *)uStaff.id.c_str();
        DrawText(ch, 320, 70, 35, BLACK);
        ch = (char *)uStaff.fullname.c_str();
        DrawText(ch, 320, 130, 35, BLACK);
        ch = (char *)uStaff.gender.c_str();
        DrawText(ch, 320, 190, 35, BLACK);
        ch = (char *)uStaff.sDate.c_str();
        DrawText(ch, 320, 250, 35, BLACK);
        ch = (char *)uStaff.email.c_str();
        DrawText(ch, 320, 310, 35, BLACK);
    }
    if (role == 0)
    {
        ch = (char *)sStudent.schoolYear.c_str();
        DrawText(ch, 70, 30, 30, BLACK);
        ch = (char *)sStudent.id.c_str();
        DrawText(ch, 320, 70, 35, BLACK);
        ch = (char *)sStudent.fullname.c_str();
        DrawText(ch, 320, 130, 35, BLACK);
        ch = (char *)sStudent.gender.c_str();
        DrawText(ch, 320, 190, 35, BLACK);
        ch = (char *)sStudent.sDate.c_str();
        DrawText(ch, 320, 250, 35, BLACK);
        ch = (char *)sStudent.email.c_str();
        DrawText(ch, 320, 310, 35, BLACK);
    }
    EndDrawing();
}

void schoolYearStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu,
                           Rectangle rec_StudentSchoolYear[], int &numSchoolYear) // menu = 4
{
    numSchoolYear = currentSchoolYear - sStudent.firstYear;
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
                         Rectangle rec_StudentSemester[]) // menu = 5
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
        if (CheckCollisionPointRec(touchPosition, rec_StudentSemester[3]))
            menu = 4; // School Year Student Menu
        if (indexMouse >= 0 && indexMouse < 3 && CheckCollisionPointRec(touchPosition, rec_StudentSemester[indexMouse]))
        {
            sStudent.semeter = "HK" + to_string(indexMouse + 1);
            if (checkFileExist(sStudent))
            {
                checkStudentCourse(sStudent);
                menu = 2; // Course Student Menu
            }
            else
                menu = 20;
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

void courseStudentMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, student &sStudent, short &menu, Course &cCourse,
                       Rectangle rec_StudentCourse[], char *ch)
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
        {
            menu = 5; // Semester Student Menu
        }
        if (indexMouse >= 0 && indexMouse <= 4 && CheckCollisionPointRec(touchPosition, rec_StudentCourse[indexMouse]))
        {
            menu = 3; // Detail of Course
            sStudent.courseView = indexMouse;
            loadFileCourse(sStudent.courseID[indexMouse], cCourse, sStudent);
        }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleLines(rec_StudentCourse[indexMouse].x, rec_StudentCourse[indexMouse].y, rec_StudentCourse[indexMouse].width, rec_StudentCourse[indexMouse].height, BLACK);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    ch = (char *)sStudent.nameCourse[0].c_str();
    DrawText(ch, 70, GetScreenHeight() / 2 - 130, 30, BLACK);
    ch = (char *)sStudent.nameCourse[1].c_str();
    DrawText(ch, 70, GetScreenHeight() / 2 - 80, 30, BLACK);
    ch = (char *)sStudent.nameCourse[2].c_str();
    DrawText(ch, 70, GetScreenHeight() / 2 - 30, 30, BLACK);
    ch = (char *)sStudent.nameCourse[3].c_str();
    DrawText(ch, 70, GetScreenHeight() / 2 + 20, 30, BLACK);
    ch = (char *)sStudent.nameCourse[4].c_str();
    DrawText(ch, 70, GetScreenHeight() / 2 + 70, 30, BLACK);

    ch = (char *)sStudent.isRegistered[0].c_str();
    DrawText(ch, GetScreenWidth() - 300, GetScreenHeight() / 2 - 130, 30, BLACK);
    ch = (char *)sStudent.isRegistered[1].c_str();
    DrawText(ch, GetScreenWidth() - 300, GetScreenHeight() / 2 - 80, 30, BLACK);
    ch = (char *)sStudent.isRegistered[2].c_str();
    DrawText(ch, GetScreenWidth() - 300, GetScreenHeight() / 2 - 30, 30, BLACK);
    ch = (char *)sStudent.isRegistered[3].c_str();
    DrawText(ch, GetScreenWidth() - 300, GetScreenHeight() / 2 + 20, 30, BLACK);
    ch = (char *)sStudent.isRegistered[4].c_str();
    DrawText(ch, GetScreenWidth() - 300, GetScreenHeight() / 2 + 70, 30, BLACK);
    EndDrawing();
}

void detailOfCourseMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, Course &cCourse, student &sStudent, short &menu,
                        Rectangle rec_detailOfCourseMenu[], char *ch)
{
    if (CheckCollisionPointRec(mousePosition, rec_detailOfCourseMenu[0]))
        indexMouse = 0;
    else if (CheckCollisionPointRec(mousePosition, rec_detailOfCourseMenu[1]))
        indexMouse = 1;
    else
        indexMouse = -1;

    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(touchPosition, rec_detailOfCourseMenu[1]))
        {
            deleteListStudent(cCourse.nStudentHead, cCourse.numStudent);
            menu = 2; // Student Course Menu
        }
        if (CheckCollisionPointRec(touchPosition, rec_detailOfCourseMenu[0]) && sStudent.isRegistered[sStudent.courseView] == "Not Registered" && cCourse.numStudent < cCourse.maxStudent)
        {
            registerCourse(sStudent, cCourse);
        }
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("ID", 70, 60, 23, BLACK);
    ch = (char *)cCourse.ID.c_str();
    DrawText(ch, 250, 60, 23, BLACK);
    DrawText("Course", 70, 100, 23, BLACK);
    ch = (char *)cCourse.name.c_str();
    DrawText(ch, 250, 100, 23, BLACK);
    DrawText("Lecturer", 70, 140, 23, BLACK);
    ch = (char *)cCourse.lecturer.c_str();
    DrawText(ch, 250, 140, 23, BLACK);
    DrawText("Date", 70, 180, 23, BLACK);
    ch = (char *)cCourse.sDay.c_str();
    DrawText(ch, 250, 180, 23, BLACK);
    DrawText("Timetable", 70, 220, 23, BLACK);
    for (int i = 0; i < 2; i++)
    {
        if (cCourse.sSession[i].weekday != "None")
        {
            ch = (char *)cCourse.sSession[i].weekday.c_str();
            DrawText(ch, 250, 220 + 40 * i, 23, BLACK);
            ch = (char *)cCourse.sSession[i].sTime.c_str();
            DrawText(ch, 310, 220 + 40 * i, 23, BLACK);
        }
    }
    DrawRectangle(rec_detailOfCourseMenu[0].x, rec_detailOfCourseMenu[0].y, rec_detailOfCourseMenu[0].width, rec_detailOfCourseMenu[0].height, LIGHTGRAY);
    DrawText(TextFormat("Registered: %i / %i", cCourse.numStudent, cCourse.maxStudent), 70, 300, 25, BLACK);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    DrawRectangleLines(rec_detailOfCourseMenu[indexMouse].x, rec_detailOfCourseMenu[indexMouse].y, rec_detailOfCourseMenu[indexMouse].width, rec_detailOfCourseMenu[indexMouse].height, BLACK);
    if (sStudent.isRegistered[sStudent.courseView] == "Registered")
        DrawText("REGISTERED", 460, 295, 30, RED);
    else if (sStudent.isRegistered[sStudent.courseView] == "Not Registered" && cCourse.numStudent < cCourse.maxStudent)
        DrawText("  REGISTER", 460, 295, 30, LIME);
    else
        DrawText("     FULL", 460, 295, 30, RED);

    if (cCourse.nStudentHead != nullptr)
    {
        ch = (char *)cCourse.nStudentHead->data.id.c_str();
        DrawText(ch, 10, 10, 25, BLACK);
    }
    EndDrawing();
}

void whiteMenu(Vector2 &mousePosition, Vector2 &touchPosition, short &indexMouse, short &menu, Rectangle rec_white)
{
    if (CheckCollisionPointRec(mousePosition, rec_white))
        indexMouse = 0;
    else
        indexMouse = -1;
    if (IsMouseButtonPressed(0))
    {
        if (CheckCollisionPointRec(touchPosition, rec_white))
            menu = 5; // Semester Student Menu
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("BACK", 45, GetScreenHeight() - 60, 40, RED);
    DrawText("No Course", 530, 300, 40, LIGHTGRAY);
    if (indexMouse == 0)
        DrawRectangleLines(rec_white.x, rec_white.y, rec_white.width, rec_white.height, BLACK);
    EndDrawing();
}