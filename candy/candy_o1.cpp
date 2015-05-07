#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int slope(int n){
        return (n*(n+1) / 2);
    }
    public:
    int candy(vector<int> & ratings){
        if(ratings.size() <= 1)
            return ratings.size();
        int tot = 0;
        int up = 0;
        int down = 0;
        int oldsign = 0;
        for(int i = 1; i < ratings.size(); i++){
            int newsign = ratings[i] > ratings[i-1] ? 1 : ratings[i] < ratings[i-1] ? -1 : 0;
            if((oldsign > 0 && newsign == 0) || (oldsign < 0 && newsign >= 0)){
                tot += slope(up) + slope(down) + max(up, down);
                up = 0;
                down = 0;
            } 
            if(newsign > 0)
                up++;
            if(newsign < 0)
                down++;
            if(newsign == 0)
                tot++;
            oldsign = newsign;
        }
        tot += slope(up) + slope(down) + max(up, down) + 1;
        return tot;
    }   
};


int main(){
    Solution s;
    int ratings_arr[20] = {1,2,3,4,5,3,2,1,2,3,5,4,3,2,1,1,1,2,1,1};
    vector<int> ratings(ratings_arr, ratings_arr+20);
    cout << s.candy(ratings) << endl;
    return 0;
}
