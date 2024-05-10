#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int result = 0;
        int current = 0;

        std::stack<int> st;

        // slide current ptr until height size
        while (current < height.size())
        {
            // if stack is not empty and it's hight > stack heigh, loop it
            while (!st.empty() && height[current] > height[st.top()])
            {
                int h = height[st.top()]; // take the top element
                st.pop();

                // if empty then through out
                if (st.empty())
                {
                    break;
                }

                int distance = current - st.top() - 1;
                int min = std::min(height[st.top()], height[current]);
                result += (distance * (min - h));
            }

            st.push(current);
            current++;
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