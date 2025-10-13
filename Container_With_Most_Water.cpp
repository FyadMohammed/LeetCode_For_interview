#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int Area = 0;
        while(left < right) {
            
            // Move the pointer pointing to the shorter line
            if(height[left] < height[right]) {
                Area = max(Area, (right - left) * height[left]);
                left++;
            } else {
                Area = max(Area, (right - left) * height[right]);
                right--;
            }
        }
        return Area;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl; // Output: 49
    return 0;
}
