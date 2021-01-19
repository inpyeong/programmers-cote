#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string trans(int n, int size) {
    string ret = "0";
    int cnt = 1;
    for(int i = 1; ; ++i) {
        int tmpInt = i;
        string tmpStr = "";
        while(tmpInt > 0) {
            int rmd = tmpInt % n;
            if(rmd) {
                if(rmd >= 10) tmpStr += ('A' + rmd - 10);
                else tmpStr += to_string(rmd);
            }
            else tmpStr += '0';
            tmpInt /= n;
        }
        reverse(tmpStr.begin(), tmpStr.end());
        for(char c : tmpStr) {
            ret += c;
            cnt++;
            if(cnt == size) break;
        }
        if(cnt == size) break;
    }
    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string origin = trans(n, t * m);
    cout << origin << endl;
    for(int i = p-1; i < origin.size(); i += m)
        answer += origin[i];
    return answer;
}
