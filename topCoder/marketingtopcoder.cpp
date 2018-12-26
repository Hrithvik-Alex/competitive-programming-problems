#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Marketing {
public:
    long long howMany(vector<string> compete);
};

long long Marketing::howMany(vector<string> compete){
    int x = compete.size();
    int a[x][x];
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; ++j) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < compete[i].length(); ++j) {
            if(compete[i][j] != ' '){
                a[i][j] = 1;
                a[j][i] = 1;
            }
        }
    }

    int visited[x];
    for (int k = 0; k < x; ++k) {
        visited[k] = 0;
    }
    

}
