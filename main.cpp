// #include <iostream>
// #include "test/NoteTest.h"
// #include "test/NoteCollectionTest.h"
// #include "test/AppTest.h"

#include "gtest/gtest.h"
#include "src/Note.h"
#include "src/NoteCollection.h"
#include "src/NoteCollectionObserver.h"
#include "src/NoteModificationException.h"
#include "src/App.h"

// ------ TEST NOTE BEGIN --------------------------------

// Test del costruttore
TEST(NoteTest, ConstructorTest) {
    Note note("Test Title", "Test Content");

    EXPECT_EQ(note.getTitle(), "Test Title"); // test se il titolo è uguale a quello passato al costruttore
    EXPECT_EQ(note.getContent(), "Test Content"); // test se il contenuto è uguale a quello passato al costruttore
    EXPECT_FALSE(note.isLocked()); // di default, la note non deve essere bloccata subito dopo la sua creazione
    EXPECT_NE(note.getCreateDate(), std::time_t(0)); // la data di creazione deve essere una data nel passato e quindi diverso di quella presente
    EXPECT_EQ(note.getCreateDate(), note.getUpdateDate()); // alla creazione, una note deve avere la data di creazione e di aggiornato uguale
}

// Test the copy assignment operator
TEST(NoteTest, CopyAssignmentOperatorTest) {
    Note note1("Title 1", "Content 1");
    Note note2("Title 2", "Content 2");

    note2 = note1;

    EXPECT_EQ(note2.getTitle(), "Title 1");
    EXPECT_EQ(note2.getContent(), "Content 1");
    EXPECT_FALSE(note2.isLocked());
    EXPECT_NE(note2.getCreateDate(), std::time_t(0));
    EXPECT_EQ(note2.getCreateDate(), note2.getUpdateDate());
}

// Test del metodo setTitle
TEST(NoteTest, SetTitleTest) {
    Note note("Initial Title", "Content"); // creo una nota
    note.setTitle("New Title"); // cambio il suo titolo

    EXPECT_EQ(note.getTitle(), "New Title"); // verifico se il titolo è stato cambiato correttamente
    EXPECT_NE(note.getUpdateDate(), note.getCreateDate()); // avendo aggiornato il titolo, la data di aggiornamento deve essere diversa di quella di creazione
}

// Test del metodo setContent
TEST(NoteTest, SetContentTest) {
    Note note("Title", "Initial Content");  // creo una nota
    note.setContent("New Content"); // cambio il contenuto

    EXPECT_EQ(note.getContent(), "New Content"); // verifico se il contenuto è stato cambiato correttamente
    EXPECT_NE(note.getUpdateDate(), note.getCreateDate()); // avendo aggiornato il contenuto, la data di aggiornamento deve essere diversa di quella di creazione
}

// Test dei metodi lock e unlock
TEST(NoteTest, LockUnlockTest) {
    Note note("Title", "Content"); // creo una nota
    note.lock(); // dopo la creazione, una nota non è bloccata, blocco quest'ultima

    note.setTitle("New Title"); // dopo aver bloccato una nota, il cambio del titolo non deve aver effetto
    note.setContent("New Content"); // dopo aver bloccato una nota, il cambio del contenuto non deve aver effetto

    EXPECT_EQ(note.getTitle(), "Title"); // il titolo della nota deve essere rimasta uguale a quella della creazione
    EXPECT_EQ(note.getContent(), "Content"); // il contenuto della nota deve essere rimasta uguale a quella della creazione
    EXPECT_TRUE(note.isLocked()); // e la nota deve essere rimasta bloccata

    note.unlock(); // sblocco la nota
    note.setTitle("New Title"); // provo di nuovo a cambiare il suo titolo
    note.setContent("New Content"); // provo a cambiare il suo contenuto

    EXPECT_EQ(note.getTitle(), "New Title"); // ora che la nota è stata sbloccata, il cambio di titolo deve aver avuto effetto
    EXPECT_EQ(note.getContent(), "New Content"); // ora che la nota è stata sbloccata, il cambio di contenuto deve aver avuto effetto
    EXPECT_FALSE(note.isLocked()); // e la nota non deve essere nello stato bloccata
}


// ------ TEST NOTE END --------------------------------



// ------ TEST NOTE COLLECTION BEGIN --------------------------------

// Test del costruttore
TEST(NoteCollectionTest, ConstructorTest) {
    NoteCollection collection("Test Collection");
    EXPECT_EQ(collection.getName(), "Test Collection");
    EXPECT_FALSE(collection.isLocked());
    EXPECT_NE(collection.getCreateDate(), std::time_t(0));
    EXPECT_EQ(collection.getCreateDate(), collection.getUpdateDate());
}

// Test del metodo di cambio nome
TEST(NoteCollectionTest, SetNameTest) {
    NoteCollection collection("Initial Name");
    collection.setName("New Name");

    EXPECT_EQ(collection.getName(), "New Name");
    EXPECT_NE(collection.getUpdateDate(), collection.getCreateDate());
}

