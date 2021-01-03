#include "../../std_lib_facilities.h"

/* 
2. If we define the median of a sequence as “a number so that exactly as
many elements come before it in the sequence as come after it,” fix the
program in §4.6.3 so that it always prints out a median. Hint: A median
need not be an element of the sequence.
*/
void ex2_median() {
    const int temps_size = 9; //odd or even, changes the way the median is calculated
    double median = 0;
    vector<double> temps;
    
    for (int i=0; i<temps_size; i++) {
        temps.push_back(i);
    }

    sort(temps);
    for (int i = 0; i < temps.size(); i++) {
        cout << i << ": " << temps[i] << '\n';
    }

    if (temps.size() % 2 == 0) {
        median = (temps[temps.size()/2] + temps[(temps.size()/2)+1])/2;
    } else median = temps[temps.size()/2];

    cout << median;
}

/* 
3. Read a sequence of double values into a vector. Think of each value as
the distance between two cities along a given route. Compute and print
the total distance (the sum of all distances). Find and print the smallest
and greatest distance between two neighboring cities. Find and print the
mean distance between two neighboring cities.
*/
void ex3_distances() {
    vector<double> distances;
    double distance = 0;

    while (cin >> distance) {
        distances.push_back(distance);
    }

    double total_distance = 0, smallest=distances[0], greatest = smallest;
    for (double x : distances) {
        total_distance += x;
        if (x < smallest) smallest = x;
        if (x > greatest) greatest = x;
    }
    cout    << "The total distance is " << total_distance
            << " km.\nThe smallest distance is " << smallest
            << " km and the greatest distance is " << greatest
            << " km.\n";
}

/* 
4. Write a program to play a numbers guessing game. The user thinks of a
number between 1 and 100 and your program asks questions to figure
out what the number is (e.g., “Is the number you are thinking of less than
50?”). Your program should be able to identify the number after asking
no more than seven questions. Hint: Use the < and <= operators and the
if-else construct.
*/
void ex4_guessing_game() {
    int lower=0, upper=100;
    int median = 50;
    char yesno;
    bool less;

    cout << "Is your number less than " << median << "?\n";
    while (cin >> yesno) {
        if (yesno == 'y') less = true;
        else if (yesno == 'n') less = false;
        else continue;

        if (less) upper = median;
        else lower = median;
        median = lower + (upper - lower)/2;
        
        cout << "lower is " << lower << ", upper is " << upper << ", and the median is " << median << '\n';

        if (lower == upper) {
            cout << "your number is " << lower << ".\n";
            return;
        }

        if (upper - lower == 1) {
            cout << "Is your number " << lower << "?\n";
        } else cout << "Is your number less than " << median << "?\n";
    }
}

/*
5. Write a program that performs as a very simple calculator. Your calculator
should be able to handle the four basic math operations — add, subtract,
multiply, and divide — on two input values. Your program should prompt
the user to enter three arguments: two double values and a character to
represent an operation. If the entry arguments are 35.6 , 24.1 , and '+' , the
program output should be The sum of 35.6 and 24.1 is 59.7 . In Chapter 6
we look at a much more sophisticated simple calculator.
*/
void ex5_simple_calculator() {
    double a,b,c;
    char operation;
    string operation_name;
    bool valid = true;

    cout << "Type values and operator separated by space.\n";
    while (cin >> a >> b >> operation) {
        switch (operation) {
            case '+':
                c = a + b;
                operation_name = "sum";
                break;

            case '-':
                c = a - b;
                operation_name = "subtraction";
            break;
        
            case '*':
                c = a * b;
                operation_name = "multiplication";
            break;

            case '/':
                c = a / b;
                operation_name = "division";
            break;

            default:
                cout << "Operator invalid.";
                valid = false;
            break;
        }

        if (valid) {
            cout << "The " << operation_name << " of " << a << " and " << b << " is " << c << ".\n";
        } else valid = true;
    }
}

