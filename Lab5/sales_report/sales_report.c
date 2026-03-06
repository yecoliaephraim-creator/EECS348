#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

// Function prototypes
void readSalesFromFile(const char *filename, double sales[]);
void printMonthlyReport(char *months[], double sales[]);
void printSummaryReport(char *months[], double sales[]);
void printSixMonthAverage(char *months[], double sales[]);
void printHighestToLowest(char *months[], double sales[]);

int main() {

    // Array storing the names of the months
    char *months[MONTHS] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    // Array to store the monthly sales values
    double sales[MONTHS];

    // Read sales data from the input file
    readSalesFromFile("sales.txt", sales);

    // Generate the required reports
    printMonthlyReport(months, sales);
    printSummaryReport(months, sales);
    printSixMonthAverage(months, sales);
    printHighestToLowest(months, sales);

    return 0;
}

/*
Reads 12 monthly sales values from a file and stores them
in the sales array.
*/
void readSalesFromFile(const char *filename, double sales[]) {

    // Open the file in read mode
    FILE *file = fopen(filename, "r");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read each sales value from the file
    for (int i = 0; i < MONTHS; i++) {

        if (fscanf(file, "%lf", &sales[i]) != 1) {
            printf("Error: Invalid sales data.\n");
            fclose(file);
            exit(1);
        }
    }

    // Close the file after reading
    fclose(file);
}

/*
Prints the monthly sales report showing the month
and the corresponding sales value.
*/
void printMonthlyReport(char *months[], double sales[]) {

    printf("Monthly Sales Report for 2024\n");
    printf("%-10s %s\n", "Month", "Sales");

    // Loop through each month and print sales
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s %.2f\n", months[i], sales[i]);
    }

    printf("\n");
}

/*
Finds and prints:
- Minimum monthly sales
- Maximum monthly sales
- Average monthly sales
*/
void printSummaryReport(char *months[], double sales[]) {

    int minIndex = 0;
    int maxIndex = 0;
    double sum = 0.0;

    // Loop through sales to find min, max, and total
    for (int i = 0; i < MONTHS; i++) {

        if (sales[i] < sales[minIndex]) {
            minIndex = i;
        }

        if (sales[i] > sales[maxIndex]) {
            maxIndex = i;
        }

        sum += sales[i];
    }

    // Calculate average sales
    double average = sum / MONTHS;

    printf("Sales Summary Report:\n");
    printf("Minimum sales: %.2f (%s)\n", sales[minIndex], months[minIndex]);
    printf("Maximum sales: %.2f (%s)\n", sales[maxIndex], months[maxIndex]);
    printf("Average sales: %.2f\n", average);

    printf("\n");
}

/*
Calculates and prints the six-month moving averages.
Example: January–June, February–July, etc.
*/
void printSixMonthAverage(char *months[], double sales[]) {

    printf("Six-Month Moving Average Report:\n");

    // There are 7 possible six-month windows in 12 months
    for (int i = 0; i <= MONTHS - 6; i++) {

        double sum = 0.0;

        // Add sales values for the 6-month period
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }

        // Print the average for the six-month window
        printf("%s-%s %.2f\n", months[i], months[i + 5], sum / 6);
    }

    printf("\n");
}

/*
Sorts and prints the sales from highest to lowest.
A copy of the arrays is used so the original data is not modified.
*/
void printHighestToLowest(char *months[], double sales[]) {

    double sortedSales[MONTHS];
    char *sortedMonths[MONTHS];

    // Copy original arrays into temporary arrays
    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    // Bubble sort to order sales from highest to lowest
    for (int i = 0; i < MONTHS - 1; i++) {

        for (int j = 0; j < MONTHS - 1 - i; j++) {

            if (sortedSales[j] < sortedSales[j + 1]) {

                // Swap sales values
                double tempSale = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = tempSale;

                // Swap corresponding months
                char *tempMonth = sortedMonths[j];
                sortedMonths[j] = sortedMonths[j + 1];
                sortedMonths[j + 1] = tempMonth;
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("%-10s %s\n", "Month", "Sales");

    // Print sorted results
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2f\n", sortedMonths[i], sortedSales[i]);
    }

    printf("\n");
}