#include <bits/stdc++.h>
#include "time.h"
#include "user.h"
#include "course.h"
#include "Linkedlist.h"
using namespace std;
int main(){
    user x;
    dangnhap(x);
    pUserHead = NULL;
    ifstream fin;
    int n;
    fin.open("listofusers.txt");
    fin >> n;
    Nodeuser* cur = pUserHead;
    for (int i = 0; i < n; i ++){
        Nodeuser* tmp = new Nodeuser;
        fin >> tmp->data.ID >> tmp->data.matkhau >> tmp->data.chucvu;
        tmp->next = NULL;
        if (pUserHead == NULL){
            pUserHead = tmp;
            cur = tmp;
        }
        else{
            cur->next = tmp;
            cur = cur->next;
        }
    }
    checkuser(x);
}