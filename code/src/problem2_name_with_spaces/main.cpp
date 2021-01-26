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
#include <sstream>          // std::stringstream

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

    cin.getline(buf, bufSize);          // DO NOT be confused with the std::getline() — they are mostly different methods with the similar names

        // ^^^ if defined in the definition of istream datatype (istream cin)

    std::string first(buf);             // initialize a string w/ the buffer

    cout << "Input last name: ";
    cin.getline(buf, bufSize);
    std::string last(buf);
    
    // Use the following lines for output
    // cout << "Name in straight order: " << straight;
    // cout << "\n\nName in reverse order: " << reverse;


    // the first approach to concatenate strings
    std::string full(first + " " + last);       // inefficient due to making a set of intermediate string objects:
                                                // 1) first + " ", 2) (first + " ") + last
    cout << "\nFull name: " << full;

    
    ///////////////////////
    // Alternative method, which is useful when one needs to concatenate a sequence of strings:
    
    // using std::stringstream allows to combine different strings
    // more efficiently
    // it works as a mix of ostream (operator<<) and istream (operator>>)
    std::stringstream ss;
    ss << last << ", " << first;

    // stringstream can be converted to a string using
    std::string s = ss.str();
    cout << "\nStringStreamed full name: " << ss.str();



    // ss << last + ", " + first;




    cout << "\n\n";
    return 0;
}
