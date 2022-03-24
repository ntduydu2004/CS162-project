//#include <bits/stdc++.h>
#include "user.h"
#include "Linkedlist.h"

#include <stdio.h>
#include <iostream>


using namespace std;

void dangnhap(user x)
{
    cout << "Ten dang nhap: ";
    cin >> x.ID;
    cout << "matkhau: ";
    cin >> x.matkhau;
    x.chucvu = -1;
    x.locate = "";
}
void checkuser(user &x, Node <user>* &pHead)// lưu danh sách users vô hàm main trước
{
    do
    {
        Node<user>* cur = pHead;
        while (cur != NULL){
            if (cur->data.ID == x.ID && cur->data.matkhau == x.matkhau){
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
