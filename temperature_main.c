#include <stdio.h>
#include <string.h>
#include "temperature.h"

int main() {
    //Floating variables called temp and converted_temp.
    float temp, converted_temp;
    //Character variables called tempScale and conv with a size of 10 to each.
    char tempScale[10], conv[10];

    //Displays the message "Enter temperature value: ".
    printf("Enter temperature value: ");
    //Checks to see if the value was valid through input from scanf.
    //This is a check for an integer value.
    while (scanf("%f", &temp) != 1) {
        //If value was not valid, display the message "Invalid input. Please enter a valid temperature."
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n'); //Clear input buffer
    }

    //Prompt for a valid input scale
    while (1) {
        //Display the message "Enter temperature scale of input value (Fahrenheit, Celsius, or Kelvin): "
        printf("Enter temperature scale of input value (Fahrenheit, Celsius, or Kelvin): ");
        //Read in the value with scanf and store it into tempScale.
        scanf("%s", tempScale);

        //A check to see if the value passed in matches with the temperature scales given.
        if (strcasecmp(tempScale, "Fahrenheit") == 0 ||
            strcasecmp(tempScale, "Celsius") == 0 ||
            strcasecmp(tempScale, "Kelvin") == 0) {
            
            //Ensure Kelvin is not negative by first checking the tempScale matches Kelvin.
            //After that, another logic "&& temp < 0" is made to ensure that the value is not negative.
            if (strcasecmp(tempScale, "Kelvin") == 0 && temp < 0) {
                //If it is negative, then display the message "Error: Kelvinf temperatures cannot be negative."
                printf("Error: Kelvin temperatures cannot be negative.\n");
                continue; //Re-prompt for input
            }
            break;
        }
        //Else, the tempScale does not match the given temperature scales and prompts for input again. 
        else {
            printf("Invalid temperature scale. Please enter Fahrenheit, Celsius, or Kelvin.\n");
        }
    }

    //Prompt for a valid conversion target
    while (1) {
        //Display the message "Enter conversion target (Fahrenheit, Celsius, or Kelvin): ".
        printf("Enter conversion target (Fahrenheit, Celsius, or Kelvin): ");
        //Read in the value with scanf and store it into conv.
        scanf("%s", conv);

        //A check to see if the conv matches with the target values given.
        if (strcasecmp(conv, "Fahrenheit") == 0 ||
            strcasecmp(conv, "Celsius") == 0 ||
            strcasecmp(conv, "Kelvin") == 0) {
            break;
        }
        //Else, the conv value does not match the target values and prompts the user to enter in a valid input. 
        else {
            printf("Invalid conversion scale. Please enter Fahrenheit, Celsius, or Kelvin.\n");
        }
    }

    //Conversion logic
    //A check for each case.
    //If the tempScale matches with Fahrenheit and the conv was Celsius.
    if (strcmp(tempScale, "Fahrenheit") == 0 && strcmp(conv, "Celsius") == 0) {
        //converted_temp is set to the function call fahrenheit_to_celsius with temp passed in as the argument.
        converted_temp = fahrenheit_to_celsius(temp);
    } else if (strcmp(tempScale, "Celsius") == 0 && strcmp(conv, "Fahrenheit") == 0) { //If the tempScale matches with Celsius and the conv was Fahrenheit.
        //converted_temp is set to the function call celsius_to_fahrenheit with temp passed in as the argument.
        converted_temp = celsius_to_fahrenheit(temp);
    } else if (strcmp(tempScale, "Celsius") == 0 && strcmp(conv, "Kelvin") == 0) { //If the tempScale matches with Celsius and the conv was Kelvin.
        //converted_temp is set to the function call celsius_to_kelvin with temp passed in as the argument.
        converted_temp = celsius_to_kelvin(temp);
    } else if (strcmp(tempScale, "Kelvin") == 0 && strcmp(conv, "Celsius") == 0) { //If the tempScale matches with Kelvin and the conv was Celsius.
        //converted_temp is set to the function call kelvin_to_celsius with temp passed in as the argument.
        converted_temp = kelvin_to_celsius(temp); 
    } else if (strcmp(tempScale, conv) == 0) { //Else if the tempScale and the conv match, then there is no conversion needed.
        //Displays the message "No conversion needed. The temperature remains." with temp.
        printf("No conversion needed. The temperature remains %.2f.\n", temp);
        return 0;
    } else { //Else, there was invalid tempScale value and displays the message "Invalid temperature scale input."
        printf("Invalid temperature scale input.\n");
        //Exits with an error.
        return 1;
    }

    //Ensure Kelvin result is not negative after the conversion happens (to not mess up logic for the categorize_temperature function)
    if (strcasecmp(conv, "Kelvin") == 0 && converted_temp < 0) {
        printf("Error: Invalid conversion. Kelvin temperature cannot be negative.\n");
        return 1;
    }

    //Display results by displaying "Converted temperature: " with the converted_temp, and conv passed in.
    printf("Converted Temperature: %.2f\n", converted_temp);

    
    //Determine the Celsius equivalent for categorization
    //Float variable called "celsius_equivalent"
    float celsius_equivalent;
    //If the conv value matches with Celsius.
    if (strcmp(conv, "Celsius") == 0) {
        //Set the celsius_equivalent to the converted_temp.
        celsius_equivalent = converted_temp;
    }
    //Else if the conv value matches with Fahrenheit. 
    else if (strcmp(conv, "Fahrenheit") == 0) {
        //Set the celsius_equivalent to the function call fahrenheit_to_celsius with converted_temp passed in as an argument.
        celsius_equivalent = fahrenheit_to_celsius(converted_temp);
    }
    //Else the match would be Kelvin 
    else {
        //Set the celsius_equivalent to the function call kelvin_to_celsius with converted_temp passed in as an argument.
        celsius_equivalent = kelvin_to_celsius(converted_temp);
    }

    //Categorize temperature with a function call to categorize_temperature with the celsius_equivalent passed in.
    categorize_temperature(celsius_equivalent);

    return 0;
}
