/**
 * @file AthletsDidNotFinishRace.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - Hash
 * @version 0.1
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> partMap;

    for (string part : participant)
    {
        partMap[part]++;        
    }
    
    for (string comp : completion)
    {
        partMap[comp]--;
    }
    
    for (auto iter = partMap.begin(); iter != partMap.end(); iter++)
    {
        if (iter->second > 0)
        {
            answer = iter->first;
            break;
        }
    }
    
    return answer;
}