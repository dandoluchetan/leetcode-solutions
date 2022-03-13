//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        pascalTriangle.push_back({1});
        if(numRows==1)
            return pascalTriangle;
        pascalTriangle.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int> array;
            array.push_back(1);
            vector<int> temp=pascalTriangle[i-1];
            for(int j=0;j<temp.size()-1;j++){
                array.push_back(temp[j]+temp[j+1]);
            }
            array.push_back(1);
            pascalTriangle.push_back(array);
        }
        return pascalTriangle;
    }
};
