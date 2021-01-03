#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, here = 1, index = 0;
    while(here <= n) {
        if(here >= stations[index] - w && here <= stations[index] + w) {
            here = stations[index] + w;
            index++;
        }
        else {
            here += 2 * w;
            answer++;
        }
        here++;
    }
    return answer;
}
