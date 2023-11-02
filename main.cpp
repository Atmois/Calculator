#include <iostream>
#include <cmath>

using str = std::string;

double num1;
double num2;
double ans;
str calcOperator;
str calcProcess;

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
        if (num2 == 0)
        {
            return 0;
        }
        else
        {
            return num1 / num2;
        }
    }
    else
    {
        return std::numeric_limits<double>::quiet_NaN();
    }
}

double power(double num1, double num2)
{
    return pow(num1, num2);
}

str calculation(str calcOperator)
{
    if (calcOperator == "+" || calcOperator == "-" || calcOperator == "/" || calcOperator == "*")
    {
        std::cout << "Number 1: ";
        while (!(std::cin >> num1))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: You entered a non numerical character for Number 1\n";
            std::cout << "Number 1: ";
        }
        std::cout << "Number 2: ";
        while (!(std::cin >> num2))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: You entered a non numerical character for Number 2\n";
            std::cout << "Number 2: ";
        }

        ans = arithmetic(num1, num2, calcOperator);
        if (calcOperator == "/" && ans == 0)
        {
            std::cout << "Error: You cannot divide by 0";
            return "invDivison";
        }
        else
        {
            std::cout << num1 << calcOperator << num2 << "=" << ans;
            return "success";
        }
    }
    else if (calcOperator == "^")
    {
        std::cout << "Number 1: ";
        while (!(std::cin >> num1))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: You entered a non numerical character for Number 1\n";
            std::cout << "Number 1: ";
        }
        std::cout << "Power: ";
        while (!(std::cin >> num2))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: You entered a non numerical character for Power\n";
            std::cout << "Power: ";
        }
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

str getOperator()
{
    std::cout << "Add('+'), Subtract('-'), Divde('/'), Multiply('*') or Powers('^'): ";
    std::cin >> calcOperator;
    return calcOperator;
}

int main()
{
    calcOperator = getOperator();
    calcProcess = calculation(calcOperator);
    if (calcProcess == "failed")
    {
        std::cout << "FAILED";
    }
    else if (calcProcess == "invOp" || calcProcess == "invDivision")
    {
        main();
    }
    return 0;
}