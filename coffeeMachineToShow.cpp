#include <iostream>
//#include <Windows.h>

#define ESPRESSO_PRICE 1.5
#define CAPPUCCINO_PRICE 2.5
#define LATTE_PRICE 3.0
#define PIN 1234
#define PIN_ATTEMPTS 3
#define WARNING_CUPS_QUANTITY 3

using namespace std;

void printBalance(double balance, string string);

void printWarningIfNoCups(int cups);

void printMenu();

void pause();

int inputNumber(int number);

double inputMaterials(double material, string action);

double installPrice(int choice);

void transactPayment(double price, double &balance, double &balanceInMachine);

void giveCoffee();


int main() {
    int choice = 0, cups = 3;
    double balance = 5, price = 0, balanceInMachine = 0;


    while (true) {
        system("cls");
        printWarningIfNoCups(cups);
        printBalance(balance, "money");
        printMenu();

        choice = inputNumber(choice);

        if (0 < choice and choice < 4) {
            price = installPrice(choice);
            if (price > balance) {
                cout << "Not enough money" << endl;
//				Sleep(3000);
            } else {
//                transactPayment(price, balance, balanceInMachine); //last version
//                giveCoffee(cups);
//                cupsReduction(cups);
                transactPayment(price, balance, balanceInMachine);
                if (cups > 0) {
                    giveCoffee();
                    cups--;
                } else {}
            }
        } else if (choice == 4) {
            balance = inputMaterials(balance, "money");
        } else if (choice == 5) {
            cout << "service" << endl;
        }
    }
}

void printBalance(double balance, string string) {     //I can't think of a name for the second variable. The function for money and cups
    cout << "Balance " << string << ": " << balance << endl;
}

void printWarningIfNoCups(int cups) {
    if (cups == 0) {
        cout << "**********************************************************************" << endl;
        cout << "*********************** Warning! NO cups. ****************************" << endl;
        cout << "*** Do not order coffee, otherwise you will be wasting your money. ***" << endl;
        cout << "**********************************************************************" << endl;
    }
}

void printMenu() {
    cout << "1. Espresso " << ESPRESSO_PRICE << " BYN" << endl;
    cout << "2. Cappuccino " << CAPPUCCINO_PRICE << " BYN" << endl;
    cout << "3. Latte " << LATTE_PRICE << " BYN" << endl;
    cout << "4. Put money" << endl;
    cout << "5. Service" << endl << endl;
}

void pause() {
    cout << endl;
    system("pause");
}

int inputNumber(int number) {   //only for buttons
    cout << "Please, press the button: ";
    cin >> number;

    return number;
}

double inputMaterials(double material, string action) {  //common function for money and cups
    double input = 0;

    while (true) {
        printBalance(material, action);
        cout << "Please insert " << action << "(0 - Exit): ";
        cin >> input;
        if (input == 0) {
            break;
        }

        material += input;
    }

    return material;
}

double installPrice(int choice) {
    switch (choice) {
        case 1:
            return ESPRESSO_PRICE;
        case 2:
            return CAPPUCCINO_PRICE;
        case 3:
            return LATTE_PRICE;
        default:
            break;
    }
}

void transactPayment(double price, double &balance, double &balanceInMachine) {
    balance -= price;
    balanceInMachine += price;
}

void giveCoffee() //?
{
    cout << "*** Take your coffee! ***" << endl;
    pause();
}