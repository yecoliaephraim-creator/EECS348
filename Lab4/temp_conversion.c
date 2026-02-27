#include <stdio.h>
#include <stdbool.h>

/* Required conversion functions */
float celsius_to_fahrenheit(float c);
float fahrenheit_to_celsius(float f);
float celsius_to_kelvin(float c);
float kelvin_to_celsius(float k);

/* Extra helpers */
float fahrenheit_to_kelvin(float f);
float kelvin_to_fahrenheit(float k);
void categorize_temperature(float celsius);

int main(void) {
  // Main loop: program runs until invalid input is entered
  while(true) {
    float temp;
    char inScale, outScale;

    // Prompt the user for a temperature value
    printf("Enter the temperature value: ");
    if (scanf("%f", &temp) != 1) {
        printf("Invalid temperature input.\n");
        break;
    }

    // Prompt the user for the temperature scale
    printf("Choose the current scale (C/F/K): ");
    if (scanf(" %c", &inScale) != 1) {
        printf("Invalid scale input.\n");
        break;
    }

    // Prompt the user for the conversion target
    printf("Convert to (C/F/K): ");
    if (scanf(" %c", &outScale) != 1) {
        printf("Invalid target scale input.\n");
        break;
    }

    /* Input validation: Kelvin cannot be negative */
    if ((inScale == 'K' || inScale == 'k') && temp < 0.0f) {
        printf("Invalid input: Kelvin cannot be negative.\n");
        break;
    }

    /* Invalid conversion choice: same scale */
    if ((inScale == outScale) || (inScale + 32 == outScale) || (inScale - 32 == outScale)) {
        printf("Invalid conversion: input and output scales are the same.\n");
        break;
    }
    /* Conversion Logic */
    float converted = 0.0f;
    // Temerature catagories are based on Celsius,
    // so we store or convert the values to Celsius for classification.
    float celsiusForCategory = 0.0f;

    /* Convert input -> output */
    if ((inScale == 'C' || inScale == 'c') && (outScale == 'F' || outScale == 'f')) {
        converted = celsius_to_fahrenheit(temp);
        celsiusForCategory = temp;
        printf("Converted temperature: %.2fF\n", converted);
    }
    else if ((inScale == 'F' || inScale == 'f') && (outScale == 'C' || outScale == 'c')) {
        converted = fahrenheit_to_celsius(temp);
        celsiusForCategory = converted;
        printf("Converted temperature: %.2fC\n", converted);
    }
    else if ((inScale == 'K' || inScale == 'k') && (outScale == 'C' || outScale == 'c')) {
        converted = kelvin_to_celsius(temp);
        celsiusForCategory = converted;
        printf("Converted temperature: %.2fC\n", converted);
    }
    else if ((inScale == 'C' || inScale == 'c') && (outScale == 'K' || outScale == 'k')) {
        converted = celsius_to_kelvin(temp);
        celsiusForCategory = temp;
        printf("Converted temperature: %.2fK\n", converted);
    }
    else if ((inScale == 'F' || inScale == 'f') && (outScale == 'K' || outScale == 'k')) {
        converted = fahrenheit_to_kelvin(temp);
        celsiusForCategory = fahrenheit_to_celsius(temp);
        printf("Converted temperature: %.2fK\n", converted);
    }
    else if ((inScale == 'K' || inScale == 'k') && (outScale == 'F' || outScale == 'f')) {
        converted = kelvin_to_fahrenheit(temp);
        celsiusForCategory = kelvin_to_celsius(temp);
        printf("Converted temperature: %.2fF\n", converted);
    }
    else {
        printf("Invalid conversion choice.\n");
        break;
    }
    /* Categorize based on Celsius */
    categorize_temperature(celsiusForCategory);
    printf("\n");

  }
  
  return 0;
}

/* ---- Conversion functions ---- */

// celsius to fahrenheit
float celsius_to_fahrenheit (float c) {
  return (9.0f / 5.0f) * c + 32.0f;
}

// fahrenheit to celsius
float fahrenheit_to_celsius (float f) {
  return (5.0f / 9.0f) * (f - 32.0f);
}

// kelvin to celsius
float kelvin_to_celsius (float k) {
  return k - 273.15f;
}

// celsius to kelvin
float celsius_to_kelvin (float c) {
  return c + 273.15f;
}

// fahrenheit to kelvin
float fahrenheit_to_kelvin (float f) {
  return celsius_to_kelvin(fahrenheit_to_celsius(f));
}

// kelvin to fahrenheit
float kelvin_to_fahrenheit (float k) {
  return celsius_to_fahrenheit(kelvin_to_celsius(k));
}

/* ---- Categorization + advisory ---- */

void categorize_temperature (float celsius) {
  printf("Temperature catagory: ");

  if (celsius < 0.0f) {
    printf("Freezing\n");
    printf("Weather advisory: Wear heavy layers.\n");
  }
  else if (celsius <= 10.0f) {
    printf("Cold\n");
    printf("Weather advisory: Wear a jacket.\n");
  }
  else if (celsius <= 25.0f) {
    printf("Comfortable\n");
    printf("Weather advisory: You should feel comfortable.\n");
  }
  else if (celsius <= 35.0f) {
    printf("Hot\n");
    printf("Weather advisory: Stay hydrated.\n");
  }
  else {
    printf("Extreme Heat\n");
    printf("Weather advisory: Stay indors if possible.\n");
  }
}