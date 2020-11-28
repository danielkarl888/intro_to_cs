/***********
* Daniel Karl
* 318324563
* 01
* ass03
***********/
#include <stdio.h>
#include "ass3.h"
#define ZERO 0
//Using global variable for "printAllCombinations" function.
int counter;
int isPal_1(char str[],int first, int last);
double calc(long int firstNum, long int secondNum);
int sumDigits(long long n,int value);
int helper_countDigit(long long n,int d, int i);
void gcd(long int n1, long int n2);
void gcdOpt1(long int n1, long int n2);
void gcdOpt2(long int n1, long int n2);
void printAllCombinationsHelper(char pattern[],int index,int len);
/***********************************************************************************************************************
* Function Name: isPalindrome
* Input: char str(An array of characters which represents a string),int length(length of the string).
* Output: Prints whether or not the string is Palindrome.
* Function Operation: Calls for another function to check if the string is Palindrome, named  "isPal_1".
                      If the string is Palindrome, so this function returns 1 (true) and the current function prints it.
                      Otherwise,  the function prints the opposite.
***********************************************************************************************************************/
void isPalindrome(char str[], int len)
{
/*
Checking if the value from the function isPal_1 is 1(true) OR 0(zero).
isPal_1 checks if the number is Palindrome.
*/
if(isPal_1(str,ZERO,len-1))
    printf("The reverse of %s is also %s.\n",str,str);
else
    printf("The reverse of %s is not %s.\n",str,str);
}
/***********************************************************************************************************************
* Function Name: isPal_1.
* Input:char str(An array of characters which represents a string),int first,int last(first and last digit of the array)
* Output: 1 (for true) or 0(for false).
* Function Operation: When the string length is even, the function checks all the digits
                      recursivly if the first and last digit of any string are the same, when minimizing
                      the test to the next first digits and last digits. When the string length is odd,
                      the function does the same without the middle character.
 **********************************************************************************************************************/
int isPal_1(char str[],int first, int last)
{
    //Checking if the characters of the symmetrical indexes are the same or not.
    if(first==last)
        return 1;
    if (str[first]!=str[last])
        return 0;
   //Making sure that there is no double-check of the symmetrical indexes.
    if(first<last+1)
        return isPal_1(str,(first+1),(last-1));

        return 1;
}
/***********************************************************************************************************************
* Function Name: powRec
* Input: long int firstNum(Base),long int secondNum(exponent).
* Output: Prints the Result of the pow for the base and the exponent.
* Function Operation: If the base is zero and exponent is negative the function
                      prints that the result is not a number (nan). Otherwise, the function calls for another
                      function named "calc" to calculate the pow. The result is presented with 6 digit after the point.
 **********************************************************************************************************************/
