#include "gtest/gtest.h"

#include "../src/NoteCollection.h"
#include "../src/NoteCollectionObserver.h"

// Test del costruttore
TEST(NoteCollectionTest, ConstructorTest) {
    NoteCollection collection("Test Collection");
    EXPECT_EQ(collection.getName(), "Test Collection");
    EXPECT_NE(collection.getCreateDate(), std::time_t(0));
    EXPECT_EQ(collection.getCreateDate(), collection.getUpdateDate());
}

// Test del metodo di cambio nome
TEST(NoteCollectionTest, SetNameTest) {
    NoteCollection collection("Initial Name");
    collection.setName("New Name");

    EXPECT_EQ(collection.getName(), "New Name");
    // EXPECT_NE(collection.getUpdateDate(), collection.getCreateDate());
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
    // EXPECT_NE(collection.getUpdateDate(), collection.getCreateDate());
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