// Test aggiunta di una note
TEST(NoteCollectionTest, AddNoteTest) {
    NoteCollection collection("Test Collection");
    Note note("Test Title", "Test Content");
    collection.addNote(note);

    auto notes = collection.getNotes();
    ASSERT_EQ(notes.size(), 1);
    EXPECT_EQ(notes.front().getTitle(), "Test Title");
    EXPECT_EQ(notes.front().getContent(), "Test Content");
    EXPECT_NE(collection.getUpdateDate(), collection.getCreateDate());
}

// Test rimorsione di una note
TEST(NoteCollectionTest, RemoveNoteTest) {
    NoteCollection collection("Test Collection");
    Note note1("Title 1", "Content 1");
    Note note2("Title 2", "Content 2");
    collection.addNote(note1);
    collection.addNote(note2);

    collection.removeNote(0);

    auto notes = collection.getNotes();
    ASSERT_EQ(notes.size(), 1);
    EXPECT_EQ(notes.front().getTitle(), "Title 2");
    EXPECT_EQ(notes.front().getContent(), "Content 2");
}

// Test dei metodi di lock e unlock
TEST(NoteCollectionTest, LockUnlockTest) {
    NoteCollection collection("Test Collection");
    collection.lock();

    collection.setName("New Name");
    EXPECT_EQ(collection.getName(), "Test Collection");

    collection.addNote(Note("Title", "Content"));
    EXPECT_EQ(collection.getNotes().size(), 0);

    collection.unlock();
    collection.setName("New Name");
    collection.addNote(Note("Title", "Content"));

    EXPECT_EQ(collection.getName(), "New Name");
    EXPECT_EQ(collection.getNotes().size(), 1);
}

// Test observer notification
TEST(NoteCollectionTest, ObserverNotificationTest) {
    NoteCollection collection("Test Collection");
    NoteCollectionObserver observer;

    collection.attach(&observer);

    testing::internal::CaptureStdout();
    collection.addNote(Note("Title", "Content"));
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Note collection 'Test Collection' has been updated."), std::string::npos);
}



// ------ TEST NOTE COLLECTION END --------------------------------


// ------ TEST APP BEGIN --------------------------------

// Test del costruttore della collezione
TEST(AppTest, ConstructorTest) {
    App app("Default Collection");
    EXPECT_EQ(app.getDefaultCollectionName(), "Default Collection");
}

// Test aggiunta di una note dentro la collezione di default
TEST(AppTest, AddNoteTest) {
    App app("Default Collection");
    app.addNote("Test Title", "Test Content");

    NoteCollection defaultCollection = app.getDefaultCollection();
    auto notes = defaultCollection.getNotes();
    ASSERT_EQ(notes.size(), 1);
    EXPECT_EQ(notes.front().getTitle(), "Test Title");
    EXPECT_EQ(notes.front().getContent(), "Test Content");
}

// Test di creazione di una nuova collezione
TEST(AppTest, CreateCollectionTest) {
    App app("Default Collection");
    app.createCollection("New Collection");

    auto collection = app.getCollection("New Collection");
    EXPECT_EQ(collection.getName(), "New Collection");
}

// Test aggiunta di una note dentro una collezione specifica
TEST(AppTest, AddNoteToCollectionTest) {
    App app("Default Collection");
    app.createCollection("New Collection");
    app.addNoteToCollection("New Collection", "Test Title", "Test Content");

    auto collection = app.getCollection("New Collection");
    auto notes = collection.getNotes();
    ASSERT_EQ(notes.size(), 1);
    EXPECT_EQ(notes.front().getTitle(), "Test Title");
    EXPECT_EQ(notes.front().getContent(), "Test Content");
}

// Test rimorsione di una note specifica dentro la collezione
TEST(AppTest, RemoveNoteFromCollectionTest) {
    App app("Default Collection");
    app.createCollection("New Collection");
    app.addNoteToCollection("New Collection", "Title 1", "Content 1");
    app.addNoteToCollection("New Collection", "Title 2", "Content 2");

    app.removeNoteFromCollection("New Collection", 0);

    auto collection = app.getCollection("New Collection");
    auto notes = collection.getNotes();
    ASSERT_EQ(notes.size(), 1);
    EXPECT_EQ(notes.front().getTitle(), "Title 2");
    EXPECT_EQ(notes.front().getContent(), "Content 2");
}

// Test l'aggiornamento del nome della collezione
TEST(AppTest, UpdateCollectionTest) {
    App app("Default Collection");
    app.createCollection("Old Collection");
    app.addNoteToCollection("Old Collection", "Test Title", "Test Content");

    app.updateCollection("Old Collection", "New Collection");

    EXPECT_THROW(app.getCollection("Old Collection"), std::out_of_range);

    auto collection = app.getCollection("New Collection");
    EXPECT_EQ(collection.getName(), "New Collection");

    auto notes = collection.getNotes();
    ASSERT_EQ(notes.size(), 1);
    EXPECT_EQ(notes.front().getTitle(), "Test Title");
    EXPECT_EQ(notes.front().getContent(), "Test Content");
}


// ------ TEST APP END --------------------------------




// Main function for running all the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
