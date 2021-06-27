Le jeu est à générer avec la procédure cmake du document http://www-inf.telecom-sudparis.eu/COURS/CSC4526/new_site/Supports/Documents/OutilsCSC4526/outilsCSC4526.html.

Le jeu est lançable en définissant en tant que projet de démarrage mainLauncher et en faisant l'exécution. 

Une fois le jeu lancé, il est possible que la fenêtre du jeu soit blanche, il suffit de passer la souris dessus pour y voir apparaître le menu de démarrage. 

Il est possible de naviguer dans les menus du jeu avec les touches directionnelles haut et bas du clavier, et les éléments des menus sont sélectionnables avec la touche entrée.

Dans le jeu, le personnage controlé est la boule verte, controlable avec les touches directionnelles du clavier. 

L'attaque est déclenchée avec la touche espace, et affiche un rectangle bleu qui correspond à cette attaque.

Un menu pause est ouvrable avec la touche échap. Il n'y a que deux options : revenir au jeu ou fermer le jeu. Le joueur dispose d'un certain nombre de pièces à dépenser dans la boutique, affiché dans le menu de pause ou de la boutique.

Le menu de la boutique est ouvrable avec la touche "p" du clavier. 4 choix d'amélioration y sont proposés : ils coutent chacun un certain nombre de pièces. Le retour au jeu se fait avec le bouton se situant en bas du menu de la boutique. 

Le joueur perd de la vie lorsqu'il entre en contact avec des ennemis. Lorsqu'il n'a plus de vie, un écran de Game Over apparaît. Il faut relancer le jeu pour recommencer. 


Ce qu'on a fait depuis la dernière fois : 
	- Design pattern de template pour les menus: il y a plusieurs menus différents qui héritent d'une classe abstraite "Menu" qui contient l'algorithme utilisé pour toutes les classes filles. Ces dernières modifient les méthodes composant cet algorithme, de manière à changer le comportement sans modifier l'algorithme de base.
	- Ce design pattern a permis l'instauration de la boutique, avec un système de "pièces" pour le joueur, qui peut les échanger contre des améliorations dans cette boutique. Les améliorations respectent le thème : elles donnent des bonus en même temps que certain malus (par exemple: attaquer plus loin en échange de bouger moins vite).
	- La barre de vie est liée à la vie du joueur, elle évolue lorsque ce dernier entre en contact avec des monstres.
	- La rétroaction lors des attaques a été implémentée : les monstres perdent bien de la vie, et l'arme du joueur diminue lorsqu'elle entre en contact avec des monstres.
	- Les hitbox des murs sont déduites d'un layer supplémentaire créé avec tmxlite, de cette manière, il est possible de créer les murs "automatiquement", en les dessinant via Tiled Maps avec un layer "Object". 
	- Nous avons essayé de mettre en place un design pattern de "Builder" afin de pouvoir construire des niveaux en dehors du fichier myMain.cpp, qui ne contiendrait que la boucle de jeu. Cela permettrait de passer d'un niveau à un autre plus facilement. Cela n'a cependant pas abouti, des erreurs survenant à beaucoup d'endroits sans raisons. (ces erreurs concernent des objets qui ne sont pas affectés par le builder normalement.)