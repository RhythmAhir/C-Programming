#include<stdio.h>
#include<string.h>
#include<math.h>
#define COL 7

int check (int r,char [],char [][COL]); /*prototype*/

int main()
{

  while(1)
  {
         char color_codes[][COL]={"black","brown","red","orange","yellow","green","blue","violet","gray","white"};
         char reply[][COL]={"yes","no"};
         char inputs[COL];
         int i=0,t;
         double ohm,kohm;
         int value[3];

        while(i<3)
        {
                printf("Enter the color no %d : ",i+1);
                scanf(" %[^\n\t\b]",inputs);

                t = check(10,inputs,color_codes); /*check function is called to test  the acceptability of the input*/

            while(t<0)
            { /*if the input is not valid*/
                    printf("Invalid!!!\nPlease re-enter the color no %d : ",i+1);
                    scanf(" %[^\n]",inputs); /*asks for input*/
                    t=check(10,inputs,color_codes); /*check function is called to test  the acceptability of the input*/
            }

            value[i]= t;
            i++;
        }

        double k=value[2]; /*store the value of the third color in a double variable*/

        ohm=(value[0]*10+value[1])*pow(10.0,k); /*determining the value of resistance*/
        kohm=ohm/1000;  /*convert it into kilo ohm*/
        printf("\nResistance value: %.2lf kilo-ohms.\n",kohm);

        printf("\n\nDo you want to decode another resistor?\n");
        scanf(" %[^\n]",inputs); /*asks input whether user continues the program or not*/

        t = check(2,inputs,reply); /*test the acceptability  of the reply input*/
            while(t<0)
            { /*if reply input is invalid*/
                  printf("Invalid!!! Please reply in correct way.\n");
                  scanf(" %[^\n]",inputs); /*again asks for reply input*/
                  t=check(2,inputs,reply);
            }
        if(t == 1)//reply has only 0 and 1 row 0 = yes ; 1 = no
            break;
        else
            continue;
    }
      return 0;
}

int check(int r,char inputs[],char str[][COL])
{
    int i;
    for(i=0;i<r;i++)
    {
       if(strcmpi(inputs,str[i])==0)
           return i;//store the value of i (row)

    }
   return -1;
}
