#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getOne(int n) {
    int ret = 0;
    while(n > 0) {
        if(n % 2) ret++;
        n /= 2;
    }
    return ret;
}

int solution(int n) {
    int answer = 0, numOfOne = getOne(n);
    for(int i = n+1;;++i) {
        int tmp = getOne(i);
        if(numOfOne == tmp) return i;
    }
}
