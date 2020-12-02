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








