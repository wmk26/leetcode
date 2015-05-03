#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> grayCode(int n){
        int N(1 << n), tmp;
        int temp = 2;
        vector<int> result;
        for(int i(0); i < N; i++){
            tmp = i << 1;
            result.push_back((tmp^i) >> 1);
        }
        return result;
    }
};

int main(){
    vector<int> res;
    Solution s;
    res = s.grayCode(4);
    return 0;
}
