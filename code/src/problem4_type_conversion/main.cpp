////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 4: Type conversion.
/// \author     Georgii Zhulikov
/// \version    0.1.0
/// \date       25.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Create a program that performs the following steps:
/// 1. Reads three integer numbers from input.
/// 2. Multiplies each number by 2.
/// 3. Concatenates the results (their string representations) into a single large
///     number (also a string representation).
/// 4. Multiplies the result by 2.
/// 5. Outputs the resulting number.
/// 
/// Use stringstream for type converstion between numbers and strings.
/// (Additional) Use a debugger to check that at each step the strings and
/// numbers hold the correct values.
///
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <sstream>

int main()
{
    using std::cout;
    using std::cin;

    // TODO: provide your implementation here
    int a, b, c;
    cin >> a >> b >> c;         // use cin >> to read numbers
                                // use std::getline() to read a string with spaces

    a *= 2;                     // a = a * 2;
    b *= 2;
    c *= 2;

    //std::string abc(42, 'c');   // it creates a string of 42 characters 'c'
    // std::string abc = 42;        // there is no such a conversion
    std::string abc1 = std::to_string(a) + std::to_string(b) + std::to_string(c);
    // ^^^ this is inefficient due to presence of a complex expression with strings,
    //  which involves the presence of a set of intermediate string objects
    std::stringstream ss;
    ss << a << b << c;              // "246" as a string representation of the concatanation of "2", "4" and "6"
    std::string abc2 = ss.str();

    int abc2Num = std::stoi (abc2); // a bit “classical” approach

    int abc2Num2 = 0;               // needed for read a string representation as a number to this object
    ss >> abc2Num2;
    // look as you input a number using “cin >> abc2Num2” and type 246 as a string.


    
    cout << "\n\n";
    return 0;
}
