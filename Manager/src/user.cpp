#include "user.h"
#include "Linkedlist.h"

#include <iostream>

using namespace std;

void studentLogin(student &x)
{
    cout << "ID: ";
    cin >> x.ID;
    cout << "Password: ";
    cin >> x.password;
}
void checkStudentLogin(student &x, Node<student> *&pHead) // lưu danh sách users vô hàm main trước
{
    do
    {
        Node<student> *cur = pHead;
        while (cur != NULL)
        {
            if (cur->data.ID == x.ID && cur->data.password == x.password)
            {
                x.Class = cur->data.Class;
                return;
            }
            cur = cur->next;
        }
        cout << "Ten dang nhap hoac mat khau khong dung!";
        studentLogin(x);
    } while (1);
}
void staffLogin(user &x)
{
    cout << "ID: ";
    cin >> x.ID;
    cout << "Password: ";
    cin >> x.password;
}
void checkStaffLogin(user &x, Node<user> *&pHead) // lưu danh sách users vô hàm main trước
{
    do
    {
        Node<user> *cur = pHead;
        while (cur != NULL)
        {
            if (cur->data.ID == x.ID && cur->data.password == x.password)
                return;
            cur = cur->next;
        }
        cout << "Ten dang nhap hoac mat khau khong dung!";
        staffLogin(x);
    } while (1);
}