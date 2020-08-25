#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> ans;
    while(t--){
        //input
        int r, c;
        cin >>r>>c;
        vector<string> grid(r);
        for(int i =0;i<r;i++){
            string in;
            cin >> in;
            grid[i] = in;
        }

        //setup dist
        vector<vector<int> > dist(r, vector<int>(c, INT_MAX));
        
        int mindist = INT_MAX;
        
        for(int k = 0; k <r;k++){
            for(int l = 0; l<c;l++){
                if(grid[k][l] == 1){
                    continue;
                }
                vector<vector<int> > cdist = dist;
                cdist[k][l] = 0;
                queue <pair<int, int> > q;
                q.push(make_pair(k,l));
                for(int i =0;i<r;i++){
                    for(int j = 0; j<c;j++){
                        if(grid[i][j] - '0' == 1) {
                            cdist[i][j] = 0;
                        q.push(make_pair(i,j));
                        }
                    }
                }
                //calc dist
                int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int i =0; i < 4; i++){
                        int x = cur.first + dir[i][0];
                        int y = cur.second + dir[i][1];
                        if(x >= 0 && y >= 0 && x < r && y < c){
                            if(cdist[x][y] > cdist[cur.first][cur.second] + 1){
                                cdist[x][y] = cdist[cur.first][cur.second] + 1;
                                q.push(make_pair(x, y));
                            }
                            
                        }
                    }
                }
                // find max dist
                int overallx = 0;
                int overally = 0;
                for(int i =0;i<r;i++){
                    for(int j = 0; j<c;j++){
                        if(cdist[i][j] > cdist[overallx][overally]){
                            overallx = i;
                            overally = j;
                        }
                    }
                }

                mindist = min(mindist, cdist[overallx][overally]);
            }
        }
      

        // vector<pair<int, int> >  maxes;
        // maxes.push_back(make_pair(overallx,overally));
        
        // for(int i =0;i<r;i++){
        //     for(int j = 0; j<c;j++){
        //         if(dist[i][j] == dist[overallx][overally] && (i != overallx || j !=overally)){
        //             maxes.push_back(make_pair(i,j));
        //         }
        //     }
        // }
        // int fovrx = 0;
        // int fovry = 0;
        // for(int i = 0; i<maxes.size(); i++){
        //     fovrx += maxes[i].first;
        //     fovry += maxes[i].second;
        // }
        // fovrx/=maxes.size();
        // fovry/=maxes.size();
        // // recalc dist
        // dist[fovrx][fovry] = 0;
        // q.push(make_pair(fovrx, fovry));
        // while(!q.empty()){
        //     pair<int, int> cur = q.front();
        //     q.pop();
        //     for(int i =0; i < 4; i++){
        //         int x = cur.first + dir[i][0];
        //         int y = cur.second + dir[i][1];
        //         if(x >= 0 && y >= 0 && x < r && y < c){
        //             if(dist[x][y] > dist[cur.first][cur.second] + 1){
        //                 dist[x][y] = dist[cur.first][cur.second] + 1;
        //                 q.push(make_pair(x, y));
        //             }
        //         }
        //     }
        // }

        // for(int i =0;i<r;i++){
        //     for(int j = 0; j<c;j++){
        //         cout << dist[i][j];
        //     }
        //     cout << endl;
        // }

        // // refind max dist
        // overallx = 0;
        // overally = 0;
        // for(int i =0;i<r;i++){
        //     for(int j = 0; j<c;j++){
        //         if(dist[i][j] > dist[overallx][overally]){
        //             overallx = i;
        //             overally = j;
        //         }
        //     }
        // }
        if(mindist == INT_MAX) mindist = 0;
        ans.push_back(mindist);
    }

    for(int i = 0;i< ans.size(); i++){
        cout << "Case #" << i+1 << ": " << ans[i] << endl;
    }
}