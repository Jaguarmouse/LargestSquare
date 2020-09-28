#include "largest.h"

void largest(Map *m) {
  int dp[m->row][m->col];
  int x, y, l; x = y = 0; l = 1;

  for (int i = 0; i < m->row; i++)
    dp[i][0] = m->map[i * m->col] ? 0 : 1;
  for (int i = 0; i < m->col; i++)
    dp[0][i] = m->map[i] ? 0 : 1;

  for (int i = 1; i < m->row; i++) {
    for (int j = 1; j < m->col; j++) {
      if (m->map[i * m->col + j]) {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
      if (dp[i][j] > l) {
        l = dp[i][j];
        x = j;
        y = i;
      }
    }
  }

  for (int i = 0; i < m->row; i++) {
    for (int j = 0; j < m->col; j++) {
      printf("%d", dp[i][j]);
    }
    printf("\n");
  }
  //print_dp(m, dp);

  printf("x:%d, y:%d, l:%d\n", x, y, l);

  for (int i = 0; i < m->row; i++) {
    for (int j = 0; j < m->col; j++) {
      if (x - l < j && j <= x && y - l < i && i <= y)
        m->out[i * m->col + j] = 2;
      else if (m->map[i * m->col + j])
        m->out[i * m->col + j] = 1;
      else
        m->out[i * m->col + j] = 0;
    }
  }
}

