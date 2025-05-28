void preFillArray(int* array, int elements) {
    for (int i = 0; i < elements; i++) {
        array[i] = -1;
    }
}

void fillArray(int* array, int elements) {
    int filled = 0;
    int i = 0;
    while (filled < elements) {
        if (array[i] == -1) {
            array[i] = filled;
            filled++;
        }
        i++;
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void addToArray(int* array, int size, int index, int data) {
    if (index < 0 || index > size) {
        return;
    }
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = data;
}

void removeFromArray(int* array, int size, int index) {
    if (index < 0 || index >= size) {
        return;
    }
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = -1;

}