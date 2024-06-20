

#ifndef NOTE_PROJET_LAB_OBSERVER_H
#define NOTE_PROJET_LAB_OBSERVER_H

// #include "NoteCollection.h"

class NoteCollection;

class Observer {
public:
    // Observer(Observer *pObserver);

    virtual void update(NoteCollection& collection) = 0;
};


#endif //NOTE_PROJET_LAB_OBSERVER_H
