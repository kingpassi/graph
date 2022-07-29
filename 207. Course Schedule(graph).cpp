/******************************************************************************
207. Course Schedule

There are a total of numCourses courses you have to take, 
labeled from 0 to numCourses - 1. You are given an array prerequisites 
where prerequisites[i] = [ai, bi] indicates that you must take course 
bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have 
to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0
you should also have finished course 1. So it is impossible.
*******************************************************************************/
class Solution {
public:
    
    bool dfs(int currNode, vector<int>adj[],vector<bool>&vis,vector<bool>&dfsVis){
        vis[currNode]=true;
        dfsVis[currNode]=true;
        
        for(auto neighbor:adj[currNode]){
            if(!vis[neighbor]){
               if( dfs(neighbor,adj,vis,dfsVis))
                   return true;
            }
            else if(dfsVis[neighbor])
                return true;
                       
        }
        dfsVis[currNode]=false;
        return false;
        
    }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>adj[numCourses];
        vector<bool>vis(numCourses+1,false),dfsVis(numCourses+1,false);
        
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsVis))
                    return false;
            }
        }
        return true;
        
    }
};