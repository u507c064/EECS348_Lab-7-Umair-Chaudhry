#include "temperature.h"
#include <stdio.h>

//Function called "celsius_to_fahrenheit" which takes in a floating variable called "celsius" as a parameter.
float celsius_to_fahrenheit(float celsius)
{
    //Returns the conversion of celsius to fahrenheit.
    return (celsius * 9/5) + 32;
}

//Function called "fahrenheit_to_celsius" which takes in a floating variable called "fahrenheit" as a parameter.
float fahrenheit_to_celsius(float fahrenheit)
{
    //Returns the conversion of fahrenheit to celsius.
    return  (5.0/9) * (fahrenheit - 32);
}

//Function called "celsius_to_kelvin" which takes in a floating variable called "celsius" as a parameter.
float celsius_to_kelvin(float celsius)
{
    //Returns the conversion of celsius to kelvin.
    return celsius + 273.15;
}

//Function called "kelvin_to_celsius" which takes in a floating variable called "celsius" (typo) as a parameter.
float kelvin_to_celsius(float celsius)
{
    //Returns the conversion of kelvin to celsius.
    return celsius - 273.15;
}

//Function called "categorize_temperature" which takes in a floating variable called "celsius".
//Displays cautionary messages based on the temperature (in celsius) given.
void categorize_temperature(float celsius) {
    //If celsius is below 0.
    if (celsius < 0) {
        //Display the message "Category: Freezing\nAdvisory: Stay warm! Wear heavy winter clothing."
        printf("Category: Freezing\nAdvisory: Stay warm! Wear heavy winter clothing.\n");
    }
    //Else if the celsius was between 0 and 10.
    else if (celsius >= 0 && celsius < 10) {
        //Display the message Category: Cold Advisory: Wear a jacket."
        printf("Category: Cold\nAdvisory: Wear a jacket.\n");
    }
    //Else if the celsius was between 10 and 25. 
    else if (celsius >= 10 && celsius < 25) {
        //Display the message "Comfortable Advisory: Enjoy the weather!"
        printf("Category: Comfortable\nAdvisory: Enjoy the weather!\n");
    }
    //Else if the celsius was between 25 and 35 
    else if (celsius >= 25 && celsius < 35) {
        //Display the message "Hot Advisory: Stay hydrated and wear light clothing."
        printf("Category: Hot\nAdvisory: Stay hydrated and wear light clothing.\n");
    }
    //Else the celsius is above 35. 
    else {
        //Display the message "Category: Extreme Heat Advisory: Avoid prolonged sun exposure and stay indoors if possible."
        printf("Category: Extreme Heat\nAdvisory: Avoid prolonged sun exposure and stay indoors if possible.\n");
    }
}
