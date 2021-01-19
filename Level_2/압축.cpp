#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    map<string, int>::iterator iter;
    int dictNum;
    for(dictNum = 1; dictNum < 27; ++dictNum)
        dict[string(1, 'A' + dictNum - 1)] = dictNum;
    for(int i = 0; i < msg.size(); ++i) {
        int j = i;
        string tmp = "";
        for(; j < msg.size(); ++j) {
            // 길이가 1인 단어를 하나씩 추가하면서 사전에 등록된 단어인지 확인
            tmp += msg[j];
            iter = dict.find(tmp);
            // 사전에 등록된 글자가 아니면,
            if(iter == dict.end()) {
                // 이전에 확인한 사전에 등록된 글자의 번호는 answer에 추가
                answer.push_back(dict[tmp.substr(0, tmp.size()-1)]);
                // 사전에 등록되지 않은 글자 등록
                dict[tmp] = dictNum++;
                break;
            }
            // 메시지의 남은 글자가 등록되어 있을 경우,
            if(j == msg.size() - 1)
                answer.push_back(dict[tmp]);
        }
        i = j - 1;
    }
    return answer;
}
