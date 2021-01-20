#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getSet(string str) {
    vector<string> ret;
    for(int i = 0; i < str.size()-1; ++i) {
        char l = str[i], r = str[i+1];
        if(l < 'a' || l > 'z' || r < 'a' || r > 'z') continue;
        ret.push_back(string(1, l) + string(1, r));
    }
    return ret;
}

int solution(string str1, string str2) {
    // 모두 소문자로 변경
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    // 각 중복집합 생성
    vector<string> v1 = getSet(str1);
    vector<string> v2 = getSet(str2);
    
    // 자카드 유사도 계산
    if (v1.size() == 0 && v2.size() == 0) 
        return 65536;

	int all = v1.size() + v2.size(); 
    int dup = 0;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j]) {
				dup++; v2.erase(v2.begin() + j); break;
			}
		}
	}

	all -= dup;
	float answer = ((float)dup / (float)all) * 65536;
    return (int)answer;
}
