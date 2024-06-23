
#ifndef NOTE_PROJET_LAB_NOTE_COLLECTION_TEST_H
#define NOTE_PROJET_LAB_NOTE_COLLECTION_TEST_H


#include "../src/NoteCollection.h"
#include "../src/NoteCollectionObserver.h"
#include "../src/Note.h"
#include "../src/NoteModificationException.h"

int test_collection() {
    // Create a note collection
    NoteCollection myNoteCollection("My Collection");
    myNoteCollection.printCollection();
    assert(myNoteCollection.getName()=="My Collection");


    myNoteCollection.setName("update name");
    assert(myNoteCollection.getName()=="update name");


    // Create an observer for the note collection
    NoteCollectionObserver observer;

    // Attach the observer to the note collection
    myNoteCollection.attach(&observer);

    // Add some notes to the collection
    myNoteCollection.addNote(Note("Note 1", "Content of Note 1"));
    myNoteCollection.addNote(Note("Note 2",  "Content of Note 2"));

    assert(myNoteCollection.getNotes().size()==2);

    myNoteCollection.printCollection();

    Note note("locked note","content");
    note.lock();
    myNoteCollection.addNote(note);
    try {
        myNoteCollection.removeNote(myNoteCollection.getNotes().size()-1);
    } catch(const NoteModificationException& e) {
        std::cerr << "note modification exception: " << e.what() << std::endl;
    } catch(const std::exception& e ){
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return 0;
}

#endif //NOTE_PROJET_LAB_NOTE_COLLECTION_TEST_H
