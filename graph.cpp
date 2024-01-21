#include <iostream>
#include <cmath>
#include <vector>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

const double u = 0.02;
const double g = 9.8;
const double dt = 0.1;
const double cdpa = 0.30699;

double getVelocity(double r, double t) {
    double velocity_squared = std::pow((r / 10) - 0.9 * r * std::cos(t), 2) + std::pow(r * std::sin(t), 2) * (1 - (t - 6) / 7);
    return 170 + std::cbrt(velocity_squared);
}

double getAcceleration(double r, double t, double v) {
    double drag_force = -0.5 * cdpa * v * std::abs(v); 
    return std::abs(r * (std::sqrt(0.81 * std::pow(std::cos(t), 2) + std::pow(std::sin(t), 2))) -
           u * g * ((1 - 9 * std::cos(t)) / (10 * std::sin(t))) + drag_force)/50;
}

void plot() {
    std::vector<double> rValues = {95.6, 93.25, 90, 97, 88.74, 86.56, 84.44, 82.37};

    plt::figure_size(1200, 400); 

    std::vector<double> dtValues;
    std::vector<double> accelerationValues;
    std::vector<double> velocityValues;

    double tStart = 3.0;

    for (double r : rValues) {
        for (double t = tStart; t <= tStart + 7; t += dt) {
            double v = getVelocity(r, t);
            double a = getAcceleration(r, t, v);

            dtValues.push_back(t);
            accelerationValues.push_back(a);
            velocityValues.push_back(v);
        }

        tStart += 7.0;  
    }

    // Plot acceleration
    plt::subplot(1, 2, 1);
    plt::plot(dtValues, accelerationValues);
    plt::xlabel("Parameterisation Variable (t)");
    plt::ylabel("Acceleration (m/s^2)");
    plt::title("Acceleration");

    // Plot velocity
    plt::subplot(1, 2, 2);
    plt::plot(dtValues, velocityValues);
    plt::xlabel("Parameterisation Variable (t)");
    plt::ylabel("Velocity (m/s)");
    plt::title("Velocity");

    plt::show();
}

int main() {
    plot();
    return 0;
}
