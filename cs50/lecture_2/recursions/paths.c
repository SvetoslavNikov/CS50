#include <stdio.h>
#include<cs50.h>

// find number of path from left up corner to right down corner

int find_paths(n,m){
    if(n == 1 || m == 1){
        return 1;
    }

    return find_paths(n,m-1) + find_paths(n-1,m);
}

int main(void){
    int n = get_int("input n:\n");
    int m = get_int("input m:\n");
    int paths = find_paths(n,m);
    
    printf("%d", paths);
}

