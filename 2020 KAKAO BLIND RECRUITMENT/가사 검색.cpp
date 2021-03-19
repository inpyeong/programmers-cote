#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie {
    Trie* child[26];
    int count;
    
    Trie(): child(), count(0) {}
    void insert(string str) {
        Trie* curr = this;
        for(char ch : str) {
            curr->count++;
            if(curr->child[ch - 'a'] == nullptr) 
                curr->child[ch - 'a'] = new Trie();
            curr = curr->child[ch - 'a'];
        }
        curr->count++;
    }
    int search(string str) {
        Trie* curr = this;
        for(char ch : str) {
            if(ch == '?') return curr->count;
            curr = curr->child[ch - 'a'];
            if(curr == nullptr)
                return 0;
        }
        return curr->count;
    }
};

Trie TrieRoot[10000];
// 뒤집은 문자열에 관한 트라이
Trie ReTrieRoot[10000];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(string str : words) {
        TrieRoot[str.length() - 1].insert(str);
        reverse(str.begin(), str.end());
        ReTrieRoot[str.length() - 1].insert(str);
    }
    for(string str : queries) {
        if(str[0] != '?') 
            answer.push_back(TrieRoot[str.length() - 1].search(str));
        else {
            reverse(str.begin(), str.end());
            answer.push_back(ReTrieRoot[str.length() - 1].search(str));
        }
    }
    return answer;
}
