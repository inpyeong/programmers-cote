#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> month(13, 0);
    for(int i = 1; i <= 12; ++i) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            month[i] = 31;
        else if (i == 2) month[i] = 29;
        else month[i] = 30;
    }
    int days = 0;
    for(int i = 1; i < a; ++i)
        days += month[i];
    days += b-1;
    int check = days % 7;
    if(check == 0) return "FRI";
    if(check == 1) return "SAT";
    if(check == 2) return "SUN";
    if(check == 3) return "MON";
    if(check == 4) return "TUE";
    if(check == 5) return "WED";
    if(check == 6) return "THU";
}
