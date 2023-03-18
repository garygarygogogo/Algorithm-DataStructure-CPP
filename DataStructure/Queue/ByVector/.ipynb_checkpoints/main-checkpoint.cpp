#include<iostream>
using namespace std;

typedef int dataType;
class Queue{
private:
    dataType* arrays; // 成员数组
    int front;   // 队前
    int end;     // 队后
    int size_a;  // 数组大小
public:
    Queue();
    ~Queue();

    void push(dataType data);
    dataType pop();
    bool isEmpty();
    bool isFull();
};

Queue::Queue():size_a(10),front(0),end(0){ // 初始化
    arrays = new dataType[size_a];       // 申请10个内存大小的空间
}

Queue::~Queue(){
    delete[] arrays;
    arrays = nullptr;
}

void Queue::push(dataType data){
    if(isFull())
        cout << "The queue is full!" << endl;
    else{
        arrays[end] = data;
        end = (end+1) % size_a; // 循环队列，如果队前有空间，元素放队前
    }
}

dataType Queue::pop(){
    if(isEmpty()){
        cout << "The queue is empty!" << endl;
        return -1;
    }
    else{
        dataType t = arrays[front];
        front = (front+1) % size_a;
        return t;
    }
}

bool Queue::isEmpty(){
    return (front == end);
}

bool Queue::isFull(){
    return (front == ((end+1) % size_a));
}

int main (){ // 测试用例
    Queue q;
    for (int i=0; i<11; i++){
        q.push(i);
    }
    for (int i=0; i<11; i++){
        cout << q.pop() << endl;
    }
    return 0;
}
