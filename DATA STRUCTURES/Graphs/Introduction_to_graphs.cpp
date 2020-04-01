/*
Graph :- A graph G is an ordered pair of a set V of vertices and set E 
         of edges.
         G = (V,E)
         ordered pair (a,b) != (b,a) if a != b
         Unordered pair {a,b} = {b,a}

         v1 ---------v2
         /  \        / \            V =  {v1,v2,v3,v4,v5,v6,v7,v8}
        /    \      /   \            
       v3     v4   v5    \           Edges :
        \      \    |     v6           Directed        undirected
         \      \   |    /             (u,v)              {u,v}
          \      \  |   /           E = { {v1,v2},{v1,v3},{v1,v4},{v2,5},{v2,v6}
           v7----- v8 --                   {v3,v7},{v4,v8},{v7,v8},{v5,v8},{v6,v8} 
                                           }

Directed Graph :- A graph conataining only directed edges.
Undirecetd Graph :- A graph conataining only undirected edges.

Weighted Graphs :- Each connection(edges) having different wieghts for traversing from one
                   node to another.
Unweighted Graphs :- A weighted graph with all edges having weight = 1 unit                   



*/