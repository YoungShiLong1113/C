
//编写程序实现4后问题的求解,并给出测试用例

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_valid(int board[][8], int row, int col) {
   for (int i = 0; i < row; i++) {
       if (board[i][col] == 1) {
           return false;
       }
   }

   for (int i = 0; i < row; i++) {
       for (int j = 0; j < 8; j++) {
           if (j == col) {
               continue;
           }
           if (board[i][j] == 1 && abs(row - i) == abs(col - j)) {
               return false;
           }
       }
   }

   return true;
}

void dfs(int board[][8], int row, int col, int n, int *count) {
   if (row == n) {
       (*count)++;
       return;
   }

   for (int i = 0; i < n; i++) {
       if (is_valid(board, row, i)) {
           board[row][i] = 1;
           dfs(board, row + 1, i + 1, n, count);
           board[row][i] = 0;
       }
   }
}

/*int main() {
   int board[8][8] = {0};
   int count = 0;

   dfs(board, 0, 0, 4, &count);

   printf("共有 %d 种解法。\n", count);

   return 0;
}
*/
int main() {
   int board[8][8] = {
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0},
   };

   int count = 0;

   dfs(board, 0, 0, 4, &count);

   printf("共有 %d 种解法。\n", count);

   return 0;
   
}