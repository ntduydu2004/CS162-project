#include "..\include\user.h"
#include "..\include\Linkedlist.h"

#include <iostream>

using namespace std;

void login(user &x)
{
    cout << "ID: ";
    cin >> x.ID;
    cout << "Password: ";
    cin >> x.password;
}
