////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 2: Name with spaces.
/// \author     Georgii Zhulikov
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       25.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Modify example 1, so it allows a user to input a complex name that
/// consists of more than 1 word (separated by spaces).
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>

int main()
{
    using std::cout;
    using std::cin;

    // prompt a user to input their name separately
    cout << "Input first name: ";


    // You should use cin.getline() method, which can't work with std::string
    // directly. Hence, you have to use a buffer, implemented as an array of
    // char(acters).
    // Suppose that a name can't exceed 254 symbols
    char buf[255];                      // why not 254?
    const size_t bufSize = sizeof(buf); // get the actual size of the buffer
                                        // at the compilation stage

    cin.getline(buf, bufSize);
    std::string first(buf);             // initialize a string w/ the buffer

    cout << "Input last name: ";

    
    // Use the following lines for output
    // cout << "Name in straight order: " << straight;
    // cout << "\n\nName in reverse order: " << reverse;


    
    ///////////////////////
    // Alternative method:
    
    // using std::stringstream allows to combine different strings
    // more efficiently
    // std::stringstream ss;
    // ss << last + ", " + first;




    cout << "\n\n";
    return 0;
}
