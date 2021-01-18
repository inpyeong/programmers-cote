#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Page {
    int idx;
    int basic, link;
    double score;
};

bool comp(Page& a, Page& b) {
    if(a.score == b.score)
        return a.idx < b.idx;
    return a.score > b.score;
}

int solution(string word, vector<string> pages) {
    int wSize = word.size();
    map<string, int> pageHash;
    vector<Page> pageList;
    // 검색어를 소문자로 모두 변경
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    for(int i = 0; i < pages.size(); ++i) {
        string& s = pages[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        // url 파싱
        // mid가 posL과 posR 사이에 위치하면 반복문 종료
        int mid = 0, posL = 0, posR;
        while(mid <= posL) {
            posL = s.find("<meta", posL + 1);
            posR = s.find(">", posL);
            mid = s.rfind("https://", posR);
        }
        posR = s.find("\"", mid);
        string url = s.substr(mid, posR - mid);
        
        // 기본점수 계산
        posL = s.find("<body>", posR);
        int basic = 0;
        for(int start = posL;;) {
            start = s.find(word, start + 1);
            if(start == string::npos) break;
            if(!isalpha(s[start - 1]) && !isalpha(s[start + wSize])) {
                basic++;
                start += wSize;
            }
        }
        
        // 외부링크 수 계산
        int link = 0;
        for(int start = posL;;) {
            start = s.find("<a href", start + 1);
            if(start == string::npos) break;
            link++;
        }
        
        pageHash[url] = i;
        pageList.push_back({i, basic, link, (double)basic});
    }
    
    // 링크점수 계산
    for(int i = 0; i < pages.size(); ++i) {
        string& s = pages[i];
        for(int posL = 0, posR = 0;;) {
            posL = s.find("<a href", posR);
            if(posL == string::npos) break;
            
            posL = s.find("https://", posL);
            posR = s.find("\"", posL);
            string linkUrl = s.substr(posL, posR - posL);
            
            map<string, int>::iterator it = pageHash.find(linkUrl);
            if(it != pageHash.end()) {
                pageList[it->second].score += (double)pageList[i].basic / pageList[i].link;
            }
        }
    }
    
    sort(pageList.begin(), pageList.end(), comp);
    return pageList.begin()->idx;
}
