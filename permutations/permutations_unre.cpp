#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int> > permuteUnique(vector<int> &num){
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        result.push_back(num);
        int i, j;
        while(1){
            for(i = num.size() - 1; i > 0 ; i--){
                if(num[i-1] < num[i])
                    break;
            }

            if(i == 0){
                break;
            }

            for(j = num.size() - 1; j >= i; j--){
                if(num[j] > num[i-1])
                    break;
            }

            swap(num[i-1], num[j]);
            reverse(num, i, num.size()-1);
            result.push_back(num);
        }
        return result;
    }
    void reverse(vector<int> &num, int begin, int end){
        while(begin <= end){
            swap(num[begin++], num[end--]);
        }
    }
};

int main(){
    int arr[] = {1,1,2,3};
    vector<int> num(arr, arr+4);
    vector<vector<int> > res;
    Solution s;
    res = s.permuteUnique(num);
    int i, j;
    for(i = 0; i < res.size(); i++){
        for(j = 0; j < res[0].size(); j++){
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
