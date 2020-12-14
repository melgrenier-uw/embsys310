// Swapping Pointers Program

void swap(int **ptr1, int **ptr2);

int main(void)
{
    // Initialize variables
    int x = 12;
    int y = 20;
    int *xPtr = &x;
    int *yPtr = &y;
    int **pp1 = &xPtr;
    int **pp2 = &yPtr;
    
    // Perform swap
    swap(pp1, pp2);
    
    return 0;
}

// Swap pointers
void swap(int **ptr1, int **ptr2) {
    int *temp = *ptr1;
    
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
