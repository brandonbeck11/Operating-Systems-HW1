// -----------------------------------
// CSCI 340 - Operating Systems I 
// Fall 2021 (Anthony Leclerc)
// utils.c implementation file
// Homework Assignment 1
//
// -----------------------------------

// ----------------------------------------------
// These are the only libraries that can be 
// used. Under no circumstances can additional 
// libraries be included
#include <stdio.h>	// standard I/O functions
#include <stdlib.h> 	// atof()
#include <math.h>	// math functions

#include "utils.h"	// user defined functions

// See utils.h for the required function prototypes and specifications

// Now you put your IMPLEMENTATION of the function prototypes here...

int read(char* file_name, v_struct* p_vec_array, int n) {

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {       
        printf("Failed to open file %s\n", file_name);
        exit(1);
    }

    size_t size = 40;
    size_t bytes_read;
    char *buffer = (char*) malloc(size);
    double theta;
    int i;

    for (i = 0; i < n; i++) {
        bytes_read = getline(&buffer, &size, fp);
    
        if (bytes_read == -1) {
            break;
        }
        
        char* t = buffer;
        while (*t != ',' && *t != '\0') {
            t++;
        }
        
        p_vec_array[i].r = atof(buffer);

        theta = atof(t+1);
        if (theta > 360.0) {
            theta -= 360.0;
        } else if (theta < -360.0) {
            theta += 360.0;
        }
        p_vec_array[i].theta = theta;
    }

    fclose(fp);
    return i;
}

double x_component(v_struct* p_vec_ptr) {
    double radians;
    radians = ((p_vec_ptr->theta) * (2 * PI)) / 360;
    return p_vec_ptr->r * cos(radians);
}

double y_component(v_struct* p_vec_ptr) {
    double radians;
    radians = ((p_vec_ptr->theta) * (2 * PI)) / 360;
    return p_vec_ptr->r * sin(radians);
}