/*Author : RAJ ROY*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* divideLargeNumber(char* number, int divisor) {
   
   char* result = (char*)malloc(sizeof(char) * (strlen(number) + 1));
   int index = 0;
   
   int dividend = number[index] - '0';
   while (dividend < divisor) {
      dividend = dividend * 10 + (number[++index] - '0');
   }
   
   int resultIndex = 0;
   while (strlen(number) > index) {
      result[resultIndex++] = (dividend / divisor) + '0';
      
      dividend = (dividend % divisor) * 10 + number[++index] - '0';
   }
   result[resultIndex] = '\0';
   
   if (strlen(result) == 0) {
      strcpy(result, "0");
   }
   return result;
}

int main() {
   char large_number[] = "25000000000";
   int divisor = 5;
   printf("%s\n", divideLargeNumber(large_number, divisor));
   return 0;
}