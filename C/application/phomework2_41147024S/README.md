# DataStructure Homework 2
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
$ ./texteditor
```
## Procedure
> Info::Toc
>- [Input UI](#input-ui)
>- [Insert](#insert)
>- [Delete](#delete)
>- [Move](#move)
>- [Undo](#undo)
>- [Redo](#redo)

### Input UI
```shell
$ Please enter an initial string consisting a/A-z/Z and space:
$ hello world
```
When you run the program, you will be asked to enter an initial string.  
eg: `hello world`  
Then you can use the following commands to edit the string.
```shell
$ Please enter a command:
$ a/A-z/Z or space: Insert
$ 0) Delete a character before the cursor
$ 1) Move the cursor to the left
$ 2) Move the cursor to the right
$ 3) undo
$ 4) redo
$ Esc) exit the program
$ hello world|
```
Your input string will be displayed at the end of the line.   
**Be aware that you can only enter one character at a time.**

### Insert
In the input UI, enter `a/A-z/Z or space or other characters` is acceptable.  
eg : insert `!` after `hello world`  
```shell
$ hello world|
$ !
```
```shell
$ hello world!|
```
  
### Delete 
In the input UI, enter `0` to delete a character before the cursor.
```shell
$ hello world!|
$ 0
```
```shell
$ hello world|
```
   
### Move
In the input UI:
- enter `1` to move the cursor to the left.
- enter `2` to move the cursor to the right.
```shell
$ hello world|
$ 2
```
```shell
$ hello worl|d
```
```shell
$ hello worl|d
$ 1
```
```shell
$ hello world|
```
  
### Undo

