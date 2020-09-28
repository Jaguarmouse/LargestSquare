#include "largest.h"

Map *parse(char *p) {
  FILE *fp = fopen(p, "r");
  Map *map = malloc(sizeof(Map));

  if (fp == NULL) {
    printf("file couldnt be opend\n");
    return NULL;
  }

  int row, col;
  char empty, full, obst;

  fscanf(fp, "%d%c%c%c", &row, &empty, &full, &obst);

  printf("row:%d, empty:%c, full:%c, obst:%c\n", row, empty, full, obst);

  char chr = fgetc(fp);
  fpos_t pos;
  fgetpos(fp, &pos);

  for (chr = fgetc(fp); chr != '\n'; chr = fgetc(fp)) col++;
  printf("col:%d\n", col);

  fsetpos(fp, &pos);

  if (empty == full || empty == obst || full == obst) {
    printf("parse failed\n");
    return NULL;
  }

  map->map = malloc(sizeof(bool) * row * col);
  map->out = malloc(sizeof(int) * row * col);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      chr = fgetc(fp);
      //printf("%d.chr=%c\n", i * col + j, chr);
      if (chr == empty)
        map->map[i * col + j] = false;
      else if (chr == full)
        map->map[i * col + j] = true;
      else {
        printf("map parse failed; chr=%c\n", chr);
        return NULL;
      }
    }
    chr = fgetc(fp);
  }

  fclose(fp);

  map->row = row;
  map->col = col;
  map->empty = empty;
  map->full = full;
  map->obst = obst;

  return map;
}

void print(Map *map) {
  char c;
  for (int i = 0; i < map->row; i++) {
    for (int j = 0; j < map->col; j++) {
      int index = i * map->col + j;
      if (map->out[index] == 0)
        c = map->empty;
      else if (map->out[index] == 1)
        c = map->full;
      else if (map->out[index] == 2)
        c = map->obst;
      printf("%c", c);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    Map *m = parse(argv[i]);

    if (m == NULL)
      return 1;

    largest(m);

    print(m);
  }

  return 0;
}
