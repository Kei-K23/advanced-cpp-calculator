# Advanced CLI Calculator in C++

This project is an advanced Command-Line Interface (CLI) calculator implemented in C++. The calculator can evaluate mathematical expressions using infix notation, supporting basic arithmetic operations like addition, subtraction, multiplication, division, and exponentiation. It also handles operator precedence and parentheses.

## Features

- Supports the following operators:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
  - Exponentiation (`^`)
- Handles operator precedence (e.g., multiplication and division before addition and subtraction).
- Supports parentheses for grouping expressions.
- Error handling for invalid expressions, including division by zero.

## How It Works

1. **Tokenization**: The input expression is first converted into tokens, separating numbers, operators, and parentheses.

2. **Infix to Postfix Conversion**: The infix expression (which is human-readable) is converted into postfix notation using the Shunting Yard algorithm. Postfix notation is easier to evaluate programmatically because it doesn't require handling operator precedence.

3. **Postfix Evaluation**: The postfix expression is then evaluated using a stack-based approach.

### Example

For an expression like `12 + 2 - ( 2 + 2 ) * 2`, the calculator processes it as follows:

1. **Tokenize**: Break down the expression into individual components: `["12", "+", "2", "-", "(", "2", "+", "2", ")", "*", "2"]`.

2. **Convert to Postfix**: Convert the infix expression to postfix notation: `["12", "2", "+", "2", "2", "+", "2", "*", "-"]`.

3. **Evaluate Postfix**: Evaluate the postfix expression to get the result: `8`.

## Code Structure

- **`precedence()`**: Determines the precedence of operators (`+`, `-`, `*`, `/`, `^`).
- **`applyOp()`**: Applies the operator to two operands.
- **`tokenize()`**: Converts the input string into tokens.
- **`infixToPostfix()`**: Converts the tokenized infix expression to postfix notation using the Shunting Yard algorithm.
- **`evaluatePostfix()`**: Evaluates the postfix expression to produce a numerical result.
- **`calculator()`**: The main function that handles user input and integrates all the above functions.

## Getting Started

### Prerequisites

To compile and run this program, you'll need:

- A C++ compiler (e.g., `clang++`, `g++`)
- A terminal or command prompt

### Compilation

1. Clone or download the repository to your local machine.
2. Open your terminal or command prompt and navigate to the directory containing `main.cpp`.
3. Compile the code using a C++ compiler. For example, using `clang++`:

```bash
# With clang++ compiler
clang++ -std=c++20 main.cpp -o calculator
# or with g++ compiler
g++ main.cpp -o calculator
```

## Running the Program

1. Run the program by executing the compiled file:

```bash
./calculator
```

2. Example program structure

```bash
$ ./calculator
Enter a mathematical expression (or type 'exit' to quit): 12 + 2 - (2 + 2) * 2
Result: 8
Enter a mathematical expression (or type 'exit' to quit): exit

```
