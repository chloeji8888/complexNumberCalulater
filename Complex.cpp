
#include "Complex.hpp"
#include<sstream>
#include <iostream>
#include<stdexcept>
#include <string>


using namespace std;

Complex::Complex(std::string in){
 
    istringstream input(in);
    char op;
    real = 0;
    imaginary = 0;
    string completeNum;

    if(input.peek() == EOF) {
        throw logic_error("bad input string: " + in);
    }
    while(input.peek() != EOF) {
        op = input.peek();
        if (op == '+') {
            input.get();//if the next char is +, get the current number
            op = input.peek();//check the next char
            if (op == 'i') {//if the next char is just a i
                imaginary++;//increment the imaginary number for the result to have 1
                input.get();
                continue;
            } else {//if is not i
                while (char c = input.get()) {//phrasing complete numbers
                    if (c == '+' || c == '-' || c == 'i') {//if there is a sign or i
                        input.unget();//unget the number
                        break;//stop when encountering +, -, i
                    }
                    completeNum += c;//else add the char of number to the string of complete number that we gonna convert to double.
                    if (input.peek() == EOF) {
                        break;
                    }
                }
            }

            double doubleCompleteNum = stod(completeNum);
            // convert the string of complete number to double
            completeNum.clear();//erase the content in the string to become an empty string

            char sth = input.peek();//check the next char after the complete number
            if (sth == '+' || sth == '-' || sth == EOF) {// if it is a sign or an end of string
                real += doubleCompleteNum;// add the complete number to real number.
            } else if (sth == 'i') {// if there is a i
                imaginary += doubleCompleteNum;// add it to the imaginary number
                input.get();
            }

        } else if (op == '-') {//if the next char is -
            //get the current number
            input.get();
            if (input.peek() == 'i') {//if the nect char is i
                imaginary--;// make the imaginary -1
                input.get();
                continue;
            } else if (isdigit(input.peek())) {
                //if the next char is a decimal digit: 0123456789
                while (char c = input.get()) {//phrasing complete numbers
                    if (c == '+' || c == '-' || c == 'i') {
                        input.unget();
                        break;//stop when encountering +, -, i
                    }
                    completeNum += c;//else add the char to the string of complete number
                    if (input.peek() == EOF) {//if reached to the end of the string
                        break;//break
                    }
                }
                double doubleCompleteNum = stod(completeNum);
                // convert the string of complete number to double
                completeNum.clear();//erase the content in the string to become an empty string

                char sth = input.peek();//check the next char after the complete number
                if (sth == '+' || sth == '-' || sth == EOF) {// if it is a sign or an end of string
                    real -= doubleCompleteNum;// subtract the complete number to real number.
                } else if (sth == 'i') {// if there is a i
                    imaginary -= doubleCompleteNum;//  subtract it to the imaginary number
                    input.get();
                }
            }
        } else if (isdigit(op)) {//when decimal digits comes first
            while (char c = input.get()) {//phrasing complete numbers
                if (c == '+' || c == '-' || c == 'i') {
                    input.unget();
                    break;//stop when encountering +, -, i
                }
                completeNum += c;//add it to the complete number string
                if (input.peek() == EOF) {
                    break;
                }
            }
            double doubleCompleteNum = stod(completeNum);
            // convert the string of complete number to double
            completeNum.clear();//erase the content in the string to become an empty string

            char sth = input.peek();//check the next char after the complete number
            if (sth == '+' || sth == '-' || sth == EOF) {// if it is a sign or an end of string
                real += doubleCompleteNum;// add the complete number to real number.
            } else if (sth == 'i') {// if there is a i
                imaginary += doubleCompleteNum;// add it to the imaginary number
                input.get();
            }
        }else if(op == 'i'){//if i comes first
            ++imaginary ;// increment the imaginary
            input.get();
        }else{// if it is neither of things above
            throw logic_error("bad input string: " + in);// throw an error
            break;
        }
    }
}

double Complex::operator[](std::string i)const{
    if(i == "real"){
        return real;//if i is "real" return real number
    }else if(i == "imag"){
        return imaginary;//if i is "imaginary" return imaginary number
    }else{
        throw std::out_of_range("invalid index: [" + i + "]");
        // if i will be neither "real" nor "imaginary" throw an exception
    }
}

double& Complex::operator[](std::string i){
    if(i=="real"){
         return real;//if i is "real" return real number
    }
    else if(i =="imag"){
         return imaginary;//if i is "imaginary" return imaginary number
    }
    else{
         throw std::logic_error("invalid index: [" + i + "]");
        // if i will be neither "real" nor "imaginary" throw an exception
    }
}


std::istream &operator>>(istream &in, Complex &c) {
    in >> c.real >> c.imaginary;//read in real number and imaginary number
    if(in.fail()){
        throw std::runtime_error("read error");// if fail to read the file, throw read error
    }
    return in;
}


std::ostream &operator<<(ostream &out, const Complex & c) {
    double realOut = c["real"];
    double imaOut = c["imag"];
    if(realOut == 0 && imaOut == 0){
        out << 0;
    }
    if(realOut != 0){
        out << realOut;
    }else if(imaOut != 0){
        if(imaOut < 0){
            if(imaOut == -1){
                if(realOut == 0){
                    out << "-i";
                }
                else{
                    out << imaOut << "i";
                }
            }else{
                out << imaOut << "i";
            }
        }else if(imaOut > 0){
            if(imaOut == 1){
                if(realOut == 0){
                    out << "i";
                }else{
                    out << "+" << "i";
                }
            }else{
                if(realOut == 0){
                    out << imaOut << "i";
                }
                out << "+" << imaOut << "i";
            }
        }
    }
    return out;
}
    

    
//    double realOut = c["real"];//if the input is "real", return the real number
//    double imaOut = c["imag"];
//    //if the input is "imaginary", return the imaginary number
//    if (realOut == 0 && imaOut == 0) {// if both of the number are 0
//        out << 0;//read out 0;
//    }
//    if (realOut != 0) {//if real number is not 0
//        out << realOut;//read out the real number
//    }
//    if (imaOut != 0) {//if imaginary number is not 0
//        if (imaOut > 0) {//if ima is positive
//            if (imaOut == 1) {//if ima is 1
//                if (realOut == 0) {//if real number is 0
//                    out << "i";// read out i
//                } else {//if real number is not 0
//                    out << "+ i";// read out +i after the real number
//                }
//            } else {//if ima is positive except 1
//                if (realOut == 0) {// real number is 0
//                    out << imaOut << "i";// read out ima*i
//                } else {//real number is not 0
//                    out << "+" << imaOut << "i";// plus the ima*i;
//                }
//            }
//        } else if (imaOut < 0) {//if ima is negative
//            if (imaOut == -1) {//if ima is -1
//                out << "-i";//read out -i
//            } else {//if ima is negative number except -1
//                out << imaOut << "i";//read out - ima * i;
//            }
//        }
//    }
//    return out;
//}
Complex::operator std::string() const {
    ostringstream input ;
    input << *this;//inplement the double into the stream
    string number= input.str();//conver the double through str and store it in string number
    return number;//return the number
}






           




