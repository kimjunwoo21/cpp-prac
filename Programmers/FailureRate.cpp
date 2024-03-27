/**
 * @file FailureRate.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - 2019 KAKAO BLIND RECRUITMENT
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<int> arrive(N, 0);
    vector<int> pass(N, 0);

    for (int stage : stages)
    {
        if (stage <= N)
        {
            arrive[stage - 1]++;
        }
        else
        {
            stage--;
        }

        for (int i = stage; i > 0; i--)
        {
            pass[i - 1]++;
        }
    }

    vector<pair<int, float>> failRateVec;
    for (int i = 0; i < N; i++)
    {
        float failRate = 0.0f;        
        if (arrive[i] != 0)
        {
            if (pass[i] != 0)
            {
                failRate = ((float)arrive[i] / (float)pass[i]) * 100.0f;
            }
            else
            {
                failRate = 100.0f;
            }
        }

        failRateVec.push_back(make_pair(i + 1, failRate));
    }

    sort(failRateVec.begin(), failRateVec.end(), compare);

    for (int i = 0; i < N; i++)
    {
        answer.push_back(failRateVec[i].first);
    }

    return answer;
}