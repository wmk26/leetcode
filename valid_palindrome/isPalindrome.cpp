#include<iostream>
#include<string>
using namespace std;

class Solution {
	public:
		bool isPalindrome(string s) {
			if(s.size() == 0){
				return true;
			}
			string new_s;
			for(int i = 0; i < s.size(); i++) {
				if((s[i] >= 65 && s[i] <= 90)){
					new_s += s[i];
				} else if((s[i] >= 97 && s[i] <= 122)) {
					char temp = char(int(s[i]) - 32);
					new_s += temp;
				} else if(s[i] >= 48 && s[i] <= 57) {
					new_s += s[i];
				} else 
					continue;
			}
			cout << new_s << endl;
			int length = new_s.size();
			for(int j = 0; j <= length / 2; j++) {
				if(new_s[j] == new_s[length-j-1]) {
					continue;
				}
				else {
					return false;
				}
			}
			return true;
		}
};

int main() {
	Solution soultion;
	//string s = "A man, a plan, a canal: Panama";
	string s = "1a2";
	cout << soultion.isPalindrome(s) << endl;
	return 0;
}
