#include <stdio.h>
#include "cars.h"



// Declaration des fonctions
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

int main() {
    // Declaration et initialisation des variables
    Car cars[100];
    int count = 0;
    int choice;

    do {
        printMenu();
        scanf_s("%d", &choice, sizeof(choice));

        switch (choice) {
        case 1:
            addCar(cars, &count);
            break;
        case 2: {
            int serialNumber;
            printf("Numero de serie de la voiture : ");
            scanf_s("%d", &serialNumber, sizeof(serialNumber));
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (cars[i].serialNumber == serialNumber) {
                    displayCar(&cars[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Voiture non trouvee avec le numero de serie %d.\n", serialNumber);
            }
            break;
        }
        case 3: {
            char brand[50];
            printf("Marque de la voiture : ");
            scanf_s("%s", brand, sizeof(brand));
            countCarsByBrand(cars, count, brand);
            break;
        }
        case 4:
            updateCarMileage(&cars[0]);
            break;
        case 5:
            findCarsByYear(cars, count, 2010);
            break;
        case 6:
            printCarsWithHighMileage(cars, count);
            break;
        case 7:
            addCarFromInput(cars, &count);
            break;
        case 8:
            displayCarWithFormattedMileage(&cars[0]);
            break;
        case 9:
            findCarWithMaxMileage(cars, count);
            break;
        case 10:
            displayCarBrandModel(&cars[0]);
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }
    } while (choice != 11);

    return 0;
}

void printMenu() {
    printf("\n--- Gestion des voitures ---\n");
    printf("1. Ajouter une nouvelle voiture\n");
    printf("2. Consulter les details d'une voiture\n");
    printf("3. Consulter le nombre de voitures par marque\n");
    printf("4. Mettre a jour le kilometrage d'une voiture\n");
    printf("5. Rechercher les voitures par annee\n");
    printf("6. Afficher les voitures avec un kilometrage eleve\n");
    printf("7. Ajouter une voiture a partir de l'entree utilisateur\n");
    printf("8. Afficher le kilometrage d'une voiture formate\n");
    printf("9. Trouver la voiture avec le kilometrage maximum\n");
    printf("10. Afficher la marque et le modele d'une voiture\n");
    printf("11. Quitter\n");
    printf("Choix : ");
}

void addCar(Car* cars, int* count) {
    Car newCar;
    printf("Numero de serie de la voiture : ");
    scanf_s("%d", &newCar.serialNumber, sizeof(newCar.serialNumber));
    printf("Marque de la voiture : ");
    scanf_s("%s", newCar.brand, sizeof(newCar.brand));
    printf("Modele de la voiture : ");
    scanf_s("%s", newCar.model, sizeof(newCar.model));
    printf("Annee de la voiture : ");
    scanf_s("%d", &newCar.year, sizeof(newCar.year));
    printf("Kilometrage de la voiture : ");
    scanf_s("%d", &newCar.mileage, sizeof(newCar.mileage));

    cars[*count] = newCar;
    (*count)++;
}

void displayCar(const Car* car) {
    printf("\n--- Details de la voiture ---\n");
    printf("Numero de serie : %d\n", car->serialNumber);
    printf("Marque : %s\n", car->brand);
    printf("Modele : %s\n", car->model);
    printf("Annee : %d\n", car->year);
    printf("Kilometrage : %d\n", car->mileage);
}

void countCarsByBrand(const Car* cars, int count, const char* brand) {
    int brandCount = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].brand, brand) == 0) {
            brandCount++;
        }
    }
    printf("Nombre de voitures de la marque %s : %d\n", brand, brandCount);
}

void updateCarMileage(Car* car) {
    int newMileage;
    printf("Nouveau kilometrage de la voiture : ");
    scanf_s("%d", &newMileage, sizeof(newMileage));
    car->mileage = newMileage;
    printf("Kilometrage mis a jour avec succes.\n");
}

void findCarsByYear(const Car* cars, int count, int year) {
    printf("\n--- Voitures de l'annee %d ---\n", year);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (cars[i].year == year) {
            displayCar(&cars[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucune voiture trouvee pour l'annee %d.\n", year);
    }
}

void printCarsWithHighMileage(const Car* cars, int count) {
    printf("\n--- Voitures avec un kilometrage < 100 000 ---\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (cars[i].mileage < 100000) {
            displayCar(&cars[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucune voiture avec un kilometrage < 100 000.\n");
    }
}

void addCarFromInput(Car* cars, int* count) {
    Car newCar;
    printf("Numero de serie de la voiture : ");
    scanf_s("%d", &newCar.serialNumber, sizeof(newCar.serialNumber));
    printf("Marque de la voiture : ");
    scanf_s("%s", newCar.brand, sizeof(newCar.brand));
    printf("Modele de la voiture : ");
    scanf_s("%s", newCar.model, sizeof(newCar.model));
    printf("Annee de la voiture : ");
    scanf_s("%d", &newCar.year, sizeof(newCar.year));
    printf("Kilometrage de la voiture : ");
    scanf_s("%d", &newCar.mileage, sizeof(newCar.mileage));

    cars[*count] = newCar;
    (*count)++;
}

void displayCarWithFormattedMileage(const Car* car) {
    printf("\n--- Details de la voiture (kilometrage formate) ---\n");
    printf("Numero de serie : %d\n", car->serialNumber);
    printf("Marque : %s\n", car->brand);
    printf("Modele : %s\n", car->model);
    printf("Annee : %d\n", car->year);

    int mileage = car->mileage;
    int km = mileage % 1000;
    int m = (mileage / 1000) % 1000;
    int km_display = mileage / 1000000;
    printf("Kilometrage : %d,%03d,%03d km\n", km_display, m, km);
}

void findCarWithMaxMileage(const Car* cars, int count) {
    int maxMileage = 0;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (cars[i].mileage > maxMileage) {
            maxMileage = cars[i].mileage;
            index = i;
        }
    }
    if (index != -1) {
        printf("\n--- Voiture avec le kilometrage maximum ---\n");
        displayCar(&cars[index]);
    }
    else {
        printf("Aucune voiture trouvee.\n");
    }
}

void displayCarBrandModel(const Car* car) {
    printf("\n--- Marque et modele de la voiture ---\n");
    printf("Marque : %s\n", car->brand);
    printf("Modele : %s\n", car->model);
}
