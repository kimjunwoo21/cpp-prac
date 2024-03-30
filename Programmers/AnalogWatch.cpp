/**
 * @file AnalogWatch.cpp
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
#include <cmath>

using namespace std;

double calcSecondDeg(const int s)
{
    return (double)s * 6.0;
}

double calcMinuteDeg(const int s, const int m)
{
    return ((double)s * 0.1) + ((double)m * 6.0);
}

double calcHourDeg(const int s, const int m, const int h)
{
    int modH = h % 12;
    return ((double)s * (0.5 / 60.0)) + ((double)m * 0.5) + ((double)modH * 30.0);
}

bool checkPassingStoM(const int s1, const int s2, const int m1, const int m2)
{
    // s1, s2, m1, m2 != 0 && s1 < s2 && m1 < m2
    double s1Deg = calcSecondDeg(s1);
    double s2Deg = calcSecondDeg(s2);
    double m1Deg = calcMinuteDeg(s1, m1);
    double m2Deg = calcMinuteDeg(s2, m2);

    return (s1Deg < m1Deg && m2Deg < s2Deg);
}

bool checkPassingStoH(const int s1, const int s2, const int m1, const int m2, const int h1, const int h2)
{
    // s1, s2, h1, h2 != 0 && s1 < s2 && h1 < h2
    double s1Deg = calcSecondDeg(s1);
    double s2Deg = calcSecondDeg(s2);
    double h1Deg = calcHourDeg(s1, m1, h1);
    double h2Deg = calcHourDeg(s2, m2, h2);
    
    return (s1Deg < h1Deg && h2Deg < s2Deg);
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    if (s1 == 0 && m1 == 0)
    {
        answer++;
    }
    
    if (h1 == h2 && m1 == m2)
    {
        if (checkPassingStoM(s1, s2, m1, m1) == true)
        {
            answer++;
        }
        
        if (checkPassingStoH(s1, s2, m1, m1, h1, h1) == true)
        {
            answer++;
        }   
        
        return answer;
    }
    else // h1 != h2 || m1 != m2
    {
        if (checkPassingStoM(s1, 60, m1, m1) == true)
        {
            answer++;
        }
        if (checkPassingStoH(s1, 60, m1, m1, h1, h1) == true)
        {
            answer++;
        }      

        s1 = 0;
        if (++m1 == 60)
        {
            m1 = 0;
            h1++;
        }
    }

    while (h1 != h2 || m1 != m2)
    {   
        if (m1 == 0)
        {
            if (h1 % 12 != 0)
            {
                answer += 2;
            }
            else
            {
                answer++;
            }
        }
        else if (m1 == 59)
        {
            if (h1 % 12 != 11)
            {
                answer++;
            }
        }
        else
        {
            answer += 2;
        }
        
        if (++m1 == 60)
        {
            m1 = 0;
            h1++;
        }
    }
    
    // s1 must be 0
    
    if (m1 == 0)
    {
        answer++;
    }
    
    if (s2 == 0)
    {
        return answer;
    }
    
    if (checkPassingStoM(s1, s2, m2, m2) == true)
    {
        answer++;
    }

    if (checkPassingStoH(s1, s2, m2, m2, h2, h2) == true)
    {
        answer++;
    }   
    
    return answer;
}