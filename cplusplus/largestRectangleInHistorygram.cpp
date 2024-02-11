#include "globals.h"

/*
    [2,1,5,6,2,3]

          |---- Pop 6, but calculate area first
        | |
        | |
        | |   |
    |   | | | |
    | | | | | |
    - - - - - -
    0 1 2 3 4 5

            Stack
            Index       Height
    i=0:     0            2

    Height 1 is lower than height 2. So, pop 2 from stack
    Before pop, calculate max area: 2 * 1 = 2
    i=1:     0 (width)    1

    Height 5 is greater than height 1. No need to pop 1 from stack.
    i=2:     2            5

    Height 6 is greater than 5, so don't pop.
    i=3:     3            6

    Height 2 is less than height 6.
    Calculate area first, then pop stack 6.
    Compare top of stack again. Pop stack since height 2 is less than height 5.
    i=4:     2            2 --> index 2 can be extended back to height 2 at index 2

    NOTE: We still have leftover elements not popped from the stack.
    This means there is area leftover that can be calculated as part of the histogram extended all the way back.
*/
