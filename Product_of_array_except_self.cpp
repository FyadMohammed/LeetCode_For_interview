#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>output(n,0);
        int prefix=1,postfix=1;
        for(int i = 0;i < nums.size();i++){
            output[i] = prefix;
            prefix = prefix * nums[i];
        }
        for(int i = nums.size()-1;i >= 0;i--){
            output[i] = postfix * output[i];
            postfix = postfix * nums[i];
        }
        return output;
    }
};

int main()
{
    Solution sol;
    vector<int> test = {1,2,3,4};
    vector<int> answer = sol.productExceptSelf(test);
    for(int i = 0;i < answer.size();i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}
