#include <iostream>

void InPutNumCard(size_t& cardNum)
{
    printf("Input your card number:");
    std::cin>>cardNum;
}

void CheckStartDigit(const size_t& cardNum)
{
    size_t i,flag=cardNum/10,y;

    for(i=1;i<=flag;i*=10);
    if(cardNum/i==4)
        {
               printf("\nThis is Visa Card!\n");
        }
        else
    {

        for(y=1;y<(cardNum%i)/10;y*=10);

        if(cardNum/i==3 && ( (cardNum%i)/y==4  || (cardNum%i)/y==7 ) )
        {
        printf("\nThis is AmericanExpress!\n");
        }
        else if(cardNum/i==5 && ( (cardNum%i)/y==1  || (cardNum%i)/y==2 || (cardNum%i)/y==3 || (cardNum%i)/y==4 || (cardNum%i)/y==5 ))
        {
            printf("\nThis is MasterCard!\n");
        }
        else
        printf("\nInvalid!!!\n");

    }

}


void LuhnCheck(const size_t& cardNum)
{
    size_t count = 0,sumEv=0,sumOd=0,totalSum=0;
    size_t virCarNum=cardNum,temp1=0,temp2=0;

    while(virCarNum>0)
    {
            count++;
            if(count%2==0)
            {
                temp1=((virCarNum%10)*2)/10;
                temp2=((virCarNum%10)*2)%10;
                sumEv+=(temp1+temp2);
            }
            else
            {
                sumOd+=virCarNum%10;
            }
            virCarNum=virCarNum/10;
    }
    totalSum+=(sumEv+sumOd);
    if((totalSum%10)!=0)
    {
        printf("\ntotalSum:%ld\n",totalSum);
        printf("\nInvali!!!!!!!\n");
        exit(0);
    }
    else
    {
        switch(count)
        {
            case 13:
            CheckStartDigit(cardNum);
            break;
            case 15:
                CheckStartDigit(cardNum);
            break;
            case 16:
                CheckStartDigit(cardNum);
            break;
        }
    }

}



int main()
{
    size_t a;
    InPutNumCard(a);
    LuhnCheck(a);
}