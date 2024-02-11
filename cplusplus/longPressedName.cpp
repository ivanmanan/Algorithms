#include "globals.h"

bool isLongPressedName(string name, string typed) {
    uint p1 = 0 ;
    uint p2 = 0 ;

    while(p1 < name.size() && p2 < typed.size()) {

        if(typed[p2] == name[p1]) {
            p1++;
            p2++;
        }
        else {
            p2++;
        }
    }
    for(uint i = p2; i < typed.size(); i++) {
        if(typed[i] != typed[p2]) {
            return false;
        }
    }
    return p1 < name.size() ? false : true;

}
