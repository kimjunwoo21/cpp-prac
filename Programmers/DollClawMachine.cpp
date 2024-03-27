/**
 * @file DollClawMachine.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - 2019 KAKAO WINTER INTERNSHIP 
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> bucket;
    
    for (int move : moves)
    {
        for (int i = 0; i < board.size(); i++)
        {
            int target = board[i][move-1];
            if (target != 0)
            {
                board[i][move-1] = 0;
                
                if (bucket.empty() == true)
                {
                    bucket.push_back(target);
                }
                else
                {
                    if (bucket.back() == target)
                    {
                        answer += 2;
                        bucket.pop_back();
                    }
                    else
                    {
                        bucket.push_back(target);    
                    }  
                }
                 
                break;
            }
        }
    }

    return answer;
}