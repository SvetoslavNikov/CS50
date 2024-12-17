#include <stdio.h>
#include <cs50.h>


int main(void){

    int arr[] = {3,4,2,1,6,5};
    int count = 6;

    int holder;
    bool sorted = false;

    while(sorted == false){
        sorted = true;
        for(int i = 0; i < count-1; i++){
            if(arr[i]>arr[i+1]){
                holder = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = holder;
                sorted = false;
                count--;
            }
        }
    }

    //print arr
    for(int i = 0; i < 6; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

}