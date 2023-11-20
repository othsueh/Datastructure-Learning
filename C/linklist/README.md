# Function in LinkList
### Invert function
Invert the order of link list, let the **link** reverse.

```
input: the head of the link list(lead)
process:
  init 2 ptr(middle, trail)
  middle set null
  loop:lead not null
    trail set middle
    middle set lead
    lead set lead_link
    middle_link set trail
output: the head of the **new** link list(original tail)
```
timeComplexity: $O(n)$

# function in DDL
## What DDL can do
- 網頁瀏覽器的前進與後退功能：瀏覽器可使用雙向鏈表來儲存訪問過的網頁，從而實現前進和後退功能。
- 應用程序的Undo和Redo功能：軟件中的撤銷（Undo）和重做（Redo）功能可以通過雙向鏈表來管理命令或操作的歷史。
- 音樂播放器的播放列表：音樂播放器中的播放列表，可以使用雙向鏈表來實現上一首/下一首的歌曲切換。
- 遊戲開發中的實體列表：在遊戲開發中，雙向鏈表可用於管理遊戲實體的列表，以便快速添加和刪除實體。
### Insert 
Insert a new node in DDL.
```
input: node before new node, new node(head,new)
process:
  new_Rlink set head_Rlink
  new_Llink set head
  head_Rlink_Llink set new
  head_Rlink set new
```
### Delete
Delete a new node in DDL.
```
input: DDL head, delete node(head,del)
process:
  if: head equal del
    error
  else:
    del_Llink_Rlink set del_Rlink
    del_Rlink_Llink set del_Llink
    kill del
```