void powRec (long int firstNum, long int secondNum)
{
    //If the base is zero and the exponent is negative, it prints that the restult is not a number.
    if(firstNum==0&&secondNum<0)
        printf("The result is nan.\n");
    else
    {
        //Using function "calc" to calculate the pow and insert the result into sum and prints it.
        double sum=calc(firstNum,secondNum);
        printf("The result is %f.\n",sum);
    }
}
/**********************************************************************************************************************
* Function Name: calc
* Input: long int firstNum(Base),long int secondNum(exponent).
* Output: double (Result of the pow for the base and the exponent).
* Function Operation: calculates the pow recursivly. when the exponent is positive, the number is multiplied
  by recursion for "secondNum" times. If the exponent is negative, the number is divided "secondNum" times.
***********************************************************************************************************************/
double calc(long int firstNum, long int secondNum)
{
  /*
  When the exponent is positive the base is multiplied by himself "exponent" times.
  The function does it through recursion.
  The function checks for cases when the base is 0 or 1.
  */
  if(secondNum>=0.0)
    {
        if(secondNum==1.0)
            return firstNum;
        if(secondNum==0.0)
            return 1.0;
        else
            return (firstNum*calc(firstNum,secondNum-1.0));
    }
  /*
  When the exponent is negative the base is divided by himself "exponent" times.
  The function does it through recursion.
  The function checks for cases when the base is -1.
  */
  else
  {
   if(secondNum==-1.0)
        return 1.0/firstNum;
   else
        return (1.0/(firstNum*calc(firstNum,(-1.0)*(secondNum+1.0))));
  }
}
/**********************************************************************************************************************
* Function Name: isDivisibleBy3
* Input: long long n ( a number complicated with only digits of 1,2,3).
* Output: Prints if the number is Divisible By 3 or not.
* Function Operation: using another function named "sumDigits".If the output of this function is is 3,
                      the function prints that the number is Divisible By 3. the function does it without arithmetic
                      operators except for %10 and /10.
***********************************************************************************************************************/
void isDivisibleBy3(long long n)
{
 long long temp = n;
 n=sumDigits(n,ZERO);
//If the function sumDigits returned 3 to n, the original number is divisible by 3.
 if(n==3)
    printf("The number %lld is divisible by 3.\n", temp);
 else
    printf("The number %lld is not divisible by 3.\n", temp);;
}
/**********************************************************************************************************************
* Function Name: sumDigits
* Input: long long n (a number complicated with only digits of 1,2,3), int value.
* Output: int (The sum of the digit number represented in 1-3).
* Function Operation: the function sums the digits through recursion. the summing is represented with the the values 1-3
for example '1232' sums the number into 2(1+2+3+2=8=8-3*2=2).
***********************************************************************************************************************/
int sumDigits(long long n, int value)
{
 int check;
//Stop condition for the recursion when the function checked all the digits.
 if(n%10==n)
    return n;
/*
The variable "value" is the most right digit of the function. the function sums the rest of the digits and gives it
the weight of 1-3 to analyze if the the summing of the digits is divided by 3 or not.
*/
 else
  {
    value=n%10;
    check=sumDigits(n/10,value);
 //Summing the most right digit with the rest of the number, giving its weight.
    switch(check)
    {
    case 1: switch(value)
           {
            case 1: return 2;
            case 2: return 3;
            default: return 1;
           }
    case 2: switch(value)
           {
            case 1: return 3;
            case 2: return 1;
            default: return 2;
           }
    default: return value;
    }
  }
}

