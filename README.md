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

