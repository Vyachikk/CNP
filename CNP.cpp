#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        // сгенерировать CNP
        int gender = rand() % 2 + 1;
        int birthYear = rand() % 100;
        int birthMonth = rand() % 12 + 1;
        int birthDay = rand() % 31 + 1;
        int areaCode = rand() % 52 + 1;
        int orderNumber = rand() % 1000;
        
        // высчитать числа
        int cnp[12];
        cnp[0] = gender;
        cnp[1] = birthYear / 10;
        cnp[2] = birthYear % 10;
        cnp[3] = birthMonth / 10;
        cnp[4] = birthMonth % 10;
        cnp[5] = birthDay / 10;
        cnp[6] = birthDay % 10;
        cnp[7] = areaCode / 10;
        cnp[8] = areaCode % 10;
        cnp[9] = orderNumber / 100;
        cnp[10] = (orderNumber / 10) % 10;
        cnp[11] = orderNumber % 10;
        
        int weights[] = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
        int sum = 0;
        for (int j = 0; j < 12; j++) {
            sum += cnp[j] * weights[j];
        }
        int controlDigit = sum % 11;
        if (controlDigit == 10) {
            controlDigit = 1;
        }
        
        // вывод
        cout << gender << birthYear / 10 << birthYear % 10 << birthMonth / 10 << birthMonth % 10
             << birthDay / 10 << birthDay % 10 << areaCode / 10 << areaCode % 10
             << orderNumber / 100 << (orderNumber / 10) % 10 << orderNumber % 10 << controlDigit << endl;
    }
    return 0;
}

