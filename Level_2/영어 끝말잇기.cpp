#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, bool> list;
    for(int turn = 0; turn < words.size(); ++turn) {
        bool ok = true;
        // 첫 순서는 통과
        if(turn == 0) {
            list[words[turn]] = true;
            continue;
        }
        // 이전에 사용한 단어라면
        if(list.find(words[turn]) != list.end())
            ok = false;
        // 앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말하지 않은 경우
        if(words[turn-1][words[turn-1].size()-1] != words[turn][0])
            ok = false;
        if(!ok) return { turn % n + 1, turn / n + 1};
        list[words[turn]] = true;
    }
    return { 0, 0 };
}
