/***********
* Daniel Karl
* 318324563
* 01
* ass03
***********/
#include <stdio.h>
#include "ass3.h"
#define ZERO 0
int counter;
int isPal_1(char str[],int f, int l);
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
if(isPal_1(str,ZERO,len-1)==1)
    printf("The reverse of %s is also %s.\n",str,str);
else
    printf("The reverse of %s is not %s.\n",str,str);

}
/***********************************************************************************************************************
* Function Name: isPal_1.
* Input:char str(An array of characters which represents a string),int first,int last(first and last digit of the array)
* Output: 1 (for true) or 0(for false).
* Function Operation: When the string is even, the function checks all the digits
                      recursivly if the first and last digit of any string are the same, when minimizing
                      the test to the next first digits and last digits. When the string is odd,
                      the function does the same without the middle character.
 **********************************************************************************************************************/
int isPal_1(char str[],int first, int last)
{
    if(first==last)
    return 1;
    if (str[first]!=str[last])
        return 0;
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
    if(firstNum==0&secondNum<0)
        printf("The result is nan.\n");
    else
    {
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
  if(secondNum>=0.0)
    {
        if(secondNum==1.0)
            return firstNum;
        if(secondNum==0.0)
                return 1.0;
        else
            return (firstNum*calc(firstNum,secondNum-1.0));
    }
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
if(n%10==n)
    return n;
else
{
 value=n%10;
 check=sumDigits(n/10,value);
 if(check==1)
 {
     if(value==1)
        return 2;
     else
     if(value==2)
        return 3;
     else
        return 1;
 }
 else if(check==2)
 {
     if(value==1)
        return 3;
     else
        if(value==2)
        return 1;
     else
        return 2;
 }
 else
 {
     if(value==1)
        return 1;
     else
        if(value==2)
        return 2;
     else
        return 3;
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
    if(n!=0)
    {
    sum=helper_countDigit(n,d,ZERO);
    printf("%d has %d times %d.\n",n,sum,d);
    }
    else
    {
     sum=helper_countDigit(n,d,1);
     printf("%d has %d times %d.\n",n,sum,d);
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
 if(n==0)
 return i;
 else
if(n%10==d)
    i++;

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
  if(len%2==0)
  {
   for (int i=0,j=len-1;i<=j;i++,j--)
   {
   if(str[i]!=str[j])
   error++;
   }
  }
  else
  {
      if(len!=1)
        for(int i=0,j=len-1;i<j;i++,j--)
        {
        if(str[i]!=str[j])
            error++;
        }
  }
 if(error==0)
        printf("The reverse of %s is also %s.\n",str,str);
 else
        printf("The reverse of %s is not %s.\n",str,str);

}
/***********************************************************************************************************************
* Function Name: gcd
* Input:long int n1 (first number), long int n2(second number)
* Output: void(prints the way of finding the gcd of 2 numbers, and prints the final solution).
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
long int q,r;
  if(n1==n2&&n1!=0)
    {
      gcdOpt1(n1,n2);
      return;
    }
  else if(n1==0)
  {
      if(n2<0)
        n2=-n2;
       printf("GCD=%ld\n",n2);
       return;
  }
   if(n2==0)
   {
       if(n1<0)
        n1=-n1;
       printf("GCD=%ld\n",n1);
       return;
   }
   else
   {
       if((n1>0&&n2>0&&n1>n2)||(n1>0&&n2<0&&(n1>(-n2)))||(n1<0&&n2>0&&(n2<(-n1)))||(n1<0&&n2<0&&n1<n2))
   {
   gcdOpt1(n1,n2);
   return;
   }
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
* Output: void(prints the way of finding the gcd of 2 numbers, and prints the final solution).
* Function Operation: using the formula of finding the gcd. the function does it recrusively.
                      the function does the calculating every time with the remainder of the first and second numbers
                      and takes the 2nd number instead of the 1st number.
 **********************************************************************************************************************/
void gcdOpt1(long int n1, long int n2)
{
   long int r,q;
   r=n1%n2;
   q=((n1-r)/n2);
   printf("%ld*%ld+%ld=%ld(a=%ld,b=%ld)\n",n2,q,r,n1,n1,n2);
   if(r!=0)
   {
      return (gcdOpt1(n2,r));
   }

    else{
    if(n2<0)
    n2=-n2;
    printf("GCD=%ld\n",n2);
    return;
    }

}
/***********************************************************************************************************************
* Function Name: gcdOpt2
* Input:long int n1 (second number), long int n2(first number)
* Output: void(prints the way of finding the gcd of 2 numbers, and prints the final solution).
* Function Operation: using the formula of finding the gcd. the function does it recrusively.
                      the function does the calculating every time with the remainder of the second and first numbers
                      and takes the 2nd number instead of the 1st number.
 **********************************************************************************************************************/
void gcdOpt2(long int n1, long int n2)
{
    long int r,q;
    r=n2%n1;
    q=((n2-r)/n1);
    printf("%ld*%ld+%ld=%ld(a=%ld,b=%ld)\n",n1,q,r,n2,n2,n1);
    if(r!=0)
    return (gcdOpt2(r,n1));
    else
    {
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
 counter=0;
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

 if(index==len)
 {
     printf("%s\n",pattern);
     counter++;
     return;
 }
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
     else
     printAllCombinationsHelper(pattern,index+1,len);

    }

















