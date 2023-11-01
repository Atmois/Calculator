#include <iostream>
#include <cmath>

using str = std::string;

double add(double num1, double num2)
{
    return num1 + num2;
}

double subtract(double num1, double num2)
{
    return num1 - num2;
}

double multiply(double num1, double num2)
{
    return num1 * num2;
}

double divide(double num1, double num2)
{
    if (num2 == 0)
    {
        std::cout << "Error: You cannot divde by 0.";
    }
    else
    {
        return num1 / num2;
    }
}

double power(double num1, double num2)
{
    return pow(num1, num2);
}

int main()
{
    double num1;
    double num2;
    double ans;
    str calcOperator;

    std::cout << "Number 1: ";
    std::cin >> num1;
    std::cout << "Add('+'), Subtract('-'), Divde('/'), Multiply('*') or Powers('^'): ";
    std::cin >> calcOperator;
    if (calcOperator != "^")
    {
        std::cout << "Number 2: ";
        std::cin >> num2;
    }

    if (calcOperator == "+")
    {
        ans = add(num1, num2);
        std::cout << num1 << "+" << num2 << "=" << ans;
    }
    else if (calcOperator == "-")
    {
        ans = subtract(num1, num2);
        std::cout << num1 << "-" << num2 << "=" << ans;
    }
    else if (calcOperator == "*")
    {
        ans = multiply(num1, num2);
        std::cout << num1 << "*" << num2 << "=" << ans;
    }
    else if (calcOperator == "/")
    {
        ans = divide(num1, num2);
        std::cout << num1 << "/" << num2 << "=" << ans;
    }
    else if (calcOperator == "^")
    {
        std::cout << "What power would you like: ";
        std::cin >> num2;
        ans = power(num1, num2);
        std::cout << num1 << "^" << num2 << "=" << ans;
    }
    else
    {
        std::cout << "Error: Invalid Operator\n";
    }
    return 0;
}
