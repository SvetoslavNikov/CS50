#include <stdio.h>
#include <cs50.h>

void meow(void){
    printf("Meow Meow\n");

}

int main(void){
    int a = get_int("ïnput int pls: \n");
    do{
        meow();
        a--;
    }while(a > 0);

    string s = "hi!";
    printf("I am %d. String: %c %c %c %i\n", a, s[0],s[1],s[2],s[3]);
}

