#include <iostream> // консоль - cout
#include "Counter.h"
#include "myFunc.h"

// Один в один - старое задание, просто все вынес во внешние файлы

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");   // задаём русский текст
    system("chcp 1251");            // настраиваем кодировку консоли
    std::system("cls");

    std::cout << "Задача 2. Счётчик\n";
    std::cout << "-----------------\n";

    Counter counter;

    if (yesOrNo())
    {
        counter.setCount(userInput("Введите начальное значение счётчика: "));
    }

    bool contin = true;
    do
    {
        switch (oper())
        {
        case Operand::PLUS:
            counter.increase();
            std::cout << "+";
            break;

        case Operand::MINUS:
            counter.decrease();
            std::cout << "-";
            break;

        case Operand::ANSWER:
            std::cout << "= " << counter.getCount();
            break;

        case Operand::EXIT:
            contin = false;
            std::cout << "До свидания!";
            break;

        default:
            break;
        }
        std::cout << std::endl;
    } while (contin);

    return 0;
}
