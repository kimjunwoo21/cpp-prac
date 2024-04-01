/**
 * @file SecretMap.cpp
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
#include <cmath>

using namespace std;

string convDec2Bin(const int n, int a)
{
    string binStr = "";
    
    for (int i = n - 1; i >= 0; i--)
    {
        int targetVal = pow(2, i);
        if (a >= targetVal)
        {
            a -= targetVal;
            binStr.push_back('#');
        }
        else
        {
            binStr.push_back(' ');
        }
    }
    
    
    return binStr;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<int> orVec;
    for (int i = 0; i < arr1.size(); i++)
    {
        orVec.push_back(arr1[i] | arr2[i]);
    }
    
    for (int i = 0; i < orVec.size(); i++)
    {
        string res = convDec2Bin(n, orVec[i]);
        answer.push_back(res);
    }
    
    return answer;
}