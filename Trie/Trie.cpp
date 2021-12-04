#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
	bool isEnd;
	Trie* arr[256] = {};
public:
	Trie() {}

	void buildTrie(vector<string>& words) {
		for (auto i : words) {
			insert(i);
		}
	}
	void insert(string word) {
		Trie* node = this;
		for (auto c : word) {
			if (node->arr[c - 'a'] == NULL) 
				node->arr[c - 'a'] = new Trie();
			else
				node = node->arr[c- 'a'];
		}
		node->isEnd = true;
	}
	bool search(string word) {
		Trie* node = this;
		for (auto c : word) {
			if (node->arr[c - 'a'] == NULL) return false;
			node = node->arr[c - 'a'];
		}
		return node->isEnd;
	}
};
int main() {
	return 0;
}