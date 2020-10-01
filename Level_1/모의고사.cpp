#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    int p1Cnt = 0, p1Ans[5] = { 1, 2, 3, 4, 5 };
    int p2Cnt = 0, p2Ans[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int p3Cnt = 0, p3Ans[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    for(int i = 0; i < answers.size(); ++i) {
       if(answers[i] == p1Ans[i%5]) ++p1Cnt;
       if(answers[i] == p2Ans[i%8]) ++p2Cnt;
       if(answers[i] == p3Ans[i%10]) ++p3Cnt;
    }
    
    vector<int> answer;
    if(p1Cnt == p2Cnt && p1Cnt == p3Cnt) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(p1Cnt == p2Cnt && p1Cnt > p3Cnt) {
        answer.push_back(1);
        answer.push_back(2);
    }
    else if(p2Cnt == p3Cnt && p2Cnt > p1Cnt) {
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(p1Cnt == p3Cnt && p1Cnt > p2Cnt) {
        answer.push_back(1);
        answer.push_back(3);
    }
    else if(p1Cnt > p2Cnt && p1Cnt > p3Cnt) answer.push_back(1);
    else if(p2Cnt > p1Cnt && p2Cnt > p3Cnt) answer.push_back(2);
    else if(p3Cnt > p1Cnt && p3Cnt > p2Cnt) answer.push_back(3);
    
    return answer;
}
