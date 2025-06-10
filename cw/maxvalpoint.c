// pos = adres w pamieci (pointer)
// *pos = wartosc tego co jest pod pointerem
int* findMaxValue(int* array, int size) {
    int* pos = array;
    int* max = array;
    for (int i = 0; i < size; i++, pos++) {
        if (*pos > *max) {
            max = pos;
        }
    }
    return max;
}