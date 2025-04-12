#pragma once
#ifndef STACK_H
#define STACK_H

#include "arena.h"
#include "types.h"

#define INITIAL_STACK_SIZE 10

/** Declaration of a custom stack */
#define CUSTOM_STACK(stack_name, value_type)                                                                                               \
    /** A stack_name stack node. */                                                                                                        \
    typedef struct stack_name##StackNode                                                                                                   \
    {                                                                                                                                      \
        value_type value;                                                                                                                  \
        stack_name##StackNode *next;                                                                                                       \
    } stack_name##StackNode;                                                                                                               \
                                                                                                                                           \
    /** A stack_name stack. */                                                                                                             \
    typedef struct stack_name##Stack                                                                                                       \
    {                                                                                                                                      \
        Arena arena;                                                                                                                       \
        usize size;                                                                                                                        \
        stack_name##StackNode *first;                                                                                                      \
    } stack_name##Stack;                                                                                                                   \
                                                                                                                                           \
    /**                                                                                                                                    \
     * Create a stack_name stack.                                                                                                          \
     * @returns Created stack_name stack.                                                                                                  \
     */                                                                                                                                    \
    inline stack_name##Stack stack_name##StackCreate()                                                                                     \
    {                                                                                                                                      \
        return (stack_name##Stack){.arena = ArenaCreateCustom(sizeof(value_type) * INITIAL_STACK_SIZE), .size = 0, .first = NULL};         \
    }                                                                                                                                      \
    /**                                                                                                                                    \
     * Create a stack_name stack with a custom initial size.                                                                               \
     * @param size Initial stack size.                                                                                                     \
     * @returns Created stack_name stack.                                                                                                  \
     */                                                                                                                                    \
    inline stack_name##Stack stack_name##StackCreateCustom(usize size)                                                                     \
    {                                                                                                                                      \
        return (stack_name##Stack){.arena = ArenaCreateCustom(sizeof(value_type) * size), .size = 0, .first = NULL};                       \
    }                                                                                                                                      \
                                                                                                                                           \
    /**                                                                                                                                    \
     * Deletes a stack_name stack.                                                                                                         \
     * @param stack The stack_name stack to delete.                                                                                        \
     */                                                                                                                                    \
    inline void stack_name##StackDelete(stack_name##Stack *stack) { ArenaDelete(&stack->arena); }                                          \
                                                                                                                                           \
    /**                                                                                                                                    \
     * Adds an item to the stack_name stack.                                                                                               \
     * @param stack The stack_name stack to use.                                                                                           \
     */                                                                                                                                    \
    inline void stack_name##StackPush(stack_name##Stack *stack, value_type value)                                                          \
    {                                                                                                                                      \
        stack_name##StackNode *node = ArenaPushType(stack->arena, stack_name##StackNode);                                                  \
        *node = (stack_name##StackNode){.value = value, .next = stack->first};                                                             \
        stack->first = node;                                                                                                               \
        ++stack->size;                                                                                                                     \
    }                                                                                                                                      \
    /**                                                                                                                                    \
     * Removes an item from the stack_name stack.                                                                                          \
     * @param stack The stack_name stack to use.                                                                                           \
     */                                                                                                                                    \
    inline value_type stack_name##StackPop(stack_name##Stack *stack)                                                                       \
    {                                                                                                                                      \
        value_type value = stack->first->value;                                                                                            \
        stack->first = stack->first->next;                                                                                                 \
        --stack->size;                                                                                                                     \
        ArenaPopType(stack->arena, stack_name##StackNode); /* The last bytes added are the first element's */                              \
        return value;                                                                                                                      \
    }                                                                                                                                      \
                                                                                                                                           \
    /**                                                                                                                                    \
     * Retrieves the size of a stack_name stack.                                                                                           \
     * @param stack The stack_name stack to use.                                                                                           \
     */                                                                                                                                    \
    inline usize StackSize(stack_name##Stack stack) { return stack.size; }

#endif // STACK_H