#include<stdio.h>
#include<stdlib.h>

int main()
{
    // int ref_str[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    // int ref_str_size = sizeof(ref_str) / sizeof(int); // size of ref_str

    int* ref_str, ref_str_size;
    printf("\nEnter the number of elements in the reference string: ");
    scanf("%d", &ref_str_size);

    ref_str = (int*)malloc(ref_str_size * sizeof(int));

    printf("Enter the elements: \n");
    for (int k=0; k<ref_str_size; k++)
    {
        scanf("%d", &ref_str[k]);
    }

    int frame_size;
    printf("Enter the frame size - ");
    scanf("%d", &frame_size);

    int frame[frame_size], clock[frame_size];
    int search_elem, elem_found=0, i=0;
    int page_fault_count = 0, max_time_index, max_time;
    
    for(int i=0; i<frame_size; i++)
    {
        frame[i] = -1;
        clock[i] = 0;
    }

    printf("The given reference string is --> { ");
    for(int k=0; k<ref_str_size; k++)
    {
        printf("%d ", ref_str[k]);
    }
    printf("}\n\n");

    while(i<ref_str_size)
    {
        search_elem = ref_str[i];
        printf("search string = %d\n", search_elem);
        elem_found = 0;
        max_time_index = 0; // Finding the index that was updated very long back
        max_time = 0;

        for(int j=0; j<frame_size; j++)
        {
            if(search_elem == frame[j])
            {
                elem_found = 1;
                clock[j] = 0;
                max_time_index = j;
                break;
            }

            else
            {
                elem_found = 0;
            }

        }

        if (elem_found == 0)
        {
            page_fault_count++;
            for(int k=0; k<frame_size; k++)
            {
                if (clock[k] > max_time)
                {
                    max_time_index = k;
                    max_time = clock[k];
                }
            }

            frame[max_time_index] = search_elem;
            clock[max_time_index] = 0;
        }

        for (int z=0; z<frame_size; z++)
        {
            if (z!=max_time_index)
            {
                clock[z]++;
            }
        }
        
        for (int z=0; z<frame_size; z++)
        {
            printf("%d  ", frame[z]);
        }
        printf("\n");
        printf("Current page-fault count - %d  ", page_fault_count);
        printf("\n\n");
        i++;
    }

    printf("\nThe total number of page faults are --> %d", page_fault_count);
}