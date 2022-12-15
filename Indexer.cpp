#include "Indexer.h"

Indexer::Indexer(std::string filepath) {
    this->filepath = filepath;
}

vector<WordInfo> Indexer::findDocumentWordsOccurrences(Indexer::Keyword keyword){

    return docs;
}



const AVLMap<Indexer::Keyword, std::vector<WordInfo>> &Indexer::getKeywords() const {
    return keywords;
}

const std::unordered_map<Indexer::PersonName, std::vector<WordInfo>> &Indexer::getPersonIndex() const {
    return personIndex;
}


const std::unordered_map<Indexer::OrganizationName, std::vector<WordInfo>> &Indexer::getOrgIndex() const {
    return orgIndex;
}

void Indexer::addKeyword(string keyword) {
    documentParser parser(filepath);
    vector<WordInfo> docs;
    for(WordInfo doc : parser.getDocuments()){
        doc.fillText();
        doc.fillTitle();
        if(doc.getWords().containsByKey(keyword))
            docs.push_back(doc);
    }
    keywords.insert(keyword, docs);
}

void Indexer::addOrganization(Indexer::OrganizationName, WordInfo) {

}

void Indexer::addPerson(Indexer::PersonName, WordInfo) {

}


vector<WordInfo> Indexer::findDocumentOrganizationOccurrences(Indexer::OrganizationName name) {
}

vector<WordInfo> Indexer::findDocumentPersonOccurrences(Indexer::PersonName name) {
}

void Indexer::addOrganization(Indexer::OrganizationName) {

}

void Indexer::addPerson(Indexer::PersonName) {

}

