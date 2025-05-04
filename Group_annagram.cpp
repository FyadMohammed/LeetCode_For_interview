#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashmap;
        for(const string& str : strs){
            vector<int>count(26,0);
            for(char s : str){
                count[s-'a']++;
            }
            string key;
            for(int i =0;i < 26;i++){
                key += to_string(count[i])+',';
            }
            hashmap[key].push_back(str);
        }
        vector<vector<string>> output;
        for(const auto& var : hashmap){
            output.push_back(var.second);
        }
        return output;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = sol.groupAnagrams(input);

    // Print results
    for(const auto& group : result) {
        for(const string& s : group) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
