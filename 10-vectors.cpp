/* This exercise defines a program which reads a list of number from a file
 * stores them in a vector. Then, it calculates the following operations:
 *   - Mean (average)
 *   - Median
 *   - Mode
 *
 * REQUIREMENTS
 *   - Pointers:
 *   - Input: Get the name of the file as an user input.
 *   - Error handling: Handle the file is not empty and does not contain numeric
 * data.
 *   - Modular design: Create separate functions to effectively break down the
 * problem.
 *
 * HINTS
 *   - Sorting: Might need to sort the vector to find the median.
 *   - Mode Calculation: A frequency map (e.g., std::map<int, int>) could be
 * helpful for counting occurrences of each number.
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "10-statistics.h"

// Function declaration
std::vector<int> read_numbers(const std::string& filename);

// Main function
int main() {
    std::string f_name;
    std::cout << "Specify the name of the file containing the numbers: ";
    std::cin >> f_name;

    try {
        std::vector<int> numbers = read_numbers(f_name);

        double mean = calculate_mean(numbers);
        double median = calculate_median(numbers);
        std::vector<int> modes = calculate_mode(numbers);

        std::cout << "Mean: " << mean << '\n'
                  << "Median: " << median << '\n'
                  << "Mode: ";
        for (int mode : modes) {
            std::cout << mode << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

// Function: Open file and populate a vector.
std::vector<int> read_numbers(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Could not open the given file.");
    }

    std::vector<int> numbers;
    int number;
    while (inFile >> number) {
        numbers.push_back(number);
    }

    if (numbers.empty()) {
        // No integers into 'numbers', ergo the file data was not correct.
        throw std::runtime_error(
            "The file is empty or contains non-numeric data.");
    }

    inFile.close();
    return numbers;
}
