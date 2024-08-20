#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <stdexcept>
#include <cmath>

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '/' || op == '*')
    {
        return 2;
    }
    if (op == '^')
    {
        return 3;
    }
    return 0;
}

double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            throw std::invalid_argument("Division by zero error");
        }
        return a / b;
    case '^':
        return pow(a, b);
    default:
        throw std::invalid_argument("Unknown operator");
    }
}

std::vector<std::string> tokenize(const std::string &expr)
{
    std::vector<std::string> tokens;
    std::string number;

    for (size_t i = 0; i < expr.length(); ++i)
    {
        char c = expr[i];

        if (std::isdigit(c) || c == '.')
        {
            number += c;
        }
        else
        {
            if (!number.empty())
            {
                tokens.push_back(number);
                number.clear();
            }

            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
            {
                tokens.push_back(std::string(1, c));
            }
        }
    }

    if (!number.empty())
    {
        tokens.push_back(number);
    }

    return tokens;
}

std::vector<std::string> infixToPostfix(const std::vector<std::string> &tokens)
{
    std::vector<std::string> output;
    std::stack<char> operators;

    for (const auto &token : tokens)
    {
        if (std::isdigit(token[0]) || (token.size() > 1 && token[0] == '.'))
        {
            output.push_back(token);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^")
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token[0]))
            {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            operators.push(token[0]);
        }
        else if (token == "(")
        {
            operators.push('(');
        }
        else if (token == ")")
        {
            while (!operators.empty() && operators.top() != '(')
            {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.empty())
    {
        output.push_back(std::string(1, operators.top()));
        operators.pop();
    }

    return output;
}

double evaluatePostfix(const std::vector<std::string> &tokens)
{
    std::stack<double> values;

    for (const auto &token : tokens)
    {
        if (std::isdigit(token[0]) || (token.size() > 1 && token[0] == '.'))
        {
            values.push(std::stod(token));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^")
        {
            if (values.size() < 2)
                throw std::runtime_error("Invalid expression");
            double b = values.top();
            values.pop();
            double a = values.top();
            values.pop();
            values.push(applyOp(a, b, token[0]));
        }
    }

    if (values.size() != 1)
        throw std::runtime_error("Invalid expression");
    return values.top();
}

void calculator()
{
    std::string expression;
    std::cout << "Enter a mathematical expression (or type 'exit' to quit): ";

    while (std::getline(std::cin, expression))
    {
        if (expression == "exit")
        {
            break;
        }

        try
        {
            auto tokens = tokenize("12 + 2 - ( 2 + 2 ) * 2");
            auto postFix = infixToPostfix(tokens);
            double result = evaluatePostfix(postFix);
            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << "Enter a mathematical expression (or type 'exit' to quit): ";
    }
}

int main()
{
    calculator();
    return 0;
}