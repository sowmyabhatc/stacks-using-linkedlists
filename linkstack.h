#include<stdint.h>

#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED

typedef struct _node_  Node;
struct  _node_ {
int32_t data;
Node  *next;
};

typedef struct  _stack_  Stack;  //instead of Slist here we define stack intead of head ,tail, we here define top and length

struct _stack_ {
Node  *top;
uint32_t  length;
char st[];
};

typedef struct _stack_result_  StackResult;

struct  _stack_result_ {
int32_t data;   //data stored in node part
uint8_t status;  //status in stack part
};

#define STACK_OK 1
#define STACK_EMPTY 2  // no stack full because there is no question of linklist being full


/* public interfaces */

Stack    stack_new();
uint8_t  stack_empty(Stack *stk);
Stack*   stack_push(Stack  *stk,int32_t ele, StackResult *res);
Stack*   stack_pop(Stack  *stk,StackResult *res);
Stack*   stack_peek(Stack  *stk,StackResult *res);
//int     evaluatePostfix(char* exp)
#endif // LINKSTACK_H_INCLUDED
