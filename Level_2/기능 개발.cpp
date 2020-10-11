#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int numOfFunc = progresses.size();
    queue<pair<int, int> > q;
    for(int i = 0; i < numOfFunc; ++i) {
        pair<int, int> p = make_pair(progresses[i], speeds[i]);
        q.push(p);
    }
    
    int days = 0, totalFinish = 0;
    vector<int> answer;
    while(true) {
        bool check = false;
        int finish = 0;
        days++;
        int sizeOfQueue = q.size();
        for(int i = 0; i < sizeOfQueue; ++i) {
            if(q.front().first + days * q.front().second >= 100) {
                check = true;
                q.pop();
                finish++;
            } 
            else break;
        }
        if(check) {
            answer.push_back(finish);
            totalFinish += finish;
        }
        if(totalFinish == numOfFunc) break;
    }
    return answer;
}
