#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> grayCode(int n){
        vector<int> result(1, 0);
        for(int i = 0; i < n; i++){
            int curCount = result.size();
            while(curCount){
                curCount--;
                int curNum = result[curCount];
                //curNum += (1 << i); //another way
                curNum = curNum | (1 << i);
                result.push_back(curNum);
            }
        }
    }
};

int main(){
    vector<int> res;
    Solution s;
    res = s.grayCode(10);
    return 0;
}
