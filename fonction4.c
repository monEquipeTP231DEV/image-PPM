#include <stdio.h>

// ---- Fonction qui lit et affiche la taille d’une image PPM ----
void afficher_taille_image(const char *nomFichier) {
    FILE *f = fopen(nomFichier, "r");
    if (!f) {
        printf("Erreur : impossible d,ouvrir le fichier %s\n", nomFichier);
        return;
    }

    char format[3];
    int largeur, hauteur, maxval;

    // Lecture du format (P3 ou P6)
    if (fscanf(f, "%2s", format) != 1) {
        printf("Erreur : format PPM invalide.\n");
        fclose(f);
        return;
    }

    // Vérification du format
    if (format[0] != 'P' || (format[1] != '3' && format[1] != '6')) {
        printf("Erreur : type PPM non reconnu (%s)\n", format);
        fclose(f);
        return;
    }

    // ---- Ignorer les commentaires et lignes vides ----
    int c = fgetc(f);
    while (c == '#' || c == '\n' || c == '\r') {
        if (c == '#') {
            // Ignorer la ligne de commentaire complète
            while (c != '\n' && c != EOF)
                c = fgetc(f);
        }
        c = fgetc(f);
    }
    ungetc(c, f); // remettre le dernier caractère lu

    // ---- Lecture des dimensions ----
    if (fscanf(f, "%d %d", &largeur, &hauteur) != 2) {
        printf("Erreur : dimensions introuvables.\n");
        fclose(f);
        return;
    }

    // ---- Lecture de la valeur maximale ----
    if (fscanf(f, "%d", &maxval) != 1) {
        printf("Erreur : valeur maximale manquante.\n");
        fclose(f);
        return;
    }

    // ---- Affichage du résultat ----
//    printf("Format : %s\n", format);
    printf("size: %s\n", nomFichier );
    printf("Valeur maximale : %d\n", maxval);
    printf("Taille de l'image : %d x %d pixels\n", largeur, hauteur);

    fclose(f);
}

// ---- Programme principal pour tester ----
int main() {
    char nomFichier[100];

    printf("Entrez le nom du fichier PPM : ");
    scanf("%s", nomFichier);

    afficher_taille_image(nomFichier);

    return 0;
}
