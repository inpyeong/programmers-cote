#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> m;
    map<string, int>::iterator it;
    for(int i = 0; i < cities.size(); ++i) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        // cache hit
        if(m.find(cities[i]) != m.end()) {
            answer += 1;
            m[cities[i]] = i; 
        }
        // cache miss
        else {
            answer += 5;
            if(m.size() == cacheSize) {
                string key = "";
                int val = 100000;
                for(it = m.begin(); it != m.end(); ++it)
                    if(it->second < val) {
                        val = it->second;
                        key = it->first;
                    }
                m.erase(key);
            }
            if(cacheSize > 0)
                m[cities[i]] = i; 
        }
    }
    return answer;
}
