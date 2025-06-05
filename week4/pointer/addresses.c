
#include<stdio.h>

int main(void)
{


    char *s = "HI!";
    printf("%p\n",s);  // -> this will print out the address of the string aka the address of the first letter of the string

    printf("%c\n",*s);     // is the same as printf("%c\n",s[0]); because pointer always point at the first char of the string
    printf("%c\n",*(s+1)); // is the same as printf("%c\n",s[1])
    printf("%c\n",*(s+2)); // is the same as printf("%c\n",s[2])





}