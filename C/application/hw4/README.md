# DataStructure Homework 4
> **Name** : 余竣學  
**Student ID** : 41147024S

> #### Info::Toc
>- [Compile](#compile)
>- [Run](#run)
>- [Procedure](#procedure)
>- [Test](#test)

## Compile
```shell
$ make
```
## Run
```shell
$ ./main
```

## Procedure
1. Set structure for the task network
```C
typedef struct {
    int duration;
    int earliestStart;
    int latestStart;
    int *dependencies;
    int dependencyCount;
} Task;
```
2. After input all data, calculate the earliest start time for each task
3. Then use max function to get the time to finish the project
4. Use the time to finish the project to calculate the latest start time for each task 
5. Then use the result of latest start time and earliest start time to find the critical activities
## Test
### Test1
```shell
./main
4                         
2 1 3 2 
3
1 4
2 3
3 4
```
```shell
6
2 0 1 4 
2 3 4 
```
### Test2
```shell
./main
5
4 6 2 6 4
4
1 3
3 4
2 4
1 5
```
```shell
12
0 0 4 6 8 
1 2 3 4 
```