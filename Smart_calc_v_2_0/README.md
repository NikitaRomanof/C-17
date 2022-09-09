## Part 1. Implementation of SmartCalc v2.0

- The program must be developed in C++ language of C++17 standard
- The program code is located in the src folder
- Classes implemented inside `s21` namespace
- The build of the program is configured using a Makefile with a standard set of targets for GNU programs: all, install, uninstall, clean, dvi, dist, tests.
- Implementation with a graphical user interface, based on Qt.
- The program is implemented using the MVC pattern.
- The input of the program can be both integers and real numbers.
- The calculation is performed after the full input of the expression to be calculated and pressing the symbol `=`
- Calculation of arbitrary bracket arithmetic expressions in infix notation
- Calculation of arbitrary bracket arithmetic expressions in infix notation with substitution of the value of the variable _x_ as a number
- Plotting a function specified using an expression in infix notation with a variable _x_ (with coordinate axes, a mark of the scale used and a grid with an adaptive step)
- The user has the ability to enter up to 255 characters
- Bracket arithmetic expressions in infix notation support the following arithmetic operations and mathematical functions:
    - **Arithmetic operators**: \
        | Brackets | (a + b) |  
        | Addition | a+b |  
        | Subtraction | a-b |  
        | Multiplication | a*b |  
        | Division | a/b |  
        | Exponentiation | a^b |  
        | Remainder of division | a mod b |  
        | Unary plus | +a |  
        | Unary minus | -a |  

        >Note that the multiplication operator contains the obligatory `*` character. Processing an expression with an omitted `*` sign is NOT POSSIBLE!

    - **Functions**: \
        | Calculates cosine | cos(x) |  
        | Calculates the sine | sin(x) |  
        | Calculates tangent | tan(x) |  
        | Calculates the arc cosine | acos(x) |  
        | Calculates arcsine | asin(x) |  
        | Calculates arc tangent | atan(x) |  
        | Calculates the square root | sqrt(x) |  
        | Calculates the natural logarithm | log(x) |  
        | Calculates the decimal logarithm | log(x) |  

## Part 2. Loan Calculator

There is a special mode "loan calculator":
 - Input: total loan amount, term, interest rate, type (annuity, differentiated)
 - Output: monthly payment, loan overpayment, total payment

## Part 3. Deposit Calculator

There is a special mode "deposit yield calculator":
 - Input: deposit amount, placement period, interest rate, tax rate, frequency of payments, capitalization of interest, list of replenishments, list of partial withdrawals
 - Exit: accrued interest, tax amount, deposit amount by the end of the term