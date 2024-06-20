#include "NoteCollectionObserver.h"
#include <iostream>

void NoteCollectionObserver::update(NoteCollection& collection) {
    std::cout << "Note collection '" << collection.getName() << "' has been updated." << std::endl;
}
