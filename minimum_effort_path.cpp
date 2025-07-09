class Solution {
public:
    #define pp pair<int,int>
    int shortest_path(vector<vector<int>>& grid){
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
          vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
            pq.push({0,{0,0}});
           // int ans  = INT_MAX;
            int dr[4] = {0,0,1,-1};
            int dc[4] = {-1,1,0,0};
            int p  = INT_MIN;
            int ans = INT_MAX;

            while(pq.size()>0){
                int dist = pq.top().first;
                auto pos = pq.top().second;
                int row = pos.first;
                int col = pos.second;
                if(visited[row][col]==true){
                    pq.pop();
                    continue;
                }
                else{
                    visited[row][col] = true;
                    for(int i = 0; i<4; i++){
                        int nr = row + dr[i];
                        int nc = col + dc[i];
                        if(nr==grid.size()-1&&nc==grid[0].size()-1){
                            int diff = abs(grid[row][col]-grid[nr][nc]);
                             p = max(dist,diff);
                            ans = min(ans,p);
                          
                        }
                        else if(nr>=0&&nc>=0&&nr<=grid.size()-1&&nc<=grid[0].size()-1){
                            int diff = abs(grid[row][col]-grid[nr][nc]);
                            p = max(dist,diff);
                            pq.push({p,{nr,nc}});

                            
                        }
                    }
                }
            }
            if(ans==INT_MAX){
              return 0;
            }
            return ans;    
    }
   
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = shortest_path(heights);
        return ans;
    }
};
