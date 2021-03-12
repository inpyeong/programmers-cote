#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int J(const vector<string>& v1, const vector<string>& v2) {
    vector<bool> _v1(v1.size(), false);
    vector<bool> _v2(v2.size(), false);
   	// intersection
    vector<string> intersection;
    for(int i = 0; i < v1.size(); ++i)
        for(int j = 0; j < v2.size(); ++j) {
            if(_v2[j] == false) {
                if(_v1[i] == false && v1[i] == v2[j]) {
            		_v1[i] = true;
                    _v2[j] = true;
                    intersection.push_back(v1[i]);
                }
            }
        }
    // union
    vector<string> uni;
    uni.assign(v1.begin(), v1.end());
    for(int i = 0; i < _v2.size(); ++i)
        if(_v2[i] == false) uni.push_back(v2[i]);
    
    for(string s : intersection)
        cout << s << " ";
    cout << endl;
    for(string s : uni)
        cout << s << " ";
    if(intersection.size() == 0 && uni.size() == 0) return 65536;
    return (intersection.size() * 65536) / uni.size();
}

int solution(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    vector<string> v1, v2;
    for(int i = 0; i < str1.size()-1; ++i) {
        if(str1[i] < 'a' || str1[i] > 'z') continue;
        if(str1[i+1] < 'a' || str1[i+1] > 'z') continue;
        string str = string(1, str1[i]) + string(1, str1[i+1]);
        v1.push_back(str);
    }
    for(int i = 0; i < str2.size()-1; ++i) {
        if(str2[i] < 'a' || str2[i] > 'z') continue;
        if(str2[i+1] < 'a' || str2[i+1] > 'z') continue;
        string str = string(1, str2[i]) + string(1, str2[i+1]);
        v2.push_back(str);
    }
    return J(v1, v2);
}
