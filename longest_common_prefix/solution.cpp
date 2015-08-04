#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			int n = strs.size();
			string res;
			if(n == 0) 
				return res;
			for(int pos = 0; pos < strs[0].size(); pos++) {
				for(int k = 1; k < n; k++) {
					if(strs[k].size() == pos || strs[k][pos] != strs[0][pos])
						return res;
				}
				res.push_back(strs[0][pos]);
			}
			return res;
		}
};
