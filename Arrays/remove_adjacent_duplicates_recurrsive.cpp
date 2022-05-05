#include<bits/stdc++.h>
using namespace std;

string remove(string s) {
	char temp = '\0';
	int n = s.size();
	string sf = "";
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (temp  == s[i]) {
			flag = true;
			continue;
		} else {
			if (flag) {
				sf.pop_back();
			}
			temp = s[i];
			sf += s[i];
			flag = false;
		}
	}
	if (flag) sf.pop_back();
	if (n == sf.size()) return sf;
	return remove(sf);
}

int main() {
	string s;
	cin >> s;
	cout << remove(s) << endl;
}