#include <bits/stdc++.h>
#include "user.h"
#include "Linkedlist.h"
using namespace std;
void dangnhap(user x)
{
    cout << "Ten dang nhap: ";
    cin >> x.ID;
    cout << "matkhau: ";
    cin >> x.matkhau;
    x.chucvu = -1;
}
void checkuser(user &x)// lưu danh sách users vô hàm main trước
{
    do
    {
        Nodeuser* cur = pUserHead;
        while (cur != NULL){
            if (cur->data.ID == x.ID && cur->data.matkhau == x.matkhau){
                x.chucvu == cur->data.chucvu;
                return;
            }
            cur = cur->next;
        }
        cout << "Ten dang nhap hoac mat khau khong dung!";
        dangnhap(x);
    } while(1);
    
}