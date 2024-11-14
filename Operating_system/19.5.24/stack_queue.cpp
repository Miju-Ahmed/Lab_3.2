#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

};

void push(struct Node** top, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if(!new_node){
        cout<<"Memory allocation failure";
        return;
    }

    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
    cout<<"Push "<<data<<" into the stack"<<endl;
}

int pop(struct Node** top){
    if(*top==NULL){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }

    struct Node* temp = *top;
    int poped_data = temp->data;
    *top = (*top)->next;
    free(temp);
    return poped_data;
}

int peek(struct Node** top){
    if(*top==NULL){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }

    return (*top)->data;
}

int main(){
    struct Node* top;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    push(&top, 5);

    //cout<<"Popped element is "<<pop(&top)<<endl;
    while(top!=NULL){
        cout<<peek(&top)<<endl;
        pop(&top);
    }
    printStack(top);
}