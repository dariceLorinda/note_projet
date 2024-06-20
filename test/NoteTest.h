

#ifndef NOTE_PROJET_LAB_NODE_TEST_H
#define NOTE_PROJET_LAB_NODE_TEST_H

#include <iostream>
#include <cassert>
#include "../src/Note.h"

class NoteTest {

};

void test_note() {
    // Test Note creation and getters
    Note note("Title Note", "Content of Note");
    note.printNote();
     assert(note.getTitle() == "Title Note");
     assert(note.getContent() == "Content of Note");

    // Test Note update
    note.setTitle("Updated Title");
    note.setContent("Updated Content");
    note.printNote();
    assert(note.getTitle() == "Updated Title");
    assert(note.getContent() == "Updated Content");

    // Test Note lock
    assert(note.isLocked()== false);
    note.lock();
    assert(note.isLocked()== true);

    note.setTitle("Updated Title after lock");
    note.setContent("Updated Content after lock");
    note.printNote();
    assert(note.getTitle() == "Updated Title");
    assert(note.getContent() == "Updated Content");

    note.unlock();
    assert(note.isLocked()== false);


    std::cout << "All tests passed!" << std::endl;
    

}

#endif //NOTE_PROJET_LAB_CPP_NODE_TEST_H
