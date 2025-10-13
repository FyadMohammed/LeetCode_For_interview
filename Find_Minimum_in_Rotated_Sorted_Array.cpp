#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size() - 1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]){
                left = mid+1;
            }
            else 
                right = mid;
        }
        
        return nums[left];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {11,13,15,17};
    cout << sol.findMin(nums) << endl; // Output: 1
    return 0;
}