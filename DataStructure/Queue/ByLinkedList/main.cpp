#include<iostream>
using namespace std;

typedef int dataType;
struct node{             //链栈节点
    dataType data;       //数值
    node *next;          //指针域
};

class Queue{
public:
    Queue();
    ~Queue();

    void push(dataType var); 
    dataType pop();           
    int size();       
    bool isEmpty();          
private:
    node* front;   // 队前
    node* end;     // 队后
    int size_a;    // 内存大小
};

Queue::Queue():size_a(0),end(NULL){ // 初始化
    front = new node;
    front->next = NULL;
}

Queue::~Queue(){
    node *ptr = NULL;
    while(front != NULL){
        ptr = front->next;
        delete front;
        front = ptr;
    }
}

void Queue::push(dataType a){ // end创建节点连接至front后面
    if (end == NULL){
        end = new node;
        end->data = a;
        end->next = NULL;
        front->next = end;
    }
    else{
        node* pTail = end; // 在end与front之间插入节点
        end = new node;
        end->data = a;
        pTail->next = end;
        end->next = NULL;
    }
    size_a++;                
}

dataType Queue::pop(){
    if (isEmpty()){
        cout << "The queue is empty!" << endl;
        return -1;
    }
    dataType data = front->next->data; // 删除front后一个节点
    node* pCurr = front->next;
    front->next = pCurr->next;
    delete pCurr;
    if (isEmpty()){
        end = NULL;
    }
    size_a--;
    return data;
}

int Queue::size(){
    return size_a;            //返回队列大小
}

bool Queue:: isEmpty(){
    return (size() == 0);
}

int main (){ // 测试用例
    Queue q;
    for (int i=0; i<11; i++){
        q.push(i);
    }
    for (int i=0; i<12; i++){
        cout << q.pop() << endl;
    }
    return 0;
}