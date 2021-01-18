#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 1;; ++i) {
        int tmp = arr[0] * i;
        bool check = false;
        for(int j = 1; j < arr.size(); ++j) {
            if(tmp % arr[j]) {
                check = true;
                break;
            }
        }
        if(!check) {
            answer = tmp;
            break;
        }
    }
    return answer;
}
