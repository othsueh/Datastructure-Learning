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
```
input: root node(root)
process:
    if: root is not null
        inorder(root_left)
        print(root)
        inorder(root_right)
```
### preorder traversal
preorder traverse a binary tree.
```
input: root node(root)
process:
    if: root is not null
        print(root)
        inorder(root_left)
        inorder(root_right)
```
### postorder traversal
postorder traverse a binary tree.
```
input: root node(root)
process:
    if: root not null
        inorder(root_left)
        inorder(root_right)
        print(root)
```
### level traversal
level traverse a binary tree.
```
input: root node(root)
process:
    init two value(front,rear)
    init queue(que)
    que[rear++] = root
    loop: front not equal rear
        init value(temp)
        temp set que[front++]
        print(temp)
        if: temp_left not null
            que[rear++] set temp_left
        if: temp_right not null
            que[rear++] set temp_right
```
### copy tree
copy a binary tree.
```
input: root node(root)
process:
    if: root is not null
        init ptr(new)
        new_left set copy(root_left)
        new_right set copy(root_right)
        new_data set root_data
        return new
```


