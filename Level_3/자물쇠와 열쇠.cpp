#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > rotateKey(const vector<vector<int> >& key, int kSize) {
    vector<vector<int> > keyCopy(kSize, vector<int>(kSize, 0));
    for(int i = 0; i < kSize; ++i)
        for(int j = 0; j < kSize; ++j)
            if(key[i][j]) keyCopy[j][kSize-i-1] = 1;
    return keyCopy;
}

bool isValid(const vector<vector<int> > v, const vector<vector<int> > key, int kSize, int lSize) {
    bool ret = false;
    vector<vector<int> > vCopy;
    for(int i = 0; i < kSize+lSize-1; ++i) {
        for(int j = 0; j < kSize+lSize-1; ++j) {
            vCopy.assign(v.begin(), v.end());
            bool ok = false;
            for(int k = 0; k < kSize && !ok; ++k)
                for(int w = 0; w < kSize; ++w) {
                    if(k+i >= kSize-1 && k+i < kSize+lSize-1 && w+j >= kSize-1 && w+j < kSize+lSize-1)
                        if(key[k][w] && vCopy[k+i][w+j]) {
                            ok = true;
                            break;
                        }
                    if(key[k][w]) vCopy[k+i][w+j] = 1;
                }
            if(ok) continue;
            int oneCnt = 0;
            for(int k = kSize-1; k < kSize+lSize-1; ++k)
                for(int w = kSize-1; w < kSize+lSize-1; ++w)
                    if(vCopy[k][w]) oneCnt++;
            if(oneCnt == lSize * lSize) ret = true;
        }
    }
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int kSize = key.size(), lSize = lock.size();
    vector<vector<int> > v(2 * kSize + lSize - 2, vector<int>(2 * kSize + lSize - 2, 0));
    for(int i = kSize-1; i < kSize+lSize-1; ++i)
        for(int j = kSize-1; j < kSize+lSize-1; ++j)
            if(lock[i-kSize+1][j-kSize+1])
                v[i][j] = 1;
    for(int r = 0; r < 4; ++r) {
        key = rotateKey(key, kSize);
        if(isValid(v, key, kSize, lSize))
            return true;
    }
    return false;
}
