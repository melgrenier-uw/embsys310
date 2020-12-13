#include "stackHeader.h"

#define STACK_SIZE 5

int StackStore[STACK_SIZE];

int* pushPtr;
int* popPtr;

// Initialize
void stack_init(void) {
    pushPtr= 0;
    popPtr = 0;
    
    for (int i=0; i<STACK_SIZE; i++) {
        StackStore[i] = 0; 
    }
}

// Add data to stack
int stack_push(int data) {
    // Stack is full, cannot store new data. Return error
    if (popPtr == StackStore && pushPtr == &StackStore[STACK_SIZE-1]){
        return -1;
    }
    
    if (popPtr == 0) {
        popPtr = &StackStore[0];
    }
    
    // Increment or reinitialize pointers, as needed
    if (pushPtr == 0 || pushPtr == &StackStore[STACK_SIZE-1]) {
        pushPtr = &StackStore[0];
    }
    else {
        pushPtr++;
    }
     
    // Store element in stack
    *pushPtr = data;
    return 0;
}

// Retrieve data from stack
int stack_pop(int *var) {
    // Stack is empty, no data to retrieve. Return error
    if (popPtr == 0) {
        return -1;
    }
    
    // Retrieve data
    *var = *popPtr;
    
    // Increment or reinitialize pointers, as needed
    if (popPtr == pushPtr) {
        pushPtr = 0;
        popPtr = 0;
    }
    else if (popPtr == &StackStore[STACK_SIZE-1]) {
        popPtr = &StackStore[0];
    }
    else {
        popPtr++;
    }     
    return 0;
}