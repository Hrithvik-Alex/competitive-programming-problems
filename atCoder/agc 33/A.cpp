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

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin >> h >> w;
    vector<vector<int> > score(h, vector<int>(w));
    queue<ii> q;
    forn(i,0,h){
        forn(j,0,w){
            char x;
            cin >> x;
            if(x == '#'){
                q.push(mp(i,j));
                score[i][j] = 0;
            } else {
            score[i][j] = -1;
            }
        }
    }
    
    int depth = 0;
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    while(!q.empty()){
        ii top = q.front();
        int s = score[top.first][top.second];
        q.pop();
        forn(i,0,4){
            int nx = top.first + dir[i][0];
            int ny = top.second + dir[i][1];
            ii ntop = mp(nx,ny);
            if(nx >= 0 && ny >= 0 && nx < h && ny < w && score[nx][ny] < 0){
                q.push(ntop);
                score[nx][ny] = s+1;
                depth = max(depth,s+1);
            }
        }
    }
    cout << depth << endl;
}
