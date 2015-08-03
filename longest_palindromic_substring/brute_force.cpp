#include<iostream>
#include<string>
using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) {
			int startIndex = 0;
			int len = 0;
			int sI, eI;
			for(int i = 0; i < s.size()-1; i++) {
				if(s[i] == s[i+1]) {
					sI = i;
					eI = i+1;
					Search(s, sI, eI, len, startIndex);
				} 
				sI = i;
				eI = i;
				Search(s, sI, eI, len, startIndex);

			}
			if(len == 0) 
				len = s.size();
			return s.substr(startIndex, len);
		}

	public:
		void Search(string &s, int sI, int eI, int &len, int &startIndex) {
			int step = 1;
			while((sI - step) >= 0 && (eI + step) < s.size()) {
				if(s[sI - step] != s[eI + step]){
					break;
				}
				step++;
			}
			int wid = eI - sI + 2 * step - 1;
			if(wid > len) {
				len = wid;
				startIndex = sI - step + 1;
			}
		}
};

int main() {
	Solution solu;
	string s = "ccc";
	cout << solu.longestPalindrome(s) << endl;
	return 0;
}
