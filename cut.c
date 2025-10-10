# include<stdio.h>
# include<string.h>
#include<stdlib.h>

#define HAUTEUR 500
#define LARGEUR 500
#define MAXVAL 255


// structure pour representer un pixel
typedef struct {
    int R,G,B;
} pixel;


// structure pour representer une image
typedef struct {
    int largeur;
    int hauteur;
    int maxval;
    pixel pixels[HAUTEUR][LARGEUR];
} Image;


// fonction pour lire une image dans un fichier
void lec(const char *nomfichier , Image *img){

    FILE *f = fopen(nomfichier, "r");
    if (!f) {
        printf("fichier inexistant\n");
        exit(1);
    }


    char format[3];
    fscanf(f, "%2s", format);

    // on verifie que le format est p3
    if (strcmp(format, "P3") != 0) {
        printf("Format non supporté, doit être P3\n");
        fclose(f);
        return;
    }

        fscanf(f, "%d %d", &img->largeur,&img->hauteur);
        fscanf(f, "%d", &img->maxval);


        for (int i = 0; i < img->hauteur; i++)
        for (int j = 0; j < img->largeur; j++)
            fscanf(f, "%d %d %d", &img->pixels[i][j].R, &img->pixels[i][j].G, &img->pixels[i][j].B);


        fclose(f);


}

 // fonction utilitaire pour enregistrer une image modifiée
void ecrire(const char *nomfichier, Image * img){
    char imgmod[256];

    sprintf(imgmod, "%.*s_cut.ppm", (int)(strlen(nomfichier) - 4), nomfichier);

// Ouverture du fichier en écriture
FILE *fichier = fopen(imgmod, "w");
if (!fichier) {
    printf("Impossible de créer le fichier de sortie\n");
    return;
}

// Écriture de l'entete PPM
fprintf(fichier, "P3\n%d %d\n%d\n", img->largeur, img->hauteur, img->maxval);

// Écriture des pixels modifiés
for (int i = 0; i < img->hauteur; i++) {
    for (int j = 0; j < img->largeur; j++) {
        fprintf(fichier, "%d %d %d ", img->pixels[i][j].R, img->pixels[i][j].G, img->pixels[i][j].B);
    }
    fprintf(fichier, "\n");
}

fclose(fichier);
printf("Fichier de sortie créé : %s\n", imgmod);
}

 void cut(const char *nomfichier,int l1,int l2,int c1,int c2,const char *nomfichier_cut){

    Image img,nouv_img;  // nouvelle structure image pour representer l'image recadree


    // appel de la fonction pour la lecture du fichier 
    lec(nomfichier, &img);

    nouv_img.hauteur= l2-l1;
    nouv_img.largeur=c2-c1;

    // recadrage de l'image
    for (int i = 0; i < nouv_img.hauteur; i++) {
        for (int j =0; j < nouv_img.largeur; j++) {
            nouv_img.pixels[i][j]=img.pixels[i+l1][j+c1];
        }
    }

    //appel de la donction pour l'ecriture du fichier resultant
    ecrire(nomfichier_cut,&nouv_img);
}

int main () {

        FILE *fichier;
        char nomfichier[255];
        char nomfichier_cut[256];
        int l1, l2, c1, c2;
        Image img;

         printf(" 2. la fonction cut pour recadrer une image :\n");


    // Demande du nom du fichier original
    printf("Nom du fichier original  : ");
    scanf("%s", nomfichier);

    //appel de la fonction lec pour lire le fichier temporaire
    lec(nomfichier,&img);
    printf("Image chargée : %d x %d\n", img.largeur, img.hauteur);

    // Demande des coordonnées de recadrage

        //saisie des hauteurs
        printf("Entrer l1 (0 < l1 < l2 <= %d) : ", img.hauteur);
        scanf("%d", &l1);
        printf("Entrer l2 (l1 < l2 <= %d) : ", img.hauteur);
        scanf("%d", &l2);
    
        // saisie des largeurs
        printf("Entrer c1 (0 < c1 < c2 <= %d) : ", img.largeur);
        scanf("%d", &c1);
        printf("Entrer c2 (c1 < c2 <= %d) : ", img.largeur);
        scanf("%d", &c2);

        // Vérification des coordonnées
    if (l1 < 0 || l2 > img.hauteur || c1 < 0 || c2 > img.largeur || l1 >= l2 || c1 >= c2) {
        printf("Coordonnées invalides.\n");
        return 1;
    }

        
        // Demande du nom du fichier de sortie
        printf("Nom du fichier recadré : ");
        scanf("%255s", nomfichier_cut);

        // Appel de la fonction cut
        cut(nomfichier, l1, l2, c1, c2, nomfichier_cut);

        printf("Recadrage terminé.\n");

        return 0;
        
    
   
}
