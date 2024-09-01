#ifndef NOTE_PROJET_LAB_APP_H
#define NOTE_PROJET_LAB_APP_H

#include <unordered_map>
#include <memory>

#include "NoteCollection.h"
#include "NoteCollectionObserver.h"


class App {
private:
    std::unordered_map<std::string, std::unique_ptr<NoteCollection>> collections;
    NoteCollection defaultCollection;
    NoteCollectionObserver observer;

public:
    App(const std::string& defaultCollectionName);

    void addNote(const std::string& title, const std::string& content);
    void addNoteToCollection(const std::string& collectionName, const std::string& title, const std::string& content);
    void removeNoteFromCollection(const std::string& collectionName, const std::string& noteTitle);
    void printNotesFromCollection(const std::string& collectionName) const;
    void printAllNotes() const;
    void createCollection(const std::string& collectionName);
    void updateCollection(const std::string& collectionName, const std::string& newCollectionName);
    void listCollections() const;
    std::string getDefaultCollectionName() const;
    NoteCollection getDefaultCollection()const;
    NoteCollection getCollection(const std::string& collectionName)const;
};



#endif //NOTE_PROJET_LAB_APP_H
