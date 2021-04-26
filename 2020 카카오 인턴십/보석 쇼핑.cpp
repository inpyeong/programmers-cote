#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> answer = {0,0};
map<string, int> m;
queue<string> q;

vector<int> solution(vector<string> gems) {
    for(string gem : gems)
        m[gem] = 1;
    int gemSize = m.size(), start = 0, len = 100000;
	m.clear();    
    for(int i = 0; i < gems.size(); ++i) {
        m[gems[i]]++;
        q.push(gems[i]);
        while(true) {
            if(m[q.front()] > 1) {
                m[q.front()]--;
                q.pop();
                start++;
            }
            else break;
        }
        if(m.size() == gemSize && len > q.size()) {
            len = q.size();
            answer[0] = start+1;
            answer[1] = start+len;
        }
    }
    return answer;
}
