#include <iostream>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

// REFERENCE PARAMETERS

const double MAX_RPM_RACING = 9000;     // Maximum RPM for racing engines
const double MAX_RPM_OFFROAD = 6500;    // Maximum RPM for offroad engines
const double TORQUE_RACING = 0.75;      // Racing torque factor (higher RPMs)
const double TORQUE_OFFROAD = 1.25;     // Offroad torque factor (lower RPMs)

// FUNCTIONS

double calculateDisplacement(double bore, double stroke, int cylinders) {
    return (M_PI * pow(bore / 2, 2) * stroke * cylinders);
}

double calculateBore(double displacement, double stroke, int cylinders) {
    return 2 * sqrt(displacement / (M_PI * stroke * cylinders));
}

double estimateHorsepower(double displacement, double rpm) {
    // Simple approximation of horsepower, not very realistic though
    return (displacement * rpm) / 5252.0;
}

double estimateTorque(double displacement, double rpm) {
    // Torque approximation, again, not very realistic
    return (displacement * rpm) / 5252.0;
}

double calculatePowerToWeight(double horsepower, double weight) {
    return horsepower / weight;
}

int main() {
    double stroke, desiredCc, bore, rpm, weight, horsepower, torque, powerToWeight;
    int cylinders;
    string useCase;

    // INPUT

    cout << "Enter the stroke length of the engine (in mm): ";
    cin >> stroke;

    if (cin.fail() || stroke <= 0) {
        cout << "Invalid input for stroke. Please enter a positive value." << endl;
        return 1;
    }

    cout << "Enter the desired power output (displacement) of the engine (in cc): ";
    cin >> desiredCc;

    if (cin.fail() || desiredCc <= 0) {
        cout << "Invalid input for displacement. Please enter a positive value." << endl;
        return 1;
    }

    cout << "Enter the use case (racing or offroad): ";
    cin >> useCase;

    if (useCase != "racing" && useCase != "offroad") {
        cout << "Invalid use case. Please enter either 'racing' or 'offroad'." << endl;
        return 1;
    }

    cout << "Enter the number of cylinders: ";
    cin >> cylinders;

    if (cylinders <= 0) {
        cout << "Invalid number of cylinders. Please enter a positive integer." << endl;
        return 1;
    }

    cout << "Enter the weight of the engine in kg (estimate): ";
    cin >> weight;

    if (weight <= 0) {
        cout << "Invalid input for weight. Please enter a positive value." << endl;
        return 1;
    }

    // CALCULATE

    bore = calculateBore(desiredCc, stroke, cylinders);

    double totalDisplacement = calculateDisplacement(bore, stroke, cylinders);

    rpm = (useCase == "racing") ? MAX_RPM_RACING : MAX_RPM_OFFROAD;
    double torqueFactor = (useCase == "racing") ? TORQUE_RACING : TORQUE_OFFROAD;

    horsepower = estimateHorsepower(totalDisplacement, rpm);
    torque = estimateTorque(totalDisplacement, rpm) * torqueFactor;

    powerToWeight = calculatePowerToWeight(horsepower, weight);

    // OUTPUT

    cout << "\nCalculated Engine Specifications:" << endl;
    cout << "Bore size: " << bore << " mm" << endl;
    cout << "Total displacement: " << totalDisplacement << " cc" << endl;
    cout << "Estimated Horsepower: " << horsepower << " hp" << endl;
    cout << "Estimated Torque: " << torque << " Nm" << endl;
    cout << "Power-to-Weight Ratio: " << powerToWeight << " hp/kg" << endl;

    if (useCase == "racing") {
        cout << "\nFor racing: A higher RPM engine with a focus on horsepower is ideal." << endl;
        cout << "Consider increasing bore size for better power output." << endl;
    } else {
        cout << "\nFor offroad: A torque-oriented engine is ideal with lower RPM." << endl;
        cout << "Consider increasing stroke length for better low-end torque." << endl;
    }

    return 0;
}
