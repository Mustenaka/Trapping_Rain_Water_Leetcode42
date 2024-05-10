#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int result = 0;
        int max_left_heigh = 0;

        // Return to special input processing in advance
        if (height.size() <= 1)
        {
            return 0;
        }

        // 2ptr-dp array, left heigh and right heigh
        vector<int> right_heigh(height.begin(), height.end());

        // dp calc right_heigh array
        for (int i = height.size() - 2; i >= 0; i--)
        {
            right_heigh[i] = std::max(right_heigh[i + 1], height[i + 1]);
        }

        // calc the result
        for (int i = 1; i < height.size() - 1; i++)
        {
            max_left_heigh = std::max(max_left_heigh, height[i - 1]);
            int min = std::min(max_left_heigh, right_heigh[i]);

            if (min > height[i])
            {
                result += (min - height[i]);
            }
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