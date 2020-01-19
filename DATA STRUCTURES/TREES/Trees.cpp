//INTRODUCTION TO TREES
/*
  ->Tree :-  collectio entities called nodes , linked together to simulate a hierarchy.
  
  --> Non linear data struture
  
  ->Root node :- Top most node is called root node
   
  ->Each arror in a tree is a link
      1
    /   \
   2     3
   2 and 3 are children of 1 and 1 is parent of 2 and 3
  -->leaf Node :- Those nodes which do not have childrens
  -->Remember these links are not bidirection 

  If we can go from A to B
  then A is ancestor of B
  And B is descendent of A
  
  -->PROPERTIES:-

   ->Tree can be called a recursive data structure
  ->If tree conatins N nodes then There must be      N-1 edges.
  ->Depth of x = length of path from Root to x or                 simply no of edges in path from                  root to x.
  ->Hegiht of x = No of edges in longest path from                 x to leaf.
  ->heigt of tree = height of root node.

  -> Basic way of implementing  a tree is using Node and links created recursively. 



  -->Binary Trees :- Each node can have at most 2                     children.
        root
       /    \ 
      /      \
    Left    right 
    child   child
    /   \   /   \
   /     \ /     \
  
  -->Strict/Proper binary Tree :-  Each node can          have either 2 or 0 children.
  
  -->Complete Binary tree:- All levels Except possibly the last are completely filled and all the nodes are as left as possible.

  -->Max No of nodes at level i = 2^i //       
        Considering root node at level zero.

  -->Perfect Binary tree:- All levels will be   
       completely filled.
       
       ->Maximum no Nodes in a Binary tree with height h 
         = (2^(h+1) - 1)
       ->Height of binary tree with n nodes
         h = log2(n+1) - 1 
   
   -->Balanced Binary Tree:-
        Difference Between height of left and right subtree for every node is not more than k (mostly 1).
    -->Implementing a Binary  tree:-
        a. Dynamically created nodes
        b. arrays
            
*/