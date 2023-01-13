// -----------------------------------
// CSCI 340 - Operating Systems I 
// Fall 2021 (Anthony Leclerc)
// utils.c implementation file
// Homework Assignment 1
//
// -----------------------------------

#define PI    3.14159265  // define of constant PI
#define DEBUG 0		  // 1 turns on debug printf(); 0 turns debugging off

// -----------------------------------
// C-Style data structure to hold vector magnitude, r, and direction, theta
// Note: theta is in degrees
//
typedef struct {
  double r;	// magnitude value
  double theta;	// direction value (in degrees)
} v_struct;

// -------------------- BEGIN read() --------------------
// Function prototype for reading a text file that defines vectors. See 
// assignment for format of this file.
int read(char* file_name, v_struct* p_vec_array, int n);
// Arguments: 	file_name   --- file name of vector text file
//	      	p_vec_array --- pointer to an array of v_structs
//              n           --- size of p_vec_array
//
// Step-by-Step instructions this function performs:

//  1. Open the text file named file_name
//
//  2. For each vector defined in the text file, BUT NO MORE than n vectors:
//     a) read the line containing the magnitude and direction values
//     b) keep track of the number of lines you have read-in
//     c) split using the comma character as the delimiter. NOTE:
//        There are many ways to do this, just remember a char pointer
//        (i.e. char*) can be treated as a character array
//        (i.e. file_name[0] will return the char value at index
//        position 0).  Don't forget to increment a counter variable
//        that maintains the number of vectors read-in by this
//        function.
//     d) Convert parsed magnitude and direction values from a string
//        to a double (hint: use atof() function)
//     e) Store magnitude and direction double values in the correct
//        index position in the v_struct array.  Hint: The position of
//        the vector in the text file is equivalent to the index
//        position in the v_struct array. That is, the direction and
//        magnitude values stored in p_vec_array[0] would be the first
//        vector in the vectors text file.
//
//  3. Close file
//
// Return:  the number (int type) of vectors read-in by function
//
// -------------------- END read() --------------------

// -------------------- BEGIN x_component() --------------------
// Function prototype that uses the magnitude and direction values in
// the vector structure to compute the x component, i.e. r*cos(theta)
double x_component(v_struct* p_vec_ptr);
// Arguments: 	p_vec_ptr --- points to a v_struct
//
// Note: theta must be converted from degrees to radians prior to
// calculation.
//
// Return:  double value that represents x component value
//
// -------------------- END x_component() --------------------




// -------------------- BEGIN y_component() --------------------
// Function prototype that uses the magnitude and direction values in
// vector structure to compute the y component, i.e. r*sin(theta)
//
double y_component(v_struct* p_vec_ptr);
// Arguments: 	p_vec_ptr --- points to a v_struct
//
// Note: theta must be converted from degrees to radians prior to
// calculation.
//
// Return:  double value that represents y component value
//
// -------------------- END y_component() --------------------
