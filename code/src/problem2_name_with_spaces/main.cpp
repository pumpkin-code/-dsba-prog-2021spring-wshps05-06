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
#include <sstream>      // for std::stringstream

int main()
{
    using std::cout;
    using std::cin;

    // prompt a user to input their name separately
    cout << "Input first name (not longer than 254 characters): ";


    // You should use cin.getline() method, which can't work with std::string
    // directly. Hence, you have to use a buffer, implemented as an array of
    // char(acters).
    // Suppose that a name can't exceed 254 symbols (characters)
    char buf[255];                      // why not 254? — we need to reserver one more symbol for null-terminator '\0'
    const size_t bufSize = sizeof(buf); // get the actual size of the buffer
                                        // at the compilation stage

    cin.getline(buf, bufSize);          // a method getline() defined for the istream type.
                                        // do not be confused with the same-name method std::getline()


    std::string first(buf);             // initialize a string w/ the buffer

    cout << "Input last name (not longer than 254 characters): ";
    cin.getline(buf, bufSize);
    std::string last = buf;             // exactly the same as if we would use last(buf)
    
    std::string fullName = first + " " + last;
                            // ^^^ this is working (correct), but inefficient way to concatenate strings
                            // we have too many intermediate string objects

    // Use the following lines for output
    cout << "Name in straight order: " << fullName;

    
    ///////////////////////
    // Alternative method:
    
    // using std::stringstream allows to combine different strings
    // more efficiently
    std::stringstream ss;
    ss << last << ", " << first;        // it outputs the given objects into a set
                                        // of internal buffer(s) efficiently

    std::string fullReversedName = ss.str();    // given the string representation of properly combined internal buffers
    //cout << "\n\nName in reverse order: " << fullReversedName;
    cout << "\n\nName in reverse order: " << ss.str();


    cout << "\n\n";
    return 0;
}
