/**
 * @file KthNumber.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - sort
 * @version 0.1
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> command : commands)
    {
        int start = command[0] - 1;
        int end   = command[1] - 1;
        int target = command[2] - 1;
        vector<int> splited(array.begin() + start, array.begin() + end + 1);
        
        sort(splited.begin(), splited.end());
        answer.push_back(splited[target]);
    }
    
    return answer;
}