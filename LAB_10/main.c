#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int repeat = 1;
    while (repeat) {
        char output[100] = "";
        // Wypisanie tekstu i pobieranie wartości od użytkownika
        printf("=== KONWERTER SYSTEÓW LICZBOWYCH ===");
        printf("\n\nWybierz system liczbowy:");
        printf("\n1. Dziesiętny (DEC)");
        printf("\n2. Binarny (BIN)");
        printf("\n3. Ósemkowy (OCT)");
        printf("\n4. Szesnastkowy (HEX)\n");
        int fromSystem;
        scanf("%d", &fromSystem);
        int fromNumber;
        char fromString[100];
        printf("Podaj liczbę: ");
        switch (fromSystem) {
            case 1:
            case 2:
            case 3:
                scanf("%d", &fromNumber);
            break;
            case 4:
                scanf("%s", fromString);
            break;
            default:
                printf("Niepoprawny system liczbowy!\n");
            continue;
        }
        printf("\n\nWybierz system liczbowy:");
        printf("\n1. Dziesiętny (DEC)");
        printf("\n2. Binarny (BIN)");
        printf("\n3. Ósemkowy (OCT)");
        printf("\n4. Szesnastkowy (HEX)\n");
        int toSystem;
        scanf("%d", &toSystem);

        if (fromSystem == toSystem) { //Sprawdzanie czy początkowy i końcowy system są takie same
            if (fromSystem == 4) {
                strncpy(output, fromString, sizeof(output));
            } else {
                snprintf(output, sizeof(output), "%d", fromNumber);
            }
        } else { //Przeliczanie wszystkich wartości na system dziesiętny
            int decimal = 0;
            int binaryValue;
            int temp;
            int temp2;
            char tempString[2];
            int reversed;
            int length;
            switch (fromSystem) {
                case 1: //Dziesiętny na dziesiętny
                    decimal = fromNumber;
                break;
                case 2: //Binarny na dziesiętny
                    binaryValue = 1;
                    while (fromNumber > 0) {
                        temp = fromNumber % 10;
                        fromNumber -= temp;
                        fromNumber /= 10;
                        decimal += binaryValue * temp;
                        binaryValue *= 2;
                    }
                break;
                case 3: //Ósemkowy na dziesiętny
                    temp = fromNumber;
                    reversed = 0;
                    length = 0;
                    while (temp > 0) {
                        temp2 = temp % 10;
                        temp -= temp2;
                        temp /= 10;
                        reversed *= 10;
                        reversed += temp2;
                        length++;
                    }
                    while (length > 0) {
                        temp = reversed % 10;
                        reversed -= temp;
                        reversed /= 10;
                        decimal += temp * pow(8, length - 1);
                        length--;
                    }
                break;
                case 4: //Szesnastkowy na dziesietny 
                    length = strlen(fromString);
                    for (int i = 0; i < length; i++) {
                        tempString[0] = fromString[i];
                        tempString[1] = '\0';
                        if (strcmp(tempString, "A") == 0) {
                            temp = 10;
                        } else if (strcmp(tempString, "B") == 0) {
                            temp = 11;
                        } else if (strcmp(tempString, "C") == 0) {
                            temp = 12;
                        } else if (strcmp(tempString, "D") == 0) {
                            temp = 13;
                        } else if (strcmp(tempString, "E") == 0) {
                            temp = 14;
                        } else if (strcmp(tempString, "F") == 0) {
                            temp = 15;
                        } else {
                            temp = atoi(tempString);
                        }
                        decimal += temp * pow(16, length - i - 1);
                    }
                break;
            }
            output[0] = '\0';
            int tempDec;
            char tempHex[2];
            switch (toSystem) { //Przeliczanie dziesietnego na pozostale systemy
                case 1: //Dziesietny
                    sprintf(output, "%d", decimal);
                break;
                case 2: //Binarny
                    while (decimal > 0) {
                        char bit[2];
                        snprintf(bit, sizeof(bit), "%d", decimal % 2);
                        decimal /= 2;
                        char tempOut[100];
                        strcpy(tempOut, output);
                        strcpy(output, bit);
                        strcat(output, tempOut);
                    }
                break;
                case 3: //Osemkowy
                    while (decimal > 0) {
                        char digit[2];
                        sprintf(digit, "%d", decimal % 8);
                        char newOutput[100];
                        strcpy(newOutput, digit);
                        strcat(newOutput, output);
                        strcpy(output, newOutput);
                        decimal /= 8;
                    }
                break;
                case 4: // Szesnastkowy
                output[0] = '\0';
                    while (decimal > 0) {
                        tempDec = decimal % 16;
                        if (tempDec >= 10) {
                            tempHex[0] = 'A' + (tempDec - 10);
                            tempHex[1] = '\0';
                        } else {
                            sprintf(tempHex, "%d", tempDec);
                        }
                        decimal /= 16;
                        char tempOut[100];
                        strcpy(tempOut, output);
                        strcpy(output, tempHex);
                        strcat(output, tempOut);
                    }
                break;
                default:
                    printf("Niepoprawny system liczbowy!\n");
                continue;
            }
        }
        printf("\nWynik: %s", output);
        printf("\nCzy chcesz wykonac kolejna konwersje? (t/n)\n");
        char askRepeat[10];
        scanf("%s", askRepeat);
        printf("\n");
        if (strcmp(askRepeat, "n") == 0 || strcmp(askRepeat, "N") == 0) {
            repeat = 0;
        }
    }
}