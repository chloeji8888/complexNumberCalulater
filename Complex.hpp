
#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>
#include<string>
#include <sstream>
#include <stdexcept>
#include <iostream>

class Complex{
    
private:
    double real;
    double imaginary;
    
public:
    /**
     A single constexpr constructor that, through the use of default arguments, behaves
     as a default constructor that sets both the real and imaginary parts to 0; when given
     a single double as a parameter, the real part is set to this value and the imaginary
     part is set to 0; and when given two double inputs, it sets the real and imaginary
     parts to these values in respective order
     @param _real default real value
     @param _ima defauly imaginary value
     */
    constexpr Complex(double _real = 0, double _ima = 0);
    
    /**
     A constructor that accepts a string input, containing no spaces that
     can parse a string containing addition/subtraction of complex numbers,
     and turn it into a complex number.
     Given an invalid input like the empty string or one that cannot be parsed, it should throw a
     std::logic error with message “bad input string: [THE STRING]”.
     @param complexString a string containing addition/subtraction of complex number.
     */
    Complex(std::string complexString);
    
    /**
     Unary operators declarations
     */
    
    /**
     Unary operator- to return a complex number with negated real and imaginary
     parts;
     @return return a complex number with negated real and imaginary
     */
    constexpr Complex operator-()const;
    
    /**
     Unary operator+ to return a copy of the complex number;
     @return return a copy of the complex number
     */
    constexpr Complex operator+()const;
    
    /**
     Unary operator ̃ to return the conjugate of the complex number;
     @return  return the conjugate of the complex number;
     */
    constexpr Complex operator~()const;
    
    /**
     Prefic(unary) operator such that the real part (and
     only the real part) is incremented by 1;
     @return the complex number with real part increased by 1
     */
    constexpr Complex& operator++();
    
    /**
     unary --, prefix, decrease real number by 1
     @return the complex number with real part decreased by 1
     */
    constexpr Complex& operator--();

    
    /**
     Binary operators declarations
     */
    
    /**
     binary operator += adding two complex numbers, changing the left-hand side
     @param other complex number input
     @return sum
     */
    constexpr Complex& operator+=(const Complex& other);
    
    /**
     binary operator -= subtracting two complex numbers, changing the left-hand side
     @param other complex number input
     @return difference
     */
    constexpr Complex& operator-=(const Complex& other);
    
    /**
     binary ++, postfix, increasing the real part by 1
     @param unused unused
     @return the number after addition
     */
    constexpr Complex operator++(int unused);
    
    /**
     binary -- . postfix, decrease the real part by 1
     @param unused unused
     @return the number after subtraction
     */
    constexpr Complex operator--(int unused);
    
    /**
     binary operator *= multiplying two complex numbers, changing the left-hand side
     @param other input of multiplication
     @return pruduct
     */
    constexpr Complex& operator*=(const Complex& other);
    
    /**
     binary operator /= divided two complex numbers, changing the left-hand side
     @param other complex number input
     @return quotient
     */
    constexpr Complex& operator/=(const Complex& other);
    
    
    /**
     call operator resetting both parts to 0
     @return 0
     */
    constexpr Complex& operator()();
    
    
    /**
     A subscript operator overloaded on const taking either “real” or “imag” as
     arguments and returning the real or imaginary parts of the number respectively
     (possibly as references), and should the subscript be invalid an std::out of range
     exception should be thrown, without being caught, with an error description “invalid
     index: [WHATEVER THE BAD INDEX WAS]”;
     */
    double operator[](std::string i) const;
    
    /**
     Subscript operator returning correponding real or imaginary parts of a complex number according to an argument
     (reference used for assigning value)
     @param i argument "real' or "imag" corresponding to real or imaginary part
     @return corresponding part
     */
    double& operator[](std::string i);
    
    /**
     bool  operator < check if left one is smaller than the right one.
     @param left complex number one left
     @param right comlex number on the riht
     */
    friend constexpr bool operator<(const Complex& left , const Complex&right);

    
    /**
     Operator>> to read in two double values, separated by white space, respectively
     setting the real and imaginary parts of the complex number on the right-hand side
     of an input stream;
     @param in instream with the two numbers
     @param c complex number to be assigned
     @return the istream
     */
     friend std::istream& operator >>(std::istream& in, Complex& c);
    
    /**
     conversion operator from Complex to std::string
     @return the string
     */
    operator std::string() const;
    
    
};

/**
 binary operator +, adding two complex numbers
 @param add complex number on the left
 @param to_add complex number on the right
 @return sum
 */
constexpr Complex operator+(Complex add, const Complex& to_add);

/**
 binary operator -, subtract two complex numbers
 @param sub complex number on the left
 @param to_sub complex number on the right
 @return difference
 */
constexpr Complex operator-(Complex sub, const Complex& to_sub);

/**
 binary operator *, time two complex numbers
 @param mul complex number on the left
 @param to_mul complex number on the right
 @return product
 */
constexpr Complex operator*(Complex mul, const Complex& to_mul);

/**
 binary operator /, divided two complex numbers
 @param div complex number on the left
 @param to_div complex number on the right
 @return quotient
 */
constexpr Complex operator/(Complex div, const Complex& to_div);

/**
 operator<< to display a complex number with an output stream
 @param out the stream out
 @param _in the complex number to be displayed
 @return the outstream with the complex number passed
 */
std::ostream& operator<<(std::ostream& out, const Complex& _in);

/**
 bool  operator > check if left one is greater than the right one.
 @param left complex number one left
 @param right comlex number on the riht
 */
