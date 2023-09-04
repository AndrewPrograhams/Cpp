#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    // Create a vector to store the floating-point values
    std::vector<double> floatingValues;

    // Input lines (replace these with your actual input)
    std::string lines[] = {
        "5/29/2012 16:00:00 29.72",
        "5/30/2012 16:00:00 29.479",
        "5/31/2012 16:00:00 29.42"
    };

    // Iterate over each line
    for (const auto& line : lines) {
        // Create a stringstream to parse the line
        std::istringstream iss(line);

        // Skip the non-numeric parts (date and time in this case)
        std::string date, time;
        iss >> date >> time;

        // Extract the floating-point value at the end
        double value;
        if (iss >> value) {
            // Store the value in the vector
            floatingValues.push_back(value);
        } else {
            // Handle parsing error (if any)
            std::cerr << "Failed to parse value from line: " << line << std::endl;
        }
    }

    // Now, 'floatingValues' vector contains all the floating-point values from the input lines
    // You can use the values as needed

    // Print the values to check if they were stored correctly
    for (const auto& value : floatingValues) {
        std::cout << value << std::endl;
    }

    return 0;
}