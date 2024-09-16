#include <iostream>
#include <fstream>
#include <string>

// Function to generate the Fibonacci sequence as a string
std::string fibonacci(int n) {
    std::string result;
    int a = 0, b = 1, next;

    for (int i = 1; i <= n; ++i) {
        result += std::to_string(a) + " ";
        next = a + b;
        a = b;
        b = next;
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc == 1) { // Run mode with user input
        int n;
        std::cout << "Enter the value of n: ";
        std::cin >> n;

        std::string result = fibonacci(n);
        std::cout << "Fibonacci sequence up to " << n << ": " << result << std::endl;

    } else if (argc == 2 && std::string(argv[1]) == "test") { // Test mode
        std::ifstream testFile("test.txt");
        int input;
        std::string expected_output, output;
        int passed_tests = 0, test_num = 1;

        if (!testFile) {
            std::cerr << "Error: Could not open test.txt" << std::endl;
            return 1;
        }

        while (testFile >> input && std::getline(testFile, expected_output)) {
            // Remove the leading whitespace from expected_output
            if (!expected_output.empty() && expected_output[0] == ' ') {
                expected_output = expected_output.substr(1);
            }

            output = fibonacci(input);

            if (output == expected_output + " ") {
                std::cout << "Test " << test_num << " passed!" << std::endl;
                ++passed_tests;
            } else {
                std::cout << "Test " << test_num << " failed. Expected: \"" 
                          << expected_output << "\", Got: \"" << output << "\"" << std::endl;
            }
            ++test_num;
        }

        std::cout << "Passed " << passed_tests << " out of 10 tests." << std::endl;
        testFile.close();
    } else {
        std::cerr << "Invalid arguments." << std::endl;
    }

    return 0;
}