/*
6. Make a vector holding the ten string values "zero" , "one" , . . . "nine" .
Use that in a program that converts a digit to its corresponding
spelled-out value; e.g., the input 7 gives the output seven . Have the same
program, using the same input loop, convert spelled-out numbers into
their digit form; e.g., the input seven gives the output 7.
*/
void ex6_number_speller() {
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int input;

    cout << "Input number from 0 to 9.\n";
    while (cin >> input) {
        if (input < 0 or input > 9) continue;
        cout << numbers[input] << '\n';
    }
}

/*
7. Modify the “mini calculator” from exercise 5 to accept (just) single-digit
numbers written as either digits or spelled out.
*/
void ex7_simple_calculator_spelled(){
    double a=0,b=0,c;
    char operation;
    string operation_name, number_one, number_two;
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    bool valid = true;

    cout << "Type one-digit numbers and operator separated by space.\n";
    while (cin >> number_one >> number_two >> operation) {

        if (number_one.size() == 1)
            a = number_one[0] - 48;
        else for (int i=0; i<numbers.size(); i++)
            if (number_one == numbers[i]) {
                a = i;
                break;
            }

        if (number_two.size() == 1)
            b = number_two[0] - 48;
        else for (int i=0; i<numbers.size(); i++)
            if (number_two == numbers[i]) {
                b = i;
                break;
            }

        switch (operation) {
            case '+':
                c = a + b;
                operation_name = "sum";
                break;

            case '-':
                c = a - b;
                operation_name = "subtraction";
            break;
        
            case '*':
                c = a * b;
                operation_name = "multiplication";
            break;

            case '/':
                c = a / b;
                operation_name = "division";
            break;

            default:
                cout << "Operator invalid.";
                valid = false;
            break;
        }

        if (valid) {
            cout << "The " << operation_name << " of " << a << " and " << b << " is " << c << ".\n";
        } valid = true;
    }
}

/*
8. There is an old story that the emperor wanted to thank the inventor of
the game of chess and asked the inventor to name his reward. The inven-
tor asked for one grain of rice for the first square, 2 for the second, 4 for
the third, and so on, doubling for each of the 64 squares. That may sound
modest, but there wasn’t that much rice in the empire! Write a program to
calculate how many squares are required to give the inventor at least 1000
grains of rice, at least 1,000,000 grains, and at least 1,000,000,000 grains.
You’ll need a loop, of course, and probably an int to keep track of which
square you are at, an int to keep the number of grains on the current
square, and an int to keep track of the grains on all previous squares. We
suggest that you write out the value of all your variables for each iteration
of the loop so that you can see what’s going on.
*/
void ex8_chess_rice() {
    const int rice = 1000;
    int current_square = 1;
    uint64_t rice_for_square = 1, total_rice=1;

    while (total_rice < rice) {
        current_square++;
        rice_for_square *= 2;
        total_rice += rice_for_square;
        cout << "Square number " << current_square << ", amount of rice for this square is " << rice_for_square << ", amount of rice grains up until this square can hold in total: " << total_rice << "\n";
    }
    
    cout << "The amount of squares necessary to hold " << rice << " grains of rice is " << current_square << " squares.\n";
}

/*
9. Try to calculate the number of rice grains that the inventor asked for in
exercise 8 above. You’ll find that the number is so large that it won’t fit
in an int or a double . Observe what happens when the number gets too
large to represent exactly as an int and as a double . What is the larg-
est number of squares for which you can calculate the exact number of
grains (using an int )? What is the largest number of squares for which
you can calculate the approximate number of grains (using a double )? 
*/
void ex9_chess_rice_total() {
    int current_square = 1;
    const int squares_amount = 64;
    uint64_t rice_for_square = 1, total_rice=1;

    while (current_square < squares_amount) {
        current_square++;
        rice_for_square *= 2;
        total_rice += rice_for_square;
        cout << "Square number " << current_square << ", amount of rice for this square is " << rice_for_square << ", and total amount of rice grains up until this square: " << total_rice << ".\n";
    }
    
    cout << "The total amount of rice grains for the chess board is " << total_rice << ".\n";
}


