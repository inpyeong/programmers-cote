#include <iostream>
#include <string>

using namespace std;

const int INF = 987654321;

int solution(string s) {
    int maxLenOdd = -INF, maxLenEven = -INF;
    for(int i = 0; i < s.size(); ++i) {
        int lenOdd = 0, leftIdxOdd = i - 1, rightIdxOdd = i + 1;
        while(leftIdxOdd >= 0 && rightIdxOdd < s.size()) {
            if(s.at(leftIdxOdd--) == s.at(rightIdxOdd++)) 
                lenOdd++;
            else break;
        }
        if(lenOdd) maxLenOdd = max(maxLenOdd, lenOdd);
        
        if(i < s.size()-1 && (s.at(i) == s.at(i+1))) {
            int lenEven = 1, leftIdxEven = i - 1, rightIdxEven = i + 2;
            while(leftIdxEven >= 0 && rightIdxEven < s.size()) {
                if(s.at(leftIdxEven--) == s.at(rightIdxEven++)) 
                    lenEven++;
                else break;
            }
            if(lenEven > 1) maxLenEven = max(maxLenEven, lenEven);
        }
    }
    if(maxLenOdd == -INF && maxLenEven == -INF) return 1;
    maxLenOdd = maxLenOdd * 2 + 1;
    maxLenEven = maxLenEven * 2;
    return max(maxLenOdd, maxLenEven);
}
