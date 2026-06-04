# 📑 Day 3: Setting & Toggling Register States

### 🧠 Core Mechanics

#### 1. Bitwise OR (`|`) → Set Bit (Force ON)
* **Rule:** Anything OR'd with `0` stays the same. Anything OR'd with `1` is forced to `1`.
* **Superpower:** Safely forces a target pin HIGH without checking if it was already on.

#### 2. Bitwise XOR (`^`) → Toggle Bit (Flip State)
* **Rule:** Outputs `1` only if inputs are different. To toggle, we XOR our target against a `1` mask.
* **The Math:**
  * Pin was ON (`1`): `1 ^ 1 = 0` (Flips OFF)
  * Pin was OFF (`0`): `0 ^ 1 = 1` (Flips ON)
* **Blinking Application:** Blinking is just a timed, unconditional XOR flip loop. It bypasses heavy `if-else` assembly branching codes completely.

---

### 💻 Local Driver Code (Tested in VS Code)

```c
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

```
### 📋 Verified Terminal Output Trace
```text
Enter 1 to switch the PIN 3 ON or 2 to read the pin's status
or 3 for Togling off the PIN 3, ELSE 4 to Stop : 1
Succesfully Turned on the 3rd pin ...
Enter 1 to switch the PIN 3 ON or 2 to read the pin's status
or 3 for Togling off the PIN 3, ELSE 4 to Stop : 2
The PIN 3 is ON ...
Enter 1 to switch the PIN 3 ON or 2 to read the pin's status
or 3 for Togling off the PIN 3, ELSE 4 to Stop : 3
PIN 3 is succesfully Toggled ...
Enter 1 to switch the PIN 3 ON or 2 to read the pin's status
or 3 for Togling off the PIN 3, ELSE 4 to Stop : 2
The PIN 3 is OFF...
Enter 1 to switch the PIN 3 ON or 2 to read the pin's status
or 3 for Togling off the PIN 3, ELSE 4 to Stop : 4
Program End !!!
```
### 🏆 Day 3 Summary
 * **Operators:** | (Set) and ^ (Toggle).
 * **Breakthrough:** Realized XOR toggles cleanly by matching a bit against 1, eliminating extra if-else branching cycles.
```

---
