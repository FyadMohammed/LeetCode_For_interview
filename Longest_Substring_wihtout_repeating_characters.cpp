#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,max_len = 0;
        unordered_set<char>window;
        for(int r = 0;r < s.size();r++){
            if(window.find(s[r])!= window.end()){
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            max_len = max(max_len,r-l+1);
        }
        return max_len;
    }
};
int main() {
    Solution soln;

    string s = "abcabcbb";
    cout << soln.lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}
