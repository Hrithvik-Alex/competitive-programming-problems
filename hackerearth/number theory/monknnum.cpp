//HACKEREARTH : Monk and number

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <utility>
#include <algorithm>

#define MOD 1000000007

using namespace std; 


vector<int> divisors(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; ++i) {
        if(n%i==0){
            res.push_back(i);
            if(n/i!=i){
                res.push_back(n/i);
            }
        }
    }
    return res;
}


int main(){
    int t;
    cin >> t;
    vector<int> ans;
    while(t--){
        int n;
        cin >> n;
        vector<int> vals(n);
        for(int i = 0; i < n;i++){
            cin >> vals[i];
        }
        int k = 1;
        for(int i = 0; i < n;i++){
            k = ((k%MOD)*(vals[i]%MOD))%MOD;
        }
        vector<int> divs = divisors(k);
        int sum = 0;
        for(int i = 0; i < divs.size(); i++){
            vector<int> divdivs = divisors(divs[i]);
            for(int j = 0; j < divdivs.size(); j++){
                sum = ((divdivs[j]%MOD) + (sum%MOD))%MOD;
            }
        }
        ans.push_back(sum);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}

// solution
// #include <bits/stdc++.h>
// using namespace std;
 
// #define ll long long
// #define pb push_back
// #define mp make_pair
// #define mo 1000000007
// #define MAX 1000004
// #define fast_io ios::sync_with_stdio(false)
// map<int,int> m1;
// std::vector<int> pr;
// int a[10000000];
// ll pow(int a, int b, int MOD = mo)
// {
//     ll x=1,y=a;
//     while(b)
//     {
//         if(b%2)
//             x=(x*y)%MOD;
//         y = (y*y)%MOD;
//         b /= 2;
//     }
//     return x;
// }
// ll inv(int a, int MOD=mo)
// {
// 	return pow(a,MOD-2,MOD);
// }
// ll func(int p, int a)
// {
// 	ll ans=((pow(p,a+2)-p+mo)%mo-(1LL*(a+1)*(p-1))%mo+mo)%mo;
// 	ans=(ans*inv(pow(p-1,2)))%mo;
//     return ans;
// }
// void sieve()
// {
// 	for(int i=2;i<=4000;i++)
// 	{
// 		if(!a[i])
// 		for(int j=i*i;j<=100000;j+=i)
// 			a[j]=1;
// 	}
// 	for(int i=2;i<=100000;i++)
// 		if(!a[i])
// 			pr.pb(i);
// }
// int main()
// {
// 	sieve();
// 	fast_io;
// 	int n,x,t;
// 	cin >> t;
// 	int sz=pr.size();
// 	while(t--)
// 	{
// 		m1.clear();
// 		cin >> n;
// 		for(int i=0;i<n;i++)
// 		{
// 			cin >> x;
// 			int y=sqrt(x);
// 			for(int j=0;j<sz && pr[j]<=y;j++)
// 			{
// 				while(x%pr[j]==0)
// 				{
// 					m1[pr[j]]++;
// 					x/=pr[j];
// 				}
// 				y=sqrt(x);
// 			}
// 			if(x>1)
// 				m1[x]++;
 
// 		}
// 		ll ans=1;
// 		for(auto it : m1)
// 			ans=(ans*func(it.first,it.second))%mo;
// 		cout << ans << endl;
 
// 	}
// 	return 0;
// }