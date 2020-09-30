#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> v(201, 0);
    for(int i = 0; i < numbers.size(); ++i) {
        for(int j = 0; j < numbers.size(); ++j) {
            if(i == j) continue;
            v[numbers[i]+numbers[j]] += 1;
        }
    }
    vector<int> answer;
    for(int i = 0; i < v.size(); ++i)
        if(v[i] != 0) answer.push_back(i);
    
    return answer;
}
