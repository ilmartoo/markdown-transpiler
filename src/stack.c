#include "stack.h"

Stack StackCreate() { return (Stack){.arena = ArenaCreateCustom(sizeof(StackValue) * 10), .size = 0, .first = NULL}; }

void StackDelete(Stack *stack) { ArenaDelete(&stack->arena); }

void StackPush(Stack *stack, StackValue value)
{
    StackNode *node = ArenaPushType(stack->arena, StackNode);
    *node = (StackNode){.value = value, .next = stack->first};
    stack->first = node;
    ++stack->size;
}

StackValue StackPop(Stack *stack)
{
    StackValue value = stack->first->value;
    stack->first = stack->first->next;
    --stack->size;
    ArenaPopType(stack->arena, StackNode); // The last bytes added are the first element's
    return value;
}

usize StackSize(Stack stack) { return stack.size; }
