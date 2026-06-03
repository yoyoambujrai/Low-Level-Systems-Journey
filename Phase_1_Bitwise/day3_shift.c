#include <stdio.h>

void main() {
    int initial_reg_val = 0;
    while (1) {
        printf("Enter 1 to switch PIN 3 ON, 2 to READ, 3 to TOGGLE, 4 to Stop: ");
        int usv;
        scanf("%d", &usv);
        
        if (usv == 1) {
            initial_reg_val = initial_reg_val | 8;
            printf("PIN 3 forced ON.\n");
        }
        else if (usv == 2) {
            if ((initial_reg_val & 8) == 8) printf("PIN 3 is ON.\n");
            else printf("PIN 3 is OFF.\n");
        }
        else if (usv == 3) {
            initial_reg_val = initial_reg_val ^ 8; // Unconditional single-cycle toggle!
            printf("PIN 3 Toggled.\n");
        }
        else if (usv == 4) {
            printf("Program End !!!\n");
            break;
        }
        else {
            printf("INVALID INPUT !!!\n");
        }
    }
}
