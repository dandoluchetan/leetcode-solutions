// https://leetcode.com/problems/flood-fill/
class Solution {
public:
    
    void bfs(vector<vector<int>>& image,int sr,int sc,int sourceColor,int newColor, bool visited[51][51],queue<pair<int,int>>& pixel){
        visited[sr][sc]=true;
        if(sr-1 >= 0)//UP
            if(image[sr-1][sc]==sourceColor && !visited[sr-1][sc])
                pixel.push(make_pair(sr-1,sc));
        
        if(sr+1 < image.size())//DOWN
            if(image[sr+1][sc]==sourceColor && !visited[sr+1][sc])
                pixel.push(make_pair(sr+1,sc));
        
        if(sc-1 >= 0)//LEFT
            if(image[sr][sc-1]==sourceColor && !visited[sr][sc-1])
                pixel.push(make_pair(sr,sc-1));
                
        if(sc+1 < image[0].size())//RIGHT
            if(image[sr][sc+1]==sourceColor && !visited[sr][sc+1])
                pixel.push(make_pair(sr,sc+1));
                
        image[pixel.front().first][pixel.front().second]=newColor;
        pixel.pop();
        if(pixel.empty())
            return;
        bfs(image,pixel.front().first,pixel.front().second,sourceColor,newColor,visited,pixel);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {    
        bool visited[51][51]={false};
        queue<pair<int,int>> pixel;
        pixel.push(make_pair(sr,sc));
        bfs(image,sr,sc,image[sr][sc],newColor,visited,pixel);
        
        return image;
    }
};
