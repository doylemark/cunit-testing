

#include "avg_and_max.h"

/*
 Calculates the average of the double values inside array
 
 Parameters:
 array: contains the double values
 size: the size of the array, i.e. the number of double values inside the array
 */
double average(double array[], int size){
    double sum = 0;
    for(int i =0; i < size - 1; i++){
        sum += array[i];
    }
    return sum/size;
    
}

/*
 Calculates the maximum among the double values inside array
 
 Parameters:
 array: contains the double values
 size: the size of the array, i.e. the number of double values inside the array
 */
double max (double array[], int size){
    double max;
    for(int i =0; i < size ; i++){
        if(max < array[i])
            max = array[i];
    }
    return max;
    
}
