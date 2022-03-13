class Solution {
public:
    
    // to get to nth stair we must go till n-1th or n-2th stair. 
    int climbStairs(int n) {
        int array[46]={0};
        array[0]=array[1]=1;
        for(int i=2;i<n+1;i++)
            array[i]=array[i-1]+array[i-2];
        return array[n];
    }
};
