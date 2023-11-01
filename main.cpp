#include <iostream>

using str = std::string;

double add(double num1, double num2, double ans)
{
    ans = num1 + num2;
    return ans;
}

double subtract(double num1, double num2, double ans)
{
    ans = num1 - num2;
    return ans;
}

double multiply(double num1, double num2, double ans)
{
    ans = num1 * num2;
    return ans;
}

double divide(double num1, double num2, double ans)
{
    ans = num1 / num2;
    return ans;
}

double power(double num1, double num2, double ans) // In this case num1 is the number to be manipulated and num2 is the power, total is used to preseve these values
{
    double total;
    total = num1 * num1;
    for (int i = 2; i < num2; i++)
    {
        total = num1 * total;
    }
    ans = total;
    return ans;
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
        ans = add(num1, num2, ans);
        std::cout << num1 << "+" << num2 << "=" << ans;
    }
    else if (calcOperator == "-")
    {
        ans = subtract(num1, num2, ans);
        std::cout << num1 << "-" << num2 << "=" << ans;
    }
    else if (calcOperator == "*")
    {
        ans = multiply(num1, num2, ans);
        std::cout << num1 << "*" << num2 << "=" << ans;
    }
    else if (calcOperator == "/")
    {
        ans = divide(num1, num2, ans);
        std::cout << num1 << "÷" << num2 << "=" << ans;
    }
    else if (calcOperator == "^")
    {
        std::cout << "What power would you like: ";
        std::cin >> num2;
        ans = power(num1, num2, ans);
        std::cout << num1 << "^" << num2 << "=" << ans;
    }
    else
    {
        std::cout << "Error: Invalid Operator\n";
    }
    return 0;
}
