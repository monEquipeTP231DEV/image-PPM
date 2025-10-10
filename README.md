# image-PPM
realiser une application d'images PPM

# Collection de programmes en C

## Description générale

Ce repository contient un ensemble de fonctions permettant le manipulation d'une image ppm p3.cet ensemble de fonctions regroupe en 6 programmes codees en c et decrivant les differentes manipulations possibles sur une image ppm p3

## Liste des programmes et description

1. foncer ou eclaircir les pixels d'une image ppm p3

2. passer en noir et blanc en utilisant les niveaux de gris

3. creer le negatif d'une image

4. afficher la taille d'une image

5. recadrer une image

6. appliquer a une image le filtre median:

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
     
### Objectif :
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

     




