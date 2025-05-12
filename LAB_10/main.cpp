#include <iostream>
#include <cmath>

int main() {
    using namespace std;
    bool repeat = true;
    while (repeat == true) {
        string output = "";
        // Wypisanie tekstu i pobieranie wartości od użytkownika
        cout << "=== KONWERTER SYSTEÓW LICZBOWYCH ===";
        cout << "\n\nWybierz system liczbowy:";
        cout << "\n1. Dziesiętny (DEC)";
        cout << "\n2. Binarny (BIN)";
        cout << "\n3. Ósemkowy (OCT)";
        cout << "\n4. Szesnastkowy (HEX)\n";
        int fromSystem;
        cin >> fromSystem;
        int fromNumber;
        string fromString;
        cout << "Podaj liczbę: ";
        switch (fromSystem) {
            case 1:
            case 2:
            case 3:
                cin >> fromNumber;
            break;
            case 4:
                cin >> fromString;
            break;
            default:
                cout << "Niepoprawny system liczbowy!\n";
            continue;
        }
        cout << "\n\nWybierz system liczbowy:";
        cout << "\n1. Dziesiętny (DEC)";
        cout << "\n2. Binarny (BIN)";
        cout << "\n3. Ósemkowy (OCT)";
        cout << "\n4. Szesnastkowy (HEX)\n";
        int toSystem;
        cin >> toSystem;

        if (fromSystem == toSystem) { //Sprawdzanie czy początkowy i końcowy system są takie same
            output = to_string(fromNumber);
        } else { //Przeliczanie wszystkich wartości na system dziesiętny
            int decimal = 0;
            int binaryValue;
            int temp;
            int temp2;
            string tempString;
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
                        cout<<"\ntemp "<<temp;
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
                    length = fromString.length();
                    for (int i = 0; i < length; i++) {
                        tempString = fromString[i];
                        if (tempString == "A") {
                            temp = 10;
                        } else if (tempString == "B") {
                            temp = 11;
                        } else if (tempString == "C") {
                            temp = 12;
                        } else if (tempString == "D") {
                            temp = 13;
                        } else if (tempString == "E") {
                            temp = 14;
                        } else if (tempString == "F") {
                            temp = 15;
                        } else {
                            temp = stoi(tempString);
                        }
                        decimal += temp * pow(16, length - i - 1);
                    }
                break;
            }
            string tempHex;
            int tempDec;
            switch (toSystem) { //Przeliczanie dziesietnego na pozostale systemy
                case 1: //Dziesietny
                    output = to_string(decimal);
                break;
                case 2: //Binarny
                    output = "";
                    for (int i = 0; decimal > 0; i++) {
                        output = to_string(decimal%2) + output;
                        decimal /= 2;
                    }
                break;
                case 3: //Osemkowy
                    output = "";
                    for (int i = 0; decimal > 0; i++) {
                        output = to_string(decimal%8) + output;
                        decimal /= 8;
                    }
                break;
                case 4: //Szesnastkowy
                    output = "";
                    for (int i = 0; decimal > 0; i++) {
                        tempDec = decimal%16;
                        switch (tempDec) {
                            case 10:
                                tempHex = "A";
                            break;
                            case 11:
                                tempHex = "B";
                            break;
                            case 12:
                                tempHex = "C";
                            break;
                            case 13:
                                tempHex = "D";
                            break;
                            case 14:
                                tempHex = "E";
                            break;
                            case 15:
                                tempHex = "F";
                            break;
                            default:
                                tempHex = to_string(tempDec);
                            break;
                        }
                        output = tempHex + output;
                        decimal /= 16;
                    }
                break;
                default:
                    cout << "Niepoprawny system liczbowy!\n";
                continue;
            }
        }
        cout<<"\nWynik: "<<output;
        cout<<"\nCzy chcesz wykonac kolejna konwersje? (t/n)\n";
        string askRepeat;
        cin>>askRepeat;
        cout<<"\n";
        if (askRepeat == "n") {
            repeat = false;
        }
    }
}