/* $Id: stokpr.c,v 1.1 2003/12/09 22:43:29 GrosbaJ Exp $ */

#include "string.h"

/** @name strtokpgmram
 * The {\bf strtokpgmram} function performs a {\bf strtok} where
 * {\bf s1} points to data memory and {\bf s2} points to program
 * memory.
 * @param s1 pointer to destination in data memory
 * @param s2 pointer to source in program memory
 */
// char *strtokpgmram (char *s1, const rom char *s2);

static char *PreStr = NULL;

char *strtokpgmram (char *s1, const rom char *s2)
{
   char *Token;

   if (s1 == NULL)
      s1 = PreStr;

   // Skip over leading delimiters
   s1 += strspnrampgm ((const char *)s1, s2);
   if (*s1 == '\0')
      return NULL;

   // Find the end of the Token.
   Token = s1;
   s1 = strpbrkrampgm ((const char *)Token, s2);
   if (s1 == NULL)
      // Point to null at end of string
      PreStr = strchr ((const char *)Token, '\0');
   else
      {
      // Terminate Token. Set PreStr to next character
      *s1 = '\0';
      PreStr = s1 + 1;
      }
   return Token;
}
