#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0,result = 0,maxf = 0;
        vector <int> AlphaCount(26,0);
        for(right = 0;right < s.size();right++){

            AlphaCount[s[right]-'A']++;
            maxf = max(maxf,AlphaCount[s[right]-'A']);

            while(((right - left +1)-maxf) > k){
                AlphaCount[s[left]-'A']--;
                left++;
            }

            result = max(result, right-left+1);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string test_string = "ABBAA";
    int k = 2;
    cout << sol.characterReplacement(test_string,k) << endl;
}
