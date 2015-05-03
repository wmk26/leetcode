#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Solution{
    public:
    void setZeroes(vector<vector<int> > &matrix){
        int col0 = 1;
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0)
                col0 = 0;
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(!col0)
                matrix[i][0] = 0;
        }
    }
};

int main(){
    vector<vector<int> > input(10, vector<int>(10));
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            input[i][j] = rand() % 2;
            cout << rand() % 2 << "\t";
        }
        cout << endl;
    }
    Solution s;
    s.setZeroes(input);
    cout << "\n\n";
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << input[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
