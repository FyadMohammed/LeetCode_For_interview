#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>nums = {0,0,1,1,1,2,2,3,3,4};
    int k = 0,temp = -1;
    for(int i =0;i < nums.size();i++){
        if(nums[i] != temp){
            temp = nums[i];
            nums[k] = temp;
            k = k + 1;
        }
        for(int j = 0;j < nums.size();j++){
            cout << nums[j] <<" ";
        }
        cout << endl;
    }
    cout << k << endl;
}
