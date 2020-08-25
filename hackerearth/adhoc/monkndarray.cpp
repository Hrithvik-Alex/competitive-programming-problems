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

vector<int> input,t;
int len = 0;


int ceilIndex(int s, int end){
    int start = -1;
    int middle;
    int len = end;
    while(end-start>1){
        middle = (start+end)/2;
        if(t[middle] > s){
            end = middle;
        } else {
            start = middle;
        }
    }
    return end;
}

void LIS(){
    t[0] = input[0];
    int n = input.size();
    forn(i,0,n){
        if(input[i] < t[0]){
            t[0] = input[i];
        } else if(t[len-1] < input[i]){
            t[len++] = input[i];
        } else {
            t[ceilIndex(input[i],n-1)] = input[i];
        }
    }
}

int main(){
    int n,q;
    scanf("%d %d", &n,&q);
    input.resize(n);
    t.resize(n);
    r.resize(n);
    forn(i,0,n){
        scanf("%d", &input[i]);
    }
    LIS();
    
    for(i,0,q){
        int a,b;
        scanf("%d", &a);
        if(a==1){
            scanf("%d", &b);
            input.push_back(b);
            if(b > t[len-1]){
                t[len++] = b;
            } else if(t[0] < b){
                t[0] = b;
            } else {
                t[ceilIndex(b,n-1)] = b;
            }
        } else {
            b = input.back();
            input.pop_back();
            if(b == t[len-1]){
                len--;
            } else if(t[0] == b){

            }
        }

        printf("%d\n", len);
    }

}