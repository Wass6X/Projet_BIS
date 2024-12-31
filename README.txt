Mini-Projet : Jeu "Snake" en Langage C

Module : Programmation 2

Travail en binômeRéalisé par :

Ghedamsi Youcef

Beldjoudi Wissameddine(Groupe 03 - L1 Informatique)

Description du Projet

Ce projet consiste en une implémentation du jeu classique "Snake" en langage C.

Le programme utilise des fonctions pour :

Allouer dynamiquement une grille,

Créer et initialiser un serpent,

Gérer les déplacements du serpent,

Placer des fruits de manière aléatoire sur la grille,

Redessiner dynamiquement la grille sur l'écran pour refléter l'état du jeu.

Fonctionnement

Le jeu se lance à partir d'un terminal avec la commande suivante :

./exec <largeur> <hauteur> <vitesse> <nombre_de_joueurs>

Paramètres :

<largeur> et <hauteur> : dimensions de la grille (en cases).

<vitesse> : vitesse de rafraîchissement du jeu en dixièmes de seconde (préférablement 2 ou 3).

<nombre_de_joueurs> : 1 ou 2 joueurs.

Règles :

Le jeu commence avec un serpent sur une grille vide.

Le joueur contrôle le serpent à l'aide des touches directionnelles pour le déplacer dans la grille.

L'objectif est de manger les fruits placés aléatoirement sur la grille. Chaque fruit mangé :

Fait grandir le serpent.

Augmente le score.

Le jeu se termine si :

Le serpent entre en collision avec lui-même,

Ou s'il touche les bords de la grille.

Utilisation de GitHub

Nous avons utilisé GitHub pour organiser notre travail en binôme :

Répartition des tâches :

Chaque membre a travaillé sur différentes parties du code.

Fusion des contributions :

Nous avons fusionné nos modifications après chaque étape majeure.

Collaboration directe :

Nous avons travaillé ensemble sur certaines fonctions spécifiques pour garantir leur bon fonctionnement.

Si vous avez des suggestions ou souhaitez rapporter un bug, n'hésitez pas à ouvrir une issue sur notre dépôt GitHub.
