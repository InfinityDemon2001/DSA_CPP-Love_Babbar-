#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
	//Base case
	if(stack.empty() || (!stack.empty() && stack.top() < num)) {
		stack.push(num);
		return;
	}

	int n = stack.top();
	stack.pop();

	//Recursive call
	sortedInsert(stack, num);

	stack.push(n);
}

void sortStack(stack<int> &stack)
{
	//Base case
	if(stack.empty()) {
		return;
	}

	int num = stack.top();
	stack.pop();

	//Recursive call
	sortStack(stack);

	sortedInsert(stack, num);
}