#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void rotate(vector<vector<int> > &matrix){
        int temp;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j <= i; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size() / 2; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix[i].size() - 1 - j];
                matrix[i][matrix[i].size() - 1 -j] = temp;
            }
        }
    }
};

int main(){
    vector<vector<int> > input(3, vector<int>(3));
    int temp = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            input[i][j] = temp;
            temp++;
        }
    }
    Solution s;
    s.rotate(input);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << input[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
