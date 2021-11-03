#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// Given a word pattern and a text. Return the count of the occurences of anagrams of the word in the text.

int countAnagrams(string &text, string &pattern) {
	int ans = 0;
	unordered_map<char, int> m;
	for (auto i : pattern) {
		m[i] += 1;
	}
	int k = pattern.length();
	int count = m.size();
	int front = 0;
	for (int j = 0; j < text.length(); j++) {
		m[text[j]] -= 1;
		if (m[text[j]] == 0) count -= 1;
		if (j - front + 1 < k) continue;
		if (count == 0) ans += 1;
		if (m.find(text[front]) != m.end() && m[text[front]] == 0) count += 1;
		if (m.find(text[front]) != m.end()) m[text[front]] += 1;
		front += 1;
	}	
	return ans;
}

void test_case(){
	string pattern;
	string text;
	cin >> text;
	cin >> pattern;
	cout << countAnagrams(text, pattern) << endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
