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
- Lower the waste of space while in order traversal of binary tree(same speed $O(n)$ )
## funtions
### inthreading
make the thread of the tree.

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/1d47b9f2-fc26-4693-88d4-eaa3bdafb1a3)

### inorder traversal
inorder traverse a threaded binary tree. 

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/7358be1d-0bfd-4bf4-a505-a56b142671f3)

### insert right
insert a node in threaded binary tree

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/86a024be-068b-48a1-af10-aa58828252ca)

# heap
## features
- the root of the heap contains max(min) element.
- a kind of complete binary tree(have same properties)

## applications/derivations
- 優先隊列：在操作系統的任務調度、網絡流量管理等場景中用來管理具有不同優先級的任務或數據。
- 堆排序：堆排序算法使用堆來實現高效的數據排序。
- 圖算法中的最短路徑和最小生成樹：如 Dijkstra 算法和 Prim 算法中使用堆來管理節點。
- 軟體和系統中使用堆結構來優化性能和資源管理，包括操作系統開發者、網絡設備製造商和大型云服務提供商

## functions
### downheap
create a max heap by an unsort array.

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/90fd9388-9f33-48a3-9d8c-6e07a8cdd340)

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/b1667778-4907-46a7-abac-b19c006fef63)

### insert 
insert a new node into maxheap  
Efficency: $O(log_2n)$  

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/d47aaafc-9857-4077-acf4-6f8d2de92652)

### pop
pop a node from the root of maxheap  
Efficency: $O(log_2n)$  

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/13735ebd-ba5a-4210-8009-d4f69353c4d9)

# Binary Search Tree
## features
- left child is smaller than root child
- right child is larger than root child
- speed up searching an arbitrary node.
- best search, insert, delete speed: $O(h)$ h is the height of the tree. $log_2n$ is height in balance search tree.
## applications/derivations
- 平衡二元樹（如AVL樹）：在每個節點添加了平衡因子，以保持樹的平衡，從而優化搜索和插入操作的效率。
- 紅黑樹：一種自平衡二元搜索樹，通過規則和顏色標記來保持大致的平衡，廣泛用於許多標準庫和框架的實現中。
- B樹和B+樹：這些是為磁盤存儲和數據庫索引設計的樹結構，特點是有更寬的分支和更高的容量，以減少訪問磁盤的次數。
- 數據庫管理：用於高效地管理和檢索數據庫中的數據。
- 文件系統：在文件系統中用於組織和索引文件。
- 搜索引擎：在搜索引擎中用於高效地處理大量的索引數據。

## funtions
### search
search a specific element from root node.  

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/c7fb517e-996e-406b-91be-5d21485908be)

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/078d2fdb-d477-42a8-b15d-c120b3232335)

### insert
insert a new element in the tree

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/76481401-6e5f-45c0-b279-0c4304e98324)

### delete
remove a specific node from search binary tree

![image](https://github.com/othsueh/Datastructure-Learning/assets/69002793/5f0f422d-1b2d-470a-9af3-77ee1c21547e)

# foreset
## features
- A set of n >= 0 disjoint trees.
- Convert to binary tree with left-child, right-sibling method [ref][1].
## applications
- 計算機系統中的目錄結構：操作系統中的文件系統可以用森林來表示，其中每個目錄（或文件夾）作為一個樹。
- 數據庫系統：在數據庫系統中，森林可以用於組織和索引數據，提高查詢效率。
- 決策樹學習：在機器學習中，隨機森林算法使用多個決策樹來提高預測的準確性和健壯性。

[1]: https://www.geeksforgeeks.org/left-child-right-sibling-representation-tree
