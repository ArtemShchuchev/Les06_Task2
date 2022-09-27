#pragma once

#include <iostream> // консоль - cout
#include <conio.h>  // _kbhit()

enum class Operand { NOT, PLUS, MINUS, ANSWER, EXIT };

bool yesOrNo(); // 1 - да; 0 - нет
Operand oper();
int userInput(const std::string&); // будет запрашивать у пользователя ввод данных