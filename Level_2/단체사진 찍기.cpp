#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isOk(int dist, char cmp, int val) {
    if(cmp == '=') return dist == val;
    else if (cmp == '>') return dist > val;
    else if (cmp == '<') return dist < val;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    do {
        bool ok = true;
        for(int i = 0; i < data.size(); ++i) {
            char me = data[i].at(0);
            char you = data[i].at(2);
            char cmp = data[i].at(3);
            int val = data[i].at(4) - '0';
            
            int diff = friends.find(me) - friends.find(you);
            int dist = abs(diff) - 1;
            if(isOk(dist, cmp, val)) continue;
            ok = false;
            break;
        }
        if(ok) answer++;
    } while(next_permutation(friends.begin(), friends.end()));
    return answer;
}

// 원래 내 코드
// #include <iostream>
// #include <string>
// #include <cmath>
// #include <vector>

// using namespace std;

// int answer;

// bool isOk(string str, char a, char b, char op, char value) {
//     int diff = str.find(a) - str.find(b);
//     diff = abs(diff) - 1;
//     if(op == '<' && diff < value - '0') return true;
//     if(op == '>' && diff > value - '0') return true;
//     if(op == '=' && diff == value - '0') return true;
//     return false;
// }

// void dfs(string names, const vector<string>& data, vector<bool>& used, string tmp) {
//     if(tmp.length() == names.length()) {
//         // 조건에 만족하면 카운트
//         bool ok = true;
//         for(int i = 0; i < data.size(); ++i)
//             if(!isOk(tmp, data[i][0], data[i][2], data[i][3], data[i][4])) {
//                 ok = false;
//                 break;
//             }
//         if(ok) answer++;	
//         return;
//     }
//     for(int i = 0; i < names.length(); ++i) {
//         if(used[i]) continue;
//         used[i] = true;
//         tmp += names[i];
//         dfs(names, data, used, tmp);
//         used[i] = false;
//         tmp = tmp.substr(0, tmp.length()-1);
//     }
// }

// int solution(int n, vector<string> data) {
//     string names = "ACFJMNRT";
//     answer = 0;
//     vector<bool> used(names.length(), false);
//     dfs(names, data, used, "");
//     return answer;
// }
