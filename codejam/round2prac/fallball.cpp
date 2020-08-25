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

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl
using namespace std;

int B[100];
char grid[100][100];
int visited[100];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,c;
    cin >> t;
    int cases = 0;
    while(t--){
        cin >> c;
        forn(i,0,c) cin >> B[i];
        memset(grid, '.', sizeof(grid));
        memset(visited, 0, sizeof(visited));
        forn(i,0,c) grid[0][i] = '.';
        
        bool f=false;
        int row = 1;
        forn(i,0,c){
            int hi = i+1, lo = i-1;
            int bi = B[i];
            int currow = 1;
            while(bi>0){
                bool h=false;
                bool l=false;
                if(!visited[i]){
                    bi--;
                    visited[i] = 1;
                }
                if(lo>0 && !visited[lo] && bi){
                    grid[currow][lo] = '\\';
                    visited[lo] = 1;
                    lo--;
                    bi--;
                    l = true;
                    row = max(currow+1,row);

                }
                
                if(hi<c-1 && !visited[hi] && bi){
                    grid[currow][hi] = '/';
                    visited[hi] = 1;
                    hi++;
                    bi--;
                    h = true;
                    row = max(currow+1,row);
                }
                
                if(bi) currow++;
                if(bi && !h && !l){
                    f = true;
                    cout << "Case #"<< ++cases << ": "<< "IMPOSSIBLE" << endl;
                }
                if(f) break;
            }
            if(f) break;
        }
        if(f) continue;
        cout << "Case #"<< ++cases << ": "<< row << endl;
        for(int i = row-1; i >=0;i--){
            forn(j,0,c) cout << grid[i][j];
            cout << endl; 
        }
    }
}