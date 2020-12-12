#include <assert.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linkstack.h"

Stack stack_new(){
Stack s1={NULL,0};
return s1;
}

uint8_t stack_empty(Stack *stk){
assert (stk!=NULL);
return (stk->length==0);
}

static Node*  _get_new_node_(int32_t ele){
Node *newnode=(Node*)malloc(sizeof(Node));
newnode->data=ele;
newnode->next=NULL;
return newnode;
}

Stack*  stack_push(Stack *stk,int32_t ele,StackResult *res){
assert(stk!=NULL);
Node *new_node=_get_new_node_(ele);

new_node->next=stk->top;
stk->top=new_node;
++stk->length;
res->data=ele;
res->status=STACK_OK;
assert(stk->length >0);
return stk;
}


Stack* stack_pop(Stack* stk, StackResult  *res){
assert(stk!=NULL);
Node *temp;
if(stk->length !=0){

    res->data=stk->top->data;
    temp=stk->top;
    stk->top=stk->top->next;
    --stk->length;
    res->status=STACK_OK;
    free(temp);


}else{
res->status=STACK_EMPTY;
}
return stk;
}


Stack*  stack_peek(Stack *stk,StackResult *res){
assert(stk!=NULL);
if(stk->length!=0){
    res->data=stk->top->data;
    res->status=STACK_OK;
}
else{
    res->status=STACK_EMPTY;
}

return stk;
}



//Design a queue using two stacks as instance variables, such that all queue operations execute in amortized O(1) time.




void enqueue(Queue *q,float ele){
StackResult res;
stack_push(&q->stk1,ele,&res);

}


int deQueue(Queue* q)
{
    int x;
    StackResult res;
    /* If both stacks are empty then error */
    if (q->stk1 == NULL && q->stk2 == NULL) {
        //printf("Q is empty");
        return 0;
    }

    /* Move elements from stack1 to stack 2 only if
       stack2 is empty */
    if (q->stk2 == NULL) {
        while (q->stk1 != NULL) {
            x = stack_pop(&q->stk1,&res);
            stack_push(&q->stk2, x,&res);
        }
    }

    x = stack_pop(&q->stk2,&res);
    return x;
}





