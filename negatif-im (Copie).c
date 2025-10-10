# include <stdio.h>
# include <stdlib.h>
# define HAUTEUR 400
# define LARGEUR 400
# define MAXVAL 255

typedef struct {
    int r,g,b;
}pixel;

typedef struct{
    int hauteur;
    int largeur;
    int maxval;
    pixel pixel[HAUTEUR][LARGEUR];
}Image;
void negatif (const char *fichierppm ,const char *fichiersortir) {

    /* ouverture de l'entete*/
    FILE *f = fopen(fichierppm,"r");
    if(f == NULL) { 
        printf("impossible d'ouvrir le fichier %s\n", fichierppm);
        return;
    }

        /*lecture de l'image*/
        char format[3],ligne[200];
        Image img ;
    
        fgets(ligne, sizeof(ligne), f);
        do{
            fgets(ligne,sizeof(ligne),f);
        }while(ligne[0]=='#');
        sscanf(ligne, "%d %d", &img.largeur, &img.hauteur);
        fscanf(f, "%d", &img.maxval);
        fgetc(f);
        
        /*creer le fichier de sortir*/
        FILE *F = fopen(fichiersortir, "w");
    if (F == NULL) {
        printf("Erreur : impossible de créer l'image de sortie.\n");
        fclose(f);
        return ;
    }
    fprintf(F,"P3\n\n%d %d\n%d\n",img.largeur,img.hauteur,img.maxval);
    for(int i=0; i<img.hauteur;i++){
        for(int j=0; j<img.largeur;j++){
            if(fscanf(f,"%d %d %d",&img.pixel[i][j].r,&img.pixel[i][j].g,&img.pixel[i][j].b)==3){
                img.pixel[i][j].r = MAXVAL - img.pixel[i][j].r;
                img.pixel[i][j].g = MAXVAL - img.pixel[i][j].g;
                img.pixel[i][j].b = MAXVAL - img.pixel[i][j].b;
                fprintf(F,"%d %d %d  ",img.pixel[i][j].r,img.pixel[i][j].g,img.pixel[i][j].b);
            }
        }
        fprintf(F,"\n");
    }

    /*fermeture des fichier*/
    fclose(f);
    fclose(F) ; 
}    
    
int main() {
   char Fichierppm[100];
   char fichiersortir[200];
   char couleur;
   int pixel;
   int nbrepixel;
   int valeur;

    printf("Entrez le nom du fichier PPM : ");
    scanf("%s", Fichierppm);
    printf("Entrez le nom du fichier sortie PPM : ");
    scanf("%s", fichiersortir);
    negatif (Fichierppm,fichiersortir);
    return 0;
}