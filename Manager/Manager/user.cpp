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
<<<<<<< HEAD:user.cpp
void checkuser(user &x, Node <user>* &pHead)// lưu danh sách users vô hàm main trước
=======
void checkuser(user& x, Node <user>*& pHead)// lưu danh sách users vô hàm main trước
>>>>>>> 7573cc529352ea07d5aaa294b9b918981d5db865:Manager/Manager/user.cpp
{
    do
    {
        Node<user>* cur = pHead;
<<<<<<< HEAD:user.cpp
        while (cur != NULL){
            if (cur->data.ID == x.ID && cur->data.matkhau == x.matkhau){
=======
        while (cur != NULL) {
            if (cur->data.ID == x.ID && cur->data.matkhau == x.matkhau) {
>>>>>>> 7573cc529352ea07d5aaa294b9b918981d5db865:Manager/Manager/user.cpp
                x.chucvu = cur->data.chucvu;
                x.locate = cur->data.locate;
                return;
            }
            cur = cur->next;
        }
        cout << "Ten dang nhap hoac mat khau khong dung!";
        dangnhap(x);
<<<<<<< HEAD:user.cpp
    } while(1);
    
}
=======
    } while (1);

}
>>>>>>> 7573cc529352ea07d5aaa294b9b918981d5db865:Manager/Manager/user.cpp
