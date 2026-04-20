#include <stdio.h>

double read_sensor()
{
    // code
}

// VLA - Variable Length Arrays (C99)
void process_sensor_batch(int n)
{
    double buffer[n];

    for(int i=0; i<n; i++)
    {
        buffer[i] = read_sensor();
    }
}