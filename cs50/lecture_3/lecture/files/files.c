#include <stdio.h>
#include <cs50.h>

int main(void){
    FILE *file= fopen("phonebook.csv","w");
    if(file == NULL){
        return 1;
    }

    char *name = get_string("INPUT NAME: \n");
    char *number = get_string("input number: \n");
    fprintf(file, "%s - %s", name, number);
    fclose(file);
}