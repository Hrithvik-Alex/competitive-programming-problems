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
    float n,k;
    cin >> n >> k;
    priority_queue<float> pq;
    float average = 0;
    for(int i = 0; i < n; i++){
        float a;
        cin >> a;
        average+=a;
        pq.push(a);
    }
    average/=n;
    printf("%.6f", average);
    cout << " ";
    float naverage = 0;
    for(int i = 0; i < k;i++){
        naverage += ceil(pq.top()/3.0);
        pq.pop();
    }
    while(!pq.empty()){
        naverage += pq.top();
        pq.pop();
    }
    naverage/=n;
    printf("%.6f", naverage);
    cout << endl;
}