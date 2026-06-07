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
 
 
    // ---------- PART 2: STREAM INSPECTOR ----------
    // (reads from the keyboard)
 
    // TODO H: peek at the first character, report digit vs letter,
    //         then read and echo the full line.
    //         (Note on putback(): describe one use case in a comment.)
 
 
    // TODO I: read an int, use cin.ignore(), then getline a description.
 
 
    // TODO J: prompt for a number; if cin.fail(), clear and ignore,
    //         then report invalid input.
 
 
    return 0;
}