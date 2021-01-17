// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool cmp(vector<int>& a, vector<int>& b) {
//     return a.size() < b.size();
// }

// vector<int> solution(string s) {
//     vector<int> answer;
//     vector<vector<int> > v;
//     vector<int> temp;
//     for(int i = 0; i < s.size(); ++i) {
//         if(s[i] == '{') continue;
//         if(s[i] == '}' && i < s.size()-1) {
//             v.push_back(temp);
//             temp.clear();
//             continue;
//         }
//         if(s[i] >= '0' && s[i] <= '9') {
//             string n = "";
//             for(;;i++) {
//                 if(s[i] >= '0' && s[i] <= '9') 
//                     n += s[i];
//                 else break;
//             }
//             temp.push_back(stoi(n));
//             i--;
//         }
//     }
//     sort(v.begin(), v.end(), cmp);
//     answer.push_back(v[0][0]);
//     for(int i = 0; i < v.size()-1; ++i) {
//         int j = i + 1;
//         sort(v[i].begin(), v[i].end());
//         sort(v[j].begin(), v[j].end());
//         bool flag = false;
//         for(int k = 0; k < v[i].size(); ++k)
//             if(v[i][k] != v[j][k]) {
//                 flag = true;
//                 answer.push_back(v[j][k]);
//                 break;
//             }
//         if(!flag) answer.push_back(v[j][v[j].size()-1]);
//     }
//     return answer;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    int st[101010]={};
    vector<int> answer;
    string tmp;
    for(char i: s){
        if(i-'0' >=0 && i-'0' <=9){
            tmp += i;
        }
        else{
            if(tmp.length())
                st[stoi(tmp)]++, tmp.clear();
        }
    }
    vector<pair<int, int>> v;
    for(int i =0; i <101010; i++)
        if(st[i])
            v.push_back({st[i], i});
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    for(auto it: v) answer.push_back(it.second);
    return answer;
}
