#include <iostream>
#include <vector>

using namespace std;


class Stack {
  public:
	vector<int> arr;
	Stack() {top = -1;}
	void push(int x);
	int pop();
	bool isEmpty();
  private:
	int top;
};

void Stack::push(int x) {
	arr.push_back(x);
	top++;
}

int Stack::pop() {
	if (top >= 0) {
		int temp = arr[top];
		arr.erase(arr.begin() + top);
		top--;
		return temp;
	}
	else
		cout << "Stack is empty" << endl;
	return 0;
}

bool Stack::isEmpty() {
	if (top >= 0) {
		return true;
	}
	return false;
}



int main() {
	Stack s;
	s.push(5);
	s.push(10);
	s.push(15);

	int x = s.pop();
	cout << x << endl;
	x = s.pop();
	cout << x << endl;
	x = s.pop();
	cout << x << endl;

}