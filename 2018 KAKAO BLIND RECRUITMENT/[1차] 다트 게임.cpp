#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string strNum;
    int num;
    vector<int> scores;
    bool ok = false;
    for(int i = 0; i < dartResult.length(); ++i) {
        if(dartResult[i] >= '0' && dartResult[i] <= '9') {
            if(i != 0 && !ok) scores.push_back(num);
            if(!ok) strNum = string(1, dartResult[i]);
            else strNum += string(1, dartResult[i]);
            num = stoi(strNum);  
            ok = true;
            continue;
        }
        else if(dartResult[i] == 'S')
            num = pow(num, 1);
        else if(dartResult[i] == 'D')
            num = pow(num, 2);
        else if(dartResult[i] == 'T') 
            num = pow(num, 3);
        else if(dartResult[i] == '*') {
            num *= 2;
            if(scores.size())
                scores[scores.size()-1] *= 2;
        }
        else if(dartResult[i] == '#')
            num *= (-1);
        ok = false;
    }
    scores.push_back(num);
    for(int i = 0; i < scores.size(); ++i)
        answer += scores[i];
    return answer;
}
