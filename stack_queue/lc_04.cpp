/*
题目描述：
使用队列实现栈的下列操作：

    push(x) -- 元素 x 入栈
    pop() -- 移除栈顶元素
    top() -- 获取栈顶元素
    empty() -- 返回栈是否为空

注意:

    你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
    你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
    你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
*/


//解法1

class MyStack {
private:
    queue<int> data;
    queue<int> help;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(data.size() != 1){
            int out = data.front();
            data.pop();
            help.push(out);
        }
        int top = data.front();
        data.pop();
        while(!help.empty()){
            int in = help.front();
            help.pop();
            data.push(in);
        }
        return top;
    }
    
    /** Get the top element. */
    int top() {
        while(data.size() != 1){
            int out = data.front();
            data.pop();
            help.push(out);
        }
        int top = data.front();
        data.pop();
        help.push(top);
        while(!help.empty()){
            int in = help.front();
            help.pop();
            data.push(in);
        }
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


//解法2    

class MyStack {
private:
    queue<int> data;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) { 
        queue<int> help; 
        int t=0; 
        int length=data.size(); 
        for(int i=0; i<length; i++) { 
            t=data.front(); 
            data.pop(); 
            help.push(t); 
        } 
        //     temp.push(que.pop()); 
        data.push(x); // cout<<x<<" "; 
        for(int i=0; i<length; i++) { 
            t=help.front(); 
            data.push(t); 
            help.pop(); 
            // cout<<t<<" "; 
        } 
        //cout<<endl; //     que.push(temp.pop()); 
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(data.empty())
            return 0;
        int t=data.front();
        data.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        if(data.empty())
            return 0;
        return data.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};



