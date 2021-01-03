#include "../../std_lib_facilities.h"

void first_iteration() {
    double first = 0, second = 0;
    while (cin >> first >> second) {
        cout << first << ' ' << second << '\n';
        if (first > second) {
            cout << "the smaller value is: " << second << '\n';
            cout << "the larger value is: " << first << '\n';
        } else if (first < second) {
            cout << "the smaller value is: " << first << '\n';
            cout << "the larger value is: " << second << '\n';
        } else cout << "the numbers are equal.\n";
    }
}
////////////////////////////////////////////////////////////
void second_iteration() {
    double number = 0, smallest, largest;
    cin >> number;
    smallest = largest = number;

    while (cin >> number) {
        cout << number << '\n';

        if (number < smallest) {
            smallest = number;
            cout << "this is the smallest so far.\n";
        }

        if (number > largest) {
            largest = number;
            cout << "this is the largest so far.\n";
        }
    }
}
////////////////////////////////////////////////////////////
void third_iteration() {
    double number = 0, value = 0, sum = 0, smallest = 0, largest = 0, count = 0;
    string unit = "";
    bool first_count = true;

    while (cin >> number >> unit) {
        if (unit != "m" && unit != "cm" && unit != "in" && unit != "ft") {
            cout << "incorrect unit. \n";
            continue;
        }
        cout << number << ' ' << unit << '\n';

        if (unit == "m")  value = number;
        if (unit == "cm") value = number/100;
        if (unit == "in") value = (number*2.54)/100;
        if (unit == "ft") value = (number*2.54*12)/100;
        
        if (first_count) {
            smallest = value;
            first_count = false;
        }
        if (value < smallest) smallest = value;
        if (value > largest) largest = value;

        cout << value << " m.\n";

        sum += value;
        count++;
    }
    cout << "the sum of the lengths: " << sum
            << " m.\nthe smallest value is: " << smallest
            << " m.\nthe largest value is : " << largest
            << " m.\namount of numbers entered: " << count
            << ".\n";
}
////////////////////////////////////////////////////////////
void fourth_iteration() {
    double number = 0, value = 0, sum = 0, smallest = 0, largest = 0;
    vector<double> values;
    string unit = "";
    bool first_count = true;

    while (cin >> number >> unit) {
        if (unit != "m" && unit != "cm" && unit != "in" && unit != "ft") {
            cout << "incorrect unit. \n";
            continue;
        }
        cout << number << ' ' << unit << '\n';

        if (unit == "m")  value = number;
        if (unit == "cm") value = number/100;
        if (unit == "in") value = (number*2.54)/100;
        if (unit == "ft") value = (number*2.54*12)/100;
        
        if (first_count) {
            smallest = value;
            first_count = false;
        }
        if (value < smallest) smallest = value;
        if (value > largest) largest = value;

        cout << value << " m.\n";

        values.push_back(value);
    }
    
    sort(values);

    cout << "the values are: ";
    for (double i:values) {
        cout << i << ", ";
        sum += i;
    }

    cout << "\nthe sum of the lengths: " << sum
            << " m.\nthe smallest value is: " << smallest
            << " m.\nthe largest value is : " << largest
            << " m.\namount of numbers entered: " << values.size()
            << ".\n";
}

int main() {
    //first_iteration();
    //second_iteration();
    //third_iteration();
    fourth_iteration();
}