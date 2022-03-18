class Solution {
public:
    int min(int a,int b){
        return a>b?b:a;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2;i<cost.size();i++)
            cost[i]=cost[i]+min(cost[i-1],cost[i-2]);
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};
