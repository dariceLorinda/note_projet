

#ifndef NOTE_PROJET_LAB_NOTE_COLLECTION_OBSERVER_H
#define NOTE_PROJET_LAB_NOTE_COLLECTION_OBSERVER_H

#include <iostream>

#include "NoteCollection.h"
#include "Observer.h"

class NoteCollectionObserver: public Observer {
public:
    // NoteCollectionObserver(Observer *pObserver) : Observer(pObserver) {}

    void update(NoteCollection& collection) override;
};


#endif //NOTE_PROJET_LAB_COLLECTION_OBSERVER_H
