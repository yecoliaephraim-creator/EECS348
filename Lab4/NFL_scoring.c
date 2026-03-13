#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int score;

  printf("Enter 0 or 1 to STOP\n");

  while(true) {
    printf("Enter the NFL score: ");

    // Read input; if input is not an integer, stop
    if (scanf("%d", &score) != 1) {
      printf("Invalid input. Exiting.\n");
      return 0;
    }

    // Stop condition
    if (score <= 1) {
      break;
    }

    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    // Points for each scoring play
    const int TD = 6;     // Touchdown
    const int FG = 3;     // Field goal
    const int SAFETY = 2; // Safety
    const int TD2 = 8;    // Touchdown + 2pt conversion
    const int TDFG = 7;   // Touchdown + extra point (field goal)

    // a = # of 8-point TDs, b = # of 7-point TDs, c = # of 6-point TDs
    // d = # of field goals, e = # of safeties
    for (int a = 0; a <= score / TD2; a++) {
      int rem1 = score - (a * TD2);

      for (int b = 0; b <= rem1 / TDFG; b++) {
        int rem2 = rem1 - (b * TDFG);

        for (int c = 0; c <= rem2 / TD; c++) {
          int rem3 = rem2 - (c * TD);

          for (int d = 0; d <= rem3 / FG; d++) {
            int rem4 = rem3 - (d * FG);

            // Safeties must fill the remaining points exactly
            if (rem4 >= 0 && rem4 % SAFETY == 0) {
              int e = rem4 / SAFETY;

              printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d, e);
            }
          }
        }
      }
    }
    printf("\n");
  }

  return 0;
}
