/**
 * @file battleships-in-a-board.cpp
 * @author Kaustubh Sathe (you@domain.com)
 * @brief https://leetcode.com/problems/battleships-in-a-board/submissions/
 * @version 0.1
 * @date 2022-07-24
 *
 * @copyright Copyright (c) 2022
 *
 */

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X')
                {
                    if ((i - 1 >= 0 && board[i - 1][j] == 'X') || (j - 1 >= 0 && board[i][j - 1] == 'X'))
                    {
                        continue;
                    }
                    else
                    {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};