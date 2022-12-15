cmake_minimum_required(VERSION 3.15)
project(FinalProjExamples)

# filesystem.h require C++17
set(CMAKE_CXX_STANDARD 17)

file(COPY sample_data/ DESTINATION sample_data/)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

add_executable(rapidJSONExample rapidJSONExample.cpp AVLMap.h AVLMapTests.cpp documentParser.cpp documentParser.h HashMap.h documentParserTests.cpp HashMapTests.cpp)
add_executable(AVLMap AVLMapTests.cpp AVLMap.h)
add_executable(HashMap HashMap.h HashMapTests.cpp)
add_executable(DocumentParser documentParser.h documentParser.cpp documentParserTests.cpp)
add_executable(Indexer Indexer.h Indexer.cpp)
add_executable(QueryProcessor QueryProcessor.h QueryProcessor.cpp QueryProcessor3.h QueryProcessor3.cpp)
add_executable(WordInfo WordInfo.h WordInfo.cpp)
add_executable(UserInterface UserInterface.h UserInterface.cpp)
add_executable(supesearch AVLMap.h HashMap.h documentParser.h documentParser.cpp Indexer.h Indexer.cpp QueryProcessor.h QueryProcessor.cpp WordInfo.h WordInfo.cpp UserInterface.h UserInterface.cpp)

# this makes sure we also link rapidjson
target_include_directories(rapidJSONExample PRIVATE rapidjson/)

set(CMAKE_VERBOSE_MAKEFILE OFF)
