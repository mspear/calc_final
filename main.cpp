#include "stack.h"
#include "fraction.h"
#include <sstream>
#include <iostream>
#include <cmath>
#include <map>
#include <typeinfo>

using namespace std;

int main(int argc, char* argv[]) {
	int num, den;
  double real;
  char delim, token;
  string s, storVar;
  map<string, Fraction> stored;
  Fraction x, y;
	Stack<Fraction> stack;


	cout << "Enter an Expression: ";
	getline(cin, s);
	

	while (s!="") {

		// process s
		// loop and a half
		istringstream sin(s + " ");

		// Read one character of input

		sin >> token;
    bool failed = false;
    bool realNum = false;

		while (!sin.eof()) {
			//process the character
			switch (token) {
           case '+':
             x = stack.pop();
             y = stack.pop();

            //  if (typeid(x).name() == "double" || typeid(y).name() == "double"){
            //   x = (double)x;
            //   y = (double)y;
            // }
             stack.push(x + y);
           break;

           case '-':
             x = stack.pop();
             y = stack.pop();
            //  if (typeid(x).name() == "double" || typeid(y).name() == "double"){
            //   x = (double)x;
            //   y = (double)y;
            // }
             stack.push(y - x);
           break;

           case '*':
            x = stack.pop();
            y = stack.pop();
            // if (typeid(x).name() == "double" || typeid(y).name() == "double"){
            //   x = (double)x;
            //   y = (double)y;
            // }
            stack.push(x * y);
           break;

           case '/':
            x = stack.pop();
            y = stack.pop();
            // if (typeid(x).name() == "double" || typeid(y).name() == "double"){
            //   x = (double)x;
            //   y = (double)y;
            // }
            try{
              if (x == 0)
                throw "Divide by Zero Error";
              stack.push(y / x);
            }catch(...){
              cout << "Divide by Zero Error" << endl;
              failed = true;
            }
           break;

           case 'S':
            sin >> storVar;
            stored[storVar] = stack.peek();
           break;

           case 'R':
            try{
              sin >> storVar;
              stack.push(stored[storVar]);
            }catch (...){
              cout << "Variable not found" << endl;
              failed = true;
            }


           break;

           case '(':
            sin >> num;
            sin >> delim;
            sin >> den;
            sin >> delim;
            stack.push(Fraction(num, den));

           break;


           default:
             realNum = true;
             sin.putback(token);
             try{
               sin >> real;

               if (sin.fail()) {
                  cout << "Not a Number" << endl;
                  throw "Malformed Number";
               }
             }catch(...){
              cout << "Malformed Expression";
              while (!stack.isEmpty()){
                stack.pop();
              }
              failed = true;
              break;
             }

             int denominator = 1;
             while (abs((int)real - real) > 0.000000000000001) {
                real = real * 10;
                denominator = denominator * 10;
             }
             stack.push(Fraction((int) real, denominator));
           break;
         }
      if (failed)
        break;
			sin >> token;

		}
    if (!failed){
      stored["it"] = stack.pop();
      if (realNum)
        cout << "It is: " << stored["it"].asDouble() << endl;
      else
		    cout << "It is: " << stored["it"] << endl;
    }


		// read the next s
    cout << "Enter an Expression: ";
		getline(cin, s);

	}
  // delete stack;


	return 0;
}