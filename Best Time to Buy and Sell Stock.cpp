#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX,max_profit = 0;
        for(int i = 0;i < prices.size();i++){
            if(min_price > prices[i]){
                min_price = prices[i];
            }
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};

int main()
{
    Solution sol;
    vector<int> test_prices = {2,4,1};
    cout << sol.maxProfit(test_prices) << endl;
}
