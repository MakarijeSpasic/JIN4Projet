#include "MyContactListener.h"
#include <stdio.h>
#include <stdlib.h>


void MyContactListener::BeginContact(b2Contact* contact) {
    
    if (contact && contact->IsTouching()){

        printf("touch� \n");
        Entite* A = (Entite*) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
        Entite* B = (Entite*) contact->GetFixtureB()->GetBody()->GetUserData().pointer;

        

        //V�rifier si A ou B est un PersonnageJoueur
        //V�rifier si l'autre est un Monstre
        //Il faut donc ajouter une m�thode abstraite dans Entite.h qui s'appelle getClass() et qui renvoit une class ?
        //�a va contre l'int�r�t de fair des classes qui h�rite si ils faut qu'elle retienne de quelle classe elles sont
        //Mais je suis oblig� de faire comme �a pour les diff�rencier. 

        //On v�rifie d'abord que A et B ne soient pas des murs, dans quel cas on ne pourrait pas appeler GetIsPlayer() dessus car
        //le pointeur est NULL
        //Si l'un des deux est un mur alors on quitte la m�thode

        if (A == NULL || B == NULL) return;

        //Si le test passe alors on d�termine qui est qui dans le contact

        PersonnageJoueur* joueur = NULL;
        Monstre* monstre = NULL;
        
        if (A->GetIsPlayer()) { //Fonctionne car m�me si c'est une entit�, en tant qu'autre chose qui en h�rite cet attribut a �t� initialis� et est donc valable
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