constexpr bool operator>(const Complex& left , const Complex&right);

/**
 bool  operator == check if left one is equal to the right one.
 @param left complex number one left
 @param right comlex number on the riht
 */
constexpr bool operator ==(const Complex& left , const Complex&right);

/**
 bool  operator == check if left one smaller or equal to the right one.
 @param left complex number one left
 @param right comlex number on the riht
 */
constexpr bool operator <=(const Complex& left , const Complex&right);

/**
 bool  operator == check if left one greater or equal to the right one.
 @param left complex number one left
 @param right comlex number on the riht
 */
constexpr bool operator >=(const Complex& left , const Complex&right);

/**
 bool  operator == check if left one no  equal to the right one.
 @param left complex number one left
 @param right comlex number on the riht
 */
constexpr bool operator !=(const Complex& left , const Complex&right);

/**
user defined literal expression _i, format the user-defined literal
 @param imaginary user defined imaginary part
 @return formatted complex number
 */
constexpr Complex operator""_i(const long double imaginary);


/**
 * Definitions of Declarations
 */

/**
 * Unary definitions ----------------------------------------------------------------------------------------
 */

constexpr Complex::Complex(double _real, double _ima):real(_real), imaginary(_ima){};

constexpr Complex Complex::operator+()const{
    return *this;//copy of the complex number
}

constexpr Complex Complex::operator-()const{
    return Complex(-real, -imaginary);
    //complex number with negated real and imaginary parts;
}

constexpr Complex Complex::operator~()const{
    return Complex(real, -imaginary);
    //conjugate is to make + to -
}

constexpr Complex& Complex:: operator++(){
    ++real;//increment  real number
    return *this;
}

constexpr Complex& Complex::operator--(){
    --real;//decrement real number;
    return *this;
}


/**
 * Binary definitions ----------------------------------------------------------------------------------------
*/
constexpr Complex& Complex::operator+=(const Complex& other){
    real += other.real;//add up real numbers
    imaginary += other.imaginary;//add up imaginary numbers
    return *this;
}

constexpr Complex& Complex::operator-=(const Complex&other){
    real -= other.real;//subtract real numbers
    imaginary -= other.imaginary;//subtract real numbers
    return *this;
}

constexpr Complex Complex::operator++(int unused){
    auto copy{*this};
    ++*this;//increment  real number
    return copy;
}

constexpr Complex Complex::operator--(int unused){
    auto copy{*this};
    --(*this);//decrement real number;
    return copy;
}

constexpr Complex& Complex::operator*=(const Complex& other){
    //(1 + 2i) * (2 + 3i) == 1 * 2 + 1 * 3i + 2i * 2 + 2i * 3i
    //== 1 * 2 + 1 * 3i + 2i * 2 - 2 * 3
    double original_real = real;
    double original_ima = imaginary;
    real = other.real * original_real - other.imaginary * original_ima;//1 * 2 - 2 * 3
    imaginary = original_real * other.imaginary + original_ima * other.real;//1 * 3i + 2i * 2
    return *this;
}

constexpr Complex& Complex::operator/=(const Complex& other){
    //(1 + 2i) / (2 + 3i) == (1 + 2i)(2 - 3i) / (2 + 3i)(2 - 3i)
    double original_real = real;
    double original_ima = imaginary;
    double new_r = (original_real * other.real  + original_ima * other.imaginary)/(other.real * other.real + other.imaginary * other.imaginary);
    //(1 * 2) + (2 * 3) / 2 * 2 + 9
    double new_ima = (original_ima * other.real - original_real * other.imaginary)/(other.real * other.real + other.imaginary * other.imaginary);
    //(2i * 2) - (1 * 3i) / 2 * 2 + 9
    real = new_r;
    imaginary = new_ima;
    return *this;
}

constexpr Complex& Complex::operator()(){
    real = 0;// setting the real to 0
    imaginary = 0;//setting the imaginary to 0
    return *this;
}

constexpr bool operator < (const Complex& left , const Complex&right){
    if(left.real < right.real){// if the real in left is smaller than the real in right
        return true;//return true
    }else if(left.real == right.real){//if the real in left is equal to the real in right
        if(left.imaginary < right.imaginary){
            //if the imag in left is smaller than the imag in righ
            return true;//return true
        }
    }
    return false;
}

constexpr bool operator > (const Complex& left , const Complex&right){
    if(!(left < right) && !(left == right)){
        return true;
    }
    return false;
}

constexpr bool operator == (const Complex& left , const Complex&right){
    if(!(left < right) && !(right < left)){
        return true;
    }
    return false;
}

constexpr bool operator >= (const Complex& left , const Complex&right){
    return (left > right) || (left == right);
}

constexpr bool operator <= (const Complex& left , const Complex&right){
    return (left < right) || (left == right);
}

constexpr bool operator != (const Complex& left , const Complex&right){
    return !(left == right);
}

constexpr Complex operator""_i(long double imaginary){
    return Complex(0, static_cast<double>(imaginary));
}

constexpr Complex operator+(Complex add, const Complex &to_add) {
    return add += to_add;

}

constexpr Complex operator-(Complex sub, const Complex &to_sub) {
    return sub -= to_sub;
}

constexpr Complex operator*(Complex mul, const Complex &to_mul) {
    return mul *= to_mul;
}

constexpr Complex operator/(Complex div, const Complex &to_div) {
    return div /= to_div;
}





#endif /* Complex_hpp */
