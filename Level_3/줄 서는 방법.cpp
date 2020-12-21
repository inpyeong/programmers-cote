#include <string>
#include <vector>

using namespace std;

long long factorial(int n) {
    if(n == 1) return 1;
    return n * factorial(n-1);
}

void order(vector<int>& answer, vector<int>& people, int n, long long k) {
    if(people.size() == 1) return;
    long long slice = factorial(n) / n;
    int now = ((k-1) / slice);
    answer.push_back(people[now]);
    people.erase(people.begin() + now);
    k %= slice;
    if(!k) k = slice;
    order(answer, people, n-1, k);
}

vector<int> solution(int n, long long k) {
    vector<int> answer, people;
    for(int i = 1; i <= n; ++i)
        people.push_back(i);
    order(answer, people, n, k);
    answer.push_back(people[0]);
    return answer;
}
