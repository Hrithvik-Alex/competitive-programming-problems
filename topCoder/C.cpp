#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

class CentipedeSocks {
    public:

    int fewestSocks(int C, int F, vector<int> sockCounts){
        int count = 0;
        sort(sockCounts.begin(), sockCounts.end());
        int i = 0;
        int n = sockCounts.size();
        while(sockCounts[i] < F){
            count+=sockCounts[i];
            i++;
            if(i == n) return -1;
        }
        
        count += (n-1-i)*(F-1);

        for(int j = n-1; j >= i && C>0; j--){
            sockCounts[j]-=(F-1);
            count++;
            C--;
            while(sockCounts[j]>=F && C>0){
                sockCounts[j]-=F;
                count += F;
                C--;
            }
            if(C>0){
                count += sockCounts[j];
            }
        }
        return count;
    }


};