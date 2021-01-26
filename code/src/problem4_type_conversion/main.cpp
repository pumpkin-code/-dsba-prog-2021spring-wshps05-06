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
/// 3. Concatenates the (string representations of the numeric) results into a
///     single large number (string representation).
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

    cout << "Input three integers: ";
    int a, b, c;
    cin >> a >> b >> c;

    a *= 2;                         // a = a * 2
    b *= 2;
    c *= 2;

    // std::string abc = 2; // it's incorrect because there is no way to
                            // construct a string representation from an integer

    std::string abc = std::to_string(a) + std::to_string(b) + std::to_string(c);
        // ^^ this code is pretty correct, however it's still inefficient, because
        //    we implicitly create a lot of intermediate strings

    std::stringstream ss;
    ss << a << b << c;      // here we can consider numbers as parameters of operator<<
    std::string abc2 = ss.str();

    // the classical approach to convert a string to an integer it to use
    int abcNum = std::stoi(abc2);
    int abcNum2;
    ss >> abcNum2;          // converts the string representation of an integer to a num

    // stringstream allows to mix together object of diefferent types, e.g. integers and double and strings
    
    cout << "\n\n";
    return 0;
}
