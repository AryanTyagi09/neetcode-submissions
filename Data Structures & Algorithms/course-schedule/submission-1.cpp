class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     vector<vector<int>>adj(numCourses);
     vector<int>ind(numCourses,0);
     for(int i=0;i<prerequisites.size();i++){
        int a=prerequisites[i][0];
        int b=prerequisites[i][1];
        adj[b].push_back(a);
        ind[a]++;
     }
     queue<int>q;
     for(int i=0;i<numCourses;i++){
        if(ind[i]==0){
            q.push(i);
        }
     }
     int count=0;
     while(!q.empty()){
        int curr=q.front();
        count++;
        q.pop();
        for(int i=0;i<adj[curr].size();i++){
            ind[adj[curr][i]]--;
            if(ind[adj[curr][i]]==0){
                q.push(adj[curr][i]);
            }
        }
     }
     return count==numCourses;
    }
};