#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int AlphaCount1[26] = {0};
        int AlphaCount2[26] = {0};

        if (s1.size() > s2.size()) return false;

        int window_size = s1.size();
        for (int i = 0; i < window_size; i++) {
            AlphaCount1[s1[i]-'a']++;
            AlphaCount2[s2[i]-'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (AlphaCount1[i] == AlphaCount2[i]) matches++;
        }

        int left = 0;
        for (int right = window_size; right < s2.size(); right++) {
            if (matches == 26) return true;

            int index_right = s2[right] - 'a';
            int index_left = s2[left] - 'a';

            // update right char
            AlphaCount2[index_right]++;
            if (AlphaCount2[index_right] == AlphaCount1[index_right]) matches++;
            else if (AlphaCount2[index_right] == AlphaCount1[index_right] + 1) matches--;

            // update left char
            AlphaCount2[index_left]--;
            if (AlphaCount2[index_left] == AlphaCount1[index_left]) matches++;
            else if (AlphaCount2[index_left] == AlphaCount1[index_left] - 1) matches--;

            left++;
        }

        return matches == 26;
    }
};

int main() {
    Solution soln;
    cout << soln.checkInclusion("ab", "eidaboo") << endl; // expected 1 (true)
}
