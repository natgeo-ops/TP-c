#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("\n\nExercice 18 (Borne de recharge intelligente)\n\n");

    int retour = 0, nb_vehicule, energie_delivree, energie_total = 0, duree_charge, nb_session4h = 0, cpt_vehicule = 0, vehicule_conso_test = 0, vehicule_conso_plus = 0;
    float prix_recharge, chiffre_affaire = 0.0;

    while (1){
        printf("\nNombre de vehicule a traiter : ");
        scanf("%d", &nb_vehicule);
        if (nb_vehicule <= 0){
            printf("Veuillez saisir un nombre de vehicule valide");
        }
        else {
            break;
        }
    }
    while (nb_vehicule>cpt_vehicule){
        cpt_vehicule++;
        printf("\n\nVehicule %d - ", cpt_vehicule);
        while (1){
            printf("\nEnergie (en kWh) : ");
            scanf("%d", &energie_delivree);
            if(energie_delivree <= 0 || energie_delivree > 120){
                printf("Veuillez entrer une consommation valide");
            }
            else{
                break;
            }
        }
        while (1){
            printf("duree (en min) : ");
            scanf("%d", &duree_charge);
            if(duree_charge <= 0){
                printf("Veuillez entrer une duree valide\n");
            }
            else{
                break;
            }
        }

        prix_recharge = 0.24*energie_delivree;

        if (duree_charge > 240){
            prix_recharge += 2;
            printf("%0.2f e (dont 2e de frais fixes)", prix_recharge);
            nb_session4h+=1;
        }
        else {
            if (energie_delivree >= 50){
                prix_recharge*=0.9;
                printf("%0.2f e apres reduction ", prix_recharge);
            }
            else {
                printf("%0.2f e ", prix_recharge);
            }
        }

        chiffre_affaire += prix_recharge;
        energie_total += energie_delivree;

        if (energie_delivree > vehicule_conso_test){
            vehicule_conso_plus = cpt_vehicule;
            vehicule_conso_test = energie_delivree;
        }
        else if (energie_delivree == vehicule_conso_test){
            vehicule_conso_plus = -1;
        }
    }

    printf("\nConsommation totale : %d kWh | ", energie_total);
    printf("Chiffre d'affaire : %0.2f e | ", chiffre_affaire);
    printf("Session superieure a 4h : %d | ", nb_session4h);

    if (vehicule_conso_plus < 0){
        printf("Plusieurs vehicules ont plus consomme");
    }
    else {
        printf("Le vehicule de la session %d a consomme plus", vehicule_conso_plus);
    }
    return 0;
}
