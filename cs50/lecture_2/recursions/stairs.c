#include <stdio.h>
#include <cs50.h>

int build_stairs(int n){
    if(n == 0){
        return 0;
    }
    int b = 1 + build_stairs(n-1);

    for(int i = 0; i< b ;i++){
        printf("#");
    }

    printf("%d\n",b);
    return b;
}

int main(void){
    int a = 5;
    build_stairs(a);


}

