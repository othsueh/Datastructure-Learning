# DataStructure Homwowrk 3
> **Name**: 余竣學 **Student ID**: 41147024S

> #### Info::Toc
>- [Compile](#compile)
>- [Run](#run)
>- [Procedure](#procedure)
>- [Functions Introduction](#functions-introduction)

## Compile
```bash
$ make
```
## Run
```shell
$ ./main
```

## Procedure
This procedure is following by example test data 1 in `example_test.pdf`
> Info::Toc
>- [Input UI](#input-ui)
>- [Read Dataset](#read-dataset)
>- [Delete](#delete)
>- [Move](#move)
>- [Undo](#undo)
>- [Redo](#redo)

### Input UI
```bash
$ (1) Read dataset
$ (2) Insert a new node (storing IDs) into the BST
$ (3) Delete a node with a given value fomr the BST (If thd node does not exist, print not found)
$ (4) Search for a node with a specific value in the BST (If th node does not exist, print not found)
$ (5) Perform an in-order traversal of the BST (Print the values of the nodes in ascending order)
$ (6) Compute balance factor of a specfic node
$ (7) Find the k-th Smallest Element
$ (8) Exit
Command:  
```

### Read dataset
data in `test.txt`:
```
56 16 14 25 28 20 35 42 11 27 3 38 45 57 34 17 32 58 33 55
```
Read:
```bash
$ Command: 1
$ input file path: ./test.txt
```
### Insert Node
```bash
$ Command: 2
$ input ID: 24
```
```bash
$ Command: 2
$ input ID: 60
```
### Delete Node
**Note**: My delete function will use smallest node in right subtree to replace the node which will be deleted when the node has two children.
```bash
$ Command: 3
$ input ID: 35
```
```bash
$ Command: 3
$ input ID: 60
```
```bash
$ Command: 3
$ input ID: 14
```
```bash
$ Command: 3
$ input ID: 26
$ output: delete 26 failed, not found.
```

### Search Node
```bash
$ Command: 4
$ input ID: 34
$ output: find it
```
```bash
$ Command: 4
$ input ID: 40
$ output: not found
```

### In-order Traversal
```bash
$ command: 5
$ output: 3 11 16 17 20 24 25 27 28 32 33 34 38 42 45 55 56 57 58
```

### Compute Balance Factor
```bash
$ Command: 6
$ input ID: 11
$ output: 1
```
```bash
$ Command: 6
$ input ID: 32
$ output: -1
```
```bash
$ Command: 6
$ input ID: 25
$ output: -3
```

### Find the k-th Smallest Element
```bash
$ Command: 7
$ input k between [1,19]: 5
$ output: 20
```
```bash
$ Command: 7
$ input k between [1,19]: 18
$ output: 57
```

### Exit
```bash
$ Command: 8
```