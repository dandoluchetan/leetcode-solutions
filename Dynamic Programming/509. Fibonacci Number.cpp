class Solution {
public:
    int fib(int n) {
        int fibArray[n+1];
        fibArray[0]=0;
        if(n==0)
            return 0;
        fibArray[1]=1;
        for(int i=2;i<n+1;i++)
            fibArray[i]=fibArray[i-1]+fibArray[i-2];
        return fibArray[n];
    }
};
