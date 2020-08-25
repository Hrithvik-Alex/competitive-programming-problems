#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m;
    float avg = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int b;
            cin >> b;
            avg += b;
        }
    }
    avg /= (n*m);
    cin >> q;
    int exps[q];
    for(int i = 0; i < q; i++){
        cin >> exps[i];
    }

    int ans[q];
    for(int i = 0; i < q; i++){
        float c = exps[i]/avg;
        c *= 1000000;
        if(c == (int)c){
            ans[i] = c;
        } else{
            ans[i] = (int)c + 1;
        }
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
    
}