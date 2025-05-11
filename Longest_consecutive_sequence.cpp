#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> numSet(nums.begin(),nums.end());
        int max_length = 0;
        for(int num : numSet){
            if(numSet.find(num-1) == numSet.end()){
                int length = 1;
                while(numSet.find(num+length)!=numSet.end()){
                    length++;
                }
                max_length = max(length,max_length);
            }

        }
        return max_length;
    }
};

int main()
{
    vector<int> test_array = {100,4,200,1,3,2};
    Solution sol;
    cout << sol.longestConsecutive(test_array) << endl;
}
