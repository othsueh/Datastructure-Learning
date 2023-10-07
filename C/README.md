# DataStructure Homework 1
> **Name** : 余竣學  
**Student ID** : 41147024S

> #### Info::Toc
>- [Compile](#compile)
>- [Run](#run)
>- [Input Format](#input-format)
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
## Input Format

## Procedure
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
`term *addTerm(term *p, int cof, int exp)`  
add a term to the polynomial. If the term with the same exponent exists, add the coefficient of the term to the term. If not, create a new term and add it to the polynomial.
#### Parameters
`term *p`
pointer of the tail term from polynomial to be added.  
`int cof`
the coefficient of the term to be added.  
`int exp`  
the exponent of the term to be added.
#### Return value
`term *`  
pointer of the tail term of the polynomial. 
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
### 
---
``

#### Parameters
``
#### Return value
``
### 
---
``

#### Parameters
``
#### Return value
``