#include "MyContactListener.h"



void MyContactListener::BeginContact(b2Contact* contact) {
    
    if (contact && contact->IsTouching()){

        Entite* A = (Entite*) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
        Entite* B = (Entite*) contact->GetFixtureB()->GetBody()->GetUserData().pointer;

        //V�rifier si A ou B est un PersonnageJoueur
        //V�rifier si l'autre est un Monstre
        //Il faut donc ajouter une m�thode abstraite dans Entite.h qui s'appelle getClass() et qui renvoit une class ?
        //�a va contre l'int�r�t de fair des classes qui h�rite si ils faut qu'elle retienne de quelle classe elles sont
        //Mais je suis oblig� de faire comme �a pour les diff�rencier. 
        
        if (A->GetIsPlayer()) { //Fonctionne car m�me si c'est une entit�, en tant qu'autre chose qui en h�rite cet attribut a �t� initialis� et est donc valable
            A = (PersonnageJoueur*)A;
        }
        else {
            A = (Monstre*)A;
        }

        if (B->GetIsPlayer()) {
            B = (PersonnageJoueur*)B;
        }
        else {
            B = (Monstre*)B;
        }

        if (A->GetIsPlayer() && !B->GetIsPlayer()) {

            A->LoseHealth(B->GetForce());
            A->GetBody()->ApplyForceToCenter(-100 * A->GetBody()->GetLinearVelocity(),true); //Une force qui repousse notre objet
        }
        if (B->GetIsPlayer() && !A->GetIsPlayer()) {

            B->LoseHealth(A->GetForce());
            B->GetBody()->ApplyForceToCenter(-100 * B->GetBody()->GetLinearVelocity(), true);
        }

    }
}



void MyContactListener::EndContact(b2Contact* contact) {

}