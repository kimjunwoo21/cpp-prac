/**
 * @file OilDrilling.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - PCCP
 * @version 0.1
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int dir[4][2] =
{
    { 0, -1}, // up
    { 1,  0}, // right
    { 0,  1}, // down
    {-1,  0}, // left
};

int search(vector<vector<int>>& land, const vector<int> start, const int order)
{
    int xMax = land[0].size();
    int yMax = land.size();

    int amount = 0;

    queue<vector<int>> q;
    q.push(start);

    while (q.empty() == false)
    {
        vector<int> pos = q.front();
        q.pop();

        if (land[pos[1]][pos[0]] == 1)
        {
            land[pos[1]][pos[0]] = order;
            amount++;
        }
        else
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = pos[0] + dir[i][0];
            int nextY = pos[1] + dir[i][1];

            if (nextX < 0 || nextX >= xMax)
            {
                continue;
            }

            if (nextY < 0 || nextY >= yMax)
            {
                continue;
            }

            if (land[nextY][nextX] != 1)
            {
                continue;
            }

            vector<int> next = { nextX, nextY };

            q.push(next);
        }
    }

    return amount;
}

int solution(vector<vector<int>> land) {
    int answer = -1;

    unordered_map<int, int> oilMap;

    for (int i = 0; i < land[0].size(); i++)
    {
        int curAmount = 0;
        unordered_map<int, bool> visited;
        for (int j = 0; j < land.size(); j++)
        {
            int target = land[j][i];

            if (target == 0)
            {
                continue;
            }
            else if (target == 1)
            {
                vector<int> pos = { i, j };
                int oilMapKey = oilMap.size() + 2;

                int amount = search(land, pos, oilMapKey);

                oilMap[oilMapKey] = amount;
                curAmount += amount;
                visited[oilMapKey] = true;
            }
            else
            {
                if (visited.find(target) == visited.end())
                {
                    curAmount += oilMap[target];
                    visited[target] = true;
                }
            }
        }

        if (answer < curAmount)
        {
            answer = curAmount;
        }
    }

    return answer;
}