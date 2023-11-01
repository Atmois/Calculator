#include <iostream>
#include <cmath>

using str = std::string;

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

int main()
{
    double num1;
    double num2;
    double ans;
    str calcOperator;

    std::cout << "Number 1: ";
    std::cin >> num1;
    if (std::isnan(num1))
    {
        std::cout << "Error: Not a number";
    }
    else
    {
        std::cout << "Add('+'), Subtract('-'), Divde('/'), Multiply('*') or Powers('^'): ";
        std::cin >> calcOperator;

        if (calcOperator == "+" || calcOperator == "-" || calcOperator == "/" || calcOperator == "*")
        {
            std::cout << "Number 2: ";
            std::cin >> num2;
            if (std::isnan(num2))
            {
                std::cout << "Error: Not a number";
            }
            else
            {
                ans = arithmetic(num1, num2, calcOperator);
                if (calcOperator == "/" && ans == 0)
                {
                    std::cout << "Error: You cannot divide by 0";
                }
                else
                {
                    std::cout << num1 << calcOperator << num2 << "=" << ans;
                }
            }
        }

        else if (calcOperator == "^")
        {
            std::cout << "What power would you like: ";
            std::cin >> num2;
            if (std::isnan(num2))
            {
                std::cout << "Error: Not a number";
            }
            else
            {
                ans = power(num1, num2);
                std::cout << num1 << "^" << num2 << "=" << ans;
            }
        }

        else
        {
            std::cout << "Error: Invalid Operator\n";
        }
    }
    return 0;
}
