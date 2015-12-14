#include "stack.h"
#include "fraction.h"
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char* argv[]) {
	int num, den;
	Stack<Fraction> stack;
	string s;
	char delim, token;
	cout << "Enter an Expression: ";
	getline(cin, s);
	Fraction x, y, stored;
  double real;

	while (s!="") {

		//process s
		// loop and a half

		istringstream sin(s + " ");

		// Read one character of input

		sin >> token;

		while (!sin.eof()) {
			//process the character
			switch (token) {
           case '+':
             x = stack.pop();
             y = stack.pop();
             stack.push(x + y);
           break;

           case '-':
             x = stack.pop();
             y = stack.pop();

             x = x - y;
             stack.push(x);
           break;

           case '*':
            x = stack.pop();
            y = stack.pop();

            x = x * y;
            stack.push(x);
           break;

           case '/':
            x = stack.pop();
            y = stack.pop();

            x = x / y;
            stack.push(x);
           break;

           case 'S':
            stored = stack.peek();
           break;

           case 'R':
             // recall code goes here
           break;

           case '(':
            sin >> num;
            sin >> delim;
            sin >> den;
            sin >> delim;
            stack.push(Fraction(num, den));

           break;

           default:
             sin.putback(token);
             try{
               sin >> real;

               if (sin.fail()) {
                  cout << "Not a Number" << endl;
                  throw "Malformed Number";
               }
             }catch(...){
              while (!stack.isEmpty()){
                stack.pop();
              }
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

			sin >> token;

		}
		cout << stack.pop() << endl;


		// read the next s
    cout << "Enter an Expression: ";
		getline(cin, s);

	}
  // delete stack;


	return 0;
}