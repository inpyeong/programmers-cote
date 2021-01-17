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
