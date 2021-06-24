#include "MyContactListener.h"
#include <stdio.h>
#include <stdlib.h>


void MyContactListener::BeginContact(b2Contact* contact) {
    
    if (contact && contact->IsTouching()){

        printf("touché \n");
        Entite* A = (Entite*) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
        Entite* B = (Entite*) contact->GetFixtureB()->GetBody()->GetUserData().pointer;

        PersonnageJoueur* joueur = NULL;
        Monstre* monstre = NULL;

        //Vérifier si A ou B est un PersonnageJoueur
        //Vérifier si l'autre est un Monstre
        //Il faut donc ajouter une méthode abstraite dans Entite.h qui s'appelle getClass() et qui renvoit une class ?
        //ça va contre l'intérêt de fair des classes qui hérite si ils faut qu'elle retienne de quelle classe elles sont
        //Mais je suis obligé de faire comme ça pour les différencier. 
        
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