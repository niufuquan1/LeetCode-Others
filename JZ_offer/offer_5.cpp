/*
 * 请用栈实现一个队列，支持如下四种操作：
 * push(x) – 将元素x插到队尾；
 * pop() – 将队首的元素弹出，并返回该元素；
 * peek() – 返回队首元素；
 * empty() – 返回队列是否为空；
 * 注意：
 * 你只能使用栈的标准操作：push to top，peek/pop from top, size 和 is empty；
 * 如果你选择的编程语言没有栈的标准库，你可以使用list或者deque等模拟栈的操作；
 * 输入数据保证合法，例如，在队列为空时，不会进行pop或者peek等操作；
 * 样例
 * MyQueue queue = new MyQueue();
 * queue.push(1);
 * queue.push(2);
 * queue.peek();  // returns 1
 * queue.pop();   // returns 1
 * queue.empty(); // returns false
 */
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stk,cache;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    //思路：压入栈，是一个队列和栈相同的常规操作，直接使用push即可
    void push(int x) {
        stk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    //由于队列是先进先出，因此出队列应该是栈的首个元素出栈，因此需要通过第二个堆栈，将堆栈中的元素再进行一次压栈操作，如此一来，首位元素便到了末
    // 尾，返回末尾的元素就是需要出栈的元素
    int pop() {
        copy(stk,cache);
        int res = cache.top();
        cache.pop();
        copy(cache, stk);
        return res;
    }

    /** Get the front element. */
    int peek() {
        copy(stk, cache);
        int res = cache.top();
        copy(cache, stk);
        return res;
    }

    void copy(stack<int> &a, stack<int> &b) {
        while (a.size()) {
            b.push(a.top());
            a.pop();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};
