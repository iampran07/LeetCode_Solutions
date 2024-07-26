typedef pair<int,int> pii;
class Solution {
public:
    int number_of_cities(int node,int distanceThreshold, int n,vector<vector<pair<int,int>>>&adj)
    {
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<int>dist(n,INT_MAX);
        int count=0;
        dist[node]=0;
        pq.push({0,node});
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int poppedNode=top.second;
            int dis=top.first;
            if (dis>=distanceThreshold)
            {
                break;
            }
            for (auto it: adj[poppedNode])
            {
                if (it.second+dis<dist[it.first] && it.second+dis<=distanceThreshold)
                {
                    if (dist[it.first]==INT_MAX) count++;
                    dist[it.first]=it.second+dis;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
          vector<vector<pair<int,int>>>adj(n);
          for(auto it:edges)
          {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
          }
          int mini=INT_MAX;
          int ans=0;
          for(int i=0;i<n;i++)
          {
            int temp=number_of_cities(i,distanceThreshold,n,adj);
            if (mini>=temp)
            {
              mini=temp;
              ans=i;
            }
          }
          return ans;

    }
};