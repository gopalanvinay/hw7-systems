#include "converter.h"

#include <stdlib.h>


void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    quote_t num = 0;
    char * str = lines[i];

    while(*str >= '0' && *str <= '9')
    {
      num = (num*10) + (*str - '0');
      ++str;
    }
    nums[i] = num;
    num = 0;
  }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// The following functions are used in the optimized version. Uncomment the following lines to measure optimized 
// performance

/*

quote_t make_digit(char c)
{
  return (c - '0');
}

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    char * str = lines[i];
    quote_t num = make_digit(*str);
    quote_t checker;

    while((checker = make_digit(*++str)) <= 9)
    {
      num = (num*10) + checker;
    }
    nums[i] = num;
  }
}

*/
