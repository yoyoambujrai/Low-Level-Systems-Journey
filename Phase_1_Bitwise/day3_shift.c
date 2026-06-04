// After optimimizig the code and removing the unneeded if - else statementd, here our code availabel below...

#include <stdio.h>

int main() 
{
    int initial_reg_val = 0;
    int usv;

    while (1) {
        printf("Enter 1 to switch the PIN 3 ON or 2 to read the pin's status\nor 3 for Togling off the PIN 3, ELSE 4 to Stop : ");
        scanf("%d", &usv);
        
        if (usv == 1) {
            // Unconditional OR: Sets Pin 3 HIGH in 1 clock cycle without needing an if-check
            initial_reg_val = initial_reg_val | 8;
            printf("Succesfully Turned on the 3rd pin ...\n");
        }
        else if (usv == 2) {
            // Reading Logic via static mask checking
            if ((initial_reg_val & 8) == 8) {
                printf("The PIN 3 is ON ...\n");
            }
            else {
                printf("The PIN 3 is OFF...\n");
            }
        }
        else if (usv == 3) {
            // Unconditional XOR: Flipped blindly using a 1-mask (0^1=1, 1^1=0)
            initial_reg_val = initial_reg_val ^ 8;
            printf("PIN 3 is succesfully Toggled ...\n");
        }
        else if (usv == 4) {
            printf("Program End !!!\n");
            break;
        }
        else {
            printf("INVALID INPUT !!!\n\tTry Again ...\n");
        }
    }

    return 0;
}
