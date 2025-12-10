/*
Q1.  Write a C program that uses to store a list of integers entered by the user. The program should first ask the user
how many elements they want to store, then allocate memory using malloc() according to the provided size. After 
allocating memory, take all elements from the user and store them in the dynamically created array. Then print the
array elements using a loop. Also include proper checks such as verifying if malloc() successfully allocated memory or
not. Finally, before ending the program, free all the dynamically allocated memory using free() to avoid memory leaks. 
Add helpful messages for user interaction and use clear comments in your code.
*/

#include <stdio.h>
#include <stdlib.h>




int main()
{
    int size;
    
    // Ask user for array size 
    printf("Enter the size of your integer array\n");
    scanf("%d", &size);

    // allocating memory for storing integers using malloc
    int* arr = (int*) malloc(size * sizeof(int)); 

    // checking memory allocation was successful
    if (arr == NULL)
    {
        printf("Memory allocation failed.");
    }else
    {
            // ask the user to enter all the elements for the dynamically created array
            for (int n = 0; n < size; n++)
            {
                printf("Enter integer %d out of %d: ", n + 1, size);
                scanf(" %d", &arr[n]);
            }
            
            // printing all the contents of the array
            
            printf("\nThe contents of the array: {");
            for (int n = 0; n < size; n++)
            {
                printf("%d,", arr[n]);
            }
            printf("\b}\n\n");
        
            // freeing the memory to avoid memory leaks 
            free(arr);
    }
    
    

    return 0;
}