Le jeu est � g�n�rer avec la proc�dure cmake du document http://www-inf.telecom-sudparis.eu/COURS/CSC4526/new_site/Supports/Documents/OutilsCSC4526/outilsCSC4526.html.

Le jeu est lan�able en d�finissant en tant que projet de d�marrage mainLauncher et en faisant l'ex�cution. 

Une fois le jeu lanc�, il est possible que la fen�tre du jeu soit blanche, il suffit de passer la souris dessus pour y voir appara�tre le menu de d�marrage. 

Il est possible de naviguer dans les menus du jeu avec les touches directionnelles haut et bas du clavier, et les �l�ments des menus sont s�lectionnables avec la touche entr�e.

Dans le jeu, le personnage control� est la boule verte, controlable avec les touches directionnelles du clavier. 

L'attaque est d�clench�e avec la touche espace, et affiche un rectangle bleu qui correspond � cette attaque.

Un menu pause est ouvrable avec la touche �chap. Il n'y a que deux options : revenir au jeu ou fermer le jeu. Le joueur dispose d'un certain nombre de pi�ces � d�penser dans la boutique, affich� dans le menu de pause ou de la boutique.

Le menu de la boutique est ouvrable avec la touche "p" du clavier. 4 choix d'am�lioration y sont propos�s : ils coutent chacun un certain nombre de pi�ces. Le retour au jeu se fait avec le bouton se situant en bas du menu de la boutique. 

Le joueur perd de la vie lorsqu'il entre en contact avec des ennemis. Lorsqu'il n'a plus de vie, un �cran de Game Over appara�t. Il faut relancer le jeu pour recommencer. 


Ce qu'on a fait depuis la derni�re fois : 
	- Design pattern de template pour les menus: il y a plusieurs menus diff�rents qui h�ritent d'une classe abstraite "Menu" qui contient l'algorithme utilis� pour toutes les classes filles. Ces derni�res modifient les m�thodes composant cet algorithme, de mani�re � changer le comportement sans modifier l'algorithme de base.
	- Ce design pattern a permis l'instauration de la boutique, avec un syst�me de "pi�ces" pour le joueur, qui peut les �changer contre des am�liorations dans cette boutique. Les am�liorations respectent le th�me : elles donnent des bonus en m�me temps que certain malus (par exemple: attaquer plus loin en �change de bouger moins vite).
	- La barre de vie est li�e � la vie du joueur, elle �volue lorsque ce dernier entre en contact avec des monstres.
	- La r�troaction lors des attaques a �t� impl�ment�e : les monstres perdent bien de la vie, et l'arme du joueur diminue lorsqu'elle entre en contact avec des monstres.
	- Les hitbox des murs sont d�duites d'un layer suppl�mentaire cr�� avec tmxlite, de cette mani�re, il est possible de cr�er les murs "automatiquement", en les dessinant via Tiled Maps avec un layer "Object". 
	- Nous avons essay� de mettre en place un design pattern de "Builder" afin de pouvoir construire des niveaux en dehors du fichier myMain.cpp, qui ne contiendrait que la boucle de jeu. Cela permettrait de passer d'un niveau � un autre plus facilement. Cela n'a cependant pas abouti, des erreurs survenant � beaucoup d'endroits sans raisons. (ces erreurs concernent des objets qui ne sont pas affect�s par le builder normalement.)
	- Nous avons également fait des tests unitaires, nous avons essayé de respecter au mieux la manière de faire "correcte".