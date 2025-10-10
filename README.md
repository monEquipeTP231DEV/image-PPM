# image-PPM
realiser une application d'images PPM

# Collection de programmes en C

## Description générale

Ce repository contient un ensemble de fonctions permettant le manipulation d'une image ppm p3.cet ensemble de fonctions regroupe en 6 programmes codees en c et decrivant les differentes manipulations possibles sur une image ppm p3

## Liste des programmes et description

1. foncer ou eclaircir les pixels d'une image ppm p3

   dans ce programme il etait question de prendre une image  la foncer ou l'eclaircir en fonction de la couleur primaire du pixel entre par l'utilisateur .Pour ce faire j'ai tout d'abord declarer une structure pixel avec pour ses trois couleurs primaires ici n prenant comme pour types des entiers ensuite une structure pour representet une image en considerant celle ci comme un taableau a double entree de pixels de taille hauteur*largeur avec chaque couleur primaire d'un pixel pouvant prendre comme valeur maximal maxval(255).Ensuite j'ai non seulement definir une fonction de lecture prenant en entree un fichier (de type .ppm evidemment) et une image  a conserver dans ce fichier: la fonction va d'bord verifier si le format du fichier est p3 parcequ'il y'en a p6 ,si c'est pas le cas s'arrete et envoie une message dd'erreur stoppant le programme lors de l'execution et si c'est le  cas  lire valeurs des champs de l'image(dimensions et valmax d'abord) et enfin  parcourir l'image comme je disait la considerant comme un tableau a double entree.j'ai ensuite defini une fonction pour enregistrer un fichier qui lorsque sera appeler de la fonction proprement dites permettra de creer ou enregistrer un fichier qui conservera les modificaations effectuer sur le precedent.I est a noter que le fichier de depart s'ouvrira en lecture et le fichier a enregistre en ecriture c'est ainsi en c.pour la fonction proprement dite l'on appelra en premier lieu la fonction de lecture pour lire le fichier ou image si vs voulez a modifier ensuite la modification se fera ainsi:la fonction parcourera chaque pixel et ensuite chaque champ du pixel ,comparer la couleur entree (par l'utilisateur lors de l'execution)  a chaque couleur du pixel en s'assurant au passage que la couleur entree est effectivement celle parmi les couleurs primaires du pixel  lorsqu'elle trouvera la couleur recherche elle aujoutera(reduira resp) la valeur entree par l'utilisateur pour la modification ,le resultat de cette valeur sera comparee a valmax si elle est sup la fonction renverra cette valeur a 255 si elle est inferieur a 0 elle la renverra a 0.Enfin elle appelera la fonction pour sauveger les modifications dans le nouveau fichier.le main dans ce programme c'est pour tester la fonction a travers les donnees entre par l'utilisateur et l'appel de la fonction proprement dite.
   ##--- redige par kaze yemtsa darelle kesty 23u2684 
  

3. passer en noir et blanc en utilisant les niveaux de gris

4. creer le negatif d'une image

5. afficher la taille d'une image

6. recadrer une image

