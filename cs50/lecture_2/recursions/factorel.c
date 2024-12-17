#include <stdio.h>
#include <cs50.h>

int factorel();

int main(void){
    int a = factorel(5);
    printf("%d\n",a);

}

//calculate factorel

int factorel(int n){
    if(n == 0){
        return -1;
    } else{
        return n*factorel(n-1);
    }
}