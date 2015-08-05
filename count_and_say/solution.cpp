#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution {
	public:
		string countAndSay(int n) {
			if(n < 1) 
				return "";
			string prev = "1";
			for(int i = 2; i <= n; i++) {
				char curChar = prev[0];
				//curChar出现的次数
				int times = 1;
				string tmpStr;
				//处理边界条件
				prev.push_back('#');
				for(int k = 1; k < prev.size(); k++) {
					if(prev[k] == curChar) 
						times++;
					else {
						tmpStr += to_string(times);
						tmpStr.push_back(curChar);
						curChar = prev[k];
						times = 1;
					}
				}
				prev = tmpStr;
			}
			return prev;
		}
};

int main() {
	Solution s;
	cout << s.countAndSay(2) << endl;
	return 0;
}
