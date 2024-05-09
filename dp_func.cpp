#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int result = 0;

        // Return to special input processing in advance
        if (height.size() <= 1)
        {
            return 0;
        }

        // dp array, left heigh and right heigh
        vector<int> left_heigh(height.begin(), height.end());
        vector<int> right_heigh(height.begin(), height.end());

        // calc left dp array
        for (int i = 1; i < left_heigh.size() - 1; i++)
        {
            left_heigh[i] = std::max(left_heigh[i - 1], height[i]);
        }

        // calc right dp array
        for (int i = right_heigh.size() - 2; i >= 0; i--)
        {
            right_heigh[i] = std::max(right_heigh[i + 1], height[i]);
        }

        // calc the result
        for (int i = 0; i < height.size(); i++)
        {
            int min_board = std::min(right_heigh[i], left_heigh[i]);
            result += (min_board - height[i]);
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