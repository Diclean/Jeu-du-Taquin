# Jeu du taquin en C
Projet jeu Taquin C avec Ncurses
Jeu du Taquin réalisé dans le cadre de mon projet de programmation. 
le jeu ce joue à la souris il faut cliqué sur une image pour la déplacer si elle respecte le condition du niveau de difficulté selectionné.
Il y a 2 modes d'affichage et 2 niveaux de difficulté:

-Image/chiffres
-Facile/Difficile

Si niveau facile vous pouvez déplacer ka case grisé dans toute celle qui lui sont adjacente 

Si niveau difficile vous ne pourrez plus déplacer la case grisé dasn toutes les case adjacente en diogonal.
![image](https://user-images.githubusercontent.com/42451595/119254940-4ff91580-bbb9-11eb-9880-4a4251560de7.png)
![image](https://user-images.githubusercontent.com/42451595/119254958-669f6c80-bbb9-11eb-8431-4e220443c83e.png)



Le Jeu du Taquin :
Le taquin est un jeu solitaire en forme de damier créé vers 1870 aux États-Unis. Sa théorie mathématique a été publiée par l' ”American Journal of mathematics pure and applied” en 1879. En 1891, son invention fut revendiquée par Sam Loyd, au moment où le jeu connaissait un engouement considérable, tant aux États-Unis qu'en Europe. Il est composé de 15 petits carreaux numérotés de 1 à 15 qui glissent dans un cadre prévu pour 16. Il consiste à remettre dans l'ordre les 15 carreaux à partir d'une configuration initiale quelconque. 

Techno :

Langage C 

Le C est un langage impératif, généraliste, issu de la programmation système. Inventé au début des années 1970 pour réécrire UNIX, il est devenu un des langages les plus utilisés.

Ncurses

Ncurses est une bibliothèque libre fournissant une API pour le développement d'interfaces utilisateur à menu déroulant (GUI), en utilisant les caractères et couleurs d'un mode semi graphique. Non seulement ce type d'interface utilisateur se conçoit de manière indépendante du terminal, mais il accélère le rafraîchissement d'écran, diminuant par là le temps de latence que subissent d'ordinaire les utilisateurs de shells à distance.


Commande pour compiler : gcc -o EXEC jeu.c
Commande pour  executer le programme ./EXEC

# Taquin game in C
Taquin C game project with Ncurses
Taquin game made for my programming project. 
The game is played with the mouse. You have to click on an image to move it if it respects the condition of the selected difficulty level.
There are 2 display modes and 2 difficulty levels:

-Image/numbers
-Easy/Difficult

If the level is easy you can move the greyed out square to any adjacent square 

If the level is difficult you will not be able to move the grey square in all adjacent squares in diagonal.
![image](https://user-images.githubusercontent.com/42451595/119254940-4ff91580-bbb9-11eb-9880-4a4251560de7.png)
![image](https://user-images.githubusercontent.com/42451595/119254958-669f6c80-bbb9-11eb-8431-4e220443c83e.png)



The Teaser Game:
Taquin is a checkerboard solitaire game created around 1870 in the United States. Its mathematical theory was published in the "American Journal of mathematics pure and applied" in 1879. In 1891, its invention was claimed by Sam Loyd, at a time when the game was becoming very popular in both the United States and Europe. It consists of 15 small tiles numbered from 1 to 15 that slide into a frame designed for 16. It consists of putting the 15 tiles in order from any initial configuration. 

Techno :

C language 

C is a general-purpose imperative language derived from systems programming. Invented in the early 1970s to rewrite UNIX, it has become one of the most widely used languages.

Ncurses

Ncurses is an open source library providing an API for the development of drop-down user interfaces (GUIs), using the characters and colours of a semi-graphical mode. Not only does this type of user interface design work independently of the terminal, but it also speeds up screen refreshes, thereby reducing the latency that remote shell users usually experience.


Command to compile: gcc -o EXEC jeu.c
Command to run the ./EXEC program

