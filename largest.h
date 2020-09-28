#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int a, int b);
int max(int a, int b);

typedef struct Map Map;
struct Map {
  int row;
  int col;
  char empty;
  char full;
  char obst;
  bool *map;
  int *out;
};

void largest(Map *m);
