#include<bits/stdc++.h>
using namespace std;

class Sieve {
	private:
		vector<int> spf; // This is the array for find the smallest prime factor of any number say, N
	public:
		Sieve(int n) {
			spf.resize(n + 1);
			buildSieve();
		}
		void buildSieve() {
			int n = spf.size();
			for (int i = 2; i < n; i++) spf[i] = i;
			for (int i = 2; i*i < n; i++) {
				if (spf[i] != i) continue; // Removing the prime numbers 
				// other-wise we change the smallest prime factor of every multiple of i to i
				// suppose if come across spf[2] = 2 then we change spf[4] = 2, spf[6] = 2 and so on...
				for (int j = i*i; j < n; j += i) {
					if (spf[j] > i) spf[j] = i; // discarding if there is already a smallest prime factor
				}
			}
		}
		void getSmallestPrimeFactor(int n) {
			unordered_set<int> factors;
			while (n > 1) {
				factors.insert(spf[n]);
				n /= spf[n];
			}
			for (auto i : factors) cout << i << " ";
			cout << endl;
		}
};

int main() {
	int n;
	cin >> n;
	Sieve sieve(n);
	sieve.getSmallestPrimeFactor(n);
	return 0;
}