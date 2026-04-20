#include <stdio.h>
#include <math.h>

struct Point3D
{
    double x, y, z;
};

double calculate_distance(struct Point3D p)
{
    return sqrt(pow(p.x-0,2) + pow(p.y-0,2) + pow(p.z-0,2));
}

int main()
{
    // traditional way
    struct Point3D p1 = {2.0, 2.0, 2.0};
    printf("Distance for p1: %f\n", calculate_distance(p1));

    // compound literal way no variable name required (C99)
    printf("Distance for p2: %f\n", calculate_distance((struct Point3D){3.0,4.0,5.0}));

    return 0;
}