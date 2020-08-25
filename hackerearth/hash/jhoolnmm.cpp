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

using namespace std;

bool compare(const pair<int, string>&i, const pair<int, string>&j)
{
    return i.first < j.first;
}

int main(){
    int t;
    cin >> t;
    unordered_set<char> us{'l','i','t','e','j','h','o'};
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<pair<string, string> > names(n);
        for(int i = 0; i < n;i++){
            unordered_set<char> uniq;
            string s;
            cin >> s;
            for(int j = 0; j < s.length(); j++){
                uniq.insert(tolower(s[j]));
            }
            string uniqs;
            for(auto j = uniq.begin(); j != uniq.end(); j++){
                uniqs += (*j);
            }
            names[i] = make_pair(uniqs, s);
        }
        vector<pair<int, string> > ranked;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < names[i].first.length(); j++){
                if(us.find(names[i].first[j]) != us.end()){
                    count++;
                }
            }
            ranked.push_back(make_pair(count, names[i].second));
        }

        std::stable_sort(ranked.begin(), ranked.end(), compare);
        for(int i= 0; i < n;i++){
            cout << ranked[i].first << " " << ranked[i].second << " ";
        }
        cout << endl;
    }
}