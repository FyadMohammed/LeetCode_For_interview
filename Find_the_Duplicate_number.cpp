#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int>& nums){
      
      int s = nums[0];
      int f = nums[0];

      do{
        s = nums[s];
        f = nums[nums[f]];
      }while(s!=f);
      
      s = nums[0];
      while(s!=f) {
        s = nums[s];
        f = nums[f];
      }
      return s;
    }
};
int main()
{
  Solution sol;
  vector<int>test_vector = {1,3,4,2,2};
  vector<int>test_vector2 = {3,1,3,4,2};
  vector<int>test_vector3 = {3,3,3,3,3};


  cout << sol.findDuplicate(test_vector) << endl;
  cout << sol.findDuplicate(test_vector2) << endl;
  cout << sol.findDuplicate(test_vector3) << endl;
}
