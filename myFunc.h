#pragma once

#include <iostream> // ������� - cout
#include <conio.h>  // _kbhit()

enum class Operand { NOT, PLUS, MINUS, ANSWER, EXIT };

bool yesOrNo(); // 1 - ��; 0 - ���
Operand oper();
int userInput(const std::string&); // ����� ����������� � ������������ ���� ������