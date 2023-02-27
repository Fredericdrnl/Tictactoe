#include <stdio.h>
#include <stdlib.h>

// Frédéric DOURNEL TP-B

// ################################################### //
// ################### TICTACTOE ##################### //
// ################################################### //


// CONSTANTES
#define TAILLE_LARGEUR 3
#define TAILLE_LONGUEUR 3
char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR];


// "initGrille" Fonction permettant de créer une grille vide (avec des ' ' dans les cases)
void initGrille(char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR])
{ 
  //Parcourt du tableau.
  for (int i =0; i <=TAILLE_LARGEUR - 1; i++) 
  {
    for (int j =0; j<=TAILLE_LONGUEUR - 1; j++) 
    {
      //Insert les valeurs dans les cases.
      grille[i][j] = ' ';
    }
  }
}


// "afficheGrille" Fonction permettant d'afficher la grille avec les coordonnées.
void afficheGrille(char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR]){

  // Initialisation
  int ligne=0;

  //Coordonnées pour les colonnes.
  printf("\n    0   1   2   x");
  
  //Parcourt du tableau.
  for (int i =0; i <= TAILLE_LARGEUR - 1; i++) 
  { 
    //Affichage des coordonnées des lignes.
    printf("\n%i ", ligne);
    ligne=ligne+1;

    for (int j =0; j<= TAILLE_LONGUEUR - 1; j++) 
    {
      //Afichage d'une valeur.
      printf("| %c ", grille[i][j]);
      if (j == TAILLE_LONGUEUR - 1)
      {
        printf("|");
      }
    }
  }
  printf("\ny\n");
}


//"ajoutePiece" Fonction permettant d'ajouter une pièce dans la grille.
void ajouterPiece(char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR], int joueur){
    int x, y;
    //Demande d'une colonne au joueur.
    printf("\nx : ");
    scanf("%i", &x);

    //Demande d'une ligne au joueur.
    printf("\ny : ");
    scanf("%i", &y);

    //On vérifie si les coordonnées sont valides
    while ((grille[y][x] !=' ') || (y >= 3) || (x < 0) || (x >= 3) || (y < 0))
    {   
        printf("\nCoordonnées incorrect, nouveau x : ");
        scanf("%i", &x);

        printf("\nnouveau y : ");
        scanf("%i", &y);
    }
    printf("Valeur acceptee !\n");

    //On regarde de quel joueur il s'agit.
    if ((joueur == 1) && (grille[y][x] == ' '))
    {
      //Joueur 1 = X
      grille[y][x]='X';
    }
    if ((joueur == 2) && (grille[y][x] == ' '))
    {
      //Joueur 2 = O
      grille[y][x]='O';
    }
}


// "verifHorizontal" Vérifie si un joueur à gagné la partie avec une diagonale.
int verifHorizontal(char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR], int joueur){
    // RETURN : 0 si il n'y a pas de ligne horizontale
    //          1 si il y a une ligne horizontale

    // Initialisation
    int verif;
    int i = 0;
    int j = 0;
    char symbole;

    // On regarde quel joueur à joué
    if(joueur == 1){
        symbole = 'X';
    }else{
        symbole = 'O';
    }
    
    // Vérification
    verif = 1;

    // On parcourt le tableau de haut en bas
    while ((j < TAILLE_LARGEUR)){
        while ((i < TAILLE_LONGUEUR) && (verif == 1)){
            // Vérification de la case
            if (grille[i][j] != symbole){
                verif = 0;
            }
            // Si ligne horizontale, alors le joueur à gagné
            if ((i == 2) && (verif == 1)){
                return 1;
            }
            // Incrémentation
            i ++;
        }
        // Incrémentation
        i = 0;
        j ++;
        verif = 1;
    }

    // Si aucune ligne horizontale n'a été trouvé.
    return 0;
}


// "verifVertical" Vérifie si un joueur à gagné la partie avec une verticale.
int verifVertical(char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR], int joueur){
    // RETURN : 0 si il n'y a pas de ligne verticale
    //          1 si il y a une ligne verticale


    // Initialisation
    int verif;
    int i = 0;
    int j = 0;
    char symbole;

    // On regarde quel joueur à joué
    if(joueur == 1){
        symbole = 'X';
    }else{
        symbole = 'O';
    }

    // Vérification
    verif = 1;

    // On parcourt le tableau de gauche à droite
    while ((j < TAILLE_LARGEUR)){
        while ((i < TAILLE_LONGUEUR) && (verif == 1)){
            // Vérification de la case
            if (grille[j][i] != symbole){
                verif = 0;
            }
            // Si ligne verticale, alors le joueur à gagné
            if ((i == 2) && (verif == 1)){
                return 1;
            }
            // Incrémentation
            i ++;
        }
        // Incrémentation
        i = 0;
        j ++;
        verif = 1;
    }
    // Si aucune ligne verticale n'a été trouvé
    return 0;
}


