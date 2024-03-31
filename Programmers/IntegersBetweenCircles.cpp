/**
 * @file Budget.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int x = 1; x <= r2; x++)
    {
        int yMin;
        
        if (x > r1)
        {
            yMin = 0;
        }
        else
        {
            yMin = ceil(sqrt((long long)r1*r1 - (long long)x*x));
        }
        
        int yMax = floor(sqrt((long long)r2*r2 - (long long)x*x));
        
        answer += (yMax - yMin + 1);
    }
    
    return answer * 4;
}