/*
11. Create a program to find all the prime numbers between 1 and 100. One
way to do this is to write a function that will check if a number is prime
(i.e., see if the number can be divided by a prime number smaller than
itself) using a vector of primes in order (so that if the vector is called
primes , primes[0]==2 , primes[1]==3 , primes[2]==5 , etc.). Then write a
loop that goes from 1 to 100, checks each number to see if it is a prime,
and stores each prime found in a vector . Write another loop that lists the
primes you found. You might check your result by comparing your vector
of prime numbers with primes . Consider 2 the first prime.
*/
int check_for_prime(vector<int> primes, int number) {
    for (int i : primes) {
        if (number % i == 0 ) return 0;
    }
    return number;
}

void ex11_prime_numbers() {
    const int limit = 100;
    vector<int> primes = {2, 3, 5};

    for (int i=6; i<limit; i++) {
        int number = check_for_prime(primes, i);
        if (number == 0) continue;
        primes.push_back(number);
    }

    cout << "The prime numbers under " << limit << " are ";
    for (int i : primes) {
        cout << i << ", ";
    }
    cout << ".\n";
}

/*
12. Modify the program described in the previous exercise to take an input
value max and then find all prime numbers from 1 to max.
*/
void ex12_prime_numbers_max() {
    int max;
    vector<int> primes={2};

    cout << "Please enter the max value:\n";
    cin >> max;

    for (int i=3; i<max; i++) {
        int number = check_for_prime(primes, i);
        if (number == 0) continue;
        primes.push_back(number);
    }

    cout << "The prime numbers under " << max << " are ";
    for (int i : primes) {
        cout << i << ", ";
    }
    cout << ".\n";
}

/*
13. Create a program to find all the prime numbers between 1 and 100. There
is a classic method for doing this, called the “Sieve of Eratosthenes.” If
you don’t know that method, get on the web and look it up. Write your
program using this method.
*/
void ex13_prime_numbers_eratosthenes() {
    int const max = 100;
    vector<int> numbers;

    for (int i=2; i < max; i++) numbers.push_back(i);
    
    int iterator = 0;
    while (iterator < numbers.size()/2) {
        for (int i=iterator+1; i<numbers.size(); i++) {
            if (numbers[i] % numbers[iterator] == 0) {
                numbers.erase(numbers.begin() + i);
            }
        }
        iterator++;
    }
    cout << "The prime numbers under " << max << " are ";
    for (int i : numbers) cout << i << ", ";
    cout << endl;

}

/*
14. Modify the program described in the previous exercise to take an input
value max and then find all prime numbers from 1 to max.
*/
void ex14_prime_numbers_eratosthenes_max() {
    int max;
    vector<int> numbers;

    cout << "Please enter the max value.\n";
    cin >> max;

    for (int i=2; i < max; i++) numbers.push_back(i);
    
    int iterator = 0;
    while (iterator < numbers.size()/2) {
        for (int i=iterator+1; i<numbers.size(); i++) {
            if (numbers[i] % numbers[iterator] == 0) {
                numbers.erase(numbers.begin() + i);
            }
        }
        iterator++;
    }
    cout << "The prime numbers under " << max << " are ";
    for (int i : numbers) cout << i << ", ";
    cout << endl;
}

/*
15. Write a program that takes an input value n and then finds the first n
primes.
*/
void ex15_prime_numbers_n() {
    int n;
    vector<int> primes={2};

    cout << "Please enter the n value:\n";
    cin >> n;

    int i = 2, number;
    while (primes.size() < n) {
        i++;
        number = check_for_prime(primes, i);
        if (number == 0) continue;
        primes.push_back(number);
    }


    cout << "The first " << n << " prime numbers are: ";
    for (int i : primes) {
        cout << i << ", ";
    }
    cout << ".\n";
}

