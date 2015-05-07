#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int candy(vector<int> & ratings){
        int nCandyCnt = 0;  //total candies
        int nSeqLen = 0;    //continuous ratings descending sequence length
        int nPreCanCnt = 1;     //previous child's candy count
        int nMaxCntInSeq = nPreCanCnt;
        if(ratings.begin() != ratings.end()){
            nCandyCnt ++;
            for(vector<int>::iterator i = ratings.begin() + 1; i != ratings.end(); i++){
                if(*i < *(i-1)){
                    nSeqLen ++;
                    if(nMaxCntInSeq == nSeqLen)
                        nSeqLen++;
                    nCandyCnt += nSeqLen;
                    nPreCanCnt = 1;
                } else {
                    if(*i > *(i-1))
                        nPreCanCnt++;
                    else 
                        nPreCanCnt = 1;
                    nCandyCnt += nPreCanCnt;
                    nSeqLen = 0;
                    nMaxCntInSeq = nPreCanCnt;
                }
            }
        }
        return nCandyCnt;
    }
};


int main(){
    Solution s;
    int ratings_arr[20] = {1,2,3,4,5,3,2,1,2,3,5,4,3,2,1,1,1,2,1,1};
    vector<int> ratings(ratings_arr, ratings_arr+20);
    cout << s.candy(ratings) << endl;
    return 0;
}
