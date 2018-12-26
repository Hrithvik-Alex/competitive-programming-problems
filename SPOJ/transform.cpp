#include <iostream>
#include <string>
#include <map>
using namespace std;


void transformer(string exp){
    cout << exp << endl;
    for (int i = 0; i < exp.length(); i++) {
        if(exp[i] == '('){
            int depth = 0;
            for(int j = i + 1; j < exp.length(); j ++) {
                if(exp[j] == '(')
                    depth ++;
                if(exp[j] == ')') {
                    if(depth == 0) {
                        transformer(exp.substr(i + 1, j-1));
                        break;
                    } else {
                        depth --;
                    }
                }
            }
        }
    }

}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string exp;
        cin >> exp;
        transformer(exp);
    }
    return 0;
}