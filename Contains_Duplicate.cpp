#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int temp=nums[0];
    bool message;
    for(int i = 1;i < nums.size();i++){
        if(temp == nums[i]){
            message = 1;
            break;
        }
        else{
            message = 0;
            temp = nums[i];
        }
    }
    return message;
}
int main()
{
    vector<int>nums = {2,14,18,22,22};
    cout << containsDuplicate(nums) << endl;;
}