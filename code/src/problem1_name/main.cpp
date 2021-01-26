////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 1: Name input/output.
/// \author     Georgii Zhulikov
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       25.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Programs ask a user to input their name, individually first and last part,
/// and outputs a name into two different form: 1) straight, 2) inverse with comma
///
/// In the end, try to input both first and last names in the same line. Why a
/// program considers two words separated with spaces as two independend inputs?
/// How to fix it? → see 2nd example.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


int main()
{
    using std::cout;
    using std::cin;
            // ^^^ fully-qualified name for a global object

    // prompt a user to input their name separately
    cout << "Input first name: ";
    std::string firstName;              // we use cameStyle for local objects, not snake_style
        // ^^^ fully-qualified name for a datatype
    cin >> firstName;                   // let's input "John\n"
                                        // now cin stream consists of only "\n", it's ignored at the next call of >>
    cout << "Input last name: ";
    std::string lastName;
    cin >> lastName;                    // let's input "Doe\n"
                                        // now cin stream consists of only "\n", it would be ignored at the next call of >>
    
    // straigh direction
    cout << "Full name: " << firstName << " " << lastName; // we didn't mention any '\n' or std::endl here, so cursor is kept at the same line

    // reverse direction
    cout << " (" << lastName << ", " << firstName
         << ")" /*two consequently followed string literals are merged */ "\n\n";
    
    // now we have an issue. When we combine together imputting data with using
    // cin >> and std::getline(), after the >> operator founds the '\n' symbol in
    // the stream it stops reading from the stream keeping the '\n' left in the
    // stream. The getline() method is called, reads the '\n' symbol preserved
    // in the stream and stops immedeately returning the empty string.

    // in order to throw away the “unexpected” '\n' character, we are going to
    // use the cin.ignore() method: https://www.cplusplus.com/reference/istream/istream/ignore/
    //cin.ignore(1);      // we ignore exectly next 1 characters ('\n') in __cin__ stream
    cin.ignore();           // the same as cin.ignore(1), because n = 1 by default

    cout << "Enter full name: ";
    std::string fullName;
    std::getline(cin, fullName);                // this is a “free” function, defined in the std scope
    cout << "The full name is: " << fullName;


    cout << "\n\n";
    return 0;
}
