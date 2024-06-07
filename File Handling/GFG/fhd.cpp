#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string filename = "data.csv";
    int col_num = 2; // column number to calculate average
    double sum = 0;
    int count = 0;

    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> row;
            size_t pos = 0;
            string token;
            while ((pos = line.find(",")) != string::npos) {
                token = line.substr(0, pos);
                row.push_back(token);
                line.erase(0, pos + 1);
            }
            row.push_back(line);

            if (row.size() > col_num) {
                sum += stod(row[col_num]);
                count++;
            }
        }
        file.close();
        double average = sum / count;
        cout << "The average of column " << col_num << " is " << average << endl;
    }
    else {
        cout << "Unable to open file " << filename << endl;
    }

    return 0;
}
