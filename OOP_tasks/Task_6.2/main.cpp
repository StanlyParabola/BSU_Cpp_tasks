#include "Stationary.h"
#include "Movable.h"
#include "DynamicArray.h"

int main() {

    DynamicArray array;

    array.Add(new Star("Sun", 5778));
    array.Add(new Planet("Earth", 288, true));
    array.Add(new Asteroid(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 1000.0));
    array.Add(new SpaceShip("Falcon", 10.0, 20.0, 30.0, 0.5, 0.6, 0.7, 3000.0, 50));
    array.Add(new Rocket(10.0, 20.0, 30.0, 1.0, 1.5, 2.0, 500.0, 120.0));

    std::cout << "Initial array:" << std::endl;
    array.Print();

    array.Remove(2); // Remove the asteroid

    std::cout << "\nArray after removing the asteroid:" << std::endl;
    array.Print();


    std::cout<<"Cleared array"<<std::endl;
    array.Print();


    return 0;
}
