#include "myFunc.h"

// ���� ������� �������, ����� ����
// ���������� "true" ���� ������ - "ENTER, y, Y, �, �"
// � "false" ���� - "ESC, n, N, �, �"
bool yesOrNo()
{
    using namespace std;

    bool answer_no, answer_yes;
    bool pressKey = false; // ���� "true", �� ������ ��� �� ������
    cout << "�� ������ ������� ��������� �������� ��������?\n";
    do
    {
        if (_kbhit())  // ���� ������� ���� ������
        {
            int input = _getch(); // �������, ��� ������
            //cout << input << " ";
            answer_no = input == 27 || input == 110 || input == 78 ||
                input == 237 || input == 205; // ESC, n, N, �, �
            answer_yes = input == 13 || input == 121 || input == 89 ||
                input == 228 || input == 196; // ENTER, y, Y, �, �
            pressKey = answer_no || answer_yes;
            if (!pressKey) cout << "�� ��� ���?\n";
        }
    } while (!pressKey);

    return answer_yes;
}

// ���� ����� ��������, ���������� ��������� ��������
Operand oper()
{
    using namespace std;

    Operand op = Operand::NOT;
    cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
    do
    {
        if (_kbhit())  // ���� ������� ���� ������
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
            case 215:   // �
            case 247:   // �
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

// ����� ����������� � ������������ ���� ������
// ���� �� ����� ������� ������ ������.
// � ������ ������, ������ int.
// ��� ������ �����, ������� � ������� cin
// � ����� �������� ������ ������
int userInput(const std::string& userText)
{
    int uData = 0;
    bool err = true;

    do
    {
        std::cout << userText; std::cin >> uData;

        if (err = std::cin.fail()) std::cin.clear(); // ������ �����
        int ch; // ����� � ������� ������ ��������� ��������
        while ((ch = std::cin.get()) != '\n' && ch != EOF);
    } while (err);

    return uData;
}
