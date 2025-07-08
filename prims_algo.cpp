
#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
vector<list<pair<int,int>>>graph;
void add_edge(int u,int v,int wt,bool bi_direc = true){
    graph[u].push_back({v,wt});
    if(bi_direc==true){
        graph[v].push_back({u,wt});
    }
}
long long prims(int src,int n){
    priority_queue <pp, vector<pp>, greater<pp> > pq;//{wt,node}
    unordered_set<int>visited;
    vector<int>parent(n+1);
    unordered_map<int,int>m;//{node,wt}
    pq.push({0,src});
    for(int i =1; i<=n; i++){
        m[i] = INT_MAX;
    }
    m[src] = 0;
    int edgecount = 0;
    int res = 0;
    while(pq.size()>0&&edgecount<n){
        pp curr = pq.top();
        if(visited.find(curr.second)!=visited.end()){
            pq.pop();
            continue;
        }
        else{
            visited.insert(curr.second);
            edgecount++;
            res = res + curr.first;
            pq.pop();
            for(auto  neighbour:graph[curr.second]){
                if(visited.find(neighbour.first)==visited.end()&&m[neighbour.first]>neighbour.second){
                    pq.push({neighbour.second,neighbour.first});
                    m[neighbour.first] = neighbour.second;
                    parent[neighbour.first] = curr.second;
                }
            }
        }
    }
    return res;
}

int main(){
    int n,m ;
    cin>>n>>m;
    graph.resize(n+1,list<pair<int,int>>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    for(int i =0; i<graph.size();i++){
      cout<<graph[i].first<
    }
    int src;
    cin>>src;
    cout<<prims(src,n);



}
