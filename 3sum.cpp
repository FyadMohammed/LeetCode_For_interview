#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(),nums.end());

        for(int i = 0;i < nums.size();i++){
            if(nums[i] > 0)break;

            //skip duplicates
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1,r = nums.size()-1;
            while(l < r){
                int sum = nums[i] +  nums[l] + nums[r];
                if(sum > 0){
                    r--;
                }
                else if(sum < 0){
                    l++;
                }
                else {
                    results.push_back({nums[i],nums[l],nums[r]});
                    while(l < r && nums[l]==nums[l+1]) l++;

                    l++,r--;
                }
            }
        }
        return results;
    }
};



int main() {
    Solution sol;
    vector<int> test_case = {1,-1,-1,0};
    vector<vector<int>> result = sol.threeSum(test_case);

    // Print the results
    for(const auto& triplet : result) {
        cout << "[";
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
