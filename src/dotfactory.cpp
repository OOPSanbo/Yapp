#include "dotfactory.h"

#include "dot.h"
#include "dotgraphicscomponent.h"
#include "dotphysicscomponent.h"
#include "gameobject.h"
#include <QObject>
#include <iostream>

DotFactory::DotFactory() {}

DotFactory::DotFactory(QGraphicsScene* scene) { this->scene = scene; }

DotFactory::DotFactory(PhysicsComponent* physics, GraphicsComponent* graphics) {
}

GameObject* DotFactory::CreateObject(QString name, QPoint pos) {
    DotPhysicsComponent* dotphysicscomponent = new DotPhysicsComponent();
    DotGraphicsComponent* dotgraphicscomponent = new DotGraphicsComponent(name, *scene);

    Dot* dot = new Dot(name, dotphysicscomponent, dotgraphicscomponent);
    dot->SetPos(pos * 20);

    return dot;
}

GameObject* DotFactory::CreateObject(QString name, QPoint pos, Score* score) {
    DotPhysicsComponent* dotphysicscomponent = new DotPhysicsComponent();
    DotGraphicsComponent* dotgraphicscomponent = new DotGraphicsComponent(name, *scene);

    //connect(dotphysicscomponent, SIGNAL(IncreaseScore()), dotphysicscomponent, SLOT(HandleIncreaseScore()));

    Dot* dot = new Dot(name, dotphysicscomponent, dotgraphicscomponent);
    dot->SetPos(pos * 20);

    return dot;
}


