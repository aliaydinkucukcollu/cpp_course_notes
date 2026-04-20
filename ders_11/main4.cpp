#include <iostream>


// const correctness
struct Date
{
    int d, m, y;
};

void print_date(Date*)
{

}

int main() {

    Date d = {3, 5 ,1998};

    print_date(&d);

    return 0;
}