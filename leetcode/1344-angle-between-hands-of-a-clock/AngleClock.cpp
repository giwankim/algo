#include "bits/stdc++.h"
using namespace std;

double angleClock(int hour, int minutes) {
    double small = 30 * (hour % 12) + 0.5 * minutes;
    double big = 6 * minutes;
    double ret = abs(big-small);
    ret = min(ret, 360.0 - ret);
    return ret;
}

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        int hour = 12;
        int minutes = 30;
        double correct_result = 165;
        double result = angleClock(hour, minutes);
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    {
        cout << "=====Example 2=====\n";
        int hour = 3;
        int minutes = 30;
        double correct_result = 75;
        double result = angleClock(hour, minutes);
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    {
        cout << "=====Example 3=====\n";
        int hour = 3;
        int minutes = 15;
        double correct_result = 7.5;
        double result = angleClock(hour, minutes);
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    {
        cout << "=====Example 4=====\n";
        int hour = 4;
        int minutes = 50;
        double correct_result = 155;
        double result = angleClock(hour, minutes);
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    {
        cout << "=====Example 5=====\n";
        int hour = 12;
        int minutes = 0;
        double correct_result = 0;
        double result = angleClock(hour, minutes);
        cout << "Expected:\n\t";
        cout << correct_result << "\n";
        cout << "Output:\n\t";
        cout << result << "\n";
    }
    return 0;
}
