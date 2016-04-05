#include<stdio.h>

// Method to get the interleaved string .. returns true if input strings contain the result string else returns false..
bool isInterleavedString (char *input1, char *input2, char *result)
{
    // Iterate through all characters of C.
    while (*result != 0)
    {
        // Match first character of result string with first character of input1. If matches them we move input1 to next character
        if (*input1 == *result)
            input1++;

        // Match first character of result string with first character of input2. If matches them we move input2 to next character
        else if (*input2 == *result){
          input2++;
        }
        else{
          return false;
        }

        // Move result string to next character for next iteration
        result++;
    }

    // If input1 & input2 have some characters of result string then return false
    if (*input1 || *input2)
        return false;

    return true;
}

// Driver program to test above functions
int main()
{
    char *input1 = "XXY";
    char *input2 = "XXZ";
    char *result = "XXZXXXY";
    if (isInterleaved(input1, input2, result) == true)
        printf("%s is interleaved string of %s and %s", result, input1, input2);
    else
        printf("%s is not an interleaved string of %s and %s", result, input1, input2);

    return 0;
}
