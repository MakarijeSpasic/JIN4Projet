#include <TiledMapInterpretor.h>

TiledMapConverter::TiledMapConverter(b2World* world, sf::RenderWindow* window): world(world), window(window){
    std::vector<sf::RectangleShape> hitboxes(4);
}


void TiledMapConverter::createWalls(tmx::Map* map) {
    const auto& layers = map->getLayers();
    //Parcourt les layers des cartes
    for (const auto& layer : layers)
    {
        //S'il s'agit d'un layer de type objects (ce qui nous intéresse, puisque cela nous permet de récupérer les positions des hitbox des murs
        if (layer->getType() == tmx::Layer::Type::Object)
        {
            const auto& objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
            const auto& objects = objectLayer.getObjects();

            //Pour chaque hitbox de mur dessinée dans ce layer, 
            for (const auto& object : objects)
            {
                //On en récupère la position et les proportions
                tmx::Vector2f position = object.getPosition();
                const tmx::FloatRect proportions = object.getAABB();

                //On crée le body des hitbox
                b2BodyDef murBodyDef;

                //On set la position du body en prenant en compte le décalage de l'origine de l'objet dans les fonctions
                if (proportions.width > proportions.height) {
                    murBodyDef.position.Set((position.x + proportions.width/2) / 10, (position.y + proportions.height )/ 10);
                }
                else {
                    murBodyDef.position.Set(position.x / 10, (position.y + proportions.height/2) / 10);
                }
                std::cout << "x: " << position.x << " y: " << position.y << std::endl;

                //On crée le body
                b2Body* murBody = world->CreateBody(&murBodyDef);
                b2PolygonShape murBox;

                //On crée les hitbox associées au body
                murBox.SetAsBox(proportions.width / 20, proportions.height / 20);
                std::cout << "height: " << proportions.height << " width: " << proportions.width << std::endl;
                murBody->CreateFixture(&murBox, 0.0f);
                hitboxes.push_back(createHitbox(position.x, position.y, proportions.height, proportions.width));

                //Pour faire les vérifications de hitbox:
                //renderHitbox();
            }
        }
        /*
        else if (layer->getType() == tmx::Layer::Type::Tile)
        {
            const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
            //read out tile layer properties etc...
        }
        */
    }

    /*
    const auto& tilesets = map->getTilesets();
    for (const auto& tileset : tilesets)
    {
        //read out tile set properties, load textures etc...
    }
    */
}

sf::RectangleShape TiledMapConverter::createHitbox(float position_X, float position_Y, float height, float width){
    //On récupère les proportions des hitbox pour pouvoir dessiner des rectangles de la même taille, à la position souhaitée
    sf::Vector2f proportions;
    proportions.x = width; proportions.y = height;
    sf::RectangleShape hitbox(proportions);
    hitbox.setSize(proportions);
    hitbox.setFillColor(sf::Color::Red);
    hitbox.setPosition(position_X,position_Y);
    return hitbox;
}

void TiledMapConverter::renderHitbox() {
    for (const auto& hitbox : hitboxes) {
        window->draw(hitbox);
    }
}