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

    // On vérifie que le format est bien "P3"
            if (format[0] != 'P' || format[1] != '3') {
            printf("Format non supporte , doit etre P3\n");
            fclose(f);
        return;
    }

        // Ignorer les commentaires
        char ligne[255];
    do {
        fgets(ligne, sizeof(ligne), f);
    } while (ligne[0] == '#' || ligne[0] == '\n');

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

    sprintf(imgmod, "%.*s_dom.ppm", (int)(strlen(nomfichier) - 4), nomfichier);

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

 
// fonction pour eclaircir ou foncer une image
void dom( char couleur,int val, const char *nomfichier) {

    Image img; // permet de creer une variable de type image et non un pointeur d'ou l'absence de "*"

    //appel de la fonction lec pour lire le fichier
    lec(nomfichier,&img);

   // parcours de tous les pixels de l'image

    for (int i = 0; i < img.hauteur; i++) {
        for (int j = 0; j < img.largeur; j++) {
            pixel *p = &img.pixels[i][j];  //   p est le pointeur sur la structure pixel qui est un element de l'image  de hauteur i st de largeur j

            if (p->R >= p->G && p->R >= p->B && (couleur == 'R' || couleur == 'r')) {
                p->R += val;
                if (p->R > MAXVAL)   // pour signifier que si la valeur de la coordonnee augmentee est superieur a 255 le programme renverra cette valeur a 255
                p->R = MAXVAL;
                if (p->R < 0)  // ici elle la renverra a 0
                p->R = 0;

            } else if (p->G >= p->R && p->G >= p->B && (couleur == 'G' || couleur == 'g')) {
                p->G += val;
                if (p->G >MAXVAL)
                p->G = MAXVAL;
                if (p->G < 0) 
                p->G = 0;
            } else if (p->B >= p->R && p->B >= p->G && (couleur == 'B' || couleur == 'b')) {
                p->B += val;
                if (p->B > MAXVAL) 
                p->B = MAXVAL;
                if (p->B < 0)
                 p->B = 0;
            }
        }
    }

ecrire(nomfichier,&img);
}


int main (){

    FILE *fichier;
    char nomfichier[255];
    int val;
    char c;

    printf(" 1. la fonction dom pour eclaircir ou foncer: \n");

        
    printf("entrer la couleur a modifier (la premiere lettre de la couleur(  seulement r ou R,g ou G,b ou B  qui sont acceptables)) :\n");
    scanf(" %c",&c);

    printf("entrer la valeur a ajouter:\n");
    scanf("%d",&val);

    printf("entrer le nom du fichier:\n");
    scanf("%255s",nomfichier);

    // Exemple  d'execution 
    dom(c, val, nomfichier);
        
}