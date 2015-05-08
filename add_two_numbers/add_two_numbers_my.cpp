#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = NULL, *ans = NULL;
        int flag = 0;
        int sum = 0;
        int p3_val;
        while(p1 != NULL || p2 != NULL){
            if(p1 != NULL){
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL){
                sum += p2->val;
                p2 = p2->next;
            }
            p3_val = (sum + flag) % 10; 
            flag = (sum + flag) / 10;
            if(NULL == p3){
                p3 = new ListNode(p3_val);
                ans = p3;
            } else {
                p3->next = new ListNode(p3_val);
                p3 = p3->next; 
            }
            sum = 0;
        }
        if(flag == 1){
            p3->next = new ListNode(flag);
        }
        return ans;
    }
};

int main() {
    ListNode *ln1 = new ListNode(9);
    ListNode *ln2 = new ListNode(9);
    ln1->next = ln2;
    ListNode *n1 = new ListNode(1);
    Solution s;
    ListNode *ans = s.addTwoNumbers(ln1, n1);
    while(NULL != ln1){
        cout << ln1->val << "\t";
        ln1 = ln1->next;
    }
    cout << endl;
    while(NULL != ans) {
        cout << ans->val << "\t";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}
