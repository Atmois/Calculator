#include <cmath>
#include <iostream>
using str = std::string;

/* TO DO
- Add trig stuff
- Tidy up other functions

- Maybe make a GUI?
*/

double inputNum1(int num1)
{
    std::cout << "Number 1: ";
    while (!(std::cin >> num1))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: You entered a non numerical character for Number 1" << "\n" << "Number 1: ";
    }
    return num1;
}
double inputNum2(int num2)
{
    std::cout << "Number 2: ";
    while (!(std::cin >> num2))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: You entered a non numerical character for Number 2" << "\n" << "Number 2: ";
    }
    return num2;
}

double arithmetic(double num1, double num2, str calcOperator)
{
    if (calcOperator == "+")
    {
        return num1 + num2;
    }
    else if (calcOperator == "-")
    {
        return num1 - num2;
    }
    else if (calcOperator == "*")
    {
        return num1 * num2;
    }
    else if (calcOperator == "/")
    {
        return num1 / num2;
    }
    return std::numeric_limits<double>::quiet_NaN();
}

double power(double num1, double num2)
{
    num1 = inputNum1(num1);
    std::cout << "Power: ";
    while (!(std::cin >> num2))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: You entered a non numerical character for Power" << "\n" << "Power: ";
    }
    return pow(num1, num2);
}

str arithmeticCalc(str calcOperator, double num1, double num2)
{
    double ans;
    if (calcOperator == "+" || calcOperator == "-" || calcOperator == "/" || calcOperator == "*")
    {
        num1 = inputNum1(num1);
        num2 = inputNum2(num2);
        while (calcOperator == "/" && num2 == 0)
        {
            std::cout << "Error: You cannot divide by 0\n";
            num2 = inputNum2(num2);
        }
        ans = arithmetic(num1, num2, calcOperator);
        std::cout << num1 << calcOperator << num2 << "=" << ans;
        return "success";
    }
    else if (calcOperator == "^")
    {
        ans = power(num1, num2);
        std::cout << num1 << "^" << num2 << "=" << ans;
        return "success";
    }
    else
    {
        std::cout << "Error: Invalid Operator\n";
        return "invOp";
    }
    return "failed";
}

str getOperator(char calcMode, str calcOperator)
{
    if (calcMode == 'a')
    {
        std::cout << "Add('+'), Subtract('-'), Divde('/'), Multiply('*') or Powers('^'): ";
        std::cin >> calcOperator;
    }
    else if (calcMode == 't')
    {   
        std::cout << "Sine(S), Cosine(C), Tan(T), Sine Inverse(SI), Cosine Inverse(CI), Tan Inverse(TI), Cosine Rule(CR) or Sine Rule(SR): ";
        std::cin >> calcOperator;
        for (int i = 0; i < calcOperator.length(); i++)
        {
            calcOperator[i] = (char)std::tolower(calcOperator[i]);
        }
    }
    return calcOperator;
}

char getMode(char calcMode)
{
    bool validMode = false;
    while (validMode == false)
    {
        std::cout << "Would you like to do Arithmetic('A') or Trig('T'): ";
        std::cin >> calcMode;
        calcMode = (char)std::tolower(calcMode);
        if (calcMode == 'a' || calcMode == 't')
        {
            validMode = true;
        }
        else
        {
            std::cout << "Error: Invalid Mode\n";
        }
    }

    return calcMode;
}

char continueCheck(str calcProcess, char continueProgram)
{

    std::cout << "\nWould you like to use the calculator again (Y/N): ";
    std::cin >> continueProgram;
    continueProgram = (char)std::tolower(continueProgram);

    return continueProgram;
}

int main()
{
    char continueProgram = 'y';
    while (continueProgram == 'y')
    {
        double num1;
        double num2;
        str calcOperator;
        str calcProcess;
        char calcMode;

        calcMode = getMode(calcMode);
        calcOperator = getOperator(calcMode, calcOperator);
        if (calcMode == 'a')
        {
            calcProcess = arithmeticCalc(calcOperator, num1, num2);
        }
        else if (calcMode == 't')
        {
        }

        // -------------------------------------------- //

        if (calcProcess == "failed")
        {
            std::cout << "Error";
            continue;
        }
        else if (calcProcess == "invOp")
        {
            continue;
        }
        else if (calcProcess == "success")
        {
            continueProgram = continueCheck(calcProcess, continueProgram);
        }
    }

    return 0;
}