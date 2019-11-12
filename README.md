Conception d'un module pour Python (3.7.4) en C/C++ sous windows
-----------------------------------------------------------------
Réalisé par:
- Karen Simard-noreau
- Johan Sintondji
- Malek Khattech

Lancer le programme 
--------------------
1. Ouvrir le logiciel visual studio 2017
2. Créer un nouveau projet 
3-Ajouter video.cpp,video.h et main.cpp dans le projet qui a été créer 
4-Déplacer la vidéo "rue.avi" dans le répertoire du projet 
5-Telecharger et installer python 3.7.4 
6-Dans l'onglet de la solution du projet faire un clique droit et choisir propriété
7-Dans type de configuration choisir "Librairie dynamique(.dll)"
8-Dans l'extension cible mettre ".pyd"
9-Dans nom cible mettre "my_video.pyd"
10-Apres avoir selectionner le mode de compilation release aller dans l'onglet "repertoire VC++" il s'agit de mettre les chemins d'accès du python téléchargé plus haut
11-Dans repertoire include choisir mettre le path du fichier "include" qui se trouve dans le repertoire du fichier python 3.7.4
12-Dans repertoire bibliothèque mettre le path du dossier "libs" qui se trouve dans le repertoire du fichier python 
13-Cliquer sur le boutton "appliquer" et ensuite sur "ok"
14-Compiler le projet 
15-Le module sera donc créé 
16-Pour lancer le programe il sufit seulement d'aller dans le dossier Fichier_source et double-click sur start.py
(ou lancer en ligne de commande py start.py). Lorsque le programme roule, le menu guidera pour la suite(Play pause,accelerer,retour depart)


Voir le code source
--------------------
De plus, le code source qui a été compiler se retrouve dans le fichier Projet_code.
