/**
 * @file DonutAndBarGraph.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - 2024 KAKAO WINTER INTERNSHIP 
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);

    unordered_map<int, vector<int>> gives;
    unordered_map<int, vector<int>> takes;

    for (vector<int> edge : edges)
    {
        int give = edge[0];
        int take = edge[1];
        gives[give].push_back(take);
        takes[take].push_back(give);
    }

    int newNodeNum = -1;
    for (auto iter = gives.begin(); iter != gives.end(); iter++)
    {        
        if (takes[iter->first].empty() == true)
        {
            if (iter->second.size() > 1)
            {
                newNodeNum = iter->first;
                break;
            }
        }
    }

    if (newNodeNum == -1)
    {
        return answer;
    }

    answer[0] = newNodeNum;

    vector<int> newNodeVec = gives[newNodeNum];

    for (int startNode : newNodeVec)
    {
        int n = startNode;

        while (true)
        {
            if (gives[n].size() > 1)
            {
                answer[3]++;
                break;
            }
            else if (gives[n].size() == 1)
            {
                if (gives[n][0] == startNode || gives[n][0] == n)
                {
                    answer[1]++;
                    break;
                }
            }
            else  // if (gives[n].size() == 0)
            {
                answer[2]++;
                break;
            }

            n = gives[n][0];
        }
    }

    return answer;
}