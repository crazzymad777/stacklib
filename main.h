#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define SIZETYPE uint_fast32_t

struct Stack{
	void* Data;
	SIZETYPE DataSize;
};

// Allocates buffer. Copies data from stack top to that buffer. Buffer should be freed by caller.
void* StackTop(struct Stack* st, SIZETYPE siz);

// Push data on stack object
void StackPush(struct Stack* st, void* data, SIZETYPE siz);

// pop data from stack object
void StackPop(struct Stack* st, SIZETYPE siz);

// Creates stack object
struct Stack* CreateStack();

// Destroy stack object
void DestroyStack(struct Stack* st);

// Copies data from stack top to memory
void StackTopToMemory(struct Stack* st, void* memory, SIZETYPE siz);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__

