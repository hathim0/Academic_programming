#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Allocating the reference string
    int* ref_str, ref_str_size;
    printf("\nEnter the number of elements in the reference string: ");
    scanf("%d", &ref_str_size);

    ref_str = (int*)malloc(ref_str_size * sizeof(int));

    printf("Enter the elements: \n");
    for (int k=0; k<ref_str_size; k++)
    {
        scanf("%d", &ref_str[k]);
    }
    // {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    // int ref_str_size = sizeof(ref_str) / sizeof(int); // size of ref_str

    // Allocating the framesize and other necessary parameters
    int frame_size;

    printf("Enter the frame size - ");
    scanf("%d", &frame_size);
    int frame[frame_size], counter=0, elem_found=0, i=0, search_elem, page_fault_count=0;

    printf("The given reference string is --> { ");
    for(int k=0; k<ref_str_size; k++)
    {
        printf("%d ", ref_str[k]);
    }
    printf("}\n\n");

    for (int z=0; z<frame_size; z++)
    {
        frame[z] = -1; // Initially giving some random garbage values to be present in the frame
    }

    while(i < ref_str_size)
    {
        printf("Iteration %d --> ", i+1);
        search_elem = ref_str[i];
        for(int k=0; k<frame_size; k++)
        {
            if (frame[k] == search_elem)
            {
                elem_found = 1;
                break;
            }

            else
            {
                elem_found = 0;
            }
        }

        if (elem_found == 0)
        {
            page_fault_count ++;
            frame[counter] = search_elem;
            counter = (counter + 1) % frame_size;
        }

        for (int z=0; z<frame_size; z++)
        {
            printf("%d  ", frame[z]);
        }
        // printf("%d  %d", frame[counter], counter);
        printf("\n");
        i++;
    }

    printf("\nThe number of page faults are --> %d", page_fault_count);
}