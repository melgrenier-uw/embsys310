#include <assert.h>
#include "stackHeader.h"

int main(void)
{
    //***********************************************************************************************************
    // Test 01: Push one item, and pop it. Verify push and pop are successful and item is returned              *
    //***********************************************************************************************************
    int result = 0;
    int result1 = 0;
    int testNum = 0;
    
    // Arrange
    stack_init();
    
    // Act
    result = stack_push(12);
    result1 = stack_pop(&testNum);
    
    // Assert
    assert(0 == result);
    assert(0 == result1);
    assert(12 == testNum);
    
    //***********************************************************************************************************
    // Test 02: Pop from emtpy queue. Verify pop from empty queue returns error                                 *
    //***********************************************************************************************************
    // Arrange
    result = 0;
    testNum = 3;
    stack_init();
    
    // Act
    result = stack_pop(&testNum);
    
    // Assert
    assert(-1 == result);
    assert(3 == testNum);
    
    //***********************************************************************************************************
    // Test 03: Fill queue then push one more item. Verify push to full stack returns error                     *
    //***********************************************************************************************************
    // Arrange
    result = 0;
    stack_init();
    
    // Act and Assert
    result = stack_push(1);
    assert(0 == result);
    
    result = stack_push(2);
    assert(0 == result);
    
    result = stack_push(3);
    assert(0 == result);
    
    result = stack_push(4);
    assert(0 == result);
    
    result = stack_push(5);
    assert(0 == result);
    
    result1 = stack_push(10);
    assert(-1 == result1);
    
    //***********************************************************************************************************
    // Test 04: Fill queue, then pop all items. Verify all items are in order                                   *
    //***********************************************************************************************************
    // Act
    testNum = 0;
    stack_init();
    
    // Arrange
    stack_push(1);
    stack_push(2);
    stack_push(3);
    stack_push(4);
    stack_push(5);
    
    // Assert
    assert(0 == stack_pop(&testNum));
    assert(1 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(2 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(3 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(4 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(5 == testNum);
    
    //***********************************************************************************************************
    // Test 05: Fill queue, pop one item, then push one item, then pop all items. Verify all items are in order *
    //***********************************************************************************************************
    // Act
    testNum = 0;
    stack_init();
    
    // Arrange
    stack_push(1);
    stack_push(2);
    stack_push(3);
    stack_push(4);
    stack_push(5);
    
    // Assert
    assert(0 == stack_pop(&testNum));
    assert(1 == testNum);
    
    assert(0 == stack_push(8));

    assert(0 == stack_pop(&testNum));
    assert(2 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(3 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(4 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(5 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(8 == testNum);
    
    //***********************************************************************************************************
    // Test 06: Fill queue and retrieve all items twice. Verify all items are in order each time                *
    //***********************************************************************************************************
     // Act
    testNum = 0;
    stack_init();
    
    // Arrange
    stack_push(1);
    stack_push(2);
    stack_push(3);
    stack_push(4);
    stack_push(5);
    
    // Assert
    assert(0 == stack_pop(&testNum));
    assert(1 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(2 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(3 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(4 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(5 == testNum);
    
    assert(0 == stack_push(11));
    assert(0 == stack_push(12));
    assert(0 == stack_push(13));
    assert(0 == stack_push(14));
    assert(0 == stack_push(15));
    
    assert(0 == stack_pop(&testNum));
    assert(11 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(12 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(13 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(14 == testNum);
    assert(0 == stack_pop(&testNum));
    assert(15 == testNum);
 
    
  return 0;
}