dans ce programme il etait question de prendre une image la recadrer en fonction de la hauteur de depart ,la hauteur de fin la largeur de depart la largeur de fin entrees par l'utilisateur. Pour ce faire j'ai tout d'abord declarer une structure pixel avec pour ses trois couleurs primaires ici n prenant comme pour types des entiers ensuite une structure pour representet une image en considerant celle ci comme un taableau a double entree de pixels de taille hauteur*largeur avec chaque couleur primaire d'un pixel pouvant prendre comme valeur maximal maxval(255).Ensuite j'ai non seulement definir une fonction de lecture prenant en entree un fichier (de type .ppm evidemment) et une image  a conserver dans ce fichier: la fonction va d'bord verifier si le format du fichier est p3 parcequ'il y'en a p6 ,si c'est pas le cas s'arrete et envoie une message dd'erreur stoppant le programme lors de l'execution et si c'est le  cas  lire valeurs des champs de l'image(dimensions et valmax d'abord) et enfin  parcourir l'image comme je disait la considerant comme un tableau a double entree.j'ai ensuite defini une fonction pour enregistrer un fichier qui lorsque sera appeler de la fonction proprement dites permettra de creer ou enregistrer un fichier qui conservera les modificaations effectuer sur le precedent.Il est a noter que le fichier de depart s'ouvrira en lecture et le fichier a enregistre en ecriture c'est ainsi en c.pour la fonction proprement dite l'on appelra en premier lieu la fonction de lecture pour lire le fichier ou image si vs voulez a modifier ensuite la modification se fera ainsi:la nous allons tout d'abord definir les nouvelles valeurs de la hauteur et de la largeur(valeurs obtenues par la difference resp de la hauteur de fin et celle de depart et la largeur de fin et celle de depart) qui vont permettre de recadrer l'image ensuite parcourir la nouvelle image qui sera d'ailleurs predefini comme une structure image en prenant deux compteurs allant de 0(norme en c) a la nouvelle hauteur resp et a la nouvelle largeur et en copiant  le pixel situé à la position [premier compteur+la hauteur de depart][deuxieme compteur+largeur de depart] de l'image de depart dans le pixel de la nouvelle image.La copie se fera au fur et a mesure que avancera avec les compteurs.Apres ca on appelera la fonction d'ecriture pour y creer un fichier qui enregistrera les  modifications du fichier precedent.Ainsi donc dans le main il s'agira de tester le programme a travers les donnees entrees par l'utilisateur notamment :le fichier de depart ,la hauteur de depart ,la hauteur de fin la largeur de depart la largeur de fin ,le fichier modifie ou recadre.
###--- redigee par kaze yemtsa darelle kesty 23u2684


8. appliquer a une image le filtre median:

###  DESCRIPTION DU PROGRAMME 6 : Appliquer a une image le filtre median a une image ppm p3
### --- redigee par LAGO MARTINE PAHOLA de matricule 24G2294 --- ###
  Ce programme en c applique un filtre median sur une image au format PPM ASCII (P3);
  Il genere automatiquement une image temoin de dimension 200*300 ;
  Chaque pixel de notre image est remplace par la valeur mediane de ces 8 voisins plus lui meme;
  Le resultat est sauvegarde dans un fichier .ppm appele image_median.ppm qui sera ouvert grace a GIMP, MAGIC sur ubuntu;
  ### FONCTIONNALITES
  1. Generation d'une image aleatoire;
  2. Filtrage median sur chaque pixel de notre image;
  3. Sauvegarde des images au format PPM ASCII P3:
    Image_depart.ppm: image d'origine;
    image_median.ppm : image filtree;
  4. Compatible avec les lodiciels de traitement d'images comme "GIMP, MAGIC..."
     # ORGANISATION DU CODE
     #   Fonctions principales:
     . Pixel get_pixel(): recupere un pixel (x,y) dans un tableau 1D;
     . pixel set_pixel(): modifie un pixel(x,y) dans un tableau 1D;
     . void sauvegarder)_ppm(): sauvegarde une image au format p3 ASCII ;
     . int comparer(): comparateur pour qsort
     . pixel median_pixel(): calcule le prix median a (x,y);
     . pixel* appliquer_median(): appliquer le filtre a tout  l'image;
     # MAIN
     a. Definition de la taille de l'image;
     b. Allocation dynamique de l'image;
     c. Generation aleatoire des pixels;
     d. Sauvegarde de l'image originale;
     e. Application du filtre median;
     f. Sauvegarde de l'image filtree;
     g. Liberation de la memoire;
     # COMPILATION ET EXECUTION
     . Utiliser le gcc pour compiler le programme:
     gcc filtre_median.c -o image_creee
     ./image_creee
     A la fin de ces deux operations precedents , vous obtiendrez comme messages:
     .image dde depart enregistree dans " image_depart.ppm";
     .image filtree enregistree dans "image_median.ppm".
     traitament terminee.
     
### Objectif :4. afficher la taille d'une image
### --- redigee par KENMOGNE KAMTO BLONDELLE PATRICIA de Matricule 23U2608 --- ###
Cette fonction a pour but de lire les informations contenues dans l’en-tête d’un fichier image au format PPM (Portable Pixmap) afin d’en afficher les dimensions, c’est-à-dire la largeur et la hauteur de l’image.

### Description du fonctionnement :
La fonction commence par ouvrir le fichier image en mode lecture. Elle vérifie ensuite que le fichier est bien au format PPM, puis ignore les lignes de commentaires qui commencent par le symbole #.
Elle lit ensuite les dimensions de l’image (largeur et hauteur) ainsi que la valeur maximale des couleurs. Si ces informations sont valides, la fonction affiche la taille de l’image dans la console.
En cas d’erreur (fichier introuvable, format invalide ou données manquantes), un message explicite est affiché à l’écran.

### Test effectué :
Pour vérifier le bon fonctionnement de la fonction, un petit fichier PPM a été utilisé comme exemple. Après exécution du programme, la taille correcte de l’image a été affichée, prouvant que la fonction fonctionne correctement et lit bien les informations de l’en-tête.

### Résultat attendu :
Affichage de la taille de l’image sous la forme :
« Taille de l’image : largeur x hauteur pixels »

