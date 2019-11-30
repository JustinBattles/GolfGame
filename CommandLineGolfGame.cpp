#include <stdio.h>
#include <string.h>

//Justin Battles

int getPlayers() {

 int players;
 printf("How many players will be playing? \n");

 scanf("%d", &players);

 return players;
}

int getHoles() {
 int holes;

 printf("How many holes will you be playing? \n");

 scanf("%d", &holes);

 return holes;

}

void initNames(char *buf[], int players) {
char str[50];
  for (int i = 0; i < players; i++) {
    printf("Name players: %d/%d\n", i+1, players);
    scanf("%s", str);
    buf[i] = strdup(str);
  
  }

}

void endGame(int par, int holes, int players, int scores[], char *buf[]) {
  printf("%d Holes: Par %d\n", holes, par);
  printf("-------------------\n");

  for (int i = 0; i < players; i++) {
    if (scores[i] > par)
      printf("%s | %d | +%d\n", buf[i], scores[i], (scores[i] - par));
    else if (scores[i] < par)
      printf("%s | %d | -%d\n", buf[i], scores[i], (par - scores[i]));
    else
      printf("%s | %d | %d\n", buf[i], scores[i], scores[i]);
  }

}


void playGame(int holes, int players, int scores[], char *buf[]) {

  int tmpPar = 0, tmpScore = 0, par = 0;

  for (int i = 1; i <= holes; i++) {
    printf("What is par for hole %d?\n", i);
    scanf("%d", &tmpPar);
    par += tmpPar;

    for (int j = 0; j < players; j++) {
      printf("What did %s score on hole %d\n", buf[j], i);
      scanf("%d", &tmpScore);
      scores[j] += tmpScore;
    
    }
    if (i == holes)
      endGame(par, holes, players, scores, buf);

  }

}



int main() {

int players, holes;

char *names[1024];

players = getPlayers();

int scores[players];

for (int i = 0; i < players; i++)
  scores[i] = 0;

holes = getHoles();

initNames(names, players);

playGame(holes, players, scores, names);

}
