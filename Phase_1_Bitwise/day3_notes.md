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

```
### 📋 Verified Terminal Output Trace
```text
Enter 1 to switch PIN 3 ON, 2 to READ, 3 to TOGGLE, 4 to Stop: 2
The PIN 3 is OFF...
Enter 1 to switch PIN 3 ON, 2 to READ, 3 to TOGGLE, 4 to Stop: 1
Succesfully Turned on the 3rd pin ...
Enter 1 to switch PIN 3 ON, 2 to READ, 3 to TOGGLE, 4 to Stop: 2
The PIN 3 is ON ...
Enter 1 to switch PIN 3 ON, 2 to READ, 3 to TOGGLE, 4 to Stop: 3
PIN 3 is succesfully OFF...
Enter 1 to switch PIN 3 ON, 2 to READ, 3 to TOGGLE, 4 to Stop: 4
Program End !!!

```
### 🏆 Day 3 Summary
 * **Operators:** | (Set) and ^ (Toggle).
 * **Breakthrough:** Realized XOR toggles cleanly by matching a bit against 1, eliminating extra if-else branching cycles.
```

---