/*
16. In the drill, you wrote a program that, given a series of numbers, found
the max and min of that series. The number that appears the most times
in a sequence is called the mode. Create a program that finds the mode of
a set of positive integers.
*/
void ex16_the_mode() {
    int number;
    vector<int> numbers, appearences, unique_numbers;
    bool is_new;

    cout << "Please input numbers. Stop by entering any non-numeric symbol.\n";
    
    while (cin >> number) {
        numbers.push_back(number);
    }

    for (int i : numbers) {
        is_new = true;
        int spot = 0;
        
        for (int j =0; j < unique_numbers.size(); j++) {
            if (unique_numbers[j] == i) {
                is_new = false;
                spot = j;
                break;
            }
        }
        if (is_new) {
            unique_numbers.push_back(i);
            appearences.push_back(1);
        } else {
            appearences[spot]++;
        }
    }

    cout << "The list of unique numbers and their appearences counts are:\n[";
    for (int i : unique_numbers) {
        cout << i << ", ";
    }
    if (unique_numbers.size()>0) {
        cout << "\b\b";
    }
    cout << "]\n[";

    for (int i : appearences) {
        cout << i << ", ";
    }
    if (appearences.size()>0) {
        cout << "\b\b";
    }
    cout << "]\n";

    if (appearences.size() > 0) {
        int max = 0, spot = 0;
        for (int i = 0; i < appearences.size(); i++) {
            if (appearences[i] > max) {
                max = appearences[i];
                spot = i;
            }
        }
        cout << "The mode number is " << unique_numbers[spot] << ", with total appearences of " << max << ".\n";
    }
}

/*
17. Write a program that finds the min, max, and mode of a sequence of
string s.
*/
void ex17_the_mode_strings() {
    string word;
    vector<string> words, unique_words;
    vector<int> appearences;
    bool is_new;

    cout << "Please input words. Stop by pushing CTRL+D.\n";
    
    while (cin >> word) {
        words.push_back(word);
    }

    for (string s : words) {
        is_new = true;
        int spot = 0;
        
        for (int j =0; j < unique_words.size(); j++) {
            if (unique_words[j] == s) {
                is_new = false;
                spot = j;
                break;
            }
        }
        if (is_new) {
            unique_words.push_back(s);
            appearences.push_back(1);
        } else {
            appearences[spot]++;
        }
    }

    cout << "The list of unique words and their appearences counts are:\n[";
    for (string s : unique_words) {
        cout << s << ", ";
    }
    if (unique_words.size()>0) {
        cout << "\b\b";
    }
    cout << "]\n[";

    for (int i : appearences) {
        cout << i << ", ";
    }
    if (appearences.size()>0) {
        cout << "\b\b";
    }
    cout << "]\n";

    if (appearences.size() > 0) {
        int max = 0, spot = 0;
        for (int i = 0; i < appearences.size(); i++) {
            if (appearences[i] > max) {
                max = appearences[i];
                spot = i;
            }
        }
        cout << "The mode word is " << unique_words[spot] << ", with total appearences of " << max << ".\n";
    }
}

/*
18. Write a program to solve quadratic equations. A quadratic equation is of
the form ax^2 + bx + c = 0.
If you don’t know the quadratic formula for solving such an expression,
do some research. Remember, researching how to solve a problem is of-
ten necessary before a programmer can teach the computer how to solve
it. Use double s for the user inputs for a , b , and c . Since there are two
solutions to a quadratic equation, output both x1 and x2 .
*/
void ex18_quadratic_equations() {
    double a, b, c;

    cout << "Please enter a: ";
    cin >> a;
    cout << "\nPlease enter b: ";
    cin >> b;
    cout << "\nPlease enter c: ";
    cin >> c;

    double d = b*b - (4 * a * c);
    
    if (d < 0) {
        cout << "D is less than zero (" << d << "), the equation does not have solution.\n";
        return;
    }

    if (d == 0) {
        double x = -b/(2*a);
        cout << "D is 0, and x is " << x << ".\n";
        return;
    }

    double x1 = (-b + sqrt(d)) / (2 * a);
    double x2 = (-b - sqrt(d)) / (2 * a);
    cout << "D is " << d << ", x1 is " << x1 << ", x2 is " << x2 << ".\n";
}

