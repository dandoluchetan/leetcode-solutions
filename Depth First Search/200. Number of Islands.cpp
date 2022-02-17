//https://leetcode.com/problems/number-of-islands/

/*
1. Make an array to keep track of visited Nodes;
2. Iterate through the 2D array.
3. Do step 4 & 5 only if the "1" node is not visited;
4. if "1" then do dfs by seraching for 1 in up/right/down/left directions;
5. After each dfs call which is called from main increment islands.
6. Return islands;

Note for DFS to happen properly fix a direction: Here the direction rule is Up, Right, Down, Left.
*/
class Solution {
public:
    bool visited[300][300]={false};
    void dfs(int row,int column, vector<vector<char>>& grid){
        if(grid[row][column]==48)
            return;
        if(visited[row][column])
            return;
        visited[row][column]=true;
        if(row-1>=0)
            dfs(row-1,column,grid);//UP
        if(column+1<grid[0].size())
            dfs(row,column+1, grid);//RIGHT
        if(row+1<grid.size())
            dfs(row+1,column,grid);//DOWN
        if(column-1>=0)
            dfs(row,column-1,grid);//LEFT
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==49){
                    if(!visited[i][j]){
                        dfs(i,j,grid);
                        islands++;
                    }
                }
            }
        }
        return islands;
    }
};
