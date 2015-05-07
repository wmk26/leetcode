#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int singleNumber(vector<int> &nums){
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};

int main(){
    Solution s;
    int A[10] = {7,6,5,5,6,7,7,5,6,4};
    int B[1] = {9};
    vector<int> input(A, A+10);
    vector<int> input_1(B, B+1);
    cout << s.singleNumber(input_1) << endl;
    return 0;
}
