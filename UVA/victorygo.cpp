#include <iostream>
#include <fstream>
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
#define INF 0x3f3f3f3f
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define setv(arr,i) memset(arr, i, sizeof(arr))
using namespace std;

int t;
string grid[9];
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int visited[9][9];

pair<int, int> dfs(int r, int c){
    visited[r][c] = 1;
    int color = -1;
    int val = 1;
    bool fl = false;
    forn(i,0,4){
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if(nr>=0 && nc>=0 && nr<9 && nc<9 && !visited[nr][nc]){
            if(grid[nr][nc] == 'X' && color==-1) color = 0;
            else if(grid[nr][nc] == 'O' && color==-1) color = 1;
            else if((grid[nr][nc] == 'X' && color == 1) || (grid[nr][nc] == 'O' && color == 0)){
                fl = true;
            }  else if(grid[nr][nc] == '.'){
                ii df = dfs(nr,nc);
                if((df.first == -1 && df.second == -1) || (color!=-1 && df.second != color)) {
                    fl = true;
                } 
                else if(color == -1){
                    color = df.second;
                }
                val += df.first;
            }
        }
    }
    if(fl) return mp(-1,-1);
    return mp(val,color);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        setv(visited,0);
        forn(i,0,9){
            cin >> grid[i];
        }
        int blp=0,whp=0;
        forn(i,0,9){
            forn(j,0,9){
                if(grid[i][j]=='X') blp++;
                else if(grid[i][j]=='O') whp++;
            }
        }

        forn(i,0,9){
            forn(j,0,9){
                if(grid[i][j]=='.' && !visited[i][j]){
                    ii df = dfs(i,j);
                    if(df.second == 0) blp+=df.first;
                    else if(df.second == 1) whp +=df.first;
                }
            }
        }
        printf("Black %d White %d\n",blp,whp);
    }
}