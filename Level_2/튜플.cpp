#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt[100001] = { 0, };
    string tmp;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] >= '0' && s[i] <= '9')
            tmp += s[i];
        else {
            if(tmp.length()) {
                cnt[stoi(tmp)]++;
                tmp.clear();
            }
        }
    }
    vector<pair<int, int> > v;
    for(int i = 0; i < 100001; ++i)
        if(cnt[i]) v.push_back(make_pair(cnt[i], i));
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(auto it : v) answer.push_back(it.second);
    return answer;
}
