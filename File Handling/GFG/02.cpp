//* ifstream : declares function such as get(), getline() and read().   {>> overloaded}
//* ostream : declares function such as put(), write().   {<< overloaded}
//! ios is a child class of ios_base;

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

double calculateColumnAverage(const vector<vector<double>>& data, int columnIndex) {
    double sum = 0.0;
    for (const auto& row : data) {
        if (columnIndex < row.size()) {
            sum += row[columnIndex];
        }
    }
    return sum / data.size();
}

int main(int argc, char** argv) {
    // Assuming data.csv is in the same directory as the program
    const string fileName = "data.csv";

    // Open the CSV file
    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return 1; // Exit with an error code
    }

    vector<vector<double>> data; // 2D vector to store CSV data

    // Read data from the CSV file
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<double> row;
        double value;

        while (ss >> value) {
            row.push_back(value);

            if (ss.peek() == ',') {
                ss.ignore(); // Skip the comma
            }
        }

        data.push_back(row);
    }

    // Close the file
    file.close();

    // Specify the column index for which you want to calculate the average
    int columnIndex;
    cout << "Enter the column index for which you want to calculate the average: ";
    cin >> columnIndex;

    // Check if the specified column index is valid
    if (columnIndex < 0 || columnIndex >= data[0].size()) {
        cerr << "Invalid column index." << endl;
        return 1; // Exit with an error code
    }

    // Calculate and display the average
    double average = calculateColumnAverage(data, columnIndex);
    cout << "Average of column " << columnIndex << ": " << average << endl;

    return 0; // Exit successfully
}
