#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_value = *max_element(piles.begin(),piles.end());



        int mid,left = 1,right = max_value,sum;
        int result;
        while(left <= right){
            mid = left + (right - left)/2;
            sum = 0;
            for(int pile : piles){
                sum += (pile + mid - 1) / mid;
                if(sum > h)break;
            }
            if(sum < h){
                right = mid-1;
            }
            else if(sum > h){
                left = mid+1;
            }
            else{
                result = mid;
                break;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> test_piles = {3,6,7,11};
    int test_h = 8;
    cout << sol.minEatingSpeed(test_piles,test_h) << endl;
}
