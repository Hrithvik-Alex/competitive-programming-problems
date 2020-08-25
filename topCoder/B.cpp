//TODO: TopCoder Fillinthemaze

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class FillInTheMaze{
    public:
    vector<string> filled(int R, int C, int X){
        vector<string> res(2*R+1);
        for(int i = 0; i < 2*R+1; i++){
            string row;
            for(int j = 0; j < 2*C+1; j++){
                if(i&1 && j&1){
                    row+=".";
                } else {
                    row += "#";
                }
            }
            res[i] = row;
        }

        for(int i = 0; i < 2*R+1; i++){
            
        }



    }


};