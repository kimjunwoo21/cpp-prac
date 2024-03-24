/**
 * @file MostRecievedGift.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - 2024 KAKAO WINTER INTERNSHIP 
 * @version 0.1
 * @date 2024-03-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

#define MAX_SIZE  50

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int givingTable[MAX_SIZE][MAX_SIZE] = { 0, };
    int giftIndex[MAX_SIZE]   = { 0, };
    int resultTable[MAX_SIZE] = { 0, };

    unordered_map<string, int> strIdxMap;

    for (int i = 0; i < friends.size(); i++)
    {
        strIdxMap[friends[i]] = i;
    }

    for (string pair : gifts)
    {
        stringstream giftStream(pair);
        string giver, taker;
        int gidx, tidx;

        giftStream >> giver >> taker;
        
        gidx = strIdxMap[giver];
        tidx = strIdxMap[taker];

        givingTable[gidx][tidx]++;
        giftIndex[gidx]++;
        giftIndex[tidx]--;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = i + 1; j < friends.size(); j++)
        {
            if (givingTable[i][j] > givingTable[j][i])
            {
                resultTable[i]++;
            }
            else if (givingTable[i][j] < givingTable[j][i])
            {
                resultTable[j]++;
            }
            else
            {
                if (giftIndex[i] > giftIndex[j])
                {
                    resultTable[i]++;
                }
                else if (giftIndex[i] < giftIndex[j])
                {
                    resultTable[j]++;
                }                
            }
        }
    }

    int maxFriendIdx = resultTable[0];

    for (int i = 1; i < friends.size(); i++)
    {
        if (maxFriendIdx < resultTable[i])
        {
            maxFriendIdx = resultTable[i];
        }
    }
    
    return maxFriendIdx;
}