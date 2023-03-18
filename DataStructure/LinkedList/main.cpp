struct ListNode {
    int data;
    ListNode *next;
};

// define a list
ListNode * initLink(){
    ListNode * p=(ListNode*)malloc(sizeof(ListNode));//创建一个头结点
    ListNode * temp=p;//声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (int i=1; i<5; i++) {
        ListNode *node=(ListNode*)malloc(sizeof(ListNode));
        node->data=i;
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    return p;
}

// search node 
int selectElem(ListNode * p,int elem){
    ListNode * t=p;
    int i=1;
    while (t->next) {
        t=t->next;
        if (t->data==elem) {
            return i;
        }
        i++;
    }
    return -1;
}

// insert node
ListNode * insertElem(ListNode * p,int elem,int add){
    ListNode * temp=p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i=1; i<add; i++) {
        if (temp==NULL) {
            printf("插入位置无效\n");
            return p;
        }
        temp=temp->next;
    }    
    //创建插入结点node
    ListNode * node=(ListNode*)malloc(sizeof(ListNode));
    node->data=elem;
    //向链表中插入结点
    node->next=temp->next;
    temp->next=node;
    return  p;
}

// delete node
ListNode * delElem(ListNode * p,int add){
    ListNode * temp=p;
    //temp指向被删除结点的上一个结点
    for (int i=1; i<add-1; i++) {
        temp=temp->next;
        if (temp->next == NULL) // 判断add的有效性
            return p;
    }
    ListNode *del=temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next=temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}
