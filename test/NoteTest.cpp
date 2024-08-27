#include "gtest/gtest.h"

#include "../src/Note.h"


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
    // EXPECT_NE(note.getUpdateDate(), note.getCreateDate()); // avendo aggiornato il titolo, la data di aggiornamento deve essere diversa di quella di creazione
}

// Test del metodo setContent
TEST(NoteTest, SetContentTest) {
    Note note("Title", "Initial Content");  // creo una nota
    note.setContent("New Content"); // cambio il contenuto

    EXPECT_EQ(note.getContent(), "New Content"); // verifico se il contenuto è stato cambiato correttamente
    // EXPECT_NE(note.getUpdateDate(), note.getCreateDate()); // avendo aggiornato il contenuto, la data di aggiornamento deve essere diversa di quella di creazione
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
