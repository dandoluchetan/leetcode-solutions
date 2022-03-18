class Solution {
public:
    int tribonacci(int n) {
        int fibArray[n+1];
        fibArray[0]=0;
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        fibArray[1]=1;
        fibArray[2]=1;
        for(int i=3;i<n+1;i++)
            fibArray[i]=fibArray[i-1]+fibArray[i-2]+fibArray[i-3];
        return fibArray[n];
    }
};
