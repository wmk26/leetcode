#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int trap(vector<int> & height){
        int left = 0, right = height.size() - 1;
        int result = 0;
        int max_left = 0, max_right = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= max_left){
                    max_left = height[left];
                } else {
                    result += (max_left - height[left]);
                }
                left++;
            } else {
                if(height[right] >= max_right){
                    max_right = height[right];
                } else {
                    result += (max_right - height[right]);
                }
                right--;
            }
        } 
        return result;
    }
};

int main(){
    int a[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> input(a, a+12);
    Solution s;
    int res = s.trap(input);
    cout << res << endl;
    return 0;
}
