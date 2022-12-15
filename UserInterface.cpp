#include <filesystem>
#include <set>
#include "UserInterface.h"
#include <string>
#include <iostream>
#include "documentParser.h"

using namespace std;
namespace fs = filesystem;

UserInterface::UserInterface(){
    this->numberOfFilesIndexed = 0;
    this->numberOfUniquetWordsIndexed = 0;
    this->numUniqueAuthors = 0;
}

void UserInterface::runSearchEngine(){
    char input;
    cout << "Welcome to Matt and Sydney's Seach Engine" << endl;
    cout << "Enter 1 to create a new index" << endl;
    cout << "Enter 2 to write pesistance files" << endl;
    cout << "Enter 3 to display pesistance" << endl;
    cout << "Enter 4 to seach using a query" << endl;
    cout << "Enter 5 to output search engine statistics" << endl;
    cout << "Enter 6 to clear previous index"<<endl;
    cout << "Enter 7 to exit search engine" << endl;
    cout << "Input : ";

    while (cin >> input){
        if(input == '7'){
            return;
        }
        else if(input == '1'){
            cout << "Creating index... this may take a few moments" << endl;
            
        }
        else if(input == '2'){
            cout << "Writing Persistance.." << endl;

        }
        else if(input == '3'){
            cout << "Loading persistence.." << endl;
            this->savePersistenceWord.open("wordPersistance.txt");
            this->savePersistenceAuthor.open("authorPersistance.txt");
            this->savePersistenceStats.open("statsPersistance.txt");
            if(this->savePersistenceWord.is_open() && this->savePersistenceAuthor.is_open() && this->savePersistenceStats.is_open()){
                
            }
            {

            }

        }
        else if(input == '4'){

        }
        else if(input == '5'){

        }
        else if(input == '6'){
            cout<< "Clearing previous index.." << endl;
            this->index.getHash().clear();
            this->index.clear();
            this->numberOfFilesIndexed = 0;
            this->numberOfUniquetWordsIndexed = 0;
            this->numUniqueAuthors = 0;
            this->getTop25Words = 0;
            cout << "Index has been cleared" << endl;
            cout << "Please enter next input " << endl;

        }
        else {
        cout << "Invalid input please select from the options below " << endl;
        cout << "Enter 1 to create a new index" << endl;
        cout << "Enter 2 to write pesistance files" << endl;
        cout << "Enter 3 to display pesistance" << endl;
        cout << "Enter 4 to seach using a query" << endl;
        cout << "Enter 5 to output search engine statistics" << endl;
        cout << "Enter 6 to clear previous index"<<endl;
        cout << "Enter 7 to exit search engine" << endl;
        cout << "Input : ";
        }

}
};