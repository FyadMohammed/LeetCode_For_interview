#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int temp = nums[0];
    bool state;
    for(int i = 1;i < nums.size();i++){
        if(nums[i] == temp){
            state = true;
            break;
        }
        else
            temp = nums[i];
    }
    state = false;
    if(state)
        cout << "true" << endl;
    else
        cout << "false" << enld;
}
int main()
{
    vector<int>nums = {1,2,3,4};
    cout << containsDuplicate(nums) << endl;

}
