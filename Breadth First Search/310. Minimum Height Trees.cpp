
/*
1. We will have only one node or two nodes as our answer because a tree has no cycle.
2. Here we create a adjacency list (Create a hashmap<int,vector<int>> where this indicate all the edges to a particular to node.)
3. Create a queue and Iterate through the list and add the nodes which have adjacency as 1.
4. From the adjacency list delete the nodes which are in queue and do this process i.e step 3 and 4 till the adjacency list size is either 1 or 2.
5. return the key values of adjacency list.
*/
class Solution {
public:
    //trimming tree solution
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> edgesOfNode(n);
        queue<int> q;
        vector<int> minHeightRoots;
        if(n==1)
            return {0};
        for(auto i:edges){
            edgesOfNode[i[0]].insert(i[1]);
            edgesOfNode[i[1]].insert(i[0]);
        }
        int remainingNodes=n;
        for(int i=0;i<n;i++)
            if(edgesOfNode[i].size()==1)
                q.push(i);
        while(n>2){
            int len=q.size();
            n=n-len;
            while(len){
                int j=*edgesOfNode[q.front()].begin();
                edgesOfNode[j].erase(q.front());
                if(edgesOfNode[j].size()==1)
                    q.push(j);
                //gesOfNode.erase(q.front());
                q.pop();
                len--;
            }
        }
        while(!q.empty()){
            minHeightRoots.push_back(q.front());
            q.pop();
        }
        return minHeightRoots;
    }
};
/*
DFS Solution Time compo O(N^2)

1. Create a hashmap<int,vector<int>> where this indicate all the edges to a particular to node.(adjacency list) 
2. iterate thrugh edges, and push into hashmap, since its an undirectional graph push into the hash map vice versa.
3. use dfs to calculate the height and store min height roots.

class Solution {
public:
    unordered_map<int,vector<int>> edgesOfNode;
    void dfs(int node, bool (&visited) [20001], int& height, int& maxHeight){
        visited[node]=true;
        for(int j:edgesOfNode[node]){
            if(!visited[j]){
                dfs(j,visited,++height,maxHeight);
                if(maxHeight<=height)
                    maxHeight=height;
                height--;
            }
        }
    }
    int depth(int node){
        bool visited[20001]={false};
        int height=0,maxHeight=0;
        dfs(node,visited,height,maxHeight);
        return maxHeight;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int minHeight=-1;
        vector<int> minHeightRoots;
        for(auto i:edges){
            edgesOfNode[i[0]].push_back(i[1]);
            edgesOfNode[i[1]].push_back(i[0]);
        }
        while(n>0){
            n--;
            int depth_n=depth(n);
            if(minHeight==-1){
                minHeight=depth_n;
                minHeightRoots.push_back(n);
                continue;
            }
            else if(minHeight>depth_n){
                minHeight=depth_n;
                minHeightRoots.clear();
                minHeightRoots.push_back(n);
                continue;
            }
            else if(minHeight==depth_n){
                 minHeightRoots.push_back(n);
                 continue;
            }
        }
        return minHeightRoots;
    }
};
*/
