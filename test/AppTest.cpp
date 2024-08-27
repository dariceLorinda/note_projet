#include "gtest/gtest.h"

#include "../src/App.h"


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
