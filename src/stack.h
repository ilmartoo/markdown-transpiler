#pragma once
#ifndef STACK_H
#define STACK_H

#include "types.h"
#include "arena.h"

typedef u16 StackValue;

typedef struct StackNode
{
    StackValue value;
    StackNode *next;
} StackNode;

typedef struct Stack
{
    Arena arena;
    usize size;
    StackNode *first;
} Stack;

Stack StackCreate();
void StackDelete(Stack *stack);
void StackPush(Stack *stack, StackValue value);
StackValue StackPop(Stack *stack);
usize StackSize(Stack stack);

#endif // STACK_H