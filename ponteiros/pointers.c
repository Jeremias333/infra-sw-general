#include <stdio.h>
#include <stdlib.h>

int simple_pointer();
void init_pointer();
void func_pointer(int *count);


int simple_pointer()
{
        int var = 20;
        int *pointer;
        
        pointer = &var;
        *pointer = 30;

        printf("Address of var variable: %x\n", &var);
        printf("Address stored in ip variable: %x\n", pointer);
        printf("Value of *pointer variable: %d\n", *pointer);
        printf("Value of *pointer variable: %d\n", var);

        return var;

}

void init_pointer()
{
        int i = 0;
        int *pointer_array = malloc(3*sizeof(int));
        int point_array[3];
        
        int **pointer_matrix = malloc(3*sizeof(int));
        int point_matrix[3][3];

        for(i=0;i<3;i++)
                pointer_matrix[i] = (int *)malloc(3*sizeof(int));
}

void func_pointer(int *count)
{
        *count = 10;
}

int main () 
{
        int parceiro;
        parceiro = simple_pointer();

        //init_pointer();

        func_pointer(&parceiro);

        printf("parceiro = %d\n",parceiro);

        return 0;
}