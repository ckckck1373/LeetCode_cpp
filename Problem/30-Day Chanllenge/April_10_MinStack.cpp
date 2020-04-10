/*
    Date: 4/10/2020
    
*/

class MinStack {
private:
    int *stack;
    int top_n;
    int *stack_min;
    int capacity;
    
    void DoubleCapacity(){
        capacity *=2;
        int *newStack = new int[capacity];
        int *newStack_min = new int[capacity];
        
        for(int i=0;i < capacity/2;i++){
            newStack[i] = stack[i];
            newStack_min[i] = stack_min[i];
        }
        delete [] stack;
        delete [] stack_min;
        stack = newStack;
        stack_min = newStack_min;
    }
    
public:
    /** initialize your data structure here. */
    MinStack() {
        top_n = -1;
        capacity = 100;
        stack = new int[capacity];
        stack_min = new int[capacity];

    }
    
    void push(int x) {
        if(top_n == capacity-1){
            DoubleCapacity();
        }
        top_n = top_n + 1;
        stack[top_n] = x;
        
        if(top_n==0){
            stack_min[top_n] = x;
        }else{
            stack_min[top_n] = (x<stack_min[top_n-1])? x: stack_min[top_n-1];
        }
        
    }
    
    void pop() {
        if(top_n==-1){
            cout << " Minstack is empty.\n";
            return;
        }
        top_n = top_n-1;
    }
    
    int top() {
        if(top_n==-1){
            cout << "Stack is empty.\n";
            return -1;
        }
        return stack[top_n];
    }
    
    int getMin() {
        if(top_n==-1){
            cout << "Stack is empty.\n";
            return -1;
        }
        return stack_min[top_n];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



/*
    top=-1 : nothing in the stack
    top=0 : first thing
    ** remember do not set value in the array[-1]-> run time error
*/




/* version2 */

class MinStack {
struct Data{
    int num;
    int mins;
};

private:
    Data *stack;
    int top_n;
    int capacity;

    void DoubleCapacity(){
        capacity *=2;
        Data *newStack = new Data[capacity];

        for(int i=0;i < capacity/2;i++){
            newStack[i] = stack[i];
        }
        delete [] stack;
        stack = newStack;
    }

public:
    /** initialize your data structure here. */
    MinStack() {
        top_n = -1;
        capacity = 100;
        stack = new Data[capacity];
    }

    void push(int x) {
        if(top_n == capacity-1){
            DoubleCapacity();
        }
        top_n++;
        int min = (top_n == 0 || x<stack[top_n-1].mins)? x: stack[top_n-1].mins;
        stack[top_n] = {x, min};
    }

    void pop() {
        top_n--;
    }

    int top() {
        return stack[top_n].num;
    }

    int getMin() {
        return stack[top_n].mins;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */