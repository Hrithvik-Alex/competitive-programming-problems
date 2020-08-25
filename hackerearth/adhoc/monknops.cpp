#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int grid[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int v1,v2,v3,v4;
    cin >> v1 >> v2 >> v3 >> v4;

    long frow = 0;
    for(int i = 0; i < n; i++){
        long rmax = 0;
        long r1 = 0, r2=0,r3 = v2*m;
        for(int j = 0; j < m; j++){
            r1 += abs(grid[i][j]);
            r2 += abs(grid[i][j] + v1);
        }
        rmax = max(r1, max(r2, r3));
        frow += rmax;
    }

    long fcol = 0;
    for(int j = 0; j < m; j++){
        long cmax = 0;
        long c1 = 0, c2 = 0, c3 = v4*n;
        for(int i = 0; i < n; i++){
            c1 += abs(grid[i][j]);
            c2 += abs(grid[i][j] + v3);
        }
        cmax = max(c1, max(c2, c3));
        fcol += cmax;
    }

    cout << max(fcol, frow) << endl;
}