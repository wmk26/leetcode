//have errors
#include<iostream>
#include<map>
#include<string>
using namespace std;

class Solution {
	public:
		int romanToInt(string s) {
			map<string, int> m;
			m['I'] = 1;
			m['V'] = 5;
			m['X'] = 10;
			m['L'] = 50;
			m['C'] = 100;
			m['D'] = 500;
			m['M'] = 1000;
			
			int num = 0;

			for(int i = s.size() - 1; i >= 0; i--) {
				if((i-1>0) && (m.find(s.at(i-1)) < m.find(s.at(i)))) {
					num += (int)(m.find(s.at(i)) - m.find(s.at(i-1)));
					i--;
				} else {
					num += (int)m.find(s.at(i));
				}
			}
			return num;
		}
};

int main () {
	Solution s;
	cout << s.romanToInt("MMMCDLIV") << endl;
	return 0;
}
