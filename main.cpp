#include <iostream>
#include <cmath>
using str = std::string;

double inputNum1(int num1)
{
    std::cout << "Number 1: ";
    while (!(std::cin >> num1))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: You entered a non numerical character for Number 1\n";
        std::cout << "Number 1: ";
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
        std::cout << "Error: You entered a non numerical character for Number 2\n";
        std::cout << "Number 2: ";
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
    else
    {
        return std::numeric_limits<double>::quiet_NaN();
    }
}

double power(double num1, double num2)
{
    num1 = inputNum1(num1);
        std::cout << "Power: ";
        while (!(std::cin >> num2))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: You entered a non numerical character for Power\n";
            std::cout << "Power: ";
        }
    return pow(num1, num2);
}

str getOperator(str calcOperator)
{
    std::cout << "Add('+'), Subtract('-'), Divde('/'), Multiply('*') or Powers('^'): ";
    std::cin >> calcOperator;
    return calcOperator;
}

str calculation(str calcOperator, double num1, double num2)
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

int main()
{
    char continueProgram = 'y';
    while (continueProgram == 'y')
    {
        double num1;
        double num2;
        str calcOperator;
        str calcProcess;

        calcOperator = getOperator(calcOperator);
        calcProcess = calculation(calcOperator, num1, num2);
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
            std::cout << "\nWould you like to use the calculator again (Y/N): ";
            std::cin >> continueProgram;
            continueProgram = (char)std::tolower(continueProgram);
        }
    }

    return 0;
}