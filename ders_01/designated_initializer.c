#include <stdio.h>

struct SensorConfig
{
    int id;
    char mode;
    double frequency;
};

// traditional (must follow order: id, mode, frequency)
struct SensorConfig s1 = {1, 'A', 50.0};

// Designated Initializer (C99)
struct SensorConfig s2 = {.mode='C', .frequency=30.0, .id=5};

int main()
{

    return 0;
}