/*
19. Write a program where you first enter a set of name-and-value pairs, such
as Joe 17 and Barbara 22 . For each pair, add the name to a vector called
names and the number to a vector called scores (in corresponding po-
sitions, so that if names[7]=="Joe" then scores[7]==17 ). Terminate input
with NoName 0 . Check that each name is unique and terminate with an
error message if a name is entered twice. Write out all the (name,score)
pairs, one per line.
*/
void ex19_name_value_pairs() {
    vector<string> names;
    vector<int> scores;
    string name;
    int score;
    bool repeated = false;

    cout << "Please enter NAME SCORE: \n";
    while (cin >> name >> score) {
        if (name == "NoName") {
            cout << "Input terminated.\n\n";
            break;
        }

        for (string iname : names) {
            if (iname == name) {
                repeated = true;
                break;
            }
        }
        if (repeated) {
            cout << "Name entered twice. Input terminated.\n\n";
            break;
        }

        names.push_back(name);
        scores.push_back(score);
    }

    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << ", " << scores[i] << "\n";
    }
}

/*
20. Modify the program from exercise 19 so that when you enter a name, the
program will output the corresponding score or name not found .
*/
void ex20_score_by_name() {
    vector<string> names;
    vector<int> scores;
    string name;
    int score;
    bool repeated = false;
    bool found;

    cout << "Please enter NAME SCORE: \n";
    while (cin >> name >> score) {
        if (name == "NoName") {
            cout << "Input terminated.\n\n";
            break;
        }

        for (string iname : names) {
            if (iname == name) {
                repeated = true;
                break;
            }
        }
        if (repeated) {
            cout << "Name entered twice. Input terminated.\n\n";
            break;
        }

        names.push_back(name);
        scores.push_back(score);
    }

    cout << "Now please enter name: ";
    while (cin >> name) {
        found = false;
        for (int i = 0; i < names.size(); i++) {
            if (name == names[i]) {
                cout << "\n" << names[i] << ", " << scores[i] << "\n\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "\nName not found.\n";
    }
}

/*
21. Modify the program from exercise 19 so that when you enter an integer,
the program will output all the names with that score or score not found .
*/
void ex21_names_by_score() {
    vector<string> names;
    vector<int> scores;
    string name;
    int score;
    bool repeated = false;
    bool found;

    cout << "Please enter NAME SCORE: \n";
    while (cin >> name >> score) {
        if (name == "NoName") {
            cout << "Input terminated.\n\n";
            break;
        }

        for (string iname : names) {
            if (iname == name) {
                repeated = true;
                break;
            }
        }
        if (repeated) {
            cout << "Name entered twice. Input terminated.\n\n";
            break;
        }

        names.push_back(name);
        scores.push_back(score);
    }

    cout << "Now please enter score: ";
    while (cin >> score) {
        found = false;
        for (int i = 0; i < scores.size(); i++) {
            if (score == scores[i]) {
                cout << names[i] << ", " << scores[i] << "\n\n";
                found = true;
            }
        }
        if (!found) cout << "\nScore not found.\n";
    }
}


int main() {
    //ex2_median();
    //ex3_distances();
    //ex4_guessing_game(); TODO
    //ex5_simple_calculator();
    //ex6_number_speller();
    //ex7_simple_calculator_spelled();
    //ex8_chess_rice();
    //ex9_chess_rice_total();
    //ex11_prime_numbers();
    //ex12_prime_numbers_max();
    //ex13_prime_numbers_eratosthenes();
    //ex14_prime_numbers_eratosthenes_max();
    //ex15_prime_numbers_n();
    //ex16_the_mode();
    //ex17_the_mode_strings();
    //ex18_quadratic_equations();
    //ex19_name_value_pairs();
    //ex20_score_by_name();
    ex21_names_by_score();
}