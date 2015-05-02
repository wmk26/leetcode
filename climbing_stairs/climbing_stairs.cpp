#include <iostream>
#include <vector>
using namespace std;

//空间复杂度O(n)
/*
class Solution {
    public:
    int climbStairs(int n){
        int a[n];
        if(n <= 2)
            return n;
        else {
            a[0] = 1;
            a[1] = 2;
            for(int i = 2; i < n; i++){
                a[i] = a[i-1] + a[i-2];
            }
        }
        return a[n-1];
    }
};
*/
class Solution {
    public:
    int climbStairs(int n){
        int one_step_before = 1;
        int two_step_before = 2;
        int all_ways = 0;
        if(n <= 2)
            return n;
        else {
            for(int i = 2; i < n; i++){
                all_ways = one_step_before + two_step_before;
                one_step_before = two_step_before;
                two_step_before = all_ways;
            }
        }
        return all_ways;
    }
};
int main(){
    Solution s;
    cout << s.climbStairs(10) << endl;
    return 0;
}
