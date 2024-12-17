#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void){
    char *s = get_string("Input string s: \n");
    if(s == NULL){// means there is not engouh memory
        return 1;
    }

    char *t = malloc(strlen(s)+1);//+1 for the null char
    if(t == NULL){// means there is not engouh memory
        return 1;
    }


    for(int i = 0, n = strlen(s); i <=n; i++)//<= so it copies the null char too
    {
        t[i]= s[i];
    }// same as strcpy(destination, source)



    if(strlen(t)>0){
        t[0]= toupper(t[0]);//changes h to H
    }

    printf("%c\n", s[0]);
    printf("%c\n", t[0]);


}