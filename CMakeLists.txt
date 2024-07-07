cmake_minimum_required(VERSION 3.26)
project(note_projet_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(note_projet_lab main.cpp
        src/App.cpp
        src/Note.cpp
        src/NoteCollection.cpp
        src/NoteCollectionObserver.cpp
        src/NoteModificationException.h
        gtest/gtest-assertion-result.h
        gtest/gtest-death-test.h
        gtest/gtest-matchers.h
        gtest/gtest-message.h
        gtest/gtest-param-test.h
        gtest/gtest-printers.h
        gtest/gtest-spi.h
        gtest/gtest-test-part.h
        gtest/gtest-typed-test.h
        gtest/gtest_pred_impl.h
        gtest/gtest_prod.h
        gtest/internal/gtest-death-test-internal.h
        gtest/internal/gtest-filepath.h
        gtest/internal/gtest-internal.h
        gtest/internal/gtest-param-util.h
        gtest/internal/gtest-port.h
        gtest/internal/gtest-port-arch.h
        gtest/internal/gtest-string.h
        gtest/internal/gtest-type-util.h
        gtest/internal/custom/gtest.h
        gtest/internal/custom/gtest-port.h
        gtest/internal/custom/gtest-printers.h
)
