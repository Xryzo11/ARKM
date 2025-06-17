void usunDuplikaty(char* napis) {
    char* p1 = napis;
    char* p2 = napis;
    while (*p2) {
        *p1 = *p2;
        while (*p2 == *(p2 + 1)) {
            p2++;
        }
        p1++;
        p2++;
    }
    *p1 = '\0';
}