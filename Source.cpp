#include "Complex.hpp"
#include<vector>
#include<algorithm>
#include<iostream>
int main() {
// some warmups
    Complex u{ 2,3 }, v{ 1,1 };
    std::cout << "simple stuff: " << u + v << '\n' << u - v << '\n' << u*v << '\n' << u / v << '\n';
// constexptr stuff
    constexpr Complex z0 = 1.77_i;
    constexpr Complex z0_conj = ~z0;
    constexpr Complex z0_copy = +z0;
    constexpr Complex z0_negated = -z0;
// display this constexpr stuff
    std::cout << "z0, z0 conj, z0 copy, z0 neg: " << z0 << " " << z0_conj << " "
              << z0_copy << " " << z0_negated << '\n';
// Create Complex numbers through constructors
    constexpr Complex z1, z2{ 3, 4 };
    constexpr Complex z3 = (Complex{ 1 } += (4 - 3._i));
    Complex z4 = z3;
    z4 *= 2; // multiply by 2 (which will be converted to Complex(2,0)
    // Create with user-defined literal
    Complex z5 = 3.14 + 14.3_i;
    std::cout << "Numbers z1, z2, z3, z4, z5: " << z1 << " " << z2 << " " << z3
              << " " << z4 << " " << z5 << '\n';
// turn z5 to its conjugate
    z5 = ~z5;
    std::cout << "z5 after conjugation: " << z5 << '\n';
    std::cout << "z5*z3: " << z5*z3 << '\n';
// Do some arithmetic to them and check values
    z4 += z3; z4 /= z5;
    Complex z6 = z1 + z2 + z3 - z4;
    Complex z7 = z6;
    z7();
    std::cout << "z4, z5, z6, z7: " << z4 << " " << z5 << " " << z6 << " " << z7
              << '\n';
// And read in with std::cin
    std::cout << "Enter two doubles to set real and imaginary parts: ";
    std::cin >> z4;
    std::cout << "-z4 and +z5: " << -z4 << " " << +z5 << '\n';
// Access real and imaginary parts
    z4["real"] = 0.14;
    std::cout << "real(z4) and imag(z4): " << z4["real"] << " " << z4["imag"] <<
              '\n';
// increment and decrement operators
    ++++z4, z5------;
    std::cout << "z4 with two pre++ and z5 with 3 post--: " << z4 << " " << z5 <<
              '\n';
// store items in a vector, sort them
    std::vector<Complex> vec{ z1, z2, z3, z4, z5, z6, z7 }; // vector of complex
    std::vector<std::string> vec2{ z1, z2, z3, z4, z5, z6, z7 }; // vector of strings because of conversion operator
    std::cout << "The elements: ";
    for (const std::string& complexString : vec2) { // print each as a string
        std::cout << complexString << " ";
    }
    std::sort(std::begin(vec), std::end(vec)); // sort the Complex numbers
    std::cout << "\nsorted vector: ";
    for (const Complex& number : vec) { // print the sorted list
        std::cout << number << " ";
    }
    std::cout << '\n';
    try { // try accessing invalid index
        z2["reel"];
    }
    catch (const std::out_of_range& ORR) { // upon failure, print the error and continue to run the program
        std::cerr << ORR.what() << '\n';
    }
// access real part of a constant number
    const Complex z8 = z7;
    std::cout << "z8 imag: " << z8["imag"] << '\n';
// testing the tostrings...
    std::cout << Complex{ "3+4i" } << '\n' << Complex{ "i" } << '\n' <<
              Complex{ "i+2i-3.2+4.2i+6-1" } << '\n' << Complex{ "-i" } << '\n';
    std::string empty;
    std::string also_bad("3.2-seven");
    try { // outer try
        try { // inner try, makes a Complex from empty string
            Complex will_fail(empty);
            std::cout << will_fail << '\n';
        }
        catch (const std::logic_error& L) { // manage that exception
            std::cout << L.what() << '\n';
            Complex not_gonna_work = also_bad; // but give another bad string
            std::cout << not_gonna_work << '\n';
        }
    }
    catch (const std::logic_error& L) { // catch any throws here
        std::cerr << L.what() << '\n';
    }
    return 0;
}
