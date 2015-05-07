#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int singleNumber(vector<int> &nums){
        int ones = 0, twos = 0, threes = 0;
        for(int i = 0; i < nums.size(); i++){
            twos |= ones & nums[i];
            ones ^= nums[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

int main(){
    Solution s;
    int A[10] = {7,6,5,5,6,7,7,5,6,4};
    int B[4] = {5,6,5,5};
    vector<int> input(A, A+10);
    vector<int> input_1(B, B+4);
    cout << s.singleNumber(input_1) << endl;
    return 0;
}
