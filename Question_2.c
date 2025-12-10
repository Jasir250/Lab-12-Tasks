/*
Q2. Write a C program that demonstrates how to increase the size of a dynamically allocated array using realloc().
First, ask the user how many integers they want to store and allocate memory using calloc() so that all initial values are
set to zero. After displaying the initial values, ask the user if they want to enlarge the array, and if yes, take the new size
from the user. Use realloc() to resize the memory block and check whether the reallocation was successful. Then allow
the user to enter additional elements for the newly added positions. Display the updated array after resizing. Make sure
to free all allocated memory at the end of the program and include proper comments and user instructions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int size;
    char choice[4];

    // asking user for array size
    printf("Enter the array size\n");
    scanf("%d", &size);

    // allocating of memory using calloc
    int* arr = (int*) calloc(size, sizeof(int));

    // checking if memory allocation was successful

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
    }else
    {
        // displaying intital values
        printf("Initial array: {");
        for (int i = 0; i < size; i++)
        {
            printf("%d, ", arr[i]);
        }
        printf("\b\b}\n\n");
        
    
        // ask user if they want to enlarge the array
        printf("Enter 'yes' to enlarge the array. Entering anything else to end the program: ");
        scanf("%s", &choice);
    
            // if user said yes
            if(stricmp(choice, "yes") == 0)
            {
                int new_size;
                // ask user for new size
                printf("Enter the new size of the array: ");
                scanf("%d", &new_size);
    
                // using realloc to resize the array
                arr = (int*)realloc(arr, new_size * sizeof(int));
    
                // checking if reallocation was successful
                if (arr == NULL)
                {
                    printf("Memory reallocation failed\n");
                }else{
    
                    // asking the user to enter the additional elements for the new positions
                    for (int i = size; i < new_size; i++)
                    {
                        printf("Enter new element no %d out of %d: ", i + 1 - size, new_size - size);
                        scanf("%d", &arr[i]);
                    }
                    
                    // displaying the updated array
                    printf("\nUpdated array: {");
                    for (int i = 0; i < new_size; i++)
                    {
                        printf("%d, ", arr[i]);
                    }
                    printf("\b\b}\n\n");
                    
                }
            }
                
    
        // freeing the memory
        free(arr);
    }
    
    


        
    return 0;
}