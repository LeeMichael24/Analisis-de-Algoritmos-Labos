// header guards
#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define the structure for storing sales information
struct SalesData
{
    string customer_id;
    string product_id;
    string quantity;
    string purchase_date;
    double total_price;
};

// Function to convert a string to an integer
int stringToInt(const string &str)
{
    return stoi(str);
}

// Function to convert a string to an double
int stringToDouble(const string &str)
{
    return stod(str);
}

void load_data(SalesData *data, const int rows = 1000, const int cols = 5)
{
    // Define the file name
    string filename = "sales.txt";

    const int numRows = rows;    // Number of rows
    const int numColumns = cols; // Number of columns

    // Open the file
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    for (int i = 0; i < numRows; i++)
    {
        string line;
        if (getline(file, line))
        {
            size_t start = 0;
            size_t end = line.find('\t');
            int j = 0; // Column index

            // Store the remaining columns in the FlightInfo structure
            while (end != string::npos && j < numColumns)
            {
                if (j == 0)
                    data[i].customer_id = line.substr(start, end - start);
                if (j == 1)
                    data[i].product_id = line.substr(start, end - start);
                if (j == 2)
                    data[i].quantity = line.substr(start, end - start);
                if (j == 3)
                {
                    string price = line.substr(start, end - start);
                    data[i].total_price = stod(price);
                }

                if (j == 4)
                    data[i].purchase_date = line.substr(start, end - start);
                start = end + 1;
                end = line.find('\t', start);
                j++;
            }
        }
        else
        {
            cerr << "Error: Not enough lines in the file." << endl;
            break;
        }
    }

    // Close the file
    file.close();
}

#endif
