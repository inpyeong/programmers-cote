#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int, int> > foods;
    int n = food_times.size();
    for(int i = 0; i < n; ++i)
        foods.push_back(make_pair(food_times[i], i+1));
    sort(foods.begin(), foods.end());
    int pretime = 0;
    for(auto it = foods.begin(); it != foods.end(); ++it, --n) {
        long long spend = (long long)(it->first - pretime) * n;
        if(spend == 0) continue;
        if(spend <= k) {
            k -= spend;
            pretime = it->first;
        }
        else {
            k %= n;
            sort(it, foods.end(), cmp);
            return (it+k)->second;
        }
    }
    return -1;
}
