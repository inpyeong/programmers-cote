#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Developer {
    string lang;
    string group;
    string career;
    string food;
    int score;
};

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> scores[3][2][2][2];
    stringstream ss;
    string lang, group, career, food, scoreStr;
    for(int i = 0; i < info.size(); ++i) {
        int l, g, c, f;
        ss.str(info[i]);
        ss >> lang >> group >> career >> food >> scoreStr;
        if(lang == "cpp") l = 0;
        else if(lang == "java") l = 1;
        else if(lang == "python") l = 2;
        if(group == "backend") g = 0;
        else if(group == "frontend") g = 1;
        if(career == "junior") c = 0;
        else if(career == "senior") c = 1;
        if(food == "chicken") f = 0;
        else if(food == "pizza") f = 1;
        scores[l][g][c][f].push_back(stoi(scoreStr));
        ss.clear();
    }
    for(int i = 0; i < 3; ++i) 
        for(int j = 0; j < 2; ++j) 
            for(int k = 0; k < 2; ++k) 
                for(int l = 0; l < 2; ++l) 
                    sort(scores[i][j][k][l].begin(), scores[i][j][k][l].end());
    for(int i = 0; i < query.size(); ++i) {
        ss.str(query[i]);
        string andStr;
        ss >> lang >> andStr;
        ss >> group >> andStr;
        ss >> career >> andStr;
        ss >> food;
        ss >> scoreStr;
        ss.clear();
        int sl, el, sg, eg, sc, ec, sf, ef;
        if(lang == "cpp") sl = el = 0;
        else if(lang == "java") sl = el = 1;
        else if(lang == "python") sl = el = 2;
        else if(lang == string(1, '-'))
            sl = 0, el = 2;
        if(group == "backend") sg = eg = 0;
        else if(group == "frontend") sg = eg = 1;
        else if(group == string(1, '-'))
            sg = 0, eg = 1;
        if(career == "junior") sc = ec = 0;
        else if(career == "senior") sc = ec = 1;
        else if(career == string(1, '-'))
            sc = 0, ec = 1;
        if(food == "chicken") sf = ef = 0;
        else if(food == "pizza") sf = ef = 1;
        else if(food == string(1, '-'))
            sf = 0, ef = 1;
        
        int ans = 0;
        for(int i = sl; i <= el; ++i)
            for(int j = sg; j <= eg; ++j)
                for(int k = sc; k <= ec; ++k)
                    for(int l = sf; l <= ef; ++l) {
                        int n = scores[i][j][k][l].size();
                        if(n == 0) continue;
                        auto it = lower_bound(scores[i][j][k][l].begin(), scores[i][j][k][l].end(), stoi(scoreStr));
                        ans += (n - (it - scores[i][j][k][l].begin()));
                    }
        answer.push_back(ans);
    }
    return answer;
}
