#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int candy(vector<int> & ratings){
        int size = ratings.size();
        vector<int> num(size);
        num[0] = 1;
        for(int i = 0; i < size-1; i++){
            if(ratings[i+1] > ratings[i])
                num[i+1] = num[i] + 1;
            else
                num[i+1] = 1;
        }
        int sum = num[size-1];
        for(int i = size-2; i >= 0; i--){
            if(ratings[i] < ratings[i-1])
                num[i-1] = max(num[i] + 1, num[i-1]);
            sum += num[i];
        }
        return sum;
    }
};

int main(){
    Solution s;
    int ratings_arr[20] = {1,2,3,4,5,3,2,1,2,3,5,4,3,2,1,1,1,2,1,1};
    vector<int> ratings(ratings_arr, ratings_arr+20);
    cout << s.candy(ratings) << endl;
    return 0;
}
