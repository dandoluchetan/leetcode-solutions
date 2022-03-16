class Solution {
public:
    int max(int a, int b){
        return (a>b)?a:b;
    }
        
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int max_value=0;
        for(int i=prices.size()-1;i>-1;i--){
            max_value=max(prices[i], max_value);
            profit=max(profit,max_value-prices[i]);
        }
        return profit;
    }
};
