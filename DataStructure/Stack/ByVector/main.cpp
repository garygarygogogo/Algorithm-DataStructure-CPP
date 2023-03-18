#include<iostream>
using namespace std;

typedef int dataType;
class Stack{
private:
    dataType* arrays; // 成员数组
    int top;     // 栈顶
    int size_a;  // 数组大小
public:
    Stack();
    ~Stack();

    void push(dataType data); // 入栈
    void pop();               // 出栈
    dataType f_top();         // 访问栈顶元素
    bool isEmpty();           // 判空
    bool isFull();            // 判满
};

Stack::Stack():size_a(10), top(-1){      // 初始化
    arrays = new dataType[size_a];       // 申请10个内存大小的空间
}

Stack::~Stack(){
    delete[] arrays;
    arrays = nullptr;
}

void Stack::push(dataType data){
    if(isFull())
        cout << "The stack is full!" << endl;
    else
        arrays[++top] = data;
}

void Stack::pop(){
    if(isEmpty())
        cout << "The stack is empty!" << endl;
    else
        top--;
}

dataType Stack::f_top(){ // 返回栈顶元素
    if(isEmpty()){
        cout << "The stack is empty!" << endl;
        return -1;
    }
    else
        return arrays[top];
}

bool Stack::isEmpty(){
    return (top == -1);
}

bool Stack::isFull(){
    return (top >= size_a-1); // 当top为9的时候栈已满
}

int main (){ // 测试用例
    Stack s;
    for (int i=0; i<11; i++){
        s.push(i);
        cout << s.f_top() << endl;
    }
    for (int i=0; i<11; i++){
        s.pop();
        cout << s.f_top() << endl;
    }
    return 0;
}