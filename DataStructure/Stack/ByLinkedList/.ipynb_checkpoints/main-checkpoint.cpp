#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int dataType;
struct node{        //链栈节点
    dataType data;  //数值
    node *next;     //指针域
};

class Lstack{
public:
    Lstack();
    ~Lstack();
    void push(dataType var); //压栈
    void pop();              //出栈
    dataType f_top();        //取栈顶元素
    bool isEmpty();          //判断是否为空
private:
    node *top;               //栈顶指针，top等于NULL表示空栈
};

Lstack::Lstack(){
    top = NULL;              //top等于NULL表示栈为空
}

Lstack::~Lstack(){
    node *ptr = NULL;
    while(top != NULL){
        ptr = top->next;
        delete top;
        top = ptr;
    }
}

void Lstack::push(dataType a){
    node *ptr = new node;
    ptr->data = a;              //新栈顶存值
    ptr->next = top;            //新栈顶指向旧栈顶
    top = ptr;                  //top指向新栈顶
}

void Lstack::pop(){
    if (!isEmpty()){            //判空
        node *ptr = top->next;  //预存下一节点的指针
        delete top;             //释放栈顶空间
        top = ptr;              //栈顶变化
    }
    else
        cout << "The stack is empty!" << endl;
}

dataType Lstack::f_top(){       //判空
    if(isEmpty()){
        cout << "The stack is empty!" << endl;
        return -1;
    }
    else
        return top->data;       //返回栈顶元素
}

bool Lstack:: isEmpty(){
    return top == NULL;         //栈顶为NULL表示栈空
}

int main (){   // 测试代码
    Lstack s;
    for (int i=0; i<11; i++){
        s.push(i);
        cout << s.f_top() << endl;
    }
    for (int i=0; i<11; i++){
        s.pop();
        cout << s.f_top() << endl;
    }
    //system("Pause");
    return 0;
}