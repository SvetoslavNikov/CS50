#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE; //give and 8 bit value that is unsigned

int main(int argc, char *argv[]){//argv is an array of strings

    FILE *source = fopen(argv[1], "rb");//read binary
    FILE *destination = fopen(argv[2], "wb");//write binary

    BYTE byte;
    while(fread(&byte, sizeof(byte) ,1, source) != 0){
        //put at the adress of b, size of b * 1, from source) returns how many bytes are successfully read
        fwrite(&byte, sizeof(byte), 1, destination);
    }

    fclose(source);
    fclose(destination);
    return 0;
}