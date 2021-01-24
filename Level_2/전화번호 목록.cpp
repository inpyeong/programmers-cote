#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    int size = phone_book.size();
    for(int i = 0; i < size-1; ++i)
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].length())) return false;
    return answer;
}

// 또 다른 통과 코드
// #include <string>
// #include <vector>

// using namespace std;

// bool solution(vector<string> phone_book) {
//     for(int i = 0; i < phone_book.size()-1; ++i)
//         for(int j = i+1; j < phone_book.size(); ++j) {
//             if(phone_book[j].find(phone_book[i]) == 0) 
//                 return false;
//             if(phone_book[i].find(phone_book[j]) == 0) 
//                 return false;
//         }
//     return true;
// }