/**********************************************************************************************************************
* Function Name: countDigit
* Input: long long n, int d(a digit).
* Output: int (The number of times the digit 'd' the number n has).
* Function Operation: The function uses another function named helper_countDigit to check recursively the number of
                      times the digit 'd' is written in the number.
***********************************************************************************************************************/
void countDigit(long long n, int d)
{
    int sum;
     /*
     If the number isn't a zero, the function calls for another function called "helper_countDigit" to count
     how many times the digit d exists.
     */
    if(n!=0)
    {
        sum=helper_countDigit(n,d,ZERO);
        printf("%lld has %d times %d.\n",n,sum,d);
    }
    /*
    When the number is zero there is 2 options, when the digit is zero so zero has 1 times zero. for other digit
    the digit shows 0 times.
    */
    else
    {
        if(d==0)
            sum=1;
        else
            sum=0;
        printf("%lld has %d times %d.\n",n,sum,d);
    }
}
/**********************************************************************************************************************
* Function Name: helper_countDigit
* Input: long long n, int d(a digit), int i(an index)
* Output: int (The number of times the digit 'd' exists).
* Function Operation: the function counts the number of times the digit exists by recursion.
                      every time the function checks the most right digit and the counter is incremented
                      if the it the digit 'd'. every time the function calls herself for the number without the last
                      digit of the number until getting the last digit of the number.
***********************************************************************************************************************/
int helper_countDigit(long long n,int d, int i)
{
 /*
 Stop condition for the recursion when the number is 0. when the number isn't 0, so the function counts
 when the most right digit is same as desirable.
 */
 if(n==0)
    return i;
 else
    if(n%10==d)
        i++;
//The function calls himself for the number without the most right digit.
return helper_countDigit(n/10,d,i);
}
/**********************************************************************************************************************
* Function Name: IsDividedBy3Iter
* Input: long long num.
* Output: Prints if the number is Divisible By 3 or not.
* Function Operation: using loops and recursion to sum the digits of the number and to represent the summing
                      to an number from 0-9. If the summed number is greater than 9, the function sums the result itself
                      until getting a number from 0-9.if this number is divided by 3(3/6/9) the number is Divided By 3.
***********************************************************************************************************************/
void IsDividedBy3Iter(long long num)
{
    long long temp = num;
    int sum=0;
    /*
    Summing the digits of the number. if the summed number is greater than 9,
    the function sums again the digits of the result of the  original summed number.
    if it happen again, it sums again the digits of the summed number itself.
    */
    while(temp!=0||sum>9)
    {
        if(sum>9&&temp==0)
        {
            temp=sum;
            sum=0;
        }
        sum=sum+temp%10;
        temp=temp/10;
    }
    //After summing the digits of the number, the function checks if it divided by 3.
    if(sum==0||sum==3||sum==6||sum==9)
        printf("The number %lld is divisible by 3.\n",num);
    else
        printf("The number %lld is not divisible by 3.\n",num);
}
/***********************************************************************************************************************
* Function Name: isPalindromeIter
* Input: char str(An array of characters which represents a string),int len (the length of the array)
* Output: void(prints if the numner is Palindrome or not.
* Function Operation: Using loops, if the length of the number is even the loop checks all number in iteration way while
                      checking every digit and his appropriate digit from the end. for odd number, the function checks
                      the same way except for the middle digit.
                      If the function finds lack of matching from the first and last digits, the function counts it,
                      and the number is not Palindrome. however, if there is no "errors" the number is Palindrome.
 **********************************************************************************************************************/
void isPalindromeIter(char str[],int len)
{
  int error=0;
  /*
  For even number of digits , the function has a loop from
  first and last digit places when every loop the index of the beginning of the array
  is increased and the index of the other side of the array is decreased.
  */
  if(len%2==0)
  {
   for (int i=0,j=len-1;i<=j;i++,j--)
   {
   // If there is miss match within the beginning end ending of the array an error is counted.
   if(str[i]!=str[j])
       error++;
   }
  }
  /*
  For odd number of digits, the function has a loop from
  first and last digit places except the middle digit, when every loop the index of the beginning of the array
  is increased and the index of the other side of the array is decreased.
  */
  else
  {
      if(len!=1)
        for(int i=0,j=len-1;i<j;i++,j--)
        {
            if(str[i]!=str[j])
                error++;
        }
  }
//When was no error that counted,it is palindrome and the function prints that the reverse of the string is even.
 if(error==0)
        printf("The reverse of %s is also %s.\n",str,str);
 else
        printf("The reverse of %s is not %s.\n",str,str);

}
/***********************************************************************************************************************
* Function Name: gcd
* Input:long int n1 (first number), long int n2(second number)
* Output: void(prints the way of finding the greatest common divisor (GCD) of 2 numbers, and prints the final solution).
* Function Operation: If one of the numbers is zero, the function prints immediately the gcd(the number that isn't 0).
                      if the numbers are equal, the number prints one of the numbers.
                     the function calls for 2 helper functions to print the way of getting the gcd.
                     The function calls "gcdOpt1" in certain options:
                     1.If the numbers are all positive and the 1st
                     number is greater than the other.
                     2.the 2nd number is greater than the other, but all them are negative.
                     3.the first number is negative and the 2nd number is positive.
                     The function calls "gcdOpt2" in certain options:
                     1.If the numbers are all positive and the 2nd
                     number is greater than the other.
                     2.the 1st number is greater than the other, but all them are negative.
                     3.the first number is positive and the 2nd number is negative.
 **********************************************************************************************************************/
