class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> pascalTriangle;
        pascalTriangle.push_back({1});
        if(numRows==0)
            return pascalTriangle[0];
        pascalTriangle.push_back({1,1});
        for(int i=2;i<numRows+1;i++){
            vector<int> array;
            array.push_back(1);
            vector<int> temp=pascalTriangle[i-1];
            for(int j=0;j<temp.size()-1;j++){
                array.push_back(temp[j]+temp[j+1]);
            }
            array.push_back(1);
            pascalTriangle.push_back(array);
        }
        return pascalTriangle[numRows];
    }
};
