#include <stdio.h>
#include <cs50.h>

// select the min
// swap it with the leftmost number
// repeat to the rest of the array

int main(void){
    int arr[] = {3,4,2,1,6,5};
    int count = 6;
    int idx_min = 0;
    int holder;
    int place = 0;

    while(place < count){

        for(int i = place; i < count; i++){
            if(arr[idx_min] > arr[i]){
                idx_min = i;
            }
        }

        if(place != idx_min){
            holder = arr[place];
            arr[place] = arr[idx_min];
            arr[idx_min] = holder;
        }

        place++;
        idx_min = place;
    }

    //print arr
    for(int i = 0; i < count; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

}