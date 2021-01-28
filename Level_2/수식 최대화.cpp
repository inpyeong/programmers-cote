#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void calc(vector<long long>& numbers, vector<char>& operands, int idx) {
    long long a = numbers[idx], b = numbers[idx+1];
    numbers.erase(numbers.begin() + idx + 1);
    switch(operands[idx]) {
        case '*':
            numbers[idx] = a * b;
            break;
        case '+':
            numbers[idx] = a + b;
            break;
        case '-':
            numbers[idx] = a - b;
            break;
    } 
    operands.erase(operands.begin() + idx);
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numbers;
    vector<char> operands;
    string tmp;
    for(int i = 0; i < expression.length(); ++i) {
        if(expression[i] >= '0' && expression[i] <= '9')
            tmp += expression[i];
        else {
            numbers.push_back(stoll(tmp));
            operands.push_back(expression[i]);
            tmp.clear();
        }
        if(i == expression.length()-1)
            numbers.push_back(stoll(tmp));
    }
    string op = "*+-";
    do {
        vector<long long> numbersCopy(numbers.begin(), numbers.end());
        vector<char> operandsCopy(operands.begin(), operands.end());
        for(int i = 0; i < op.length(); ++i)
            for(int j = 0; j < operandsCopy.size(); ++j)
                if(operandsCopy[j] == op[i])
                    calc(numbersCopy, operandsCopy, j--);
        answer = max(answer, abs(numbersCopy.front()));
    } while(next_permutation(op.begin(), op.end()));
    return answer;
}
