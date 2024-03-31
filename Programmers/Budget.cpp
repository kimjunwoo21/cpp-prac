/**
 * @file Budget.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - Summer/Winter Coding(~2018)
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    for (int pay : d)
    {
        if (pay <= budget)
        {
            answer++;
            budget -= pay;
        }
    }
    
    return answer;
}