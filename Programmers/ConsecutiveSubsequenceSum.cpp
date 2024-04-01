/**
 * @file ConsecutiveSubsequenceSum.cpp
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

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int start = 0, end = 0;
    int sum = sequence[0];
    int minDist = 10000001;
    int minStart = 10000001;
    
    while(end < sequence.size() && start < sequence.size())
    {
        if (sum < k)
        {
            end++;
            sum += sequence[end];
        }
        else if (sum > k)
        {
            sum -= sequence[start];
            start++;
        }
        else
        {
            if ((end - start) < minDist || start < minStart)
            {
                minDist = end - start;
                minStart = start;
                answer = {start, end};    
            }            
            
            sum -= sequence[start];
            start++;
            
            if (start > end)
            {
                break;
            }
        }
    }
    
    
    return answer;
}