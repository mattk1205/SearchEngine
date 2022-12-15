#include <iostream>
#include <fstream>
#include <string>
#include<set>
#include "Indexer2.h"


using namespace std;

class UserInterface{
private:
    //class object
    Indexer2 Indexer;
    int numberOfFilesIndexed;
    int numberOfUniquetWordsIndexed;
    int numUniqueAuthors;
    ifstream savePersistenceWord;
    ifstream savePersistenceAuthor;
    ifstream savePersistenceStats;
    vector<string> getTop25Words;


public:
    UserInterface();
    void runSearchEngine();
    void getPersistenceStats(ifstream& input);




}
;
