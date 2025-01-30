#include <stdio.h>

typedef struct
{
    float weight;
    float height;
    int age;
} WeightHeightAge;

struct Car
{
    int id;
    char model;
    int year;
};

int structs()
{
    WeightHeightAge weightHeightAge;
    weightHeightAge.weight = 70.5;
    weightHeightAge.height = 1.75;

    struct Car car;
    car.id = 1;
    car.model = 'A';
    car.year = 2020;

    printf("Weight: %f, Height: %f\n, Age: %i", weightHeightAge.weight, weightHeightAge.height, weightHeightAge.age);

    return 0;
}

int main()
{
    printf("Testando a função structs():\n");
    structs();
    return 0;
}