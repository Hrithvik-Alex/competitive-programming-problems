#include <iostream>
#include <vector>

int main(){
    int t, n;
    std::cin >> t;
    std::string s;
    std::vector<int> ans;
    while(t--){
        std::cin >> n;
        std::cin >> s;
        
        int czeros = 0;
        int count = 0;
        bool zeroStart = true;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                czeros++;
            } else {
                int add;
                if(zeroStart){
                    add = czeros/2;
                } else if(czeros%2==0){
                    add = czeros/2-1;
                } else {
                    add = czeros/2;
                }
                
                count += add > 0 ? add : 0;
                czeros = 0;
                zeroStart = false;
            }
        }
        
        if(czeros){
            int add;
            if(zeroStart){
                if(czeros%2==0){
                    add = czeros/2;
                } else {
                    add = czeros/2+1;
                }
            } else {
                 add = czeros/2;
            }
            count += add;
        }
        
        
        ans.push_back(count);
    }
    
    for(int i=0;i<ans.size();i++){
        std::cout << ans[i] << std::endl;
    }
    
    return 0;
}
