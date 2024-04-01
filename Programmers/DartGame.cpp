/**
 * @file DartGame.cpp
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

int solution(string dartResult) {
    int answer = 0;
    vector<int> terms;
    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult.substr(i, 2) == "10")
        {
            terms.push_back(10);
            i++;
        }
        else if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            terms.push_back(dartResult[i] - '0');
        }
        else if (dartResult[i] == 'S')
        {
            // nop
        }
        else if (dartResult[i] == 'D')
        {
            int termIdx = terms.size() - 1;
            terms[termIdx] *= terms[termIdx];
        }
        else if (dartResult[i] == 'T')
        {
            int termIdx = terms.size() - 1;
            terms[termIdx] *= (terms[termIdx] * terms[termIdx]);
        }
        else if (dartResult[i] == '*')
        {
            int termIdx = terms.size() - 1;
            terms[termIdx] *= 2;
            
            if (termIdx != 0)
            {
                terms[termIdx-1] *= 2;    
            }
        }
        else if (dartResult[i] == '#')
        {
            int termIdx = terms.size() - 1;
            terms[termIdx] *= -1;
        }
    }
    
    for (int i = 0; i < terms.size(); i++)
    {
        answer += terms[i];
    }
    
    return answer;
}