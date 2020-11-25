#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 1;
    for(int center = 0; center < s.size()-1; ++center) {
        int oLength = 1, delta = 1;
        while(center - delta >= 0 && center + delta < s.size()) {
            if(s.at(center-delta) == s.at(center+delta)) {
                oLength += 2;
                delta++;
            }
            else break;
        }
        int eLength = 0;
        delta = 1;
        if(s.at(center) == s.at(center+1)) {
            eLength = 2;
            while(center - delta >= 0 && center + delta + 1 < s.size()) {
                if(s.at(center-delta) == s.at(center+delta+1)) {
                    eLength += 2;
                    delta++;
                }
                else break;
            }
        }
        int bigger = max(oLength, eLength);
        answer = max(answer, bigger);
    }
    return answer;
}
