#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(auto s : scoville)
        pq.push(s);
    while(pq.top() < K) {
        if(pq.size() == 1) return -1;
        int min1 = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        int newScov = min1 + (min2 * 2);
        pq.push(newScov);
        answer++;
    }
    return answer;
}
