#include "main.h"

int main(void)
	
{
    char *line;
    while (1)
    {
        afficher_prompt();  // Afficher le prompt
        line = lire_ligne();  // Lire la commande de l'utilisateur
        if (!line)
            break;  // Gérer la fin de fichier (Ctrl+D)
        executer_commande(line);  // Exécuter la commande
        free(line);
    }
    return (0);
}
