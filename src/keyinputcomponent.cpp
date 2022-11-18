#include "keyinputcomponent.h"

#include <QDebug>

KeyInputComponent::KeyInputComponent() {}

bool KeyInputComponent::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        auto *keyEvent = static_cast<QKeyEvent *>(event);
        int key = keyEvent->key();
        switch(key){
            case Qt::RightArrow: case Qt::Key_D:
                nextdir = eDirection::RIGHT;
                break;
            case Qt::LeftArrow: case Qt::Key_A:
                nextdir = eDirection::LEFT;
                break;
            case Qt::UpArrow: case Qt::Key_W:
                nextdir = eDirection::UP;
                break;
            case Qt::DownArrow: case Qt::Key_S:
                nextdir = eDirection::DOWN;
                break;
        }

        return (key == Qt::Key_W || key == Qt::Key_A || key == Qt::Key_S || key == Qt::Key_D ||key == Qt::Key_Left || key == Qt::Key_Right || key == Qt::Key_Up || key == Qt::Key_Down);
    }
    return false;
}

void KeyInputComponent::Update(GameObject& obj) {
    obj.nextDir = nextdir;
}
