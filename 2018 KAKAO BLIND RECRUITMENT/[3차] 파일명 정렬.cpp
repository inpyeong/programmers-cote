#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File {
    int originOrder;
    string name;
 	string head;
    int number;
};

bool cmp(File a, File b) {
    if(a.head == b.head && a.number == b.number) return a.originOrder < b.originOrder;
    if(a.head == b.head) return a.number < b.number;
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> fileList;
    for(int i = 0; i < files.size(); ++i) {
        int pos;
        string head;
        for(pos = 0; pos < files[i].size(); ++pos) {
            if(files[i][pos] >= '0' && files[i][pos] <= '9') break;
            head += files[i][pos]; 
        }
        string numberStr;
        for(; pos < files[i].size(); ++pos) {
            if(files[i][pos] < '0' || files[i][pos] > '9') break;
            numberStr += files[i][pos];
        }
        int number = stoi(numberStr);
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        fileList.push_back({ i, files[i], head, number });
    }
    sort(fileList.begin(), fileList.end(), cmp);
    for(int i = 0; i < fileList.size(); ++i)
        answer.push_back(fileList[i].name);
    return answer;
}
