#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Define constants for the different traffic light states
const int GREEN = 0;
const int YELLOW = 1;
const int RED = 2;

// Define the TrafficLight class
class TrafficLight {
private:
    int state; // Current state of the traffic light

public:
    TrafficLight() {
        // Initialize the traffic light to green
        state = GREEN;
    }

    // Method to change the state of the traffic light
    void changeState() {
        switch (state) {
            case GREEN:
                state = YELLOW;
                break;
            case YELLOW:
                state = RED;
                break;
            case RED:
                state = GREEN;
                break;
        }
    }

    // Method to get the current state of the traffic light
    int getState() {
        return state;
    }

    // Method to print the current state of the traffic light
    void printState() {
        switch (state) {
            case GREEN:
                cout << "Green" << endl;
                break;
            case YELLOW:
                cout << "Yellow" << endl;
                break;
            case RED:
                cout << "Red" << endl;
                break;
        }
    }
};

// Main function
int main() {
    TrafficLight northSouthLight, eastWestLight; // Create two traffic lights

    // Loop infinitely, changing the traffic light states every 10 seconds
    while (true) {
        // Change the north-south traffic light
        cout << "North-South light is ";
        northSouthLight.printState();
        northSouthLight.changeState();

        // Change the east-west traffic light after the north-south light has changed
        cout << "East-West light is ";
        eastWestLight.printState();

        // Check if the north-south light is currently red
        if (northSouthLight.getState() == RED) {
            eastWestLight.changeState();
        }

        // Wait for 10 seconds before changing the traffic lights again
        cout << "Waiting 10 seconds..." << endl;
        for (int i = 0; i < 10; i++) {
            cout << 10 - i << " ";
            Sleep(1000); // Wait for 1 second
        }
        cout << endl;
    }

    return 0;
}
