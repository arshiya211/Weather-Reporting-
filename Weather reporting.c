#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 5  // Number of days for forecasting

// Function to generate random temperature
int get_temperature() {
    return rand() % 41 - 10; // Temperature between -10°C and 40°C
}

// Function to generate random humidity
int get_humidity() {
    return rand() % 101; // Humidity between 0% and 100%
}

// Function to generate random wind speed
int get_wind_speed() {
    return rand() % 31; // Wind speed between 0 km/h and 30 km/h
}

// Function to determine weather condition
const char* get_weather_condition(int temp, int humidity) {
    if (humidity > 70) {
        return "Rainy";
    } else if (temp > 30) {
        return "Sunny";
    } else if (temp < 10) {
        return "Cold";
    } else {
        return "Cloudy";
    }
}

// Function to display weather forecast
void weather_forecast() {
    printf("\n🌦 Weather Forecast for Next %d Days 🌦\n", DAYS);
    printf("--------------------------------------------------\n");
    printf("| Day | Temperature (°C) | Humidity (%) | Condition |\n");
    printf("--------------------------------------------------\n");

    for (int i = 1; i <= DAYS; i++) {
        int temp = get_temperature();
        int humidity = get_humidity();
        int wind_speed = get_wind_speed();
        const char* condition = get_weather_condition(temp, humidity);

        printf("|  %d  |       %2d°C       |     %2d%%      |  %s  |\n", i, temp, humidity, condition);
    }

    printf("--------------------------------------------------\n");
}

int main() {
    srand(time(0)); // Seed for random numbers

    printf("🌍 Welcome to the Weather Forecasting System 🌍\n");

    while (1) {
        printf("\nPress ENTER to get a weather forecast or type 'exit' to quit.\n");
        char input[10];
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'e') break; // Exit on 'e'

        weather_forecast();
    }

    printf("\nThank you for using the Weather Forecasting System! 🌤\n");
    return 0;
}
