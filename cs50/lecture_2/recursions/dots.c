#include <stdio.h>
#include <cs50.h>

int partitions();

int main(void){
    int a = partitions(5,5);
    printf("%d\n",a);

}

int partitions(n,m){
    if (n ==0){
        return 1;
        }
    else if(m==0 || n<0){
        return 0;
    }
    return partitions(n-m,m)+partitions(n,m-1);
}