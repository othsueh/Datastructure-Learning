# DataStructure Homework 1
> **Name** : 余竣學  
**Student ID** : 41147024S

> #### Info::Toc
>- [Compile](#compile)
>- [Run](#run)
>- [Procedure](#procedure)
>- [Functions Introduction](#functions-introduction)

## Compile
```shell
$ make
```
## Run
```shell
$ ./polynomial
```
## Procedure
> Info::Toc
>- [Input UI](#input-ui)
>- [1) Create a polynomial](#1-create-a-polynomial)
>- [2) Set current polynomial by name and present it](#2-set-current-polynomial-by-name-and-present-it)
>- [3) Show the coefficient of the term with the given exponent from current polynomial](#3-show-the-coefficient-of-the-term-with-the-given-exponent-from-current-polynomial)
>- [4) Add a nonzero term to current polynomial](#4-add-a-nonzero-term-to-current-polynomial)
>- [5) Delete the term with the given exponent from current polynomial](#5-delete-the-term-with-the-given-exponent-from-current-polynomial)
>- [6) Add two polynomials and show the result](#6-add-two-polynomials-and-show-the-result)
>- [7) Subtract two polynomials and show the result](#7-subtract-two-polynomials-and-show-the-result)
>- [8) Multiply two polynomials and show the result](#8-multiply-two-polynomials-and-show-the-result)
>- [9) Exit](#9-exit)
### Input UI
---
```shell
Please choose the function you want to use and enter the number of the function name:
===============================================================================
1) Create a polynomial and name it.(It will automatically be current polynomial)
2) Set current polynomial by name and present it
3) Show the coefficient of the term with the given exponent from current polynomial
4) Add a nonzero term to current polynomial
5) Delete the term with the given exponent from current polynomial
6) Add two polynomials and show the result
7) Subtract two polynomials and show the result
8) Multiply two polynomials and show the result
9) Exit
===============================================================================
```
You can choose the function you want to use by entering the number of the function name.
### 1) Create a polynomial
---
```shell
1
hello
Polynomial hello is now created,set value to it
3x^3+4x^6+7x^8-2x^2
1
Polynomial hello has saved to current polynomial.
```
Input the name of the polynomial you want to create, and input the terms of the polynomial.  
When you finish inputting the terms, input 1 to finish the function.  
This function will automatically save the polynomial to current polynomial.
#### Acceptable input of the polynomial
nested way
```shell
3x^3+4x^6+7x^8-2x^2
```
every term seperated by space
```shell
3x^3 4x^6 7x^8 -2x^2
```
every term with a line
```shell
3x^3
4x^6
7x^8
-2x^2
```

### 2) Set current polynomial by name and present it
---
```shell
2
hello
Current polynomial is hello
2x^2 + 3x^3 + 4x^6 + 7x^8
```
Input the name of the polynomial you want to set as current polynomial.  
Current polynomial will be presented after setting.

#### Just print the current polynomial!
```shell
2

No such polynomial.
Current polynomial is hello
2x^2 + 3x^3 + 4x^6 + 7x^8
```
If you just want to present the current polynomial, input without any name and press enter.
### 3) Show the coefficient of the term with the given exponent from current polynomial
---
```shell
3
6
The coefficient of the term with exponent 6 is 4
```
Input the exponent of the term you want to find from current polynomial.
### 4) Add a nonzero term to current polynomial
---
```shell
4
5x^5
```
Input a nonzero term you want to add to current polynomial.  
Below is the result of the input above.
```shell
2

No such polynomial.
Current polynomial is hello
2x^2 + 3x^3 + 5x^5 + 4x^6 + 7x^8
```
### 5) Delete the term with the given exponent from current polynomial
---
```shell
5
6
```
Input the exponent of the term you want to delete from current polynomial.
Below is the result of the input above.
```shell
2       

No such polynomial.
Current polynomial is hello
2x^2 + 3x^3 + 5x^5 + 7x^8
```
### 6) Add two polynomials and show the result
---
Since we haven't set the second polynomial, we need to create a new polynomial first.
```shell
1
hi
Polynomial hi is now created,set value to it
2x^3+5x^5
1
Polynomial hi has saved to current polynomial.
```
```shell
6
Please enter the name of the first polynomial:
hi
Please enter the name of the second polynomial:
hello
2x^2 + 5x^3 + 10x^5 + 7x^8
```
Input the name of the first polynomial and the second polynomial. If the polynomial is not found, it will report error, else it will add the two polynomials together and print the result.
### 7) Subtract two polynomials and show the result
---
```shell
7
Please enter the name of the first polynomial:
hi
Please enter the name of the second polynomial:
hello
-2x^2 - 1x^3 - 7x^8
```
Input the name of the first polynomial and the second polynomial. If the polynomial is not found, it will report error, else it will subtract the second polynomial from the first polynomial and print the result.
### 8) Multiply two polynomials and show the result
---
```shell
8
Please enter the name of the first polynomial:
hi
Please enter the name of the second polynomial:
hello
4x^5 + 6x^6 + 25x^8 + 14x^11 + 10x^7 + 25x^10 + 35x^13
```
Input the name of the first polynomial and the second polynomial. If the polynomial is not found, it will report error, else it will multiply the two polynomials together and print the result.
### 9) Exit
---
```shell
9
```
It will exit the program, and free the memory of stored polynomial.
## Functions Introduction
### freePolynomial
---
`void freePolynomial(polynomial *p)`  
free the memory of the polynomial.
#### Parameters
`polynomial *`  
pointer of the polynomial to be free.
#### Return value
`void`

### setName 
---
`char *setName(char *name)`  
input the string and return the pointer of the string.

#### Parameters
`char *`  
pointer of the string to be input.
#### Return value
`char *`  
pointer of the string.

### printPolynomial 
---
`void printPolynomial(polynomial *p)`  
print the polynomial in the format of a0 + a1x + a2x^2 + ... + an-1x^n-1 + anx^n.
#### Parameters
`polynomial *`  
the pointer of the polynomial to be printed.
#### Return value
`void`
### create
---
`polynomial *create()`  
Create a polynomial and return the pointer of the polynomial.  
#### Parameters  
`void`
#### Return value
`polynomial *`  
pointer of the polynomial created.
### findTerm
---
`void findTerm(term *p, int exp)`  
find the term with the same exponent as the input. If the term is found, print the coefficient of the term. If not, print 0.
#### Parameters
`term *p`  
pointer of the start term from polynomial to be found.  
`int exp`  
the exponent of the term to be found.
#### Return value
`void`
### addTerm
---
`void *addTerm(polynomial *p, int cof, int exp)`  
add a term to the polynomial. If the term with the same exponent exists, add the coefficient of the term to the term. If not, create a new term and add it to the polynomial.
#### Parameters
`term *p`  
pointer of the tail term from polynomial to be added.  
`int cof`  
the coefficient of the term to be added.  
`int exp`  
the exponent of the term to be added.
#### Return value
`void`  
### deleteTerm 
---
`term *deleteTerm(term *p)`  
delete the term from the polynomial, and attach the next term to the before term.

#### Parameters
`term *p`  
pointer of the term to be deleted.
#### Return value
`term *`
pointer of the term after the deleted term.
### setPolynomial 
---
`polynomial *setPolynomial(polynomial *p)`  
set the polynomial with its name and terms, and store it into the polynomial set.
#### Parameters
`polynomial *p`  
pointer of the polynomial to be set.
#### Return value
`polynomial *`  
pointer of the polynomial set.
### matchPolynomial
---
`polynomial* matchPolynomial(char *name)`  
find the polynomial in the polynomial set with the same name as the input. If the polynomial is found, return the pointer of the polynomial. If not, return pointer of the current polynomial.

#### Parameters
`char *name`  
pointer of the name of the polynomial to be found.
#### Return value
`polynomial *`  
pointer of the polynomial found or current polynomial's pointer.
### input & match 
---
`void inputNmatch(polynomial **p1, polynomial **p2)`  
input the name of the two polynomials to be used, and match the polynomial in the polynomial set.

#### Parameters
`polynomial **p1`  
double pointer of the first polynomial to be matched.  
`polynomial **p2`  
double pointer of the second polynomial to be matched.
#### Return value
`void`
### addPolynomial
---
`void addPolynomial(polynomial *p1, polynomial *p2, polynomial *p)`  
input two polynomials and add them together, and store the result into the third polynomial.

#### Parameters
`polynomial *p1`  
pointer of the first polynomial to be added.  
`polynomial *p2`  
pointer of the second polynomial to be added.  
`polynomial *p`  
pointer of the third polynomial to store the result.
#### Return value
`void`
### subPolynomial
---
`void subPolynomial(polynomial *p1, polynomial *p2, polynomial *p)`  
input two polynomials and subtract the second polynomial from the first polynomial, and store the result into the third polynomial.
#### Parameters
`polynomial *p1`  
pointer of the first polynomial to be substracted.  
`polynomial *p2`  
pointer of the second polynomial to be substracted.  
`polynomial *p`  
pointer of the third polynomial to store the result.
#### Return value
`void`
### mulPolynomial
---
`void mulPolynomial(polynomial *p1, polynomial *p2, polynomial *p)`  
input two polynomials and multiply them together, and store the result into the third polynomial.
#### Parameters
`polynomial *p1`  
pointer of the first polynomial to be multiplied.  
`polynomial *p2`  
pointer of the second polynomial to be multiplied.  
`polynomial *p`  
pointer of the third polynomial to store the result.
#### Return value
`void`