// "verifDiagonal" Vérifie si un joueur à gagné la partie avec une diagonale.
int verifDiagonal(char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR], int joueur){
    // RETURN : 0 si il n'y a pas de ligne diagonale
    //          1 si il y a une ligne diagonale

    // Initialisation
    int verif;
    int i, j;
    char symbole;

    // On regarde quel joueur à joué
    if(joueur == 1){
        symbole = 'X';
    }else{
        symbole = 'O';
    }

// HAUT GAUCHE à BAS DROITE

    // Initialisation des valeurs
    i = 0; 
    j = 0;
    verif = 1;

    // On parcourt la digonale haut gauche à bas droite
    while ((j < TAILLE_LONGUEUR) && (verif == 1)){
        // Vérification de la case
        if(grille[i][j] != symbole){
            verif = 0;
        }
        // Si ligne diagonale, alors le joueur à gagné
        if ((j == 2) && (verif == 1)){
            return 1;
        }
        // Incrémentation
        j ++;
        i ++;
    }

// HAUT DROITE à BAS GAUCHE

    // Initialisation des valeurs
    i = 0;
    j = 2;
    verif = 1;

    // On parcourt la digonale haut droite à bas gauche
    while ((j > -1) && (verif == 1)){
        // Vérification de la case
        if(grille[i][j] != symbole){
            verif = 0;
        }
        // Si ligne diagonale, alors le joueur à gagné  
        if ((i == 2) && (verif == 1)){
            return 1;
        }
        // Incrémentation
        j --;
        i ++;
    }
    // Si aucune diagonale trouvée.
    return 0;
}


// "grillePleine" Fonction permettant de vérifier si la grille est pleine.
int grillePleine(char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR])
    // RETURN : 0 si le tableau n'est pas plein
    //          1 si le tableau est plein

// retourne 1 si elle est pleine, sinon 0.
{
  //Parcourt du tableau.
  for (int i =0; i <= TAILLE_LARGEUR - 1; i++) {
    for (int j =0; j<= TAILLE_LONGUEUR - 1; j++) {
      //Vérification d'une case.
      if (grille[i][j] == ' ')
      {
        //Si la case est vide.
        return 0;
      }
    }
  }
  //Si le tableau est plein.
  return 1;
}


// "jeuFini" qui rassemble les conditions pour que le jeu soit terminé.
int jeuFini(char grille[TAILLE_LARGEUR][TAILLE_LONGUEUR]){
    // RETURN : 0 si le jeu n'est pas fini
    //          1 si un joueur à gagné
    //          2 si la grille est pleine

    // Initialisation
    int resultat = 0;

    //Vérification si un joueur à gagné

    //Boucle pour vérifier pour les deux joueurs
    for (int i = 1; i < 3; i++){

        // Vérification si un joueur à gagné
        if ((verifDiagonal(grille, i) == 1) || (verifHorizontal(grille, i) == 1) || (verifVertical(grille, i) == 1))
        {
        resultat = 1;
        }

        // Vérification si la grille est Pleine.
        if (grillePleine(grille) == 1)
        {
        resultat = 2;
        }
    }

    return resultat;
}


// ======= MAIN ======= //
int main(){

    // Initialisation
    int joueur = 1;
    initGrille(grille);
    afficheGrille(grille);

    // Boucle avec condition d'arret du jeu
    while (jeuFini(grille) == 0) 
    {   
        // Le joueur ajoute une pièce
        ajouterPiece(grille, joueur);
        afficheGrille(grille);

        // Changement de joueur
        if (joueur == 1){
            joueur = 2;
        }else {
            joueur = 1;
        }
        // Si je jeu n'est pas fini, la partie continues !
        if (jeuFini(grille) == 0){
            printf("\ncontinue");
        }   
    }

    // Vérification si un joueur à gagné
    if ((joueur == 1) && (jeuFini(grille) == 1)){
        printf("\n\nOwins");
    }else if ((joueur == 2) && (jeuFini(grille) == 1)){
        printf("\n\nXwins");
    }else{
        // Vérification si la grille est pleine
        if (jeuFini(grille) == 2 && joueur == 1){
            printf("\n\nOend");
        } else if (jeuFini(grille) == 2 && joueur == 2)
        {
            printf("\n\nXend");
        }
    }
}