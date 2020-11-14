#include <vector>
#include <algorithm>

using namespace std;
 
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    sort(dist.begin(), dist.end());
    
    // 원형탐색 weak.size()만큼 반복
    for (int i = 0; i < weak.size(); i++) {
        // 취약지점 순환
        int tmp = weak[0] + n;
        for (int j = 1; j < weak.size(); j++) 
            weak[j - 1] = weak[j];
        weak[weak.size() - 1] = tmp;
 
        // 친구들 배치
        do {
            // w : 취약지점 index, d : 친구들 index
            int w = 0, d;
 			bool ok = false;
            // 친구 한명이 갈 수 있는 취약지점 까지 모두 탐색
            for (d = 0; d < dist.size() && !ok; d++) {
                int fin = weak[w] + dist[d];
                while (fin >= weak[w] && !ok) {
                    w++;
                    if (w == weak.size())
                        ok = true;
                }
            }
            // 모든 취약지점이 탐색 되었다면, 가장 적게 친구를 사용한 결과 저장
            if (w == weak.size()) 
                if (answer == -1 || d < answer) 
                    answer = d;
        } while (next_permutation(dist.begin(), dist.end()));
    }
    return answer;
}
