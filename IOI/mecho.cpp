#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>
#include <bitset>

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define setv(arr,i) memset(arr, i, sizeof(arr))
using namespace std;

int n,s;
vector<string> grid;
ii houseloc, mechloc;
int beetime[800][800];
int mechtime[800][800];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};


bool mechleave(int x){
    bool visited[n][n];
    setv(visited, false);
    queue<ii> q;
    q.push(mechloc);
    mechtime[mechloc.first][mechloc.second] = x;
    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        if(cur.first==houseloc.first && cur.second==houseloc.second){
            return true;
        }
        forn(i,0,4){
            int nx = cur.first+dir[i][0];
            int ny = cur.second+dir[i][1];
            if(nx > 0 && ny > 0 && nx < n && ny < n && !visited[nx][ny]){
                mechtime[nx][ny] = min(mechtime[nx][ny],mechtime[cur.first][cur.second] + 1);
                if(mechtime[nx][ny] < beetime[nx][ny]) q.push(mp(nx,ny));
                visited[nx][ny] = true;
            }
        }
    }
    return false;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    setv(beetime, 200000);
    setv(mechtime, 200000);
    cin >> n >> s;
    forn(i,0,n){
        string x;
        cin >> x;
        grid.pb(x);
    }
    queue<ii> q;
    bool visited[800][800];
    setv(visited, false);
    forn(i,0,n){
        forn(j,0,n){
            if(grid[i][j]=='T'){
                beetime[i][j] = -1;
                visited[i][j] = true;
            } else if(grid[i][j] == 'D'){
                houseloc = mp(i,j);
            } else if(grid[i][j] == 'M'){
                mechloc = mp(i,j);
            } else if(grid[i][j] == 'H'){
                q.push(mp(i,j));
                visited[i][j] = true;
                beetime[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        forn(i,0,4){
            int nx = cur.first+dir[i][0];
            int ny = cur.second+dir[i][1];
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]){
                if(grid[nx][ny] == 'G'){
                    beetime[nx][ny] = min(beetime[nx][ny], beetime[cur.first][cur.second] + s);
                    q.push(mp(nx,ny));
                } 
                visited[nx][ny] = true;
            }
        }
    }
    beetime[houseloc.first][houseloc.second] = n*n*s;
    int secs = -1;
    int hi = n*n*2;
    int lo = -1;
    while(hi-lo>1){
        int mid = (lo+hi)/2;
        if(mechleave(mid*s)){
            secs = mid;
            lo = mid;
        } else {
            hi = mid;
        }
        setv(mechtime, 200000);

    }
    cout << secs << endl;
   
}