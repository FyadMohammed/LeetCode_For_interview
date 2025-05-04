#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> HashMap;
        for(int i = 0;i < nums.size();i++){
            int dif = target - nums[i];
            if(HashMap.find(dif) != HashMap.end()){
                return {HashMap[dif],i};
            }
            HashMap.insert({nums[i], i});
        }
        return {};
    }
};

int main()
{
    vector<int>nums = {4,2,6,3,9,-4};
    int target = 9;
    Solution sln;
    vector<int> result = sln.twoSum(nums, target);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
