#include <stdio.h>

void main() {
    int res_v = 72;
    // Creating an inverted mask for switch 3
    int mask = ~8;
    // Applying the changes with the stencil mask
    res_v = res_v & mask;
    
    printf("3rd pin successfully turned OFF...\nresult after the changes is %d\n", res_v);
}

/* Verified Terminal Trace :
3rd pin successfully turned OFF...
result after the changes is 64
*/
