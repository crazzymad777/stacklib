/**
 * Copyright (c) 2021 Yuri Moskov
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted (subject to the limitations in the disclaimer below) provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of Yuri Moskov nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 */

#include "main.h"

// Allocates buffer. Copies data from stack top to that buffer. Buffer should be freed by caller.
void* StackTop(struct Stack* st, SIZETYPE siz) {
    SIZETYPE realsize = siz;
    if(realsize > st->DataSize) {
        realsize = st->DataSize;
    }

    void* datareturn = (void*)malloc(siz);

    if(st->Data != NULL) memcpy(datareturn, st->Data, realsize);
    return datareturn;
}

// Copies data from stack top to memory
void StackTopToMemory(struct Stack* st, void* memory, SIZETYPE siz) {
    SIZETYPE realsize = siz;
    if(realsize > st->DataSize){
        realsize = st->DataSize;
    }

    if(st->Data != NULL) memcpy(memory, st->Data, realsize);
}

// Push data on stack object
void StackPush(struct Stack* st, void* data, SIZETYPE siz) {
    SIZETYPE newdataSize = siz+st->DataSize;
    void* newdata = malloc(newdataSize);

    if(st->Data != NULL) {
	    memcpy(newdata+siz, st->Data, st->DataSize);
	    free(st->Data);
    }

    if(data != NULL) {
    	memcpy(newdata, data, siz);
    }

    st->Data = newdata;
    st->DataSize = newdataSize;
}

// pop data from stack object
void StackPop(struct Stack* st, SIZETYPE siz) {
    int64_t newdataSize = st->DataSize-siz;

    if(newdataSize <= 0) {
        if(st->Data!=NULL)
            free(st->Data);
        st->DataSize = 0;
        st->Data = NULL;
    } else {
        void* newdata = malloc(newdataSize);

        if(st->Data != NULL){
            SIZETYPE realsize = newdataSize;
            if(realsize>st->DataSize) realsize = st->DataSize;
            memcpy(newdata, st->Data+siz, realsize);

            free(st->Data);
        }
        st->Data = newdata;
        st->DataSize = newdataSize;
    }
}

// Creates stack object
struct Stack* CreateStack() {
    struct Stack* newstack=malloc(sizeof(struct Stack));
    newstack->Data = NULL;
    newstack->DataSize = 0;
    return newstack;
}

// Destroy stack object
void DestroyStack(struct Stack* st) {
    if(st->Data != NULL){
        free(st->Data);
        st->Data = NULL;
        st->DataSize = 0;
    }

    free(st);
    st = NULL;
}

