#include <bits/stdc++.h>
#include "user.h"
using namespace std;
const int maxNum = 50;
struct Session{
    string weekday;
    Time time;
};
struct course{
    string ID;
    string name;
    staff teacher;
    Session session;
    Date startday, endday;
    // student List...

};
