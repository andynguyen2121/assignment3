// Programming Assignment 3
// Programming Fundamentals II (COSC 1437)
// Author: Andy Nguyen
// Description: Reads employee records from a file, writes a formatted
//              payroll report, then demonstrates stream-inspection
//              functions and input-failure handling.
 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
 
using namespace std;
 
int main()
{
    // ---------- PART 1: PAYROLL FILE PROCESSOR ----------
 
    // TODO B: declare inFile (ifstream) and outFile (ofstream)
    ifstream inFile; ofstream outFile;
 
 
    // TODO C: open payrollData.txt and payrollReport.txt
    //         then check that the input file opened successfully.
    //         If it failed, print an error and return 1.

    inFile.open("payrollData.txt");
    outFile.open("payrollReport.txt");

    if (!inFile) {
        cout << "There was an error opening the file!" << endl;
        return 1;
    }

    // Variables for one employee's data
    string firstName, lastName, department;
    double grossSalary, bonusPercent, taxPercent;
    double distance, travelTime;
    double paycheck, averageSpeed;
 
    outFile << fixed << showpoint << setprecision(2);
 
    // TODO D: loop while the input stream still reads a first name.
    //         Inside the loop, read the rest of each employee's data.
    while ( inFile >> firstName )
    {
        // read the remaining fields for this employee
        inFile >> lastName >> department >> grossSalary >> bonusPercent >> taxPercent >> distance >> travelTime;
 
        // TODO E: compute paycheck and averageSpeed
        paycheck = grossSalary + (grossSalary * (bonusPercent / 100)) - (grossSalary * (taxPercent / 100));
        averageSpeed = (distance / travelTime);
 
        // TODO F: write the formatted report block for this employee
        //         remember fixed/showpoint/setprecision are already set,
        //         and use setw at least once.

        outFile << "Name: " << setw(8) << firstName << " " << lastName << ", Department: " << setw(11) << department << endl
                << "Monthly Gross Paycheck: $" << grossSalary << ", Bonus: " << bonusPercent << "%, Taxes: " << taxPercent << "%" << endl
                << "Paycheck: $" << paycheck << endl
                << "Distance Traveled: " << distance << " miles, Travel Time: " << travelTime << " hours" << endl
                << "Average Speed: " << averageSpeed << " miles per hour" << endl; 
 
    }
 
    // TODO G: close both files
    inFile.close();
    outFile.close();

    /*
    payrollData.txt input:

    Giselle Robinson Accounting
    5600 5 30
    450 9

    payrollReport.txt results:

    Name:  Giselle Robinson, Department:  Accounting
    Monthly Gross Paycheck: $5600.00, Bonus: 5.00%, Taxes: 30.00%
    Paycheck: $4200.00
    Distance Traveled: 450.00 miles, Travel Time: 9.00 hours
    Average Speed: 50.00 miles per hour

    */
 
 
    // ---------- PART 2: STREAM INSPECTOR ----------
    // (reads from the keyboard)
 
    // TODO H: peek at the first character, report digit vs letter,
    //         then read and echo the full line.
    //         (Note on putback(): describe one use case in a comment.)


    
    // putback use case - Grabbing strings one by one and accidently taking one part of the next string, use putback to undo and continue from there

    string text;
    cout << "Type a line of text: ";

    char firstChar = cin.peek();

    // found c++ functions for checking if a character is a digit or letter
    
    if (isdigit(firstChar)) {
        cout << "First character is a digit." << endl;
    }
    else if (isalpha(firstChar)) {
        cout << "First character is a letter." << endl;
    }
    else {
        cout << "Neither a digit or letter." << endl;
    }

    cin.ignore(100, '\n');

    // TODO I: read an int, use cin.ignore(), then getline a description.
    int num;
    string line;

    cout << "Enter a number: ";
    cin >> num;

    cin.ignore(100, '\n');
    
    cout << "Type a long line of text: ";
    getline(cin, line);

    cout << "Number: " << num << endl << "Long line of text: " << line << endl;
 
    // TODO J: prompt for a number; if cin.fail(), clear and ignore,
    //         then report invalid input.
    int num2;
    cout << "Type another number: ";
    cin >> num2;

    if (cin.fail()) {
        cout << "Not a valid input!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    else {
        cout << "You entered: " << num2 << endl;
    }
 
    return 0;

    /* part 2 output input test 1

    Type a line of text: hi
    First character is a letter.
    Enter a number: 1
    Type a long line of text: hello world
    Number: 1
    Long line of text: hello world
    Type another number: a
    Not a valid input!

    part 2 output input test 2

    Type a line of text: hi 2
    First character is a letter.
    Enter a number: 2
    Type a long line of text: hello world 2
    Number: 2
    Long line of text: hello world 2
    Type another number: 2
    You entered: 2

    */
}