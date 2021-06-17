#include "MyContactListener.h"



void MyContactListener::BeginContact(b2Contact* contact) {
    
    if (contact && contact->IsTouching()){

        Entite* A = (Entite*) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
        Entite* B = (Entite*) contact->GetFixtureB()->GetBody()->GetUserData().pointer;

        //Vérifier si A ou B est un PersonnageJoueur
        //Vérifier si l'autre est un Monstre
        //Il faut donc ajouter une méthode abstraite dans Entite.h qui s'appelle getClass() et qui renvoit une class ?
        //ça va contre l'intérêt de fair des classes qui hérite si ils faut qu'elle retienne de quelle classe elles sont
        //Mais je suis obligé de faire comme ça pour les différencier. 
        
        if (A->GetIsPlayer()) { //Fonctionne car même si c'est une entité, en tant qu'autre chose qui en hérite cet attribut a été initialisé et est donc valable
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