#include <stdio.h>
#include <math.h>    // For sqrt and pow functions
#include <ctype.h>   // For isalpha and tolower functions
#include <stdlib.h>  // For exit()
#include <string.h>  // For strlen function

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to check for palindrome
int isPalindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Function for simple calculator
void simpleCalculator() {
    double num1, num2, result;
    char operator;

    printf("Enter first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return;
    }

    printf("Enter operator (+, -, *, /, ^, %%): ");
    if (scanf(" %c", &operator) != 1) {
        printf("Invalid operator input.\n");
        return;
    }

    printf("Enter second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return;
    }

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                return;
            }
            result = num1 / num2;
            break;
        case '^':
            if (num1 < 0 && num2 != (int)num2) {
                printf("Error: Negative base with a non-integer exponent.\n");
                return;
            }
            result = pow(num1, num2);
            break;
        case '%':
            if (num2 == 0) {
                printf("Error: Division by zero in modulus.\n");
                return;
            }
            result = fmod(num1, num2);
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }
    printf("Result: %.2lf\n", result);
}

// Function to check if a date is valid (basic validation)
int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0; // Invalid month
    }

    if (day < 1 || day > 31) {
        return 0; // Invalid day
    }

    // Check for month-specific limits
    if (month == 2) {
        // Handle leap year check for February
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) return 0; // Invalid day for leap year
        } else {
            if (day > 28) return 0; // Invalid day for non-leap year
        }
    }
    // Check for months with 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return 0; // Invalid day for these months
    }

    return 1; // Valid date
}

// Function to calculate age considering day, month, and year
void ageCalculator() {
    int birthDay, birthMonth, birthYear;
    int currentDay, currentMonth, currentYear;

    // Get the user's birth date
    printf("Enter your birth day (DD): ");
    if (scanf("%d", &birthDay) != 1) {
        printf("Invalid input for day.\n");
        return;
    }

    printf("Enter your birth month (MM): ");
    if (scanf("%d", &birthMonth) != 1) {
        printf("Invalid input for month.\n");
        return;
    }

    printf("Enter your birth year (YYYY): ");
    if (scanf("%d", &birthYear) != 1) {
        printf("Invalid input for year.\n");
        return;
    }

    // Validate the birth date
    if (!isValidDate(birthDay, birthMonth, birthYear)) {
        printf("Invalid birth date entered.\n");
        return;
    }

    // Get the current date
    printf("Enter the current day (DD): ");
    if (scanf("%d", &currentDay) != 1) {
        printf("Invalid input for day.\n");
        return;
    }

    printf("Enter the current month (MM): ");
    if (scanf("%d", &currentMonth) != 1) {
        printf("Invalid input for month.\n");
        return;
    }

    printf("Enter the current year (YYYY): ");
    if (scanf("%d", &currentYear) != 1) {
        printf("Invalid input for year.\n");
        return;
    }

    // Validate the current date
    if (!isValidDate(currentDay, currentMonth, currentYear)) {
        printf("Invalid current date entered.\n");
        return;
    }

    // Calculate age
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }

    // Calculate months
    int monthAge = currentMonth - birthMonth;
    if (monthAge < 0) {
        monthAge += 12;
    }

    // Calculate days
    int dayAge = currentDay - birthDay;
    if (dayAge < 0) {
        if (currentMonth == 1) {
            dayAge += 31;
            monthAge--;
        } else if (currentMonth == 2) {
            dayAge += 31;
            monthAge--;
        } else if (currentMonth == 3) {
            dayAge += 28;
            monthAge--;
        } else {
            dayAge += 30;
            monthAge--;
        }
    }

    printf("Your age is: %d years, %d months, and %d days.\n", age, monthAge, dayAge);
}

// Function to check leap year
void leapYearChecker() {
    int year;

    printf("Enter year to check if it's a leap year: ");
    if (scanf("%d", &year) != 1) {
        printf("Invalid input for year.\n");
        return;
    }

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
}

// Function to check if a character is vowel or consonant
void vowelConsonantChecker() {
    char ch;

    printf("Enter a character: ");
    if (scanf(" %c", &ch) != 1) {
        printf("Invalid input. Please enter a valid character.\n");
        return;
    }

    if (isalpha(ch)) {
        ch = tolower(ch);  // Convert to lowercase to handle both cases
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            printf("'%c' is a vowel.\n", ch);
        } else {
            printf("'%c' is a consonant.\n", ch);
        }
    } else {
        printf("Please enter a valid alphabetic character.\n");
    }
}

// Function to check if a number is prime
void primeNumberChecker() {
    int num;

    printf("Enter a number to check if it's prime: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return;
    }

    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
}

// Function to find the sum of numbers in a range
void sumOfRange() {
    int start, end, sum = 0;

    printf("Enter the start number: ");
    if (scanf("%d", &start) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return;
    }

    printf("Enter the end number: ");
    if (scanf("%d", &end) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        sum += i;
    }
    printf("The sum of numbers from %d to %d is: %d\n", start, end, sum);
}

// Function to calculate factorial
void factorialCalculator() {
    int num;
    long long factorial = 1;

    printf("Enter a number to calculate its factorial: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return;
    }

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return;
    }

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is: %lld\n", num, factorial);
}

int main() {
    int choice;

    while (1) {
        // Displaying the menu
        printf("\nMenu:\n");
        printf("1. Simple Calculator (+, -, *, /, ^, %%)\n");
        printf("2. Age Calculator\n");
        printf("3. Leap Year Checker\n");
        printf("4. Vowel/Consonant Checker\n");
        printf("5. Prime Number Checker\n");
        printf("6. Sum of Number Range\n");
        printf("7. Factorial Calculator\n");
        printf("8. Palindrome Checker\n");
        printf("9. Exit\n");

        // Taking user's choice
        printf("Enter your choice (1-9): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                simpleCalculator();
                break;
            case 2:
                ageCalculator();
                break;
            case 3:
                leapYearChecker();
                break;
            case 4:
                vowelConsonantChecker();
                break;
            case 5:
                primeNumberChecker();
                break;
            case 6:
                sumOfRange();
                break;
            case 7:
                factorialCalculator();
                break;
            case 8:
                {
                    char str[100];
                    printf("Enter a string to check if it's a palindrome: ");
                    scanf(" %[^\n]", str);  // Read the whole line, including spaces
                    if (isPalindrome(str)) {
                        printf("The string is a palindrome.\n");
                    } else {
                        printf("The string is not a palindrome.\n");
                    }
                }
                break;
            case 9:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
