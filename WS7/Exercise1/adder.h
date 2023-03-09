// adder.h
#ifndef MATHSLIB_ADDER_H
#define MATHSLIB_ADDER_H

/** @file
*	This file contains the declarations of all exported functions in the maths library.
*/

/** Adding function						[Basic arithmetic math function which returns the addition of two numbers]
*	This function adds two numbers		[Two int numbers are asked from the user and outputs the addition of them two]
*	@param a is the first number		[First user inputted int number]
*	@param b is the second number		[Second user inputted int number]
*	@return sum of a and b				[Returns value (a + b) and initializes int variable 'c' in calc.cpp to equal this returned value]
*/
	
	int add (int a, int b);
	
#endif