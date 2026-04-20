#include <stdio.h>
#include <stdlib.h>

struct Point3D
{
    int x, y, z;

    void print()
    {
        printf("x: %d y: %d: z: %d\n",x,y,z);
    }
};

int main() {
    printf("Hello World!\n");
    return 0;
}