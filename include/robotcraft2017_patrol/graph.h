#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef struct {
  int id, num_neigh;
  double x, y; 		//pass these attributes in meters
  int id_neigh[3];
  double cost[3];
  int visits;
}vertex_set;

void load_graph (vertex_set *graph);

#endif
