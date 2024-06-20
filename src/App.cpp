

#include <iostream>

#if __cplusplus < 201402L
#include "utils.h"
#endif

#include "App.h"

App::App(const std::string& defaultCollectionName)
    : defaultCollection(defaultCollectionName) {
    defaultCollection.attach(&observer);
    collections[defaultCollectionName] = std::make_unique<NoteCollection>(defaultCollectionName);
}

void App::addNote(const std::string& title, const std::string& content) {
    defaultCollection.addNote(Note(title, content));
}

void App::addNoteToCollection(const std::string& collectionName, const std::string& title, const std::string& content) {
    if (collections.find(collectionName) != collections.end()) {
        collections[collectionName]->addNote(Note(title, content));
    } else {
        std::cerr << "Collection " << collectionName << " does not exist." << std::endl;
    }
}

void App::removeNoteFromCollection(const std::string& collectionName, size_t index) {
    if (collections.find(collectionName) != collections.end()) {
        collections[collectionName]->removeNote(index);
    } else {
        std::cerr << "Collection " << collectionName << " does not exist." << std::endl;
    }
}

void App::printNotesFromCollection(const std::string& collectionName) const {
    if (collections.find(collectionName) != collections.end()) {
        for (const auto& note : collections.at(collectionName)->getNotes()) {
            note.printNote();
        }
    } else {
        std::cerr << "Collection " << collectionName << " does not exist." << std::endl;
    }
}

void App::printAllNotes() const {
    for (const auto& pair : collections) {
        std::cout << "Collection: " << pair.first << std::endl;
        for (const auto& note : pair.second->getNotes()) {
            note.printNote();
        }
    }
}

void App::createCollection(const std::string& collectionName) {
    if (collections.find(collectionName) == collections.end()) {
        collections[collectionName] = std::make_unique<NoteCollection>(collectionName);
        collections[collectionName]->attach(&observer);
    } else {
        std::cerr << "Collection " << collectionName << " already exists." << std::endl;
    }
}

void App::updateCollection(const std::string& collectionName, const std::string& newCollectionName) {
    if (collections.find(newCollectionName) == collections.end()) {
        auto it = collections.find(collectionName); // puntatore verso la vecchia collezione
        if(it != collections.end()) {
            collections[newCollectionName] = std::make_unique<NoteCollection>(collectionName); // creo la nuova collezione
            collections[newCollectionName]->attach(&observer); // ci metto il suo ossevatore
            for (const auto& note : collections.at(collectionName)->getNotes()) {
                collections[newCollectionName]->addNote(note); // per ogni nota presente nella vecchia collezione, lo aggiunto sulla nuova
            }
            collections.erase(it); // cancello la vecchia collezione
        } else {

        }
    } else {
        std::cerr << "Collection " << collectionName << " don't exists." << std::endl;
    }
}


void App::listCollections() const {
    for (const auto& pair : collections) {
        std::cout << "Collection: " << pair.first << std::endl;
    }
}
std::string App::getDefaultCollectionName() const{
   return defaultCollection.getName();
}

NoteCollection App::getDefaultCollection() const {
    return defaultCollection;
}

NoteCollection App::getCollection(std::string collectionName) const {
    return *collections.at(collectionName);
}