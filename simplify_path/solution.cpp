#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
	public:
		string simplifyPath(string path) {
			vector<string> stack;
			assert(path[0] == '/');
			int i = 0;
			while(i < path.size()) {
				while(path[i] == '/' && i < path.size())	
					//skip the begining '////'
					i++;
				if(i == path.size()) 
					break;
				int start = i;
				while(path[i] != '/' && i < path.size())
					//decide the end boundary
					i++;
				int end = i;
				string element = path.substr(start, end-start);

				if(element == "..") {
					if(stack.size() > 0) 
						stack.pop_back();
				} else if(element != "."){
					stack.push_back(element);
				}
			}
			if(stack.size() == 0) 
				return "/";
			string simpPath;
			for(int i = 0; i < stack.size(); i++) {
				simpPath += "/" + stack[i];
			}
			return simpPath;
		}
};
