#include <iostream>

void printFibonacci(int n)
{
    int a = 0, b = 1, next;

    std::cout << "Fibonacci sequence up to " << n << ": ";

    // Print Fibonacci sequence
    for (int i = 1; i <= n; ++i)
    {
        std::cout << a << " ";

        // Calculate next Fibonacci number
        next = a + b;
        a = b;
        b = next;
    }

    std::cout << std::endl;
}

int main()
{
    int n;

    // Get the user input
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Output the Fibonacci sequence up to n
    printFibonacci(n);

    return 0;
}
