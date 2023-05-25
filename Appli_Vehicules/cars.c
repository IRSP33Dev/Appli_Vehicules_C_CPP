#include "cars.h"
#include <stdio.h>
#include <string.h>

// Définition des fonctions
void printMenu();
void addCar(Car* cars, int* count);
void displayCar(const Car* car);
void countCarsByBrand(const Car* cars, int count, const char* brand);
void updateCarMileage(Car* car);
void findCarsByYear(const Car* cars, int count, int year);
void printCarsWithHighMileage(const Car* cars, int count);
void addCarFromInput(Car* cars, int* count);
void displayCarWithFormattedMileage(const Car* car);
void findCarWithMaxMileage(const Car* cars, int count);
void displayCarBrandModel(const Car* car);