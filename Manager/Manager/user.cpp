#include "user.h"
#include "Linkedlist.h"
#include <stdio.h>
#include <iostream>


using namespace std;

void dangnhap(User x)
{
    cout << "Ten dang nhap: ";
    cin >> x.ID;
    cout << "matkhau: ";
    cin >> x.matkhau;
    x.chucvu = -1;
    x.locate = "";
}
void checkuser(User &x, Node <User>* &pHead)// lưu danh sách users vô hàm main trước
{
    do
    {
        Node<User>* cur = pHead;
        while (cur != NULL){
            if (cur->data.getID() == x.getID() && cur->data.getPassword() == x.getPassword()){
                x.chucvu = cur->data.chucvu;
                x.locate = cur->data.locate;
                return;
            }
            cur = cur->next;
        }
        cout << "Ten dang nhap hoac mat khau khong dung!";
        dangnhap(x);
    } while(1);
    
}
