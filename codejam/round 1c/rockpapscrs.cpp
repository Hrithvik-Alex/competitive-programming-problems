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
#define vi vector<int>
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
using namespace std;

int main(){
    int t, a;
    cin >> t;
    vector<string> res;
    while(t--){
        cin >> a;
        vector<pair<string, int> > in(a);
        forn(i,0,a){
            cin >> in[i].first;
            in[i].second = 1;
        }

        forn(i,0,a){        
            while(in[i].first.length() < 500){
                in[i].first += in[i].first;
            }
            forn(j,0,500){
                cout << in[i].first[j];
            }
            cout << endl;
        }

        string ans = "";
        bool flag = false;
        bool wasS = false, wasR = false, wasP = false;
        forn(i,0,500){
            bool isS = false, isR = false, isP = false;
            if(i == 0){
                forn(j,0,a){
                    if(in[j].first[i] == 'R') isR = true;
                    else if(in[j].first[i] == 'P') isP = true;
                    else if(in[j].first[i] == 'S') isS = true;
                }
            } else {
                forn(j,0,a){
                    if(!((wasP && in[j].first[i-1] == 'R') || (wasS && in[j].first[i-1] == 'P') || (in[j].first[i-1] == 'S' && wasR)) && in[j].second == 1){
                        if(in[j].first[i] == 'R') isR = true;
                        else if(in[j].first[i] == 'P') isP = true;
                        else if(in[j].first[i] == 'S') isS = true;
                    } else {
                        in[j].second = 0;
                    }
                }
            }
            if(!isR && !isS && !isP){
                flag = true;
                break;
            }
            if(isR && isP && isS){
                break;
            }
            if(isR && !isP && !isS){
                ans += "P";
                flag = true;
                break;
            }
            if(isP && !isR && !isS){
                ans += "S";
                flag = true;
                break;
            }
            if(isS && !isR && !isP){
                ans += "R";
                flag = true;
                break;
            }
            if(isS && isR){
                ans += "R";
                wasS = true;
                wasR = true;
                wasP = false;
            } else if(isR && isP){
                ans += "P";
                wasP = true;
                wasR = true;
                wasS = false;
            } else if(isS && isP){
                ans += "S";
                wasS = true;
                wasP = true;
                wasR = false;
            }

        }
        if(!flag) ans = "IMPOSSIBLE";
        res.pb(ans);
    }   
    
    forn(i,0,res.size()){
        cout << "Case #" << i+1 << ": " << res[i] << endl;
    }
}