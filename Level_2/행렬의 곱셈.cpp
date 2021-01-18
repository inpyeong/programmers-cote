#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    // arr1 행 고정
    for(int i = 0; i < arr1.size(); ++i) {
        // arr2 열 고정
        for(int j = 0; j < arr2[0].size(); ++j) {
            int ret = 0;
            for(int k = 0; k < arr1[0].size(); ++k)
                ret += arr1[i][k] * arr2[k][j]; 
            answer[i][j] = ret;
        }
    }
    return answer;
}
