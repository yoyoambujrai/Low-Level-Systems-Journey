#include <stdio.h>
int main()
{
  printf("Enter your the overall register value over here :");
  int reg,dec;
  scanf("%d",&reg);
  printf("Press 1 to check the pin_2 (pin number 3)\n value via Bit Masking and 2 via Right shifting bitwise operator :");
  scanf("%d",&dec);
  if (dec == 1){
    int res = (reg & 4);
    if (res == 4){
      printf("High\n");
    }
    else{
      printf("Low\n");
    }
  }
  else if (dec == 2){
    int res = (reg >> 2);
    if ( (res & 1)==1){
      printf("Hight\n");
    }
    else{
      printf("Low\n");
    }
    /* Else we can also use the odd-even logic by res%2==1 and res/= 2 logic,
    butit will invoke heavy internal functions which will increase the complexity of the code */
  }
  else{
    printf("Invalid Intput ...\n");
  }
  return 0;
}
