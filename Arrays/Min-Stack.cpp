#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
	stack<int> s;
	int minElement;
public:
	MinStack() {}
	
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minElement = val;
        } else if (val < minElement) {
            s.push((2LL * val) - minElement);
            minElement = val;
        } else {
            s.push(val);
        }
    }
    
    void pop() {
        if (s.empty()) return;
        int val = s.top();
        s.pop();
        if (val < minElement) minElement = 2LL * minElement - val;
    }
    
    int top() {
        if (s.empty()) return -1;
        int val = s.top();
        return (val < minElement) ? minElement : val;
    }
    
    int getMin() {
        return minElement;
    }
};

int main() {
	return 0;
}
