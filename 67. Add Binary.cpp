/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
class Solution {
public:
    string addBinary(string a, string b) {
        map<char,int> cnt;
        int carry=0;
        int la=a.size();
        int lb=b.size();
        int nzeroes=0;
        if(la>lb){
            nzeroes=la-lb;
            string str(nzeroes,'0');
            str=str+b;
            b=str;
            lb=la;
        }
        if(lb>la){
            nzeroes=lb-la;
            string str(nzeroes,'0');
            str=str+a;
            a=str;
            la=lb;
        }
        string str1(la,'0');
        for(int i=la-1;i>=0;i--){
            if(a[i]=='1')
                cnt['1']++;
            if(b[i]=='1')
                cnt['1']++;
            if(carry==1)
                cnt['1']++;
            (cnt['1']>=2)?carry=1:carry=0;
            if(cnt['1']==1 || cnt['1']==3)
                str1[i]='1';
            cnt['1']=0;
        }
        if(carry==0)
            return str1;
        else
            return '1'+str1;
    }
};
