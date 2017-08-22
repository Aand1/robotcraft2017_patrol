//WARNING: DO NOT MODIFY THIS FILE. 
//IF YOU FIND ANY BUG LET ME KNOW AT: <davidbsp@ingeniarius.pt>

#include "robotcraft2017_patrol/graph.h"

//Construct the arena graph:

void load_graph (vertex_set *graph){
    
    //VERTEX 0:
    graph[0].id = 0;            
    graph[0].x = 0.9;           //x coordinate
    graph[0].y = 0.9;           //y coordinate
    graph[0].visits = 0;        //not visited yet.
    
    graph[0].num_neigh = 1;     //vertex 0 has 1 neighbor
    graph[0].id_neigh[0] = 1;   //the neighbor of vertex 0 is vertex 1
    graph[0].cost[0] = 2.1;     //distance between vertex 0 and 1.
    
    
    //VERTEX 1:
    graph[1].id = 1;            
    graph[1].x = 3.0;           //x coordinate
    graph[1].y = 0.9;           //y coordinate
    graph[1].visits = 0;        //not visited yet.
    
    graph[1].num_neigh = 3;     //vertex 1 has 3 neighbors
    
    graph[1].id_neigh[0] = 0;   //the 1st neighbor of vertex 1 is vertex 0
    graph[1].cost[0] = 2.1;     //distance between vertex 1 and vertex 0.    
    
    graph[1].id_neigh[1] = 2;   //the 2nd neighbor of vertex 1 is vertex 2
    graph[1].cost[1] = 2.1;     //distance between vertex 1 and vertex 2.    
    
    graph[1].id_neigh[2] = 5;   //the 3rd neighbor of vertex 1 is vertex 5
    graph[1].cost[2] = 1.811;   //distance between vertex 1 and vertex 5.
    
    
    //VERTEX 2:
    graph[2].id = 2;            
    graph[2].x = 5.1;           //x coordinate
    graph[2].y = 0.9;           //y coordinate
    graph[2].visits = 0;        //not visited yet.
    
    graph[2].num_neigh = 3;     //vertex 2 has 3 neighbors
    
    graph[2].id_neigh[0] = 1;   //the 1st neighbor of vertex 2 is vertex 1
    graph[2].cost[0] = 2.1;     //distance between vertex 2 and vertex 1.    
    
    graph[2].id_neigh[1] = 3;   //the 2nd neighbor of vertex 2 is vertex 3
    graph[2].cost[1] = 1.8;     //distance between vertex 2 and vertex 3.    
    
    graph[2].id_neigh[2] = 6;   //the 3rd neighbor of vertex 2 is vertex 6
    graph[2].cost[2] = 1.844;   //distance between vertex 2 and vertex 6.   
    
    
    //VERTEX 3:
    graph[3].id = 3;            
    graph[3].x = 6.9;           //x coordinate
    graph[3].y = 0.9;           //y coordinate
    graph[3].visits = 0;        //not visited yet.
    
    graph[3].num_neigh = 2;     //vertex 3 has 2 neighbors
    
    graph[3].id_neigh[0] = 2;   //the 1st neighbor of vertex 3 is vertex 2
    graph[3].cost[0] = 1.8;     //distance between vertex 3 and vertex 2.    
    
    graph[3].id_neigh[1] = 7;   //the 2nd neighbor of vertex 3 is vertex 7
    graph[3].cost[1] = 1.8;     //distance between vertex 3 and vertex 7.       
    
    
    //VERTEX 4:
    graph[4].id = 4;            
    graph[4].x = 0.9;           //x coordinate
    graph[4].y = 2.7;           //y coordinate
    graph[4].visits = 0;        //not visited yet.
    
    graph[4].num_neigh = 2;     //vertex 4 has 2 neighbors
    
    graph[4].id_neigh[0] = 5;   //the 1st neighbor of vertex 4 is vertex 5
    graph[4].cost[0] = 1.9;     //distance between vertex 4 and vertex 5.    
    
    graph[4].id_neigh[1] = 8;   //the 2nd neighbor of vertex 4 is vertex 8
    graph[4].cost[1] = 1.825;   //distance between vertex 4 and vertex 8.           
     
    
    //VERTEX 5:
    graph[5].id = 5;            
    graph[5].x = 2.8;           //x coordinate
    graph[5].y = 2.7;           //y coordinate
    graph[5].visits = 0;        //not visited yet.
    
    graph[5].num_neigh = 3;     //vertex 5 has 3 neighbors
    
    graph[5].id_neigh[0] = 1;   //the 1st neighbor of vertex 5 is vertex 1
    graph[5].cost[0] = 1.811;   //distance between vertex 5 and vertex 1.    
    
    graph[5].id_neigh[1] = 4;   //the 2nd neighbor of vertex 5 is vertex 4
    graph[5].cost[1] = 1.9;     //distance between vertex 5 and vertex 4.    
    
    graph[5].id_neigh[2] = 9;   //the 3rd neighbor of vertex 5 is vertex 9
    graph[5].cost[2] = 1.868;   //distance between vertex 5 and vertex 9.    

      
    //VERTEX 6:
    graph[6].id = 6;            
    graph[6].x = 4.7;           //x coordinate
    graph[6].y = 2.7;           //y coordinate
    graph[6].visits = 0;        //not visited yet.
    
    graph[6].num_neigh = 2;     //vertex 6 has 2 neighbors
    
    graph[6].id_neigh[0] = 2;   //the 1st neighbor of vertex 6 is vertex 2
    graph[6].cost[0] = 1.844;   //distance between vertex 6 and vertex 2.    
    
    graph[6].id_neigh[1] = 7;   //the 2nd neighbor of vertex 6 is vertex 7
    graph[6].cost[1] = 2.2;     //distance between vertex 6 and vertex 7.  

      
    //VERTEX 7:
    graph[7].id = 7;            
    graph[7].x = 6.9;           //x coordinate
    graph[7].y = 2.7;           //y coordinate
    graph[7].visits = 0;        //not visited yet.
    
    graph[7].num_neigh = 2;     //vertex 7 has 2 neighbors
    
    graph[7].id_neigh[0] = 3;   //the 1st neighbor of vertex 7 is vertex 3
    graph[7].cost[0] = 1.8;     //distance between vertex 7 and vertex 3.    
    
    graph[7].id_neigh[1] = 6;   //the 2nd neighbor of vertex 7 is vertex 6
    graph[7].cost[1] = 2.2;     //distance between vertex 7 and vertex 6.      

      
    //VERTEX 8:
    graph[8].id = 8;            
    graph[8].x = 1.2;           //x coordinate
    graph[8].y = 4.5;           //y coordinate
    graph[8].visits = 0;        //not visited yet.
    
    graph[8].num_neigh = 2;     //vertex 8 has 2 neighbors
    
    graph[8].id_neigh[0] = 4;   //the 1st neighbor of vertex 8 is vertex 4
    graph[8].cost[0] = 1.825;   //distance between vertex 8 and vertex 4.    
    
    graph[8].id_neigh[1] = 9;   //the 2nd neighbor of vertex 8 is vertex 9
    graph[8].cost[1] = 2.1;     //distance between vertex 8 and vertex 9. 

      
    //VERTEX 9:
    graph[9].id = 9;            
    graph[9].x = 3.3;           //x coordinate
    graph[9].y = 4.5;           //y coordinate
    graph[9].visits = 0;        //not visited yet.
    
    graph[9].num_neigh = 3;     //vertex 9 has 3 neighbors
    
    graph[9].id_neigh[0] = 5;   //the 1st neighbor of vertex 9 is vertex 5
    graph[9].cost[0] = 1.868;   //distance between vertex 9 and vertex 5.    
    
    graph[9].id_neigh[1] = 8;   //the 2nd neighbor of vertex 9 is vertex 8
    graph[9].cost[1] = 2.1;     //distance between vertex 9 and vertex 8.     
    
    graph[9].id_neigh[2] = 10;  //the 3rd neighbor of vertex 9 is vertex 10
    graph[9].cost[2] = 1.8;     //distance between vertex 9 and vertex 10. 
    
      
    //VERTEX 10:
    graph[10].id = 10;            
    graph[10].x = 5.1;           //x coordinate
    graph[10].y = 4.5;           //y coordinate
    graph[10].visits = 0;        //not visited yet.
    
    graph[10].num_neigh = 2;     //vertex 10 has 2 neighbors
    
    graph[10].id_neigh[0] = 9;   //the 1st neighbor of vertex 10 is vertex 9
    graph[10].cost[0] = 1.8;     //distance between vertex 10 and vertex 9.    
    
    graph[10].id_neigh[1] = 11;  //the 2nd neighbor of vertex 10 is vertex 11
    graph[10].cost[1] = 1.8;     //distance between vertex 10 and vertex 11.      
    
    
      
    //VERTEX 11:
    graph[11].id = 11;            
    graph[11].x = 6.9;           //x coordinate
    graph[11].y = 4.5;           //y coordinate
    graph[11].visits = 0;        //not visited yet.
    
    graph[11].num_neigh = 1;     //vertex 11 has 1 neighbor
    
    graph[11].id_neigh[0] = 10;  //the 1st neighbor of vertex 11 is vertex 10
    graph[11].cost[0] = 1.8;     //distance between vertex 11 and vertex 10.    
}
