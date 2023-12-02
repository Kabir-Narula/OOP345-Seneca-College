/* Compositions------------------------

Composition represents a "whole-part" relationship, where one class (the whole) is composed of or owns objects of another class (the part). The part objects are an integral part of the whole and cannot exist independently. When the whole object is created, the part objects are usually created as well, and when the whole object is destroyed, the part objects are destroyed too.*/

class Engine {
public:
    void Start() {
        // Implementation for starting the engine
    }
};

class Car {
private:
    Engine engine; // Composition: Car has an Engine
public:
    void Drive() {
        engine.Start(); // Access the Engine through composition
        // Implementation for driving the car
    }
};

int main() {
    Car myCar; // Creating a Car object also creates an Engine
    myCar.Drive(); // Starts the car's engine and drives it
    return 0;
}


// In above code the engine  is totally dependent on the class car, when the class ca ris destoryed the object engine is destroyed aswell....


