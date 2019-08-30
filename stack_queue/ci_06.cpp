/*
题目描述：
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

//定义一个辅助栈，辅助栈的栈顶总是原始栈中最小的元素，在压栈过程中，选择性地在辅助栈中压入合适的元素。

class Solution {
public:
    stack<int> stack1,stack2;
    void push(int value) {
        if(stack1.size() == 0 || value <= stack2.top()){
            stack1.push(value);
            stack2.push(value);
        }
        else if(value > stack2.top()){
            int min = stack2.top();
            stack1.push(min);
            stack2.push(min);
        }
    }
    void pop() {
        if(stack1.top() == stack2.top())
            stack2.pop();
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
};

