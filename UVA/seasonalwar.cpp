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

int n;
int grid[25][25];
int visited[25][25];
int dir[8][2] = {{0,-1},{0,1},{-1,0},{1,0},{1,1},{-1,1},{1,-1},{-1,-1}};

void dfs(int r, int c){
    visited[r][c]=1;
    forn(i,0,8){
        int nr = r+dir[i][0];
        int nc = c+dir[i][1];
        if(nr>=0 && nc>=0 && nr<n && nc<n && visited[nr][nc]==0 && grid[nr][nc]==1){
            dfs(nr,nc);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases = 0;
    while(cin >> n){
        setv(visited,0);
        forn(i,0,n){
            string x;
            cin >> x;
            forn(j,0,n){
                grid[i][j] = x[j]-'0';
            }
        }
        int res=0;
        forn(i,0,n){
            forn(j,0,n){
                if(!visited[i][j] && grid[i][j]){
                    dfs(i,j);
                    res++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++cases,res);
    }
}