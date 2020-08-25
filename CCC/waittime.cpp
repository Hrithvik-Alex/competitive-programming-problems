#include <iostream>

using namespace std;

int m,x;
string cas;

int arr[101];
pair <int,int> comm[101];

int main(){
    cin >> m;
    int curs = 0;
    for(int i = 0; i < m; i++){
        cin >> cas >> x;
        if(cas=="R"){
            comm[x] = make_pair(1,curs);
        }
        else if(cas=="S"){
            arr[x] += curs-comm[x].second; 
            comm[x].first = 0;
        }

        if(cas=="W"){
            curs += x-1;
        } else {
            curs++;
        }
    }
    for(int i = 0; i < 100; i++){
        if(comm[i].first==1) cout << i << " " << -1 << endl;
        else if(arr[i]>0) cout << i << " " << arr[i] << endl;
    }
}