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
            // ^^ the full-quilified name for a global object
    
    // TODO: provide your implementation here


    // prompt a user to input their name separately
    cout << "Input first name: ";
    std::string firstName;                   // use cameStyle not snake_style
    // ^^^ the full qulified name for the data type
    cin >> firstName;

    // your code
    cout << "Input last name: ";
    std::string lastName;
    cin >> lastName;
    

    // straight direction
    cout << firstName << " " << lastName;

    // reverse direction
    cout << " (" << lastName  << ", " <<  firstName << ")";

    // After the last input with cin >> we have '\n' symbol preserved in the
    // input stream, and, thus, if we call getline() method, it will return
    // immediately with n empty string. This is why we use the cin.ignore() method
    // to extract the remaining part of the previous reading.
    cin.ignore(1);      // get rid of '\n'
    //cin.clear();


    cout << "\n\nInput the full name: ";
    std::string fullName;
    //cin >> fullName;          // extracts only the part of input before the very first space symbol
    std::getline(cin, fullName);
    cout << "Full Name: " << fullName;

    
    cout << "\n\n";
    return 0;
}