void gcd(long int n1, long int n2)
{
  //calls for function "gcdOpt1" when the numbers are even and first number isn't zero.
  if(n1==n2&&n1!=0)
  {
      gcdOpt1(n1,n2);
      return;
  }
  //checking the options when the first number is zero.
  else if(n1==0)
  {
      //when the 1st number is 0 and the 2nd number is negative the "gcd" is the absolute value of the 2nd number.
      if(n2<0)
          n2=-n2;
      printf("GCD=%ld\n",n2);
      return;
  }
   //checking the options when the 2nd number is zero.
   if(n2==0)
   {
       //when the 2nd number is 0 and the 1st number is negative the "gcd" is the absolute value of the 1st number.
       if(n1<0)
            n1=-n1;
       printf("GCD=%ld\n",n1);
       return;
   }
   else
   {
       /*The function calls for "gcdOpt1" in one of the options:
         1. Both numbers are positive and 1st number is bigger than the other.
         2. The 1st number is positive but other is negative, and the absolute value of
            the negative number is bigger than the 1st number.
         3. Both numbers are negative and 2nd number is bigger than the other.
       */
       if((n1>0&&n2>0&&n1>n2)||(n1>0&&n2<0&&(n1>(-n2)))||(n1<0&&n2>0&&(n2<(-n1)))||(n1<0&&n2<0&&n1<n2))
       {
            gcdOpt1(n1,n2);
            return;
       }
       /*The function calls for "gcdOpt2" in one of the options:
         1. Both numbers are positive and 2nd number is bigger than the other.
         2. The 1st number is negative but other is positive, and the 2nd number is bigger than the absolute value of
            the negative number.
         3. The 1st number is positive but other is negative, and the absolute value of the  2nd number is bigger
            than the 1st number.
         4. Both numbers are negative and 1st number is bigger than the other.
       */
       else if ((n1>0&&n2>0&&n2>n1)||(n1<0&&n2>0&&(n2>(-n1)))||(n1>0&&n2<0&&(n1<(-n2)))||(n1<0&&n2<0&&n1>n2))
       {
            gcdOpt2(n1,n2);
            return;
       }
   }
}
/***********************************************************************************************************************
* Function Name: gcdOpt1
* Input:long int n1 (first number), long int n2(second number)
* Output: void(prints the way of finding the greatest common divisor (gcd) of 2 numbers, and prints the final solution).
* Function Operation: using the formula (Euclidean Algorithm) of finding the gcd. the function does it recrusively.
                      the function does the calculating every time with the remainder of the first and second numbers
                      and takes the 2nd number instead of the 1st number.
 **********************************************************************************************************************/
void gcdOpt1(long int n1, long int n2)
{
    /*
     r is the remainder between the 1st and 2nd number.
     q is the number which is calculated according the formula,
     when q is multiplied by the 2nd number called by the function=1st number called by the function.
    */
   long int r,q;
   r=n1%n2;
   q=((n1-r)/n2);
   printf("%ld*%ld+%ld=%ld(a=%ld,b=%ld)\n",n2,q,r,n1,n1,n2);
    /*
    When the remainder isn't 0, so the function calls himself and doing the formula as the 1st variable is the original
    2nd number and the 2nd variable is the remainder of the current function.
    every calculation is printed throughout the function due to the recursion.
    */
   if(r!=0)
   {
       return (gcdOpt1(n2,r));
   }
     //If the remainded is 0, the calculation of the gcd is over and the function prints the final solution of the gcd
    else
    {
        //gcd is always positive so when the 2nd number is negative, the solution is its absolute value.
        if(n2<0)
            n2=-n2;
        printf("GCD=%ld\n",n2);
        return;
    }
}
/***********************************************************************************************************************
* Function Name: gcdOpt2
* Input:long int n1 (second number), long int n2(first number)
* Output: void(prints the way of finding the greatest common divisor (GCD) of 2 numbers, and prints the final solution).
* Function Operation: using the formula (Euclidean Algorithm) of finding the gcd. the function does it recursively.
                      the function does the calculating every time with the remainder of the second and first numbers
                      and takes the 2nd number instead of the 1st number.
 **********************************************************************************************************************/
