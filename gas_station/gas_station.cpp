#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int canCompleteCircuit(vector<int> & gas, vector<int> &cost){
        int start = gas.size() - 1, end = 0;
        int sum = gas[start] - cost[start];
        while(start > end){
            if(sum >= 0){
                sum += (gas[end] - cost[end]);
                end++;
            } else {
                start--;
                sum += (gas[start] - cost[start]);
            }
        }
        return sum >= 0 ? start : -1;
    }
};
