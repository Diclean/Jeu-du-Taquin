

/* ************************************************************************** */
/*    JEU DU TAQUIN                                                           */
/*        _______      _______. __   _______      ___                         */
/*       |   ____|    /       ||  | |   ____|    /   \                        */
/*       |  |__      |   (----`|  | |  |__      /  ^  \                       */      
/*       |   __|      \   \    |  | |   __|    /  /_\  \                      */
/*       |  |____ .----)   |   |  | |  |____  /  _____  \                     */
/*       |_______||_______/    |__| |_______|/__/     \__\                    */
/* ************************************************************************** */
/*     Classe 12                                                              */
/*      By : Mathys PURENNE                                                   */
/*           Maxime PENSIVY                                                   */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <ncurses.h> 
#include <unistd.h>
#define NB_C 2
#define NB_L 2

  char tab_1[16][44];
char tab_2[16][44];
 char tab_3[16][44];
 char tab_4[16][44];
  char tab_5[16][44];
 char tab_6[16][44];
  char tab_7[16][44];
  char tab_8[16][44];

int L, C; /*L pour désigner la ligne et C la colonne du click de la souris*/
int X,Y;


/**Initialisation de ncurses**/
void ncurses_initialiser() {
  initscr();            /* Demarre le mode ncurses */
  cbreak();         /* Pour les saisies clavier (desac. mise en buffer) */
  noecho();             /* Desactive l'affichage des caracteres saisis */
  keypad(stdscr, TRUE); /* Active les touches specifiques */
  refresh();            /* Met a jour l'affichage */
  curs_set(FALSE);      /* Masque le curseur */
}


/**Initialisation des couleurs**/
void ncurses_couleurs() {
  /* Vérification du support de la couleur */
  if(has_colors() == FALSE) {
    endwin();
    fprintf(stderr, "Le terminal ne supporte pas les couleurs.\n");
    exit(EXIT_FAILURE);
  }

  /* Activation des couleurs */
  start_color();

}

/**Initialisation de la souris**/
void ncurses_souris() {
  if(!mousemask(ALL_MOUSE_EVENTS, NULL)) {
    endwin();
    fprintf(stderr, "Erreur lors de l'initialisation de la souris.\n");
    exit(EXIT_FAILURE);
  }

  if(has_mouse() != TRUE) {
    endwin();
    fprintf(stderr, "Aucune souris n'est détectée.\n");
    exit(EXIT_FAILURE);
  }
}


/**Pour récupérer les coordonnées (x,y) du clik de la souris**/
int click_souris()
{
  MEVENT event ;
  int ch;

  while((ch = getch()) != KEY_F(1)) 
  {
    switch(ch) 
    {
      case KEY_F(2): /*Pour quitter le jeu*/
    return 1;
      case KEY_MOUSE:
        if(getmouse(&event) == OK) 
    {
      C = event.x;
      L = event.y;
      if(event.bstate & BUTTON1_CLICKED)
      {
        if (L< 51 && C<132) /*Vous pouvez changer ici et mettre les dimensions de votre plateau de jeu*/
        {
        return 0;
        }
      }
    }
    }
  }
  return 0;
}
int *tirage(int nombre, int min, int max)
{
    int *tabelems, *ret, i, indice, maxi = max - min;
    if(min >= max || nombre > maxi + 1 || nombre < 1)
        return NULL;
    tabelems = malloc((maxi + 1) * sizeof(int));
    ret = malloc(nombre * sizeof(int));
    for(i = 0; i < maxi + 1; i++)
        tabelems[i] = i + min;
    for(i = 0; i < nombre; i++){
        indice = rand() % (maxi + 1);
        ret[i] = tabelems[indice];
        tabelems[indice] = tabelems[maxi];
        maxi--;
    }
    free(tabelems);
    return ret;
}


void suite_test(int MAT[3][3],int tab[9])
{
  int x = 0;
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      printw("tab[%d] = %d",x,tab[x]);
      MAT[i][j] = tab[x];
      x++;
    }
  }
}


void test(int MAT[3][3])
{
   int i,j,*tab;
    int nb = 9
    ;
    srand(time(NULL));
    
    tab = tirage(nb, 1, 9);
    suite_test(MAT,tab);
}

