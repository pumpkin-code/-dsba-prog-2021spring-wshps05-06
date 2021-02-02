////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 8: Files.
/// \author     Georgii Zhulikov
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       25.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// 1) Create a function called sumLines() that obtains an input stream
/// object (given by reference) istream&, reads float numbers from it line by line
/// and sums up numbers from each line. The result is output to a given
/// output stream (given by reference) ostream&.
///
/// Reuse function calcSumFromStream() developed in ex.7 to deal with individual lines!
///
/// In the main program provide two different file stream (both text files) to
/// read from and output to data, correspondingly.
/// http://www.cplusplus.com/doc/tutorial/files/
/// 
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>      // for files

using std::cout;
using std::string;
using std::stringstream;

// TODO: Provide a declaration (a prototype) of the method calcSumFromStream() here.
double calcSumFromStream(std::istream& inp)
{
    double sum = 0;
    for (double buff; inp >> buff;)
    {
        sum += buff;
    }
    return sum;
}



// TODO: Provide a definition of the method sumLines() here.
void sumLines(std::istream& src, std::ostream& outS)
{
    while (!src.eof() &&
           src.good())
    {
        std::string s;
        std::getline(src, s);
        std::stringstream ss(s);        // we need to create a “wrapper”-stream for a
                                        // a string that has already been properly
                                        // read from the file stream!
                                        // do not mix together these two streams!

        double curSum = calcSumFromStream(ss);

        //std::cout <<
        outS << curSum << "\n";
    }
}


// the silution using real physical files
void solveProblemUsingFiles()
{
    const std::string OUT_FILE_NAME = "../../data/problem8_files/my_out.txt";
    const std::string IN_FILE_NAME = "../../data/problem8_files/inp.txt";
    // F:\\HSE\\training\\DSBA\\2020-21\\programming\\workshops\\05-06\\data\\problem8_files\\inp.txt
    // F:/HSE/training/DSBA/2020-21/programming/workshops/05-06/data
    std::fstream f;
    f.open(IN_FILE_NAME, std::ios_base::in);        // we may provide these parameters directly in the prev/ line

    // we may check whether the file is opened properly
    if (!f.is_open())       // logical NOT
    {
        //std::cout << "Can't open your file, bye-bye!";
        std::cerr << "Can't open your file, bye-bye!"; // the error stream,
                                                    // by default associated with the
                                                    // same “device” as std::cout
        return;
    }

    // id we didn't leave a function before this point, the file is propery open
    sumLines(f, std::cout);


    // let's try to do the same again. we can't do it w/o resetting the internal state
    // of the file stream, we need to clear all the error flags and change the position
    // of the reading header
    f.clear();                      // clears all bad flags
    f.seekg(0);                     // start reading from the very 0-th position again
    sumLines(f, std::cout);


    // now try to output the result to an associated output file stream
    std::fstream outFile(OUT_FILE_NAME, /*std::ios_base::in |*/ std::ios_base::out);
    // we may check whether the file is opened properly
    if (!outFile.is_open())       // logical NOT
    {
        // we need to close an input file properly here as well
        f.close();

        std::cerr << "Can't open the output file, bye-bye!";

        return;
    }

    f.clear();                      // clears all bad flags
    f.seekg(0);                     // start reading from the very 0-th position again
    sumLines(f, outFile);           // now we are reading from input file (stream) and output
                                    // transformed results to the output file (stream)

    outFile.close();

    // need close an opened file propery (let's do explicitly)
    f.close();


    // in C# there is the using keyword and similar the with... as construction in Python,
    // RAII idiom is used in C++ for that
}



//const int foo(const int& a) // const ← applicable to class members only
//{
//    // a = ..
//    // b = a

//    //return a;
//}

//void bar()
//{
//    int a = 10;
//    const int b = foo(a);
//}




int main()
{
    using std::cout;
    using std::cin;

    cout << "Workshop 6 Example 3\n\n";


    // DONE: Implement the main method here.
    solveProblemUsingFiles();


    // TODO: HW consider the same task (calculating numbers in lines) but read
    // the data from the std::cin instead of a file stream

    cout << "\n\n";

    return 0;
}

// TODO: Implement calcSumFromStream() method here.
