#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "linkstack.h"


void test_empty_stack(){
Stack s1=stack_new(20);
Stack *stk=&s1;
assert(stack_empty(stk)==1);
}

void test_full_stack(){
Stack s1=stack_new(2);
Stack *stk=&s1;
StackResult res;
stk=stack_push(stk,10,&res);
assert(res.status==STACK_OK);
stk=stack_push(stk,20,&res);
assert(res.status==STACK_OK);
stk=stack_push(stk,30,&res);

}

void test_stack(){
Stack s1=stack_new(5);
Stack *stk=&s1;
StackResult res;
stk=stack_pop(stk,&res);
assert(res.status==STACK_EMPTY);


stk=stack_push(stk,10,&res);
stk=stack_push(stk,20,&res);
stk=stack_peek(stk,&res);
assert(res.status==STACK_OK && res.data==20);

stk=stack_pop(stk,&res);
assert(res.status==STACK_OK && res.data==20);
stk=stack_peek(stk,&res);
assert(res.status==STACK_OK && res.data==10);

stk=stack_pop(stk,&res);
assert(stack_empty(stk)==1);
}


//Design a queue using two stacks as instance variables, such that all queue operations execute in amortized O(1) time.

void test_queue(){
Queue *q = (Queue*)malloc(sizeof(Queue));
q->stk1 = NULL;
q->stk2 = NULL;
enqueue(q, 1);
enqueue(q, 2);
enqueue(q, 3);

assert(deQueue(q)==1);
assert(deQueue(q)==2);
assert(deQueue(q)==3);


}
int main()
{
    //test_empty_stack();
    //test_full_stack();
    //test_stack();
    test_queue();
    return 0;
}
