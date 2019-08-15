#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a, n, n1;
	 int contador = 1;

	 for (a = 5; a >= 1; a--){
		 for (n = 0; n <= a; n++){
			 printf(" ");
		 }
		 for (n1 = 1; n1 <= contador; n1++){
			 printf("*");
		 }
		 printf("\n");                          /*Triangulo superior*/
		 contador += 2;           /*Asta aqui dominado mas o menos :) */
	 }
	 for (a = 4; a >= 1; a--){      /*De aqui en adelante a sido una loteria :( */
		 for (n = 6; n >= a; n--){        /*Triangulo inferior*/
			 printf(" ");
		 }
		 for (n1 = 2; n1 <= contador-3; n1 ++){
			 printf("*");
		 }
		 printf("\n");
		 contador -= 2;
	 }

 /*
 using System;
using System.Text.RegularExpressions;

public class Example
{
   public static void Main()
   {
      String input = "abacus -- alabaster - * - atrium -+- " +
                     "any -*- actual - + - armoir - - alarm";
      String pattern = @"\s-\s?[+*]?\s?-\s";
      String[] elements = Regex.Split(input, pattern);
      foreach (var element in elements)
         Console.WriteLine(element);
   }
}
// The example displays the following output:
//       abacus
//       alabaster
//       atrium
//       any
//       actual
//       armoir
//       alarm
 */
    return 0;
}
