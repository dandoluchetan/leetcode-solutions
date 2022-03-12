class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> array;
        array.push_back(0);
        int i=1;
        while(i<n+1){
            int j=i;
            for(int k=0;k<j;k++){
                if(i<n+1){
                    int temp=array[k]+1;
                    array.push_back(temp);
                    i++;
                }
            }
        }
        return array;
    }
};
