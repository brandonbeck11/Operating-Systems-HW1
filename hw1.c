// ----------------------------------------------
// These are the ONLY libraries that can be 
// used. UNDER NO CIRCUMSTANCES can additional 
// libraries be included!
#include <stdio.h>	// I/O functions
#include <stdlib.h> 	// atof() function
#include <math.h>	// math functions (eg. sin(), cos())

#include "utils.h"	// user defined functions, constants, and data types

// ----------------------------------------------
// Define constants
#define TOTAL_VECS 10	// constant that defines the total number 
			// of vectors, i.e. magnitude,direction
			// pairs, in the vectors text file. DON'T
			// CHANGE!

// -----------------------------------
// Main function 
// Arguments:	argc --- number of arguments suppled by user
//		argv --- array of argument values
//
int main(int argc, char** argv) {
  // --------------------------------
  // Steps to be performed
  //	1. Define variables (including arrays)
  //	2. Using read() function in utils.h, read vectors
  //	   defined in text file
  //	  - the location of the text file (i.e. vectors.txt)
  //	    MUST BE specified in argv[1]
  //  	3. Loop through array of vector structs and print to
  //  	   console:
  //	  - vector magnitude (using only 2 decimal places)
  //	  - vector direction (in radians using only 2 decimal places)
  //	  - vector direction (in degrees using only 2 decimal places)
  //	  - x component value (using only 2 decimal places) using
  //	      x_component() function in utils.h
  //	  - y component value (using only 2 decimal places) using
  //	      y_component() function in utils.h,
  //
  //	  in the following format:
  //
  //  r = <val>, theta = <val> deg, <val> rad, x_comp = <val>, y_comp = <val>
  //
  //	  FOR EXAMPLE:
  //  r = 10.00, theta = 180.00 deg, 3.14 rad, x_comp = -10.00, y_comp = 0.00 
  //
  
  v_struct* vectors = (v_struct*) malloc(sizeof (v_struct) * TOTAL_VECS);
  int n;
  n = read("vectors.txt", vectors, TOTAL_VECS);

  int i;
  double radians;
  double x_value;
  double y_value;

  for (i = 0; i < n; i++) {
    x_value = x_component(&vectors[i]);
    y_value = y_component(&vectors[i]);
    radians = ((vectors[i].theta) * (2 * PI)) / 360;
    printf("r = %6.2f, theta = %6.2f deg, %4.2f rad, x_comp = %6.2f, y_comp = %6.2f\n"
    , vectors[i].r, vectors[i].theta, radians, x_value, y_value);  
  }

  return 0;
} // end main() function
