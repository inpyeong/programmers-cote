#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;    
    for(int i = 0; i < skill_trees.size(); ++i) {
        int skillIdx = -1;
        bool check = true;
        for(int j = 0; j < skill_trees[i].size(); ++j) {
            for(int k = 0; k < skill.size(); ++k) {
                if(skill_trees[i].at(j) == skill.at(k)) {
                    if (k - skillIdx != 1) {
                        check = false;
                        break;
                    }
                    else ++skillIdx;
                }
            }
        }
        if(check) ++answer;
    }
    return answer;
}
