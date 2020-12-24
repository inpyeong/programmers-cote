#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    for(int i = 0; i < size; ++i)
        for(int j = i+1; j < size; ++j) {
            int length1 = phone_book[i].length();
            int length2 = phone_book[j].length();
            if(length1 >= length2) {
                if(phone_book[j] == phone_book[i].substr(0, phone_book[j].length())) return false;
            }
            else
                if(phone_book[i] == phone_book[j].substr(0, phone_book[i].length())) return false;
        }
    return answer;
}
