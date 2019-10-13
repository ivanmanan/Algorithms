#include <iostream>
#include <queue>

using namespace std;

class stack {
 public:
    stack() : m_size(0) {};
    void push(int x);
    void pop();
    int top();
 private:
    queue<int> q1;
    queue<int> q2;
    int m_size;
    int m_top;
};


// O(1) push operation
void stack::push(int x) {
    m_size++;

    q1.push(x);
    m_top = x;
}

// O(N) pop operation
void stack::pop() {

    int front;
    for (int i = 0; i < m_size; i++){
        front = q1.front();
        q1.pop();
        if (i != m_size - 1) {
            q2.push(front);
        }
    }

    m_size--;
    swap(q1, q2);
}

int stack::top() {
    return m_top;
}

int stack::size() {
    return m_size;
}

int main() {
    stack s;

    s.push(5);
    s.push(3);
    cout << s.top() << endl; // should be 3
    s.pop();
    cout << s.top() << endl; // should be 5
}