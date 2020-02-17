// FDE 561 Food Engineering Analysis
// HOMEWORK 2
// Prepared By: Baris Ege Gulenc

// IMPORTANT:
// Note to insturctor:
// There were no input example provided,
// therefore I have assumed there will be a file
// of which consists of a V value in every line.
// Such as:
// 1
// 2
// ...
//
// I have also assumed that V values will be integers. 

#include <stdio.h>
#include <stdlib.h> // for atoi()

// define constants for the Hagen-Poiseuille equation
int LEN = 6;
float DIA = 0.05;
float VIS = 0.0000135;

// define the function returning the result of Hagen-Poiseuille equation,
// depending on the provided V argument
float deltap(int v) {
    return 32*VIS*v*LEN/DIA/DIA;
}

int main() {
    // initialize arrays to hold the delta P and V values
    float deltap_values[15];
    int v_values[15];

    int counter = 0;

    // initialize char buffer
    char buffer[10];

    // initializer file pointer
    FILE * fptr;

    fptr = fopen("numbers.txt", "r");
    // reads text until newline is encountered
    // we could also run a for loop 15 times but thıs seems like a better way to do it
    while (EOF != fscanf(fptr, "%[^\n]\n", buffer))
    {   
        // convert the readed value to int and write to the relevant array
        v_values[counter] = atoi(buffer);

        // calculate delta p according to v value and write to the relevant array
        deltap_values[counter] = deltap(v_values[counter]);
        counter++;
    }

    // close the file
    fclose(fptr);

    // print the table headers
    printf("%11s %11s %11s", "increment #", "V", "ΔP\n");

    // print rows of the table, formatted accordingly
    for (int i = 0; i < 15; i++)
    {
        printf("%11i %11d %11.2f\n", i+1, v_values[i], deltap_values[i]);
    }

    return 0;
}