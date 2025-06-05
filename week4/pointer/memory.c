#include<stdio.h>
int main (int argc, char* args[])
{
   int a = 28;
   int b = 50;
   int *c = &a; // take the address of a and put it inside the pointer c, the value of address of the pointer c still remain the same
                // or simply means that pointer c now points to a

    *c = 14; // dereference the pointer c, which means basically go straight in to the value that inside the pointer c
            // since the pointer c have the address of a, the value are being passed to a
            // now the value of a has been changed to 14

    printf("a has a value of %i, located at %p\n", a, &a );

    printf("c has a value of %p, located at %p\n", c, &c );


    c = &b; // c now has the address of b
            // c points to b
    *c = 25;// dereference the pointer c, now go straight into the address of b and change the value inside of b

    printf("b has a value of %i, located at %p\n", b, &b );

    printf("c has a value of %p, located at %p\n", c, &c );

}