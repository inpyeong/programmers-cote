#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string Hand;
pair<int, int> numPos[13]; 
pair<int, int> posR, posL;

void init() {
    numPos[1] = {0, 0}; numPos[2] = {0, 1}; numPos[3] = {0, 2};
    numPos[4] = {1, 0}; numPos[5] = {1, 1}; numPos[6] = {1, 2};
    numPos[7] = {2, 0}; numPos[8] = {2, 1}; numPos[9] = {2, 2};
    numPos[10] = {3, 0}; numPos[11] = {3, 1}; numPos[12] = {3, 2};
    
    posR = numPos[10];
    posL = numPos[12];
}

int getDistance(string side, int num) {
    int numY = numPos[num].first, numX = numPos[num].second;
    if(side == "right") 
        return (abs(posR.first - numY) + abs(posR.second - numX));
    else 
        return (abs(posL.first - numY) + abs(posL.second - numX));
}

void setPos(string side, int num) {
    if(side == "right") {
        posR.first = numPos[num].first;
        posR.second = numPos[num].second;
    }
    else {
        posL.first = numPos[num].first;
        posL.second = numPos[num].second;
    }
}

string getSide(int num) {
    if(num == 0) num = 11;
    if(num == 1 || num == 4 || num == 7) {
        setPos("left", num);
        return "L";
    }
    if(num == 3 || num == 6 || num == 9) {
        setPos("right", num);
        return "R";
    }
	int distR = getDistance("right", num);
    int distL = getDistance("left", num);
    if(distR > distL) {
        setPos("left", num);
        return "L";
    }
    if(distR < distL) {
        setPos("right", num);
        return "R";
    }
    // 만약 두 엄지손가락과 눌러야 할 번호와 떨어진 거리가 같다면
    if(Hand == "right") {
        setPos("right", num);
        return "R";
    }
    else if(Hand == "left") {
        setPos("left", num);
        return "L";
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    Hand = hand;
    init();
   	for(int num : numbers) 
   		answer += getSide(num); 
    return answer;
}
