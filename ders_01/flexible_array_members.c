#include <stdio.h>
#include <stdlib.h>

double get_imu_reading()
{

}

// FAM - Flexible Array Members(C99)

struct SensorPackage
{
    int sensor_id;
    int data_count;

    // FLA - must be the LAST member
    double readings[];
};

int main()
{
    // Beacuse the array no fixed size
    // sizeof() operator only counts the fized members
    // total memory must be manually calculated with malloc() 

    // let's say we have 10 sensor reading
    int count = 10;
    size_t total_size = sizeof(struct SensorPackage) + (count * sizeof(double));
    
    // allocate memory
    struct SensorPackage *packet = malloc(total_size);

    if(packet)
    {
        packet->data_count = count;

        for(int i=0; i<count; i++)
        {
            packet->readings[i] = get_imu_reading();
        }
    }

    return 0;
}
