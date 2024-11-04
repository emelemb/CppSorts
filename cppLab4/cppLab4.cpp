#include "PersonReg.h"
#include <cstdlib>
#include <iostream>
#include <Vector>
#include <algorithm>

void print_vector(std::vector<int>& vec) {
    //prints :)
    for (int i{}; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

void print_carray(int aray[], int lenght)
{
    for (int i{}; i < lenght; i++)
    {
        std::cout << aray[i] << std::endl;
    }
    std::cout << std::endl;
}

void uppg1a() 
{
    //creates the vector: 
    int vectorLen = 10;
    std::vector<int> vector;
    for (int i{}; i < vectorLen; i++) 
    {
        int rng = rand();
        vector.push_back(rng);
    }
    std::cout << "before sort: " << std::endl;
    print_vector(vector);
    std::sort(vector.begin(), vector.end());
    std::cout << "after sort: " << std::endl;
    print_vector(vector);

}

void uppg1c() 
{
    int vectorLen = 10;
    std::vector<int> vector;
    for (int i{}; i < vectorLen; i++)
    {
        int rng = rand();
        vector.push_back(rng);
    }
    std::cout << "before sort: " << std::endl;
    print_vector(vector);
    std::sort(vector.rbegin(), vector.rend());
    std::cout << "after sort: " << std::endl;
    print_vector(vector);
}

void uppg1b() 
{
    const int lenght = 10;
    int array[lenght];

    for (int i{}; i < lenght; i++)
    {
        int rng = rand();
        array[i] = rng;
    }
    std::cout << "before sort: " << std::endl;
    print_carray(array,lenght);
    std::sort(array, array + lenght);
    std::cout << "after sword:  "  << std::endl;
    print_carray(array, lenght);
}

bool greater(int x, int y)
{
    return x > y;
}

void uppg1d()
{
    const int lenght = 10;
    int array[lenght];

    for (int i{}; i < lenght; i++)
    {
        int rng = rand();
        array[i] = rng;
    }
    std::cout << "before sort: " << std::endl;
    print_carray(array, lenght);
    std::sort(array, array + lenght, greater);
    std::cout << "after sword:  " << std::endl;
    print_carray(array, lenght);
}

void uppg2a(PersonReg& reg) {
    reg.Empty();
    std::cout << "before sort:" << std::endl;
    reg.AddPersonTest("hector", "0703955123");
    reg.AddPersonTest("hector", "123");
    reg.AddPersonTest("karin", "12345");
    reg.AddPersonTest("hector", "456");
    reg.AddPersonTest("sven", "456");
    reg.AddPersonTest("karin", "95815");
    reg.Print();

    std::random_shuffle(reg.begin(), reg.end());
    std::sort(reg.begin(), reg.end());
    std::cout << "after sort:" << std::endl;
    reg.Print();
}

bool even(int i) 
{
    return i % 2 == 0;
}

void uppg3a() 
{
    const int lenght = 10;
    int array[lenght];

    for (int i{}; i < lenght; i++)
    {
        int rng = rand();
        array[i] = rng;
    }
    std::cout << "Before removal: " << std::endl;
    print_carray(array, lenght);

    int* new_end = std::remove_if(array, array + lenght, even);
    int new_length = new_end - array; 

    std::cout << "After removal: " << std::endl;
    print_carray(array, new_length);
}


int main()
{
   // uppg1a();
    //uppg1b();
    //uppg1c();
   // uppg1d();
   // PersonReg personReg(6);
    //uppg2a(personReg);  // + uppg2b, depending of whihch bool operator is active. 
    uppg3a();
}
