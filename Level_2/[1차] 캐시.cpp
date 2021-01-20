#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return 5 * cities.size();
    int answer = 0;
    // 모든 도시이름 소문자로 변경
    for(int i = 0; i < cities.size(); ++i)
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    
    vector<pair<int, string> > cache(cacheSize, make_pair(-1, ""));
    for(int i = 0; i < cities.size(); ++i) {
        bool flag = false;
        for(int j = 0; j < cache.size(); ++j) {
            // 만약 cache hit일 경우,
            if(cache[j].second == cities[i]) {
                answer += 1;
                cache[j].first = i;
                flag = true;
                break;
            }
        }
        // 만약 cache miss일 경우,
        if(!flag) {
            answer += 5;
            cache[0].first = i;
            cache[0].second = cities[i];
        }
        sort(cache.begin(), cache.end());
    }
    return answer;
}
