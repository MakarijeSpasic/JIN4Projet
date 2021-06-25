#include "MyContactListener.h"
#include <stdio.h>
#include <stdlib.h>


void MyContactListener::BeginContact(b2Contact* contact) {
    
    if (contact && contact->IsTouching()){

        printf("touché \n");
        Entite* A = (Entite*) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
        Entite* B = (Entite*) contact->GetFixtureB()->GetBody()->GetUserData().pointer;

        

        //Vérifier si A ou B est un PersonnageJoueur
        //Vérifier si l'autre est un Monstre
        //Il faut donc ajouter une méthode abstraite dans Entite.h qui s'appelle getClass() et qui renvoit une class ?
        //ça va contre l'intérêt de fair des classes qui hérite si ils faut qu'elle retienne de quelle classe elles sont
        //Mais je suis obligé de faire comme ça pour les différencier. 

        //On vérifie d'abord que A et B ne soient pas des murs, dans quel cas on ne pourrait pas appeler GetIsPlayer() dessus car
        //le pointeur est NULL
        //Si l'un des deux est un mur alors on quitte la méthode

        if (A == NULL || B == NULL) return;

        //Si le test passe alors on détermine qui est qui dans le contact

        PersonnageJoueur* joueur = NULL;
        Monstre* monstre = NULL;
        
        if (A->GetIsPlayer()) { //Fonctionne car même si c'est une entité, en tant qu'autre chose qui en hérite cet attribut a été initialisé et est donc valable
            joueur = (PersonnageJoueur*)A;
        }
        else {
            monstre = (Monstre*)A;
        }

        if (B->GetIsPlayer()) {
            joueur = (PersonnageJoueur*)B;
        }
        else {
            monstre = (Monstre*)B;
        }

        

        joueur->LoseHealth(monstre->GetForce());
        joueur->GetBody()->SetLinearVelocity(-10000 * joueur->GetDirection()); //Une force qui repousse notre objet
        

    }
}



void MyContactListener::EndContact(b2Contact* contact) {

}