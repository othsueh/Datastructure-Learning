# Tree
## features
- **node**  
    - nooterminal nodes
    - terminal nodes(Leaf)
- **degree**   
    the number of subtree of a node.
- **level**   
    the root node is level 1, the children of the root node is level 2, and so on.
- **children**  
    the children of a node, not grand children.
- **siblings**   
    children of the same parent.
- **parent**   
    the parent of children nodes.
- **ancestor**  
    all the nodes that along the path from the root to the node. 
## applications/derivations
- **forest**  
    a set of trees.
- **binary tree**  
    a tree with degree 2.
- 組織架構：在公司或機構中用來表示組織結構，顯示員工和部門之間的層級關係。
- 文件系統：計算機的文件系統通常以樹的形式組織，其中每個文件夾是一個節點，並包含子文件夾和文件。
- XML/HTML文檔：XML 和 HTML 文檔的結構可以用樹來表示，其中每個標籤是一個節點，並擁有子標籤。
- 決策樹：在決策分析中，用於表示不同的選擇和其可能的後果或結果

# Binary Tree
## features(complete binary tree)
- **maximum number of nodes**  
    - total nodes of a tree <= 2^h - 1, h is height.
    - total nodes of a level <= 2^(i-1), i is level.
- **relation between leaf nodes & degree-2 nodes**  
    n0 = leaf_node, n1=degree-1_node, n2=degree-2_node, n=n0+n1+n2.  
    Number of links = n-1 = n1+2*n2.  
    n0+n1+n2-1 = n1+2*n2.  
    n0 = n2+1.
- **relation between parent, children, siblings**  
    Suppose a node index is i.
    - left child index = 2*i
    - right child index = 2*i+1
    - parent index = i/2

## applications/derivations
- threaded binary tree
- binary search tree
- AVL tree
- heap
- huffman tree
- 計算表達式：二元樹常用於表示和計算數學表達式，其中每個內部節點代表一個運算符，葉節點代表運算元。
## funtions 
### inorder traversal
inorder traverse a binary tree.  

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/a05722d8-d7e8-4355-8627-f795c3b5e62a)
### preorder traversal
preorder traverse a binary tree.   

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/a447b90a-3ff3-4a56-8570-4495a5f2fed2)

### postorder traversal
postorder traverse a binary tree.  

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/7e292c43-f6b6-4c0a-afe4-434d98e6f312)

### level traversal
level traverse a binary tree.

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/bb53ff2d-ebaa-4f24-b2c7-aaa51871dbb0)

### copy tree
copy a binary tree.

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/b0244e86-9f9d-44f4-9c78-1ddf3d6b45dd)

# Threaded binary tree
## features
- **use waste space**
  For a n nodes typical binary tree, the number of total links is 2n, non-null link is n-1.
  So there are 2n-(n-1)=n+1 links are wasted. So we can use the wasted space to do other functions.
## applications
- Lower the waste of space while in order traversal of binary tree(same speed)
## funtions
### 
