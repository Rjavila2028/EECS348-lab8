#include <stdio.h>

// Converts temperature from one scale to another
float convertTemp(float temp, char from, char to) {
    float celsius;

    // Convert input temperature to Celsius
    if (from == 'C') {
        celsius = temp;
    } else if (from == 'F') {
        celsius = (temp - 32) * 5 / 9;
    } else if (from == 'K') {
        celsius = temp - 273.15;
    } else {
        // Invalid input scale
        printf("Invalid input scale.\n");
        return -9999;
    }

    // Convert Celsius to target scale
    if (to == 'C') {
        return celsius;
    } else if (to == 'F') {
        return celsius * 9 / 5 + 32;
    } else if (to == 'K') {
        return celsius + 273.15;
    } else {
        // Invalid target scale
        printf("Invalid target scale.\n");
        return -9999;
    }
}

// Categorizes temperature and prints weather advisory
void giveAdvisory(float celsius) {
    printf("Temperature category: ");

    // Determine category based on Celsius value
    if (celsius < 0) {
        printf("Freezing\nWeather advisory: Wear a heavy coat!\n");
    } else if (celsius < 10) {
        printf("Cold\nWeather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Comfortable\nWeather advisory: Enjoy the weather!\n");
    } else if (celsius < 35) {
        printf("Hot\nWeather advisory: Drink lots of water!\n");
    } else {
        printf("Extreme Heat\nWeather advisory: Stay indoors and stay cool!\n");
    }
}

int main() {
    float temp, converted;
    char from, to;

    // Prompt user for temperature value
    printf("Enter the temperature value: ");
    scanf("%f", &temp);

    // Prompt for original scale (C, F, or K)
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &from);

    // Prompt for target scale (C, F, or K)
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &to);

    // Perform conversion
    converted = convertTemp(temp, from, to);

    // If conversion was successful, display result and advisory
    if (converted != -9999) {
        printf("Converted temperature: %.2f %c\n", converted, to);

        // Convert to Celsius for advisory logic
        float celsius = convertTemp(temp, from, 'C');
        giveAdvisory(celsius);
    }

    return 0;
}
