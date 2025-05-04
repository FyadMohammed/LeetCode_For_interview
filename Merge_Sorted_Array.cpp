#include <bits/stdc++.h>

using namespace std;
void removeTrailingZeroes(vector<int>& nums, int k) {
    if (nums.empty()) return; // Early exit for empty vector

    auto it = nums.end();
    int i = 0;

    // Start removing trailing zeros
    while (i < nums.size() && nums[nums.size() - 1 - i] == 0 && i < nums.size() - k) {
        it--; // Move iterator backward
        i++;
    }

    nums.erase(it, nums.end()); // Erase trailing zeros
}




int main()
{
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 4,n = 2;

    removeTrailingZeroes(nums1,m);
    removeTrailingZeroes(nums2,n);
    int len = nums1.size() + nums2.size();

    int i=0,j=0,itr = 0;
    vector<int> temp;
    while(i != nums1.size() && j!= nums2.size()){
        if(nums1[i] < nums2[j]){
            temp.push_back(nums1[i]);
            i++;
        }
        else if(nums1[i] > nums2[j]){
            temp.push_back(nums2[j]);
            j++;
        }
        else if(nums1[i] == nums2[j]){
            temp.push_back(nums1[i]);
            temp.push_back(nums2[j]);
            i++,j++;
        }
        itr++;
    }
    if(i == nums1.size()){
        for(int k = j;k < nums2.size();k++)
            temp.push_back(nums2[k]);
    }
    if(j == nums2.size()){
        for(int k = i;k < nums1.size();k++)
            temp.push_back(nums1[k]);
    }
    nums1.clear();

    for(int i = 0;i < temp.size();i++){
        nums1.push_back(temp[i]);
    }
    for(int i = 0;i < nums1.size();i++){
        cout << nums1[i] << " ";
    }
    cout << endl;
}
