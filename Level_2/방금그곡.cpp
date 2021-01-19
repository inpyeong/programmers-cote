#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Song {
    int idx;
    int playTime;
    string note;
    string name;
};

string transHash(string str) {
    string ret = "";
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '#') 
            ret[ret.size()-1] += 32;
        else 
            ret += str[i];
    }
    return ret;
}

bool cmp(Song& a, Song& b) {
    if(a.playTime == b.playTime)
        return a.idx < b.idx;
    return a.playTime > b.playTime;
}

string solution(string m, vector<string> musicinfos) {
    m = transHash(m);
    vector<Song> songList;
    for(int i = 0; i < musicinfos.size(); ++i) {
        string mi = musicinfos[i];
        // playTime: 노래 재생시간
        int startT = stoi(mi.substr(0, 2)) * 60 + stoi(mi.substr(3, 2));
        int endT = stoi(mi.substr(6, 2)) * 60 + stoi(mi.substr(9, 2));
        int playTime = endT - startT;
        
        int lastComma = mi.find(',', 12);
        
        // note: 라디오에서 재생된 악보
        string originNote = transHash(mi.substr(lastComma + 1));
        string note;
        if(playTime <= originNote.size()) note = originNote.substr(0, playTime);
        else {
            for(int j = 0; j < playTime; ++j) 
                note += originNote[j % originNote.size()];
        }
        
        // name: 노래 제목
        string name = mi.substr(12, lastComma - 12);
        
        // 네오가 기억한 멜로디가 재생된 악보에 있으면 songList에 추가
        if(note.find(m) != string::npos)
            songList.push_back({ i, playTime, note, name });
    }
    sort(songList.begin(), songList.end(), cmp);   
    if(songList.size())
        return songList[0].name;
    else
        return "(None)";
}
