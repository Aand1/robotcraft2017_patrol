#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <time.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id, num_neigh;
  double x, y; 		//pass these attributes in meters
  int id_neigh[3];
  double cost[3];
  int visits;
}vertex_set;

void load_graph (vertex_set *graph);

void get_time_string(char* timestring);

std::string get_log_file(FILE *results, int robot_id);

void write_visit_to_file (FILE *results, std::string file_path, int robot_id, double timestamp, int vertex_reached);

void close_log_file(FILE *results);

#endif
