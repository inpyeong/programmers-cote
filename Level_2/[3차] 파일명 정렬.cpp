#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File {
    int idx;
    string head;
    int number;
};

bool cmp(File& a, File& b) {
    if(a.head == b.head && a.number == b.number)
        return a.idx < b.idx;
    if(a.head == b.head)
        return a.number < b.number;
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> fileList;
    for(int i = 0; i < files.size(); ++i) {
        // pos1: 파일명에서 숫자가 첫 번째로 등장한 위치
        int pos1;
        for(int j = 0; j < files[i].size(); ++j) {
            if(files[i][j] >= '0' && files[i][j] <= '9') {
                pos1 = j;
                break;
            }
        }
        
        // head: 파일의 HEAD
        string head = files[i].substr(0, pos1);
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        
        // pos2: 파일명에서 NUMBER 이후 처음으로 등장하는 문자의 위치
        int pos2 = files[i].size();
        for(int j = pos1; j < files[i].size(); ++j) {
            if(files[i][j] < '0' || files[i][j] > '9') {
                pos2 = j;
                break;
            }
        }
        int number = stoi(files[i].substr(pos1, pos2 - pos1));
        fileList.push_back({ i, head, number });
    }
    sort(fileList.begin(), fileList.end(), cmp);
    for(auto file : fileList)
        answer.push_back(files[file.idx]);
    return answer;
}
