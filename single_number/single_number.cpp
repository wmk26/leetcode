#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int singleNumber(vector<int> &nums){
        const int W = sizeof(int) * 8;
        int count[W] = {0};
        int result = 0;
        for(int i = 0; i < W; i++){
            for(int j = 0; j < nums.size(); j++){
                if((nums[j] >> i) & 1){
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }
};

int main(){
    Solution s;
    int A[10] = {7,6,5,5,6,7,7,5,6,4};
    vector<int> input(A, A+10);
    cout << s.singleNumber(input) << endl;
    return 0;
}
