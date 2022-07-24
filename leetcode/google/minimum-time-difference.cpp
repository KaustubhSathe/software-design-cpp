/**
 * @file minimum-time-difference.cpp
 * @author Kaustubh Sathe
 * @brief
 * @version 0.1
 * @date 2022-07-24
 *
 * @copyright Copyright (c) 2022
 */

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> timePointsInInt;

        for (auto x : timePoints)
        {
            timePointsInInt.push_back(absTime(x));
        }

        sort(timePointsInInt.begin(), timePointsInInt.end());

        int mn = 1000000000;
        for (int i = 0; i < timePointsInInt.size() - 1; i++)
        {
            int diff1 = timePointsInInt[i + 1] - timePointsInInt[i];
            int diff2 = 24 * 60 - timePointsInInt[i + 1] + timePointsInInt[i];
            // cout<<diff1<<" "<<diff2<<endl;
            mn = min(mn, min(diff1, diff2));
        }

        int diff1 = timePointsInInt[timePointsInInt.size() - 1] - timePointsInInt[0];
        int diff2 = 24 * 60 - timePointsInInt[timePointsInInt.size() - 1] + timePointsInInt[0];
        mn = min(mn, min(diff1, diff2));

        return mn;
    }

    int absTime(string time)
    {
        string hour = time.substr(0, 2);
        string mins = time.substr(3, 2);

        int totaltime = stoi(hour) * 60 + stoi(mins);
        return totaltime;
    }
};