void gcdOpt2(long int n1, long int n2)
{
    /*
     r is the remainder between the 2nd and 1st number.
     q is the number which is calculated according the formula,
     when q is multiplied by the 1st number(that was called by the function)=2nd number that was called by the function.
    */
    long int r,q;
    r=n2%n1;
    q=((n2-r)/n1);
    printf("%ld*%ld+%ld=%ld(a=%ld,b=%ld)\n",n1,q,r,n2,n2,n1);
    /*
    When the remainder isn't 0, so the function calls himself and doing the formula as the 1st number is the remainder
    and the 2nd number is the 1st original number.
    every calculation is printed throughout the function due to the recursion.
    */
    if(r!=0)
        return (gcdOpt2(r,n1));
    //If the remainded is 0, the calculation of the gcd is over and the function prints the final solution of the gcd
    else
    {
        //gcd is always positive so when the first number is negative the solution is its absolute value.
        if(n1<0)
            n1=-n1;
        printf("GCD=%ld\n",n1);
        return;
    }
}
/***********************************************************************************************************************
* Function Name: printAllCombinations
* Input:char pattern (an array of chars which exsits the characters 0-2 and wild pattern '?'),int len
        (length of the array).
* Output: void(prints the number of comibnations the function "printAllCombinationsHelper" found).
* Function Operation: The function calls for another function named "printAllCombinationsHelper" while using global
                        variable to count the number of combinations the function found. the combinations are for
                        every time there is '?' in the array. the printAllCombinationsHelper prints it and count it.
 **********************************************************************************************************************/
void printAllCombinations(char pattern[],int len)
{
 //using global variable in order to count how many combinations throughout the whole recursions of the helper function.
 counter=0;
 /*
  The "printAllCombinationsHelper" function prints all the different combinations
  and the function has an access for the number of the combinations that the helper has done
 */
 printAllCombinationsHelper(pattern,ZERO,len);
 printf("Number of combinations is: %d\n",counter);
}
/***********************************************************************************************************************
* Function Name: printAllCombinationsHelper
* Input:char pattern (an array of chars which exsits the characters 0-2 and wild pattern '?'),int index(the current
        digit the function checks, int len(length of the array).
* Output: void(prints comibnations of the array while changing the wild patterns of '?' to 0/1/2.
* Function Operation: The function uses recursion and backtracking. every time there is wild pattern ('?') the function
                      calls for himself and checks the remaining of the array. if there is another '?' it calls himself
                      3 times and change it to 0-1-2.the function prints the combinations from the smallest to biggest.
 **********************************************************************************************************************/
void printAllCombinationsHelper(char pattern[],int index,int len)
{
 // When the building of combination is done, the function counts it and prints the combination.
 if(index==len)
 {
     printf("%s\n",pattern);
     counter++;
     return;
 }
    /*
    the function checks for char '?' in the current index of the array and calls himself 3 times in order to print all
    different options(0/1/2). when the combination for the current index is done, the other '?' back to the original'?'
    to check more combinations.
    */
    if(pattern[index]=='?')
    {
        pattern[index]='0';
        printAllCombinationsHelper(pattern,index+1,len);
        pattern[index]='1';
        printAllCombinationsHelper(pattern,index+1,len);
        pattern[index]='2';
        printAllCombinationsHelper(pattern,index+1,len);
        pattern[index]='?';
    }
    //The function checks the next digits when the current digit has no '?'.
     else
         printAllCombinationsHelper(pattern,index+1,len);
}
