#include <string.h>

void usunSpacje(char* napis) {
    for (char* p = napis; *p != '\0'; p++) {
        if (*p == 32) {
            char* p1 = p;
            char* p2 = p + 1;
            while (*p2 != '\0') {
                *p1 = *p2;
                p1++;
                p2++;
            }
        }
    }
}