#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int result = 0;
        vector<int> water_height(height.begin(), height.end());

        // Return to special input processing in advance
        if (height.size() <= 1)
        {
            return 0;
        }

        // Calc the current board can save how many water
        for (int i = 0; i < height.size(); i++)
        {
            int current_board_heigh = height[i];
            int left_board_heigh = 0;
            int right_board_heigh = 0;

            // if it's not a board, continue
            if (current_board_heigh == 0)
            {
                continue;
            }

            // calc the left board
            for (int l = i - 1; l >= 0; l--)
            {
                left_board_heigh = height[l];
                if (left_board_heigh >= current_board_heigh)
                {
                    for (int w = l; w <= i; w++)
                    {
                        if (water_height[w] < current_board_heigh)
                        {
                            water_height[w] = current_board_heigh;
                        }
                    }
                    break;
                }
            }

            // calc the right board
            for (int r = i + 1; r < height.size(); r++)
            {
                right_board_heigh = height[r];
                if (right_board_heigh >= current_board_heigh)
                {
                    for (int w = i; w <= r; w++)
                    {
                        if (water_height[w] < current_board_heigh)
                        {
                            water_height[w] = current_board_heigh;
                        }
                    }
                    break;
                }
            }
        }

        // calc the result
        for (int i = 0; i < water_height.size(); i++)
        {
            result += (water_height[i] - height[i]);
            // cout << water_height[i] << " - " << height[i] << endl;
        }

        return result;
    }
};

int main()
{
    // Init data
    Solution sol;

    // Example 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result1 = sol.trap(height1);
    cout << "result1 :" << result1 << endl;

    // Example 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    int result2 = sol.trap(height2);
    cout << "result2 :" << result2 << endl;
}