#include <stdio.h>

int main()
{
    // Using the all-new masking technique to read sensor states directly!
    printf("Enter to check : ");
    
    int a;
    scanf("%d", &a);
    
    // The CPU instantly snapshots the hardware switches using a Bit Mask of 1
    if ((a & 1) == 1) {
        printf("HIGH\n"); // Bit is 1 (Voltage Detected / Odd Number)
    }
    else {
        printf("LOW\n");  // Bit is 0 (Ground / Even Number)
    }
    
    return 0;
}
