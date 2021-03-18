#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    string newId;
	for(int i = 0; i < new_id.size(); ++i) {
        bool ok = false;
        char c = new_id[i];
        if(c >= 'a' && c <= 'z') ok = true;
        if(c >= '0' && c <= '9') ok = true;
        if(c == '-' || c == '_' || c == '.') ok = true;
        if(ok) newId += c;
    }    
    // cout << newId << endl;
    string newId1 = string(1,newId[0]);
    int idx = 0;;
    for(int i = 1; i < newId.size(); ++i) {
        if(newId1[idx] == '.' && newId[i] == '.')
            continue;
        else {
            newId1 += newId[i];
            idx++;
        }
    }
    // cout << newId1 << endl;
    if(newId1.front() == '.') newId1 = newId1.substr(1);
    if(newId1.back() == '.') newId1.pop_back();
    if(newId1.size() == 0) newId1 += 'a';
    if(newId1.size() >= 16) newId1 = newId1.substr(0, 15);
    if(newId1.back() == '.') newId1.pop_back();
    if(newId1.size() <= 2) {
        char sum = newId1.back();
        while(newId1.size() < 3) {
            newId1 += sum;
        }
    }
    return newId1;
}
