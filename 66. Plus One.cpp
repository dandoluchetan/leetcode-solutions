/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int x=1;
        int sum=0;
        int p=digits.back();
        int carry=1;
        int z=digits.size();
        int j;
        for(j=z-1;j>=0;j--){
            if(digits[j]+carry==10){
                carry=1;
                digits[j]=(digits[j]+carry)%10;
                if(j==0 && digits[0]==0)
                    digits.emplace(digits.begin(),1);

            }
            else{
                digits[j]=(digits[j]+carry)%10;
                carry=0;
            }
        }
        return digits;
    }
};
