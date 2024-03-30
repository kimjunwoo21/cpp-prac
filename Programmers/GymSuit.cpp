/**
 * @file GymSuit.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - Greedy
 * @version 0.1
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    unordered_map<int, bool> reserveMap;
    unordered_map<int, bool> lostMap;   
    
    for (int i = 0; i < reserve.size(); i++)
    {
        reserveMap[reserve[i]] = true;
    }
    
    for (int i = 0; i < lost.size(); i++)
    {
        if (reserveMap.find(lost[i]) != reserveMap.end())
        {
            reserveMap[lost[i]] = false;
            answer++;
            continue;
        }
        
        lostMap[lost[i]] = true;
    }
    
    for (auto iter = lostMap.begin(); iter != lostMap.end(); iter++)
    {
        int taker = iter->first;
    
        if (reserveMap.find(taker-1) == reserveMap.end())
        {
            if (reserveMap[taker+1] == true)
            {
                reserveMap[taker+1] = false;
                answer++;
            }
            continue;
        }
        else if (reserveMap.find(taker+1) == reserveMap.end())
        {
            if (reserveMap[taker-1] == true)
            {
                reserveMap[taker-1] = false;
                answer++;
            }
            continue;
        }
        
        if (reserveMap[taker+1] == true)
        {
            reserveMap[taker+1] = false;
            answer++;
        }
        else if (reserveMap[taker-1] == true)
        {
            reserveMap[taker-1] = false;
            answer++;
        }    
    }

    return answer;
}