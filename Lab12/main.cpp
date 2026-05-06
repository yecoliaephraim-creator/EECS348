#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;

const double INVALID = -999999.99;

// Function to extract a floating-point number
double extractNumeric(const string& str)
{
    int n = str.length();

    for (int start = 0; start < n; start++)
    {
        // Possible start of number
        if (isdigit(str[start]) ||
            str[start] == '+' ||
            str[start] == '-' ||
            str[start] == '.')
        {
            int i = start;

            // Handle sign
            bool negative = false;

            if (str[i] == '+' || str[i] == '-')
            {
                // only keep sign if next char is digit or .
                if (i + 1 < n &&
                    (isdigit(str[i + 1]) || str[i + 1] == '.'))
                {
                    negative = (str[i] == '-');
                    i++;
                }
                else
                {
                    continue;
                }
            }

            bool hasDigits = false;
            bool hasDecimal = false;
            bool hasExponent = false;

            double integerPart = 0;
            double fractionalPart = 0;
            double divisor = 10;

            // Parse base number
            while (i < n)
            {
                if (isdigit(str[i]))
                {
                    hasDigits = true;

                    if (!hasDecimal)
                    {
                        integerPart = integerPart * 10 + (str[i] - '0');
                    if (integerPart > 9999999999999999.0) {
                            return INVALID;
                        }
                    }
                    else
                    {
                        fractionalPart += (str[i] - '0') / divisor;
                        divisor *= 10;
                    }

                    i++;
                }
                else if (str[i] == '.')
                {
                    if (hasDecimal)
                    {
                        return INVALID;
                    }

                    hasDecimal = true;
                    i++;
                }
                else
                {
                    break;
                }
            }

            if (!hasDigits)
            {
                continue;
            }

            double value = integerPart + fractionalPart;

            // Handle exponent
            if (i < n && (str[i] == 'e' || str[i] == 'E'))
            {
                hasExponent = true;
                i++;

                bool expNegative = false;

                if (i < n && (str[i] == '+' || str[i] == '-'))
                {
                    expNegative = (str[i] == '-');
                    i++;
                }

                if (i >= n || !isdigit(str[i]))
                {
                    return INVALID;
                }

                int exponent = 0;

                while (i < n && isdigit(str[i]))
                {
                    exponent = exponent * 10 + (str[i] - '0');
                    i++;
                }

                if (expNegative)
                {
                    exponent = -exponent;
                }

                value *= pow(10, exponent);
            }

            // Check for invalid continuation
            // Check for invalid numeric continuation
            // Invalid only if another numeric sequence immediately continues
            if (i < n &&
                (isdigit(str[i]) || str[i] == '.'))
            {
                return INVALID;
            }

            if (negative)
            {
                value = -value;
            }

            // Range check
            if (fabs(value) > 1.7e308)
            {
                return INVALID;
            }

            return value;
        }
    }

    return INVALID;
}

int main()
{
    string input;

    while (true)
    {
        cout << "Enter a string (or 'END' to quit): ";
        getline(cin, input);

        if (input == "END")
        {
            cout << "Program terminated." << endl;
            break;
        }

        double result = extractNumeric(input);

        if (result == INVALID)
        {
            cout << "Invalid input: no valid floating-point number found" << endl;
        }
        else
        {
            cout << fixed << setprecision(4);
            cout << "Extracted number: " << result << endl;
        }

        cout << endl;
    }

    return 0;
}