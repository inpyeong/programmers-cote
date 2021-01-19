#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, bool> wordsList;
    map<string, bool>::iterator iter;
    string beforeWord = "";
    
    vector<int> person(n+1, 0);
    int personIdx = 0;
    bool flag = false;
    for(string word : words) {
        personIdx++;
        if(personIdx > n) personIdx = 1;
        person[personIdx]++;
        
        iter = wordsList.find(word);
        // 사용된 적이 없는 단어라면,
        if(iter == wordsList.end()) {
            // 끝말잇기 규칙에 위배되는 단어를 말한 경우,
            if(beforeWord.size() > 0 && beforeWord[beforeWord.size()-1] != word[0]) {
                flag = true;
                break;
            }
            // 정상적으로 말한 경우,
            wordsList[word] = true;
            beforeWord = word;
        }
        else {
            flag = true;
            break;
        }
    }
    if(flag) answer = { personIdx, person[personIdx] };
    else answer = { 0, 0 };
    return answer;
}
