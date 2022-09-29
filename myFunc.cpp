#include "myFunc.h"

// ждет нажатия клавиши, после чего
// возвращает "true" если нажато - "ENTER, y, Y, д, Д"
// и "false" если - "ESC, n, N, н, Н"
bool yesOrNo()
{
    using namespace std;

    bool answer_no, answer_yes;
    bool pressKey = false; // если "true", то нажали что то нужное
    cout << "Вы хотите указать начальное значение счётчика?\n";
    do
    {
        if (_kbhit())  // если клавиша была нажата
        {
            int input = _getch(); // смотрим, что нажато
            //cout << input << " ";
            answer_no = input == 27 || input == 110 || input == 78 ||
                input == 237 || input == 205; // ESC, n, N, н, Н
            answer_yes = input == 13 || input == 121 || input == 89 ||
                input == 228 || input == 196; // ENTER, y, Y, д, Д
            pressKey = answer_no || answer_yes;
            if (!pressKey) cout << "Да или нет?\n";
        }
    } while (!pressKey);

    return answer_yes;
}

// ждет ввода комманды, возвращает введенную комманду
Operand oper()
{
    using namespace std;

    Operand op = Operand::NOT;
    cout << "Введите команду ('+', '-', '=' или 'x'): ";
    do
    {
        if (_kbhit())  // если клавиша была нажата
        {
            switch (_getch())
            {
            case 43:    // +
                op = Operand::PLUS;
                break;

            case 45:    // -
                op = Operand::MINUS;
                break;

            case 13:    // Enter
            case 61:    // =
                op = Operand::ANSWER;
                break;

            case 27:    // ESC
            case 88:    // X
            case 120:   // x
            case 215:   // Ч
            case 247:   // ч
                op = Operand::EXIT;
                break;

            default:
                op = Operand::NOT;
                break;
            }
        }
    } while (op == Operand::NOT);

    return op;
}

// будет запрашивать у пользователя ввод данных
// пока не будут введены верные данные.
// В случае успеха, вернет int.
// При ошибке ввода, сбросит и очистит cin
// и снова попросит ввести данные
int userInput(const std::string& userText)
{
    int uData = 0;
    bool err = true;

    do
    {
        std::cout << userText; std::cin >> uData;

        if (err = std::cin.fail()) std::cin.clear(); // ошибка ввода
        int ch; // поиск и очистка лишних введенных символов
        while ((ch = std::cin.get()) != '\n' && ch != EOF);
    } while (err);

    return uData;
}
