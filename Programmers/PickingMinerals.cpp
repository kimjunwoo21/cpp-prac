/**
 * @file PickingMinerals.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int costTable[3][3] =
{
    { 1, 1, 1},
    { 5, 1, 1},
    {25, 5, 1}
};

unordered_map<string, int> mineralMap =
{
    {"dia",   0},
    {"iron",  1},
    {"stone", 2}
};

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 1251;    // 50 * 25 = 1250 최대 값
    vector<int> picksVec;
    
    // 뽑아야 하는 개수 계산
    int pickMax = minerals.size() / 5;
    pickMax = (minerals.size() % 5) ? pickMax + 1 : pickMax;
    
    // picks 원소들을 나열
    for (int i = 0; i < picks.size(); i++)
    {
        for (int j = 0; j < picks[i]; j++)
        {
            if (picksVec.size() < pickMax)
            {
                picksVec.push_back(i);   
            }
            else
            {
                break;
            }
        }
    }
    
    // pickVec에 대해 순열 탐색
    do
    {
        int mineralIdx = 0;
        int cost = 0;
        for (int i = 0; i < picksVec.size(); i++)
        {
            int remain = min(((int)(minerals.size()) - mineralIdx), 5);
            
            for (int j = 0; j < remain; j++)
            {
                int col = mineralMap[minerals[mineralIdx]];
                int row = picksVec[i];
                cost += costTable[row][col];
                mineralIdx++;
            }
        }
        
        answer = min(cost, answer);
        
    } while (next_permutation(picksVec.begin(), picksVec.end()));
    
    
    // 최소 cost 반환
    return answer;
}