void mouvement(){
    if(L>0 && L<17 && C >0 && C<44)
    {
        X = 0, Y=0;
}
  if(L>=1 && L<=17 && C >= 44 && C <= 88){
    X = 0, Y=1;
  }
    if(L>=1 && L<=17 && C >= 88 && C <= 132){
      X = 0 ,Y=2;
  }
    if(L>=17 && L<=34 && C >= 1 && C <= 44){
      X=1, Y=0;
  }
    if(L>=17 && L<=34 && C >= 44 && C <= 88){
      X=1, Y = 1; 
  }
    if(L>=17 && L<=34 && C >= 88 && C <= 132){
      X = 1, Y = 2; 
  }
    if(L>=34 && L<=51 && C >=1 && C <= 44){
      X = 2, Y= 0;
  }
    if(L>=34 && L<=51 && C >= 44 && C <= 88){
      X = 2, Y = 1;
  }
    if(L>=34 && L<=51 && C >= 88 && C <= 132){
      X = 2, Y=2;
  }
}
void swap(int X0, int Y0, int TAB[3][3]){
  int TEMP; 
  TEMP=TAB[X][Y];
  TAB[X][Y]=TAB[X0][Y0];
  TAB[X0][Y0]=TEMP;

   
}
int CheckEZ(int X0, int Y0,int TAB[3][3]){
   if(Y+1 == Y0 && X ==X0){
    return 1;
  }
  else if(Y-1 == Y0 && X == X0){
  return 1;
  }
  else if(Y == Y0 && X-1 == X0){
    return 1;
  }
  else if (Y== Y0 && X+1 == X0){
    return 1;
  }
  else if(Y - 1== Y0 && X -1 == X0){
    return 1;
  }
  else if (Y -1 == Y0 && X +1 == X0){
    return 1;
  }
  else if(Y+ 1 == Y0 && X+1 == X0){
    return 1;
  }
  else if (Y+1 == Y0 && X-1 == X0){
    return 1;
  }
  
  return 0;
 
}


int CheckD(int X0, int Y0,int TAB[3][3]){
  int i,j; 
  if(Y+1 == Y0 && X ==X0){
    return 1;
  }
  else if(Y-1 == Y0 && X == X0){
  return 1;
  }
  else if(Y == Y0 && X-1 == X0){
    return 1;
  }
  else if (Y== Y0 && X+1 == X0){
    return 1;
  }
  return 0;
}
  int Verification(int TAB[3][3]){
  if(TAB[0][0]==1 && TAB[0][1] == 2 && TAB[0][2] == 3 && TAB[1][0]==4 && TAB[1][1]==5 && TAB[1][2]==6 && TAB[2][0] == 7 && TAB[2][1]==8 && TAB[2][2] == 0 ){
    clear(); 
    printw("GG VOUS AVEZ GAGNER !!!!");
  return 1;
  }
return 0; 
}


void affichage(int TAB[3][3], char tab_1[16][44],char tab_2[16][44],char tab_3[16][44],char tab_4[16][44],char tab_5[16][44],char tab_6[16][44],char tab_7[16][44],char tab_8[16][44],char tab_9[16][44]){
if (TAB[0][0] == 1)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[0][0] == 2)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[0][0] == 3)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[0][0] == 4)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[0][0] == 5)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[0][0] == 6)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[0][0] == 7)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[0][0] == 8)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
  }
  if (TAB[0][0] == 0)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
  }

  if (TAB[0][1] == 1)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
  }
  if (TAB[0][1] == 2)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
  }
  if (TAB[0][1] == 3)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
  }
  if (TAB[0][1] == 4)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
  }
  if (TAB[0][1] == 5)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
  }
  if (TAB[0][1] == 6)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
  }
  if (TAB[0][1] == 7)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
  }
  if (TAB[0][1] == 8)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
  }

  if (TAB[0][1] == 0)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(i,44 + j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
  }
//3eme image
  if (TAB[0][2] == 1)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
}

if (TAB[0][2] == 2)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
}
if (TAB[0][2] == 3)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
}
if (TAB[0][2] == 4)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
}
if (TAB[0][2] == 5)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
}
if (TAB[0][2] == 6)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
}
if (TAB[0][2] == 7)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
}
if (TAB[0][2] == 8)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
}

if (TAB[0][2] == 0)
  {
    for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(0+i,88+j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
}

//4eme image
if (TAB[1][0] == 1)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][0] == 2)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][0] == 3)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][0] == 4)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][0] == 5)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][0] == 6)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][0] == 7)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][0] == 8)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
}
 if (TAB[1][0] == 0)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
}

//5eme image

if (TAB[1][1] == 1)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][1] == 2)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][1] == 3)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][1] == 4)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][1] == 5)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][1] == 6)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][1] == 7)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][1] == 8)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
}
  if (TAB[1][1] == 0)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,44+j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
}

//6eme tab

if (TAB[1][2] == 1)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][2] == 2)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][2] == 3)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][2] == 4)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][2] == 5)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][2] == 6)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][2] == 7)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[1][2] == 8)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
}

 if (TAB[1][2] == 0)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(16+i,88+j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
}

//7eme image

if (TAB[2][0] == 1)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][0] == 2)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][0] == 3)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][0] == 4)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][0] == 5)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][0] == 6)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][0] == 7)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][0] == 8)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
}

 if (TAB[2][0] == 0)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
}

//8eme image

if (TAB[2][1] == 1)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][1] == 2)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][1] == 3)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][1] == 4)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][1] == 5)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][1] == 6)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][1] == 7)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][1] == 8)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
}
if (TAB[2][1] == 0)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,44+j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
}
//9eme image

if (TAB[2][2] == 1)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_1[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][2] == 2)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_2[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][2] == 3)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_3[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][2] == 4)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_4[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][2] == 5)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_5[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][2] == 6)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_6[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][2] == 7)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_7[i][j]);
    }
    printw("\n");
  }
  }
   if (TAB[2][2] == 8)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_8[i][j]);
    }
    printw("\n");
  }
}
if (TAB[2][2] == 0)
  {

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 44; ++j)
    {
      mvprintw(32+i,88+j, "%c",tab_9[i][j]);
    }
    printw("\n");
  }
}

}
/*
void detection(int TAB[3][3], int X0, int Y0){
  for(int i = 0; i<3;i++){
    for(int j = 0; j<3;j++){
      if(TAB[i][j] == 0){
        X0 = i; 
        Y0 = j;
      }
    }
  }

}*/



int main() {
  
  int X0, Y0 ; 
  
  ncurses_initialiser(); //Initialisation de ncurses
  //ncurses_couleurs();
  ncurses_souris();
  scrollok(stdscr, TRUE);
  char imagefini[48][132];
  strcpy(imagefini[0],"                                                                         :                                                   ");
  strcpy(imagefini[1],"                                                                         :                                                     "); 
  strcpy(imagefini[2],"                                                                        / \\                                                    ");
  strcpy(imagefini[3],"                                                                     _;;;;;;;_                                                      ");
  strcpy(imagefini[4],"                                                                  .-'         '-.                               .                  ");
  strcpy(imagefini[5],"                                  .                              /               \\                              m                  ");
  strcpy(imagefini[6],"                                  m                             /                 \\                            | |                   ");
  strcpy(imagefini[7],"                                 | |                           |                   |                           |M|                   ");
  strcpy(imagefini[8],"                                 |M|                           |    ___--'--___    |                           ---+                  ");
  strcpy(imagefini[9],"                                 ---+       .               .:.\\__--  _______  --__/.:.               .        |  |                  ");
  strcpy(imagefini[10],"                                 |  |       m              /   \\ -----       ----- /   \\              m        |  |                ");
  strcpy(imagefini[11],"                                 |  |      | |      :     /_____ __________________ ____\\     :      | |       |  |                ");
  strcpy(imagefini[12],"                                 |  |      |n|      __:  | n n n|  ______________  |n n n|  ;__      |n|       |  |                ");
  strcpy(imagefini[13],"                                 ___|      | |      |n\\__|_M_M_M| | ____________ | |M_M_M|__/nn|     | |      |---|                ");
  strcpy(imagefini[14],"                                 ___|      | |      |n\\__|_M_M_M| | ____________ | |M_M_M|__/nn|     | |      |---|                ");
  strcpy(imagefini[15],"                                 |   |     | |      |    |      | ||      _     || |     |     |     | |      |   |                ");
  strcpy(imagefini[16],"                                 |   |     | |      | /\\ |  .-. | ||      .-" "-.  || | .-. |  /\\ |     |-|      |   |     ..  ...      ");
  strcpy(imagefini[17],"                                 |   |     |-|      ||  || /   \\| ||  '  -\"-  ' || |/   \\| |  ||     | |      |   | ..............    ");   
  strcpy(imagefini[18]," ()                              ____|     | |      |    | +---+| || |  -----  ||| |+---+|     |     | |     |    | ...............");
  strcpy(imagefini[19]," :::)():(:)                      |    |    |_|      |    |  .-. | || |         ||| | .-. |     |     |-|     |    |................");
  strcpy(imagefini[20]," ::::):(:::)                     |    |    | |      | /\\ | /   \\| || |   ||    ||| |/   \\|  /\\ |     | |     |    | ...............");
  strcpy(imagefini[21]," :::::)::::::)   .  .            | (:():)()  |      ||  || |   || || |  ||||   ||| ||   || |  ||     | |     |    |  ..............    ");
  strcpy(imagefini[22]," ::::::):::::::)      . ::        (:(:))(:):)| -----============================================---- | | ----|    |   .............");
  strcpy(imagefini[23]," :::::):::::::::)      ::::::    (:(:):((:():)                                                      m            .,.   ...m          ");
  strcpy(imagefini[24]," ::::::::::::::::)    ::::m:m   |     000          m m  m  M     ;;;                       M M  M   MMM          ...MM   MM    m       ");
  strcpy(imagefini[25]," ::mmm::::::::mm:::). .::MM:MM  ------000---------MM MM MM MM--::::::-------------------M-MMMMMMMM--MMMm-M-MM------MMMM MMM   MMm  ");
  strcpy(imagefini[26]," MMMMMM::::::MMMM:). . . MMMMMMM      0 MM   .    MM MM MM MM             ==            M MMMMMMMM  MMMM M MMM    MMMMM MMMM  MMM  ");
  strcpy(imagefini[27]," MMMMMMM:::::MMMMM      MMMMMMMM  MM .  MMM       MM MM MM       i i i  :F_P: i i.i         MMMMMM  MMMM M MMM    MMMMM MMMM  MMM  ");
  strcpy(imagefini[28]," MMMMMMM::::MMMMMMM     MMMMMMMMM MM    MMMM      MM M        .    //             \\    .         M  MMMM M MMM    MMMMM MMMM  MMM  ");
  strcpy(imagefini[29]," MMMMMMM:::MMMMMMMMM .  MMMMMMMMM MM  M  MMM      M               /                \\.      .          MM M MM  .  MMMMM MMMM  MMM  ");
  strcpy(imagefini[30]," MMMMMMMM::MMMMMMMMM    MMMMMMMMM MM  M MMMM              .'    ./                  '\\                     MM    'MMMMM MMMM  MMMM ");
  strcpy(imagefini[31]," MMMMMMMM::MMMMMMMMM   MMMMMMMMMM MM  M MMMM           .       //                     \\.         .                MMMMM MMMM .MMMM ");
  strcpy(imagefini[32]," MMMMMMMM::MMMMMMMMM   MMMMMMMMM  MM                         ./'                       '\\\\                          MMM MMMM  MMMM'");
  strcpy(imagefini[33]," MMMMMMMM:::MMMMMMMM   MMMMMMMM                    .        //                           '\\.           .                      MMMM ");
  strcpy(imagefini[34]," MMMMMMMMM::MMMMMMMM    MMMMMM                             //                              \\\\.                                MMMM ");
  strcpy(imagefini[35]," MMMMMMMMM:: MMMMMMM   MMMMM                  .          //'                                '\\\\.            .                      ");
  strcpy(imagefini[36]," MMMMMMM:   MMMMMMM                                    .//                                    '\\\\                                     ");
  strcpy(imagefini[37]," MMMMMMM    MMMMMM                       .            ///                                       '\\\\              .                    ");
  strcpy(imagefini[38]," MMMMMM                                              //'                                          \\\\.                 .               ");
  strcpy(imagefini[39]," MMMMMMM                             .             .//                                             \\\\\\.                               ");
  strcpy(imagefini[40]," MMMMMM                                           ///                                                \\\\\\.                  .            ");
  strcpy(imagefini[41]," MMMMM                         .                .///                                                  '\\\\\\.                            ");
  strcpy(imagefini[42],"  MMM                                          ///'                                                     \\\\\\\\                     .       ");
  strcpy(imagefini[43],"                                              ///                                                        '\\\\\\.                      .    ");
  strcpy(imagefini[44],"                        .                   .///                                                           '\\\\\\.                         "); 
  strcpy(imagefini[45],"                                           ////                                                              \\\\\\\\                       ");
  strcpy(imagefini[46],"                                          ///'                                                                \\\\\\                        ");
  strcpy(imagefini[47],"                                                                                                                \\\\\\\\               ");
  char tab_1[16][44];
 strcpy(tab_1[0],"                                            ");
 strcpy(tab_1[1],"                                            ");
 strcpy(tab_1[2],"                                            ");
 strcpy(tab_1[3],"                                            ");
 strcpy(tab_1[4],"                                            ");
 strcpy(tab_1[5],"                                  .          ");
 strcpy(tab_1[6],"                                  m          ");
 strcpy(tab_1[7],"                                 | |         ");
 strcpy(tab_1[8],"                                 |M|         ");
 strcpy(tab_1[9],"                                 ---+        ");
 strcpy(tab_1[10],"                                 |  |       ");
 strcpy(tab_1[11],"                                 |  |      |");
 strcpy(tab_1[12],"                                 |  |      |");
 strcpy(tab_1[13],"                                 ___|      |");
 strcpy(tab_1[14],"                                 |   |     |");
 strcpy(tab_1[15],"                                 |   |     ");



char tab_2[16][44];
 strcpy(tab_2[0],"                             :                  ");
 strcpy(tab_2[1],"                             :                  ");
 strcpy(tab_2[2],"                            / \\                    ");
 strcpy(tab_2[3],"                         _;;;;;;;_                   ");
 strcpy(tab_2[4],"                      .-'         '-.       ");
 strcpy(tab_2[5],"                     /               \\      ");
 strcpy(tab_2[6],"                    /                 \\     ");
 strcpy(tab_2[7],"                   |                   |    ");
 strcpy(tab_2[8],"                   |    ___--'--___    |    ");
 strcpy(tab_2[9],".               .:.\\__--  _______  --__/.:. ");
 strcpy(tab_2[10],"m              /   \\ -----       ----- /   \\");
 strcpy(tab_2[11]," |      :     /_____ __________________ ____");
 strcpy(tab_2[12],"n|      __:  | n n n|  ______________  |n n ");
 strcpy(tab_2[13]," |      |n\\__|_M_M_M| | ____________ | |M_M_");
 strcpy(tab_2[14]," |      |    |      | ||      _     || |    ");
 strcpy(tab_2[15],"                                 |   |     | ");

 
    


 char tab_3[16][44];
 strcpy(tab_3[0],"                                            ");
 strcpy(tab_3[1],"                                            ");
 strcpy(tab_3[2],"                                            ");
 strcpy(tab_3[3],"                                            ");
 strcpy(tab_3[4],"                        .                   ");
 strcpy(tab_3[5],"                        m                   ");
 strcpy(tab_3[6],"                       | |                  ");
 strcpy(tab_3[7],"                       |M|                  ");
 strcpy(tab_3[8],"                       ---+                 ");
 strcpy(tab_3[9],"              .        |  |                 ");
 strcpy(tab_3[10],"              m        |  |                 ");
 strcpy(tab_3[11],"\\     :      | |       |  |                 ");
 strcpy(tab_3[12],"n|  ;__      |n|       |  |                  ");
 strcpy(tab_3[13],"M|__/nn|     | |      |---|                  ");
 strcpy(tab_3[14]," |     |     | |      |   |                  ");
 strcpy(tab_3[15]," |  /\\ |     |-|      |   |     ..  ...  ");

 

 char tab_4[16][44];
 strcpy(tab_4[0],"                                 |   |     |");
 strcpy(tab_4[1],"                                 |   |     |");
 strcpy(tab_4[2]," ()                              ____|     |");
 strcpy(tab_4[3]," :::)():(:)                      |    |    |");
 strcpy(tab_4[4]," ::::):(:::)                     |    |    |");
 strcpy(tab_4[5]," :::::)::::::)   .  .            | (:():)() ");
 strcpy(tab_4[6]," ::::::):::::::)      . ::        (:(:))(:):");
 strcpy(tab_4[7]," :::::):::::::::)      ::::::    (:(:):((:()");
 strcpy(tab_4[8]," ::::::::::::::::)    ::::m:m   |     000   ");
 strcpy(tab_4[9]," ::mmm::::::::mm:::). .::MM:MM  ------000---");
 strcpy(tab_4[10]," MMMMMM::::::MMMM:). . . MMMMMMM      0 MM  ");
 strcpy(tab_4[11]," MMMMMMM:::::MMMMM      MMMMMMMM  MM .  MMM ");
 strcpy(tab_4[12]," MMMMMMM::::MMMMMMM     MMMMMMMMM MM    MMMM");
 strcpy(tab_4[13]," MMMMMMM:::MMMMMMMMM .  MMMMMMMMM MM  M  MMM");
 strcpy(tab_4[14]," MMMMMMMM::MMMMMMMMM    MMMMMMMMM MM  M MMMM");
 strcpy(tab_4[15]," MMMMMMMM::MMMMMMMMM   MMMMMMMMMM MM  M MMMM");

  char tab_5[16][44];
 strcpy(tab_5[0]," |      | /\\ |  .-. | ||   .-" "-.  || | .-. ");
 strcpy(tab_5[1],"-|      ||  || /   \\| ||  '  -\"-  ' || |/   ");
 strcpy(tab_5[2]," |      |    | |   || || |  |   |  ||| ||   ");
 strcpy(tab_5[3]," |      |    | +---+| || |  -----  ||| |+---");
 strcpy(tab_5[4],"_|      |    |  .-. | || |         ||| | .-.");
 strcpy(tab_5[5]," |      | /\\ | /   \\| || |   ||    ||| |/ ");
 strcpy(tab_5[6]," |      ||  || |   || || |  ||||   ||| ||   ");
 strcpy(tab_5[7],")| -----====================================");
 strcpy(tab_5[8],":)                                          ");
 strcpy(tab_5[9],"       m m  m  M     ;;;                      ");
 strcpy(tab_5[10],"------MM MM MM MM--::::::-------------------");
 strcpy(tab_5[11]," .    MM MM MM MM             ==            ");
 strcpy(tab_5[12],"      MM MM MM       i i i  :F_P: i i.i     ");
 strcpy(tab_5[13],"      MM M        .    //             \\    .");
 strcpy(tab_5[14],"      M               /                \\.   ");
 strcpy(tab_5[15],"              .'    ./                  '\\  ");

 char tab_6[16][44];
 strcpy(tab_6[0],"\\| |  ||     | |      |   | ..............  ");
 strcpy(tab_6[1],"||     |     | |      ----|................  ");
 strcpy(tab_6[2],"+|     |     | |     |    | ...............  ");
 strcpy(tab_6[3]," |     |     |-|     |    |................  ");
 strcpy(tab_6[4],"\\|  /\\ |     | |     |    | ............... ");
 strcpy(tab_6[5],"|| |  ||     | |     |    |  ..............   ");
 strcpy(tab_6[6],"========---- | | ----|    |   .............   ");
 strcpy(tab_6[7],"            m            .,.   ...m           ");
 strcpy(tab_6[8],"   M M  M   MMM          ...MM   MM    m          ");
 strcpy(tab_6[9],"M-MMMMMMMM--MMMm-M-MM------MMMM MMM   MMm    ");
 strcpy(tab_6[10],"M MMMMMMMM  MMMM M MMM    MMMMM MMMM  MMM   ");
 strcpy(tab_6[11],"    MMMMMM  MMMM M MMM    MMMMM MMMM  MMM   ");
 strcpy(tab_6[12],"         M  MMMM M MMM    MMMMM MMMM  MMM   ");
 strcpy(tab_6[13],"   .          MM M MM  .  MMMMM MMMM  MMM   ");
 strcpy(tab_6[14],"                   MM    'MMMMM MMMM  MMMM  ");
 strcpy(tab_6[15],"         .                MMMMM MMMM .MMMM  ");

  char tab_7[16][44];
 strcpy(tab_7[0]," MMMMMMMM::MMMMMMMMM   MMMMMMMMM  MM        ");
 strcpy(tab_7[1]," MMMMMMMM:::MMMMMMMM   MMMMMMMM             ");
 strcpy(tab_7[2]," MMMMMMMMM::MMMMMMMM    MMMMMM              ");
 strcpy(tab_7[3]," MMMMMMMMM:: MMMMMMM   MMMMM                ");
 strcpy(tab_7[4]," MMMMMMM:   MMMMMMM                         ");
 strcpy(tab_7[5]," MMMMMMM    MMMMMM                       .  ");
 strcpy(tab_7[6]," MMMMMM                                     ");
 strcpy(tab_7[7]," MMMMMMM                             .      ");
 strcpy(tab_7[8]," MMMMMM                                     ");
 strcpy(tab_7[9]," MMMMM                         .            ");
 strcpy(tab_7[10],"  MMM                                       ");
 strcpy(tab_7[11],"                                            ");
 strcpy(tab_7[12],"                        .                   ");
 strcpy(tab_7[13],"                                           /");
 strcpy(tab_7[14],"                                          //");
 strcpy(tab_7[15],"                                            ");

  char tab_8[16][44];
 strcpy(tab_8[0],"                 ./'                       '");
 strcpy(tab_8[1],"       .        //                          ");
 strcpy(tab_8[2],"               //                           ");
 strcpy(tab_8[3],"  .          //'                            ");
 strcpy(tab_8[4],"           .//                              ");
 strcpy(tab_8[5],"          ///                               ");
 strcpy(tab_8[6],"         //'                                ");
 strcpy(tab_8[7],"       .//                                  ");
 strcpy(tab_8[8],"      ///                                   ");
 strcpy(tab_8[9],"    .///                                    ");
 strcpy(tab_8[10],"   ///'                                     ");
 strcpy(tab_8[11],"  ///                                       ");
 strcpy(tab_8[12],".///                                        ");
 strcpy(tab_8[13],"///                                         ");
 strcpy(tab_8[14],"/'                                          ");
 strcpy(tab_8[15],"                                            ");
 char tab_9[16][44];
 strcpy(tab_9[0],"/////////////////////////////////////////////");//TAB9
 strcpy(tab_9[1],"/////////////////////////////////////////////");
 strcpy(tab_9[2],"/////////////////////////////////////////////");
 strcpy(tab_9[3],"/////////////////////////////////////////////");
 strcpy(tab_9[4],"/////////////////////////////////////////////");
 strcpy(tab_9[5],"/////////////////////////////////////////////");
 strcpy(tab_9[6],"/////////////////////////////////////////////");
 strcpy(tab_9[7],"/////////////////////////////////////////////");
 strcpy(tab_9[8],"/////////////////////////////////////////////");
 strcpy(tab_9[9],"/////////////////////////////////////////////");
 strcpy(tab_9[10],"/////////////////////////////////////////////");
 strcpy(tab_9[11],"/////////////////////////////////////////////");
 strcpy(tab_9[12],"/////////////////////////////////////////////");
 strcpy(tab_9[13],"/////////////////////////////////////////////");
 strcpy(tab_9[14],"/////////////////////////////////////////////");
 strcpy(tab_9[15],"/////////////////////////////////////////////");

char chiffre_1[16][44];
strcpy(chiffre_1[0],"---------------------------------------------");
strcpy(chiffre_1[1],"|            11111                         |");
strcpy(chiffre_1[2],"|          1111111                         |");
strcpy(chiffre_1[3],"|       11111  111                         |");
strcpy(chiffre_1[4],"|              111                         |");
strcpy(chiffre_1[5],"|              111                         |");
strcpy(chiffre_1[6],"|              111                         |");
strcpy(chiffre_1[7],"|              111                         |");
strcpy(chiffre_1[8],"|              111                         |");
strcpy(chiffre_1[9],"|              111                         |");
strcpy(chiffre_1[10],"|       11111111111                        |");
strcpy(chiffre_1[11],"|                                          |");
strcpy(chiffre_1[12],"|                                          |");
strcpy(chiffre_1[13],"|                                          |");
strcpy(chiffre_1[14],"|                                          |");
strcpy(chiffre_1[15],"|                                          |");
strcpy(chiffre_1[16],"--------------------------------------------");

char chiffre_2[16][44];
strcpy(chiffre_2[0],"---------------------------------------------");
strcpy(chiffre_2[1],"|                                          |");
strcpy(chiffre_2[2],"|                 22222                    |");
strcpy(chiffre_2[3],"|            222222   222                  |");
strcpy(chiffre_2[4],"|           2222      22222                |");
strcpy(chiffre_2[5],"|                     222222               |");
strcpy(chiffre_2[6],"|                     2222                 |");
strcpy(chiffre_2[7],"|                   2222                   |");
strcpy(chiffre_2[8],"|                 22222                    |");
strcpy(chiffre_2[9],"|               22222                      |");
strcpy(chiffre_2[10],"|             22222                        |");
strcpy(chiffre_2[11],"|           2222222222222                  |");
strcpy(chiffre_2[12],"|                                          |");
strcpy(chiffre_2[13],"|                                          |");
strcpy(chiffre_2[14],"|                                          |");
strcpy(chiffre_2[15],"|                                          |");
strcpy(chiffre_2[16],"--------------------------------------------");

char chiffre_3[16][44];
strcpy(chiffre_3[0],"---------------------------------------------");
strcpy(chiffre_3[1],"|                                          |");
strcpy(chiffre_3[2],"|                                          |");
strcpy(chiffre_3[3],"|         33333333333333                   |");
strcpy(chiffre_3[4],"|         33333333333333                   |");
strcpy(chiffre_3[5],"|                   3333                   |");
strcpy(chiffre_3[6],"|                   3333                   |");
strcpy(chiffre_3[7],"|                   3333                   |");
strcpy(chiffre_3[8],"|            33333333333                   |");
strcpy(chiffre_3[9],"|            33333333333                   |");
strcpy(chiffre_3[10],"|                   3333                   |");
strcpy(chiffre_3[11],"|                   3333                   |");
strcpy(chiffre_3[12],"|                   3333                   |");
strcpy(chiffre_3[13],"|         33333333333333                   |");
strcpy(chiffre_3[14],"|         33333333333333                   |");
strcpy(chiffre_3[15],"|                                          |");
strcpy(chiffre_3[16],"-------------------------------------------");

char chiffre_4[16][44];
strcpy(chiffre_4[0],"--------------------------------------------");
strcpy(chiffre_4[1],"|                                          |");
strcpy(chiffre_4[2],"|                  444444                  |");
strcpy(chiffre_4[3],"|                44444444                  |");
strcpy(chiffre_4[4],"|              444    444                  |");
strcpy(chiffre_4[5],"|            444      444                  |");
strcpy(chiffre_4[6],"|          444        444                  |");
strcpy(chiffre_4[7],"|        444          444                  |");
strcpy(chiffre_4[8],"|      444444444444444444                  |");
strcpy(chiffre_4[9],"|                     444                  |");
strcpy(chiffre_4[10],"|                     444                  |");
strcpy(chiffre_4[11],"|                     444                  |");
strcpy(chiffre_4[12],"|                     444                  |");
strcpy(chiffre_4[13],"|                   4444444                |");
strcpy(chiffre_4[14],"|                                          |");
strcpy(chiffre_4[15],"|                                          |");
strcpy(chiffre_4[16],"--------------------------------------------");

char chiffre_5[16][44];
strcpy(chiffre_5[0],"--------------------------------------------");
strcpy(chiffre_5[1],"|                                          |");
strcpy(chiffre_5[2],"|                                          |");
strcpy(chiffre_5[3],"|               5555555555                 |");
strcpy(chiffre_5[4],"|               555                        |");
strcpy(chiffre_5[5],"|               555                        |");
strcpy(chiffre_5[6],"|               5555555555                 |");
strcpy(chiffre_5[7],"|                       555                |");
strcpy(chiffre_5[8],"|                        555               |");
strcpy(chiffre_5[9],"|                        555               |");
strcpy(chiffre_5[10],"|                      555                 |");
strcpy(chiffre_5[11],"|               5555555555                 |");
strcpy(chiffre_5[12],"|                                          |");
strcpy(chiffre_5[13],"|                                          |");
strcpy(chiffre_5[14],"|                                          |");
strcpy(chiffre_5[15],"|                                          |");
strcpy(chiffre_5[16],"--------------------------------------------");

char chiffre_6[16][44];
strcpy(chiffre_6[0],"--------------------------------------------");
strcpy(chiffre_6[1],"|                                          |");
strcpy(chiffre_6[2],"|                                          |");
strcpy(chiffre_6[3],"|                 6666666666               |");
strcpy(chiffre_6[4],"|                 66                       |");
strcpy(chiffre_6[5],"|                 66                       |");
strcpy(chiffre_6[6],"|                 666666666                |");
strcpy(chiffre_6[7],"|                 6       6                |");
strcpy(chiffre_6[8],"|                 6       6                |");
strcpy(chiffre_6[9],"|                 6       6                |");
strcpy(chiffre_6[10],"|                 666666666                |");
strcpy(chiffre_6[11],"|                                          |");
strcpy(chiffre_6[12],"|                                          |");
strcpy(chiffre_6[13],"|                                          |");
strcpy(chiffre_6[14],"|                                          |");
strcpy(chiffre_6[15],"|                                          |");
strcpy(chiffre_6[16],"--------------------------------------------");

char chiffre_7[16][44];
strcpy(chiffre_7[0],"--------------------------------------------");
strcpy(chiffre_7[1],"|                                          |");
strcpy(chiffre_7[2],"|                                          |");
strcpy(chiffre_7[3],"|              777777777777                |");
strcpy(chiffre_7[4],"|              777777777777                |");
strcpy(chiffre_7[5],"|                      777                 |");
strcpy(chiffre_7[6],"|                     777                  |");
strcpy(chiffre_7[7],"|                  7777777                 |");
strcpy(chiffre_7[8],"|                   777                    |");
strcpy(chiffre_7[9],"|                  777                     |");
strcpy(chiffre_7[10],"|                 777                      |");
strcpy(chiffre_7[11],"|                777                       |");
strcpy(chiffre_7[12],"|                                          |");
strcpy(chiffre_7[13],"|                                          |");
strcpy(chiffre_7[14],"|                                          |");
strcpy(chiffre_7[15],"|                                          |");
strcpy(chiffre_7[16],"--------------------------------------------");

char chiffre_8[16][44];
strcpy(chiffre_8[0],"--------------------------------------------");
strcpy(chiffre_8[1],"|                                          |");
strcpy(chiffre_8[2],"|                                          |");
strcpy(chiffre_8[3],"|              8888888888                  |");
strcpy(chiffre_8[4],"|              88      88                  |");
strcpy(chiffre_8[5],"|              88      88                  |");
strcpy(chiffre_8[6],"|              88      88                  |");
strcpy(chiffre_8[7],"|              88      88                  |");
strcpy(chiffre_8[8],"|              8888888888                  |");
strcpy(chiffre_8[9],"|              88      88                  |");
strcpy(chiffre_8[10],"|              88      88                  |");
strcpy(chiffre_8[11],"|              88      88                  |");
strcpy(chiffre_8[12],"|              88      88                  |");
strcpy(chiffre_8[13],"|              8888888888                  |");
strcpy(chiffre_8[14],"|                                          |");
strcpy(chiffre_8[15],"|                                          |");
strcpy(chiffre_8[16],"--------------------------------------------");

char chiffre_9[16][44];
strcpy(chiffre_9[0],"/////////////////////////////////////////////");
strcpy(chiffre_9[1],"/////////////////////////////////////////////");
strcpy(chiffre_9[2],"/////////////////////////////////////////////");
strcpy(chiffre_9[3],"/////////////////////////////////////////////");
strcpy(chiffre_9[4],"/////////////////////////////////////////////");
strcpy(chiffre_9[5],"/////////////////////////////////////////////");
strcpy(chiffre_9[6],"/////////////////////////////////////////////");
strcpy(chiffre_9[7],"/////////////////////////////////////////////");
strcpy(chiffre_9[8],"/////////////////////////////////////////////");
strcpy(chiffre_9[9],"/////////////////////////////////////////////");
strcpy(chiffre_9[10],"/////////////////////////////////////////////");
strcpy(chiffre_9[11],"/////////////////////////////////////////////");
strcpy(chiffre_9[12],"/////////////////////////////////////////////");
strcpy(chiffre_9[13],"/////////////////////////////////////////////");
strcpy(chiffre_9[14],"/////////////////////////////////////////////");
strcpy(chiffre_9[15],"/////////////////////////////////////////////");
strcpy(chiffre_9[16],"/////////////////////////////////////////////");

  int TAB[3][3];

  int choix;
  int choix2;
   a :
  printw("1 : Image 2:Chiffres");
  scanw("%d",&choix );
  if(choix > 2){
    goto a;
  }
  b:
  printw("1 : Facile 2: Difficile");
  scanw(" %d",&choix2);
  if (choix2 >2)
{
  goto b;
}
     test(TAB);

     for (int i = 0; i < 3; ++i)
     {
         for (int j = 0; j < 3; ++j)
         {
             if (TAB[i][j] == 9)
             {
                 TAB[i][j] = 0;
             }
         }
     }
     
     for(int i = 0; i<3;i++){
    for(int j = 0; j<3;j++){
      if(TAB[i][j] == 0){
        X0 = i; 
        Y0 = j;
      }
    }
  }

int verif;

int test; 
  
  while (1)
  {
    if(choix == 1){
        affichage(TAB,tab_1,tab_2,tab_3,tab_4,tab_5,tab_6,tab_7,tab_8,tab_9);
    }
    else if(choix == 2){
    affichage(TAB,chiffre_1,chiffre_2,chiffre_3,chiffre_4,chiffre_5,chiffre_6,chiffre_7,chiffre_8,chiffre_9);}
    Verification(TAB); 
 
    click_souris();
   clear();
   // printw("Vous avez clique sur la poisition (%d,%d)\n", L, C);
    mouvement();
    // printw("%d%d  " ,X ,Y);
    // printw("%d", TAB[X][Y]);
    // printw("\n");
  if(choix2 == 1){
    test = CheckEZ(X0,Y0,TAB);
  }
  else if( choix2 == 2){
    test = CheckD(X0,Y0,TAB);
  }
    if(test == 1){
    swap(X0,Y0,TAB);
    X0 = X; Y0 = Y;
    }

  }
  endwin(); // Suspendre la sesion ncurses et restorer le terminal
  return 0;
}