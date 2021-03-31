#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> room;

long long find(long long n) {
    if(room[n] == 0) return n;
    return room[n] = find(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i = 0; i < room_number.size(); ++i) {
        long long num = room_number[i];
        if(room[num] == 0) {
            answer.push_back (num);
            room[num] = find(num+1);
        }
        else {
            long long nextNum = find(num);
            answer.push_back(nextNum);
            room[nextNum] = find(nextNum+1);
        }
    }
    for(auto it = room.begin(); it != room.end(); ++it)
        cout << it->first << " " << it->second << endl;
    return answer;
}
