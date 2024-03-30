/**
 * @file MockExam.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - search
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

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    
    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores(3, 0);
    vector<int> pattern1 = { 2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> pattern2 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++)
    {
        if ( ( (i % 5) + 1 ) == answers[i] )
        {
            scores[0]++;
        }
        if ( pattern1[(i % 8)] == answers[i] )
        {
            scores[1]++;
        }
        if ( pattern2[(i % 10)] == answers[i] )
        {
            scores[2]++;
        }
    }
    
    vector<pair<int, int>> scorePair;
    for (int i = 0; i < 3; i++)
    {
        scorePair.push_back(make_pair(i + 1, scores[i]));    
    }
    
    sort(scorePair.begin(), scorePair.end(), compare);
    
    answer.push_back(scorePair[0].first);
    
    if (scorePair[0].second != scorePair[1].second)
    {
        return answer;
    }
    else
    {
        answer.push_back(scorePair[1].first);
    }
    
    if (scorePair[1].second != scorePair[2].second)
    {
        return answer;
    }
    else
    {
        answer.push_back(scorePair[2].first);
    }
    
    return answer;
}