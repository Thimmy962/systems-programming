/**
 * save patterns in memory
 */


/**
 * main - entry point into this programme
 * return: if successful return 0 else 1
 */

#include <stdio.h>
#include <stdlib.h>

void init_memory_with_0xAA(char *mem){
    for(int i = 0; i < 4; i++){
        switch (i%4){
            case 0:
                mem[i] = '0';
                break;
            case 1:
                mem[i] = 'x';
                break;
            case 2:
                mem[i] = 'A';
                break;
            case 3:
                mem[i] = 'A';
                break;
            default:
                break;
        }
    }
}



void init_memory_with_0x55(char *mem){
    for(int i = 0; i < 4; i++){
        switch (i%4){
            case 0:
                mem[i] = '0';
                break;
            case 1:
                mem[i] = 'x';
                break;
            case 2:
                mem[i] = '5';
                break;
            case 3:
                mem[i] = '5';
                break;
            default:
                break;
        }
    }
}

int main(){
    char *mem = malloc(400);
    if(mem == NULL){
        printf("Memory allocation failed\n");
        return (1);
    }

    for(int i = 0; i < 400; i+=4)
    {
        if(i%8 == 0)
            init_memory_with_0xAA(mem+i);
        else
            init_memory_with_0x55(mem+i);
    }
    
    for(int i = 0; i < 400; i+=4)
    {
        printf("%c%c%c%c\n", mem[i], mem[i+1], mem[i+2], mem[i+3]);
    }

    free(mem);

}