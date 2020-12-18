#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> temp;
    for(int n : numbers)
        temp.push_back(to_string(n));
    sort(temp.begin(), temp.end(), cmp);
    string answer = "";
    for(string t : temp) answer += t;
    if(answer.at(0) == '0') return "0";
    return answer;
}
