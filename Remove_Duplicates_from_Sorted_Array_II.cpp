#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }

        int temp = INT_MIN, cnt = 0, k = 0;
        for (int i = 0, pt = 0; i < nums.size(); i++) {
            if (temp != nums[i]) {
                cnt = 1;
                temp = nums[i];
            } else {
                cnt++;
            }

            if (cnt <= 2) {
                swap(nums[pt], nums[i]);
                pt++;
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums =
    {1,2,2,3,3,3,4,4,4,4,5,5,5,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,8,8};
    int result = sol.removeDuplicates(nums);
    cout << "Result: " << result << endl;
    for (int num : nums) {
        cout << num << " ";

    }
    return 0;
}
