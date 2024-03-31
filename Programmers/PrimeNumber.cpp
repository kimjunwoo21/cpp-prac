/**
 * @file PrimeNumber.cpp
 * @author Junwoo Kim (kingjunwoo21@naver.com)
 * @brief Programmers - Summer/Winter Coding(~2018)
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int target = nums[i] + nums[j] + nums[k];
                
                int t;
                for (t = 2; t < target; t++)
                {
                    if (target % t == 0)
                    {
                        break;
                    }
                }
                
                if (t == target)
                {
                    answer++;
                }
            }
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}