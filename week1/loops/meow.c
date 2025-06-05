#include <stdio.h>
int main(void)
{
      /*
        int i = 0;
        while(i <3) ->(i<3) in the 'while' loop is the boolean expression (Y/N).

     // this is a 'while' loop, it constantly asks whether the i is < 3 it would run the program 'printf' and addition that the 'while' loop contains.
    // if the value of the i reaches to 3, the 'while' loop wont run the program 'printf' and addition because the condition is not met.
        {
            printf("Meow!\n");
            i++;                // this means that it would take the present value, add it with 1 and make it into the next value

                                // or you can rewrite it as i += 1 or as i++  and it would do the same
         }
      */

   for(int i = 0; i < 3; i++)   // this is a 'for' loop, which you see here would do the same function as the 'while' loop but more advanced
//          (1)    (2)   (4)
                                /*
                                    the 'for' loop will start at step (1), which means get the origin value to start doing the job and do this step (1) only once
                                    after that it goes to step (2), which to check the value wheter that value met the condition if the condition is met then go to step (3)
                                    step (3) is to run the code the "for" loop contains
                                    after done running the code, it goes to step (4), do the math, after the math, the new value appears
                                    and it would return to step (2) to check that if the new value now met the condition
                                    the loop (2) -> (3) -> (4) will continue until the condition is not met
                                    if the condition is not met, the loop will end and execute not running step (3) or step (4) anymore
                                 */
   {
        printf("Moew!\n");
 //              (3)
   }
}