### Objectif 3. creer le negatif d'une image
### --- redigee par SOUOTCHUENG KOM ANNAELLE de matricule 24G2820 --- ###
Ce programme a pour but de créer le néga f d’une image contenu dans un ﬁchier ppm (portable pixel
MAP)
### Description du programme
Ce programme est cons tué de deux structures ( la structure image ayant pour champ la hauteur, la
largeur , la valeur maximal «maxval » et un tableau a deux dimensions de pixels, la structure pixel
ayant pour champ r, g ,b( qui sont les couleurs) ) d’une fonc on qui est appelé dans le main et qui
débute par l’ouverture d’un ﬁchier image en mode lecture et passe a la lecture de l’image , Ensuite il
ouvre le ﬁchier de sor en mode écriture. POUR ﬁn elle crée le néga f de l’image en retranchant la
valeur de chaqu’un par la valeur maximale et elle ferme les deux ﬁchiers.

### TPN°3 DE INF231  passer en noir et blanc en utilisant les niveaux de gris
### --- REDIGEE PAR NGOUNOU KOUOKAM MARY CHRISTY de matricule 24G2039 --- ###
Dans le cadre de l'unité d'enseignement INF231 dispensée par le Dr Melataguia aux étudiants de niveau 2 informatique fondamentale à l'université de Yaoundé 1, il nous a été demandé à nous étudiants de produire en groupe une application de gestion d'images PPM( portable pixmap format) de version ASCII( P3) codée en langage c . Le dit programme devant être chargé de lire une image sans lire les commentaires, changer la luminosité des pixels dominants, transformer l'image en noir sur blanc, faire le négatif d'une image, afficher la taille d'une image , couper une portion de l'image et enfin appliquer sur l'image un filtre méfiant. C'est le travail que notre groupe a essayé de réaliser. 
Après répartition des tâches, celle qui me fut assignée fut la réalisation du programme chargé de la transformation d'une image en noir sur blanc via l'utilisation des niveaux de gris.

Le programme que j'ai réalisé mis à part la définition de la structure pixel,caractérisée par les niveaux en nombre entiers des trois couleurs qui la composent (rouge, vert et bleu) et la définition de la structure image caractérisée par son nombre ( entier)de pixels  en hauteur, en largeur ainsi que la valeur maximale de chaque coordonnées de couleur, est composé de 03 principales fonctions .
La première ( void lireImage) est  chargée d'une part d'ouvrir un fichier image ppm en mode lecture. Si le fichier saisi par l'utilisateur est introuvable, il renvoie "impossible d'ouvrir le fichier".
D'autre part , elle  vérifie que le format d'image entré par l'utilisateur est P3, ignore les commentaires dans la lecture, lis la valeur maximale ainsi que les pixels constitutifs de l'image. 
La deuxième fonction ( void sauvegarderImage) quand à elle est chargée d'enregistrer les modifications faite sur une image dans un nouveau fichier.ppm.
Enfin,la troisième fonction ( void niveau de gris) met l'image en noir sur blanc en attribuant à chaque coordonnées de couleurs de chaque pixel la moyenne des 03 coordonnées initiales. . 


Le programme principal main ici  récupère la commande entrée par l'utilisateur:
-Si l'utilisateur entre la commande quit, il y'a un message "au revoir" à l'écran, puis fin d'exécution du programme .


-Si il entre la commande gris , le programme fait appel à la fonction niveauxdegris qui rend l'image noir sur blanc . Cette image modifiée est par la suite stockée dans un autre fichier.ppm via l'appel de la fonction sauvegarderImage. 
-Si la commande saisie ne correspond nie
 à quit , ni à gris , le programme affiche "au revoir" ce qui marque la fin de l'exécution du programme .

### COMPILATION :
Sous Windows : 
gcc ppmviewer.c -o ppmviewer.exe

Pour compiler chaque fichier (si l'on utilise un terminal):
fonction foncer et eclaircir: gcc dom.c -o dom
execution:./dom
fonction recadrer : gcc cut.c -o cut
execution:./cut


## Sous linux
gcc ppmviewer.c -o ppmviewer

### COMMENT UTILISER LE PROGRAMME 
Sous windows:
-lancer le programme sur l'invite de commande
-compiler
-taper ppmviewer
-taper enfin une commande 
### Sous linux 
-ouvrir un terminal dans le dossier du fichier 
- taper le code mis dans la partie compilation ( sous linux)
- lancer le programme ./ppmviewer
- entrer une commande.

### TECHNOLOGIE UTILISÉE 
Langage : langage c 
Bibliothèques: stdio.h, stdlib.h, string.h
compilateur : GCC 





     




