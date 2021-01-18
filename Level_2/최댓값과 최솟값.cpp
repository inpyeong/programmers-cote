#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "", num;
    vector<int> v;
    stringstream ss(s);
    while(ss >> num) v.push_back(stoi(num));
    sort(v.begin(), v.end());
    answer += to_string(v[0]) + " " + to_string(v[v.size()-1]);
    return answer;
}
