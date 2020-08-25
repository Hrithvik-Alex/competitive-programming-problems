#include <iostream>
#include <cmath>

int main(void){
    float withdraw, balance;
    std::cin >> withdraw >> balance;
    if(withdraw + 0.5 > balance) {
        std::cout << balance << std::endl;
    } else if(withdraw/5.0 != std::floor(withdraw/5)){
        std::cout << balance << std::endl;
    } else {
        std::cout << balance - withdraw - 0.5 << std::endl;
    }
    
    
    
    return 0;
}
