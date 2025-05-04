#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        int temp = INT_MAX;
        for(int i = 0;i < nums.size();i++){
            if(temp != nums[i]){
                temp = nums[i];
                hashMap.insert(temp,0);
            }
            hashMap[temp].second++;
        }

        vector<int> output;
        for(const auto& pair:hashMap){
            if(pair->second == k){
                output.push_back(pair->first);
            }
        }
        return output;
    }
};
int main()
{
    Solution sol;
    vector<int> test_array = {1,1,1,2,2,3};
    int test_k = 2;
    vector<int> answer = sol.topKFrequent(test_array,test_k);
    for(int i = 0;i < answer.size();i++){
        cout << answer[i] << " ";
    }
    cout << answer;
}
