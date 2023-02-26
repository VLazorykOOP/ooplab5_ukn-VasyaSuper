#include <iostream>
#include "Lab5Exmaple.h"
int main()
{
    std::cout << " Lab #5 \n";

    char Choice = 'n';
    do {
        setlocale(LC_CTYPE, "ukr");
        std::cout << " Задача 1.3 (1)\n";
        std::cout << " Задача 2.3 (2)\n";
        std::cout << " Задача 3.3 (3)\n";
        std::cout << " Вихiд. (q)\n";
        std::cin >> Choice;

        switch (Choice) {

        case '1': {
            Choice = Exrcise1Main();
            break;
        }
        case '2': {
            Choice = Exrcise2Main();
            break;
        }
        case '3': {
            Choice = Exrcise3Main();
            break;
        }
        default:
            std::cout << " ???  Choice {1,2,3 or q}  \n";
        }

    } while (Choice != 'q');

}
