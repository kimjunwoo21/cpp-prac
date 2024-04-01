/**
 * @file DefenseSystem.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{       
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), compare);
    
    int end = -1;
    
    for (vector<int> target : targets)
    {
        if (end <= target[0])
        {
            answer++;
            end = target[1];    
        }
    }
    
    return answer;
}