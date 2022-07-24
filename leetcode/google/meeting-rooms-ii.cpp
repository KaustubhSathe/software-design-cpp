/**
 * @file meeting-rooms-ii.cpp
 * @author your name (you@domain.com)
 * @brief https://leetcode.com/problems/meeting-rooms-ii/
 * @version 0.1
 * @date 2022-07-24
 *
 * @copyright Copyright (c) 2022
 */

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        /*
            the minimum number of rooms required will be the maximum number of overlapping intervals.
            So at a given time interval t[i], where t[i] in [0, 1000000], we have to find the number of intervals that                 overlap.

            arr   0 0 0 0 0 0 0 0 0
            pref  0 0 1 1 1 0 0  0 0
            diff  0 0 1 0 0 -1 0 0 0
            index 1 2 3 4 5 6 7 8 9
        */
        vector<int> diff(1000000 + 5, 0);
        vector<int> pref(1000000 + 5, 0);

        for (auto interval : intervals)
        {
            int first = interval[0];
            int second = interval[1] - 1;
            diff[first] += 1;
            diff[second + 1] += -1;
        }

        int mx = 1;
        for (int i = 0; i <= 1000000; i++)
        {
            if (i == 0)
            {
                pref[i] = diff[i];
            }
            else
            {
                pref[i] = pref[i - 1] + diff[i];
            }
            mx = max(mx, pref[i]);
        }

        return mx;
    }
};

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        vector<int> start, end;
        for (auto interval : intervals)
        {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0;
        for (int i = 0, j = 0; i < start.size() && j < end.size();)
        {
            if (start[i] < end[j])
            {
                rooms++;
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }

        return rooms;
    }
};
