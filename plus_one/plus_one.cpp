#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> plusOne(vector<int> &digits){
        int length = digits.size();
        for(int i = length - 1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};


int main(){
    int a[10] = {8,9,9,9,9,9,9,9,9,9};
    vector<int> input(a, a+10);
    vector<int> output;
    Solution s;
    output = s.plusOne(input);
    for(int i = 0; i < output.size(); i++){
        cout << output[i];
    }
    cout << endl;
    return 0;
}
