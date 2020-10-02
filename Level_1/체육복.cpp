#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    vector<int> students(n+1, 1);
    for(int i = 0; i < lost.size(); ++i) 
        --students[lost[i]];
    for(int i = 0; i < reserve.size(); ++i) 
        ++students[reserve[i]];
    
    for(int i = 1; i < students.size(); ++i)
        if(students[i] == 0) {
            int back = i - 1, front = i + 1;
            // 뒷번호, 앞번호 학생 순으로 확인
            if(back >= 1 && students[back] == 2) {
                --students[back];
                ++students[i];
                continue;
            } 
            if(front >= 1 && students[front] == 2) {
                --students[front];
                ++students[i];
                continue;
            } 
        }
    
    int answer = 0;
    for(int i = 1; i < students.size(); ++i)
        if(students[i] != 0) ++answer;
    return answer;
}
