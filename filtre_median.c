#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// on cree une structure pixel
typedef struct {
    int r, g, b;
} Pixel;
// ici on va chercher a acceder a un pixel dans un tableau a une dimension
Pixel get_pixel(Pixel *image, int x, int y, int largeur) {
    return image[y * largeur + x];
}
void set_pixel(Pixel *image, int x, int y, int largeur, Pixel p) {
    image[y * largeur + x] = p;
}
// ici on cree un fichier texte PPM au format P3 ASCII
void sauvegarder_ppm(const char *nom, Pixel *image, int largeur, int hauteur) {
    FILE *f = fopen(nom, "w");
    if (!f) {
        perror("Erreur ouverture fichier");
        exit(1);
    }
    fprintf(f, "P3\n%d %d\n255\n", largeur, hauteur);
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            Pixel p = get_pixel(image, x, y, largeur);
            fprintf(f, "%d %d %d\n", p.r, p.g, p.b);
        }
    }
    fclose(f);
}

int comparer(const void *a, const void *b) {
    int x = (int)a, y = (int)b;
    return (x > y) - (x < y);
}
// ici c'est la fonction pour calculer la valeur mediane a partir des 8 voisins d'un pixel
Pixel median_pixel(Pixel *image, int x, int y, int largeur, int hauteur) {
    int r[9], g[9], b[9], count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < largeur && ny >= 0 && ny < hauteur) {
                Pixel p = get_pixel(image, nx, ny, largeur);
                r[count] = p.r; g[count] = p.g; b[count] = p.b;
                count++;
            }
        }
    }
    qsort(r, count, sizeof(int), comparer);
    qsort(g, count, sizeof(int), comparer);
    qsort(b, count, sizeof(int), comparer);
    Pixel p = {r[count/2], g[count/2], b[count/2]};
    return p;
}
// ici on applique ce filtre median a tout les pixels de notre image
Pixel* appliquer_median(Pixel *image, int largeur, int hauteur) {
    Pixel *res = malloc(largeur * hauteur * sizeof(Pixel));
    if (!res) {
        perror("Erreur allocation");
        exit(1);
    }
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            res[y * largeur + x] = median_pixel(image, x, y, largeur, hauteur);
        }
    }
    return res;
}
// ici on definit une image par defaut de dimension 200*300
int main() {
    int largeur = 200;
    int hauteur = 300;
    printf("Génération d'une image %dx%d...\n", largeur, hauteur);

    srand(time(NULL));
    Pixel *image = malloc(largeur * hauteur * sizeof(Pixel));
    if (!image) {
        perror("Erreur allocation image");
        exit(1);
    }

    // Génération automatique (dégradé ou bruit aléatoire)
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            Pixel p = {rand() % 256, rand() % 256, rand() % 256};
            set_pixel(image, x, y, largeur, p);
        }
    }

    sauvegarder_ppm("image_depart.ppm", image, largeur, hauteur);
    printf("Image de départ enregistrée dans 'image_depart.ppm'.\n");

    Pixel *image_median = appliquer_median(image, largeur, hauteur);
    sauvegarder_ppm("image_median.ppm", image_median, largeur, hauteur);
    printf("Image filtrée enregistrée dans 'image_median.ppm'.\n");

    free(image);
    free(image_median);
    printf("Traitement terminé.\n");
    return 0;
}