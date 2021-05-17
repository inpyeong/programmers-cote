#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie {
    Trie* children[26];
    int numOfChildren;
    bool fin;
    
    Trie(): children(), numOfChildren(0), fin(false) {}
    void insert(string str) {
        Trie* curr = this;
        for(char ch : str) {
            curr->numOfChildren++;
            if(curr->children[ch - 'a'] == nullptr) 
                curr->children[ch - 'a'] = new Trie();
            curr = curr->children[ch - 'a'];
        }
        curr->numOfChildren++;
        curr->fin = true;
    }
    int find(string str) {
        int ret = 0;
        Trie* curr = this;
        for(char ch : str) {
            ret++;
            curr = curr->children[ch - 'a'];
            if(curr->numOfChildren == 1 || curr->fin) {
                curr->fin = false; 
                return ret;
            }
        }
        return 0;
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie root;
    sort(words.begin(), words.end());
    for(string word : words) 
        root.insert(word);
    for(string word : words) 
        answer += root.find(word);
    return answer;
}
