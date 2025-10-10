
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXHAUTEUR 1000
#define MAXLARGEUR 1000
#define MAX 256

typedef struct {
    int r;
    int g;
    int b;
} pixel;

typedef struct {
    int largeur;
    int hauteur;
    int maxval;
} image;


void lireimage(char *nomfichier, int *largeur, int *hauteur, int *maxval, pixel image[MAXHAUTEUR][MAXLARGEUR]) {
    FILE *f = fopen(nomfichier, "r");
    if (!f) {
        printf("Impossible d'ouvrir le fichier %s\n", nomfichier);
        return;
    }

    char ligne[MAX];
    fgets(ligne, MAX, f); // lire P3
    if (ligne[0] != 'P' || ligne[1] != '3') {
        printf("Format non supporté, doit être P3\n");
        fclose(f);
        return;
    }

    // Ignorer les commentaires
    do {
        fgets(ligne, MAX, f);
    } while (ligne[0] == '#');

    // Lire la largeur et la hauteur
    sscanf(ligne, "%d %d", largeur, hauteur);

    // Lire la valeur maximale
    fscanf(f, "%d", maxval);

    // Lire les pixels
    for (int i = 0; i < *hauteur; i++) {
        for (int j = 0; j < *largeur; j++) {
            fscanf(f, "%d %d %d", &image[i][j].r, &image[i][j].g, &image[i][j].b);
        }
    }

    fclose(f);
}


void sauvegarderImage(char *nomfichier, int largeur, int hauteur, int maxVal, pixel image[MAXHAUTEUR][MAXLARGEUR]) {
    FILE *f = fopen(nomfichier, "w");
    if (!f) {
        printf("Erreur, impossible de créer le fichier %s\n", nomfichier);
        return;
    }

    fprintf(f, "P3\n");
    fprintf(f, "%d %d\n%d\n", largeur, hauteur, maxVal);

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            fprintf(f, "%d %d %d ", image[i][j].r, image[i][j].g, image[i][j].b);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}


void niveauxDeGris(int largeur, int hauteur, pixel image[MAXHAUTEUR][MAXLARGEUR]) {
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            int m = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            image[i][j].r = image[i][j].g = image[i][j].b = m;
        }
    }
}


int main() {


    char cmd[MAX], fichier1[MAX], nouveauFichier[MAX];
    int largeur, hauteur, maxVal;
    pixel image[MAXHAUTEUR][MAXLARGEUR];

    printf("programme lance");

    while (1) {
        printf("ppmviewer > ");

        scanf("%s", cmd);

        if (strcmp(cmd, "quit") == 0) {
            break;

        } else if (strcmp(cmd, "gris") == 0) {
            scanf("%s", fichier1);
            lireimage(fichier1, &largeur, &hauteur, &maxVal, image);
            niveauxDeGris(largeur, hauteur, image);
            sprintf(nouveauFichier, "%s_gris.ppm", fichier1);
            sauvegarderImage(nouveauFichier, largeur, hauteur, maxVal, image);
            printf("Image convertie en noir et blanc.\n");
        } else {
            printf("Commande inconnue.\n");
        }
    }

    printf("Au revoir\n");
    return 0;
}


