class Solution {
public:
    int findunion(int x,vector<int>&parent){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = findunion(parent[x],parent);
    }
    void unions(int a,int b,vector<int>&rank,vector<int>&parent){
        a = findunion(a,parent);
        b = findunion(b,parent);
        if(a==b){
            return ;
        }
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b] = a;
        }
        else{
            rank[b]++;
            parent[a] = b;
        }
        return;
    }
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    int kruskals(vector<vector<int>>&edges,int n){
        vector<int>parent(n+1);
        vector<int>rank(n+1,0);
        for(int i =0; i<=n;i++){
            parent[i] = i;
        }
        int ans = 0;
        int edgecount = 0;
        int i =0;
        while(i<edges.size()&&edgecount<n-1){
            auto curr = edges[i];
            int src = curr[0];
            int des = curr[1];
            int wt = curr[2];
            int srcpar = findunion(src,parent);
            int despar = findunion(des,parent);
            if(srcpar!=despar){
                unions(src,des,rank,parent);
                ans = ans + wt;
            }
            i++;
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>edges;
        for(int i =0; i<points.size();i++){
            for(int j =i+1; j<points.size();j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                vector<int>v = {i,j,dist};
                edges.push_back(v);
            }
        }
       
        sort(edges.begin(),edges.end(),cmp);
        int ans = kruskals(edges,points.size());

        return ans;





        
    }
};
