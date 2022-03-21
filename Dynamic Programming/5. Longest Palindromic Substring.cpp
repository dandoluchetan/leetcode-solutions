class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==1)
            return s;
        int array[s.length()][s.length()];
        int LPSLength=1;
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            array[i][i]=1;
            if(i==s.length()-1)
                continue;
            if(s[i]==s[i+1]){
                array[i][i+1]=1;
                LPSLength=2;
                start=i;
                end=i+1;
            }
            else
                array[i][i+1]=0;
        }
        for(int j=2;j<s.length();j++){
            for(int i=0;i<j-1;i++){
                if(s[i]==s[j] && array[i+1][j-1]){
                    array[i][j]=1;
                    if((j-i+1)>LPSLength){
                        LPSLength=j-i+1;
                        start=i;
                        end=j;
                    }
                }
                else{
                    array[i][j]=0;
                }
            }
        }
        return s.substr(start,LPSLength);
        
    }
};
