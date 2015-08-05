#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
	public:
		vector<string> anagrams(vector<string> $strs) {
			vector<string> ret;
			//key为排序之后的string，value记录相同key的string位置
			unordered_map<string, vector<int>> ht;

			for(int i = 0; i < strs.size(); i++) {
				string key = strs[i];
				//排序
				sort(key.begin(), key.end());
				ht[key].push_back(i);
			}

			for(unordered_map<string, vector<int>>::iterator it = ht.begin(); it != ht.end(); it++) {
				if(it->second.size() > 1) {
					for(int i = 0; i < it->second.size(); i++) {
						ret.push_back(strs[it->second[i]]);
					}
				}
			}
			return ret;
		}
};
