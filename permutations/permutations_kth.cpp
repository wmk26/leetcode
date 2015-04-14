#include <iostream>
using namespace std;

string getPermutation(int n, int k){
    int i,j,f=1;
    string s(n, '0');
    //set s to 123...n;
    for(i = 1; i <= n; i++){
        f *= i;
        s[i-1] += i;
    }
    k--;
    for(i = 0; i < n; i++) {
        //f represent all count for (n-i) permutations
        f /= (n - i);
        //+i for O(1) space
        j = i + k/f;
        //s[j] = j + 1;
        char c = s[j];
        //remove c by shifting to cover up(adjust the right part).
        //cover s[j]
        for(; j > i; j--){
            s[j] = s[j-1];
        }
        k %= f;
        s[i] = c;
    }
    return s;
}

int main(){
    string str;
    str = getPermutation(1, 1);
    cout << str << endl;
    return 0;
}
