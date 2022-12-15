#include "WordInfo.h"

WordInfo::WordInfo(const string &id, const string &title, const string &author, const string &publishedDate,
                   const string &organizations, const string &text, const string &site, const int comparable) {
    this->id = id;
    this->site = site;
    this->title = title;
    this->organizations = organizations;
    this->publishedDate = publishedDate;
    this->text = text;
    this->authors = author;
    this->comparable = comparable;
}

void WordInfo::fillAll() {
    fillOrganizations();
    fillText();
    fillAuthors();
}

void WordInfo::fillOrganizations() {
    string temp = organizations;
    istringstream abstractStream(temp);//gets every organization
    while(abstractStream>>temp){
        temp.erase(remove(temp.begin(), temp.end(), ','), temp.end());
        int freq = checkFrequency(temp);
        if(temp!="" and temp.length()>3)
            words.insert(temp, freq);
    }
}

vector<string> WordInfo::readStopWords(){
    vector<string> words;
    string stopwrd;
    ifstream stopwords("../stopwords.txt");
    if(!(stopwords.is_open()))
        cout << "error opening stop words" << endl;
    while(getline(stopwords, stopwrd, '\n')) {
        Porter2Stemmer::trim(stopwrd);
        Porter2Stemmer::stem(stopwrd);
        words.push_back(stopwrd);
    }
    return words;
}

void WordInfo::fillText() {
    vector<string> stopwords = readStopWords();
    string temp = text;
    istringstream bodyStream(temp);//gets every word in body text
    while(bodyStream>>temp){
        temp.erase(remove(temp.begin(), temp.end(), ','), temp.end());
        int freq = checkFrequency(temp);
        Porter2Stemmer::stem(temp);
        Porter2Stemmer::trim(temp);
        if (find(stopwords.begin(), stopwords.end(), temp) == stopwords.end() and temp!="" and temp.length()>3)
            words.insert(temp, freq);
    }
}

void WordInfo::fillAuthors() {
    string temp = authors;
    istringstream authorStream(temp);//gets every author
    while(authorStream >> temp){//dont stem author name
        int freq = checkFrequency(temp);
        if(temp!="" and temp.length()>3)
            words.insert(temp, freq);
    }
}

bool WordInfo::checkOr(const vector<string> &orVector) {
    fillAll();
    bool oR = false;
    for(auto item : orVector) {
        if(words.containsByKey(item)) {
            oR = true;
            break;
        }
    }
    words.clear();
    return oR;
}

bool WordInfo::checkAnd(const vector<string> &andVector) {
    fillAll();
    bool andd = true;
    for(auto item : andVector) {
        if(!(words.containsByKey(item))){
            andd = false;
            break;
        }
    }
    words.clear();
    return andd;
}

bool WordInfo::checkNot(const vector<string> &notVector) {
    fillAll();
    bool nott = true;
    for(auto item : notVector) {
        if(words.containsByKey(item)) {
            nott = false;
            break;
        }
    }
    return nott;
}

bool WordInfo::checkAuthor(string author) {
    fillAuthors();
    bool temp = false;
    if(words.containsByKey(author))
        temp = true;
    words.clear();
    return temp;
}

int WordInfo::checkFrequency(const string &word) { //check the frequency of a word in a document
    int freq = 0;
    string temp = title;
    istringstream titleStream(temp);//gets every word in title
    while (titleStream >> temp) {
        Porter2Stemmer::stem(temp);
        if (temp == word)
            freq++;
    }
    temp = organizations;
    istringstream orgStream(temp);//gets every word in organizations
    while (orgStream >> temp) {
        if(temp == word)
            freq++;
    }

    temp = text;
    istringstream bodyStream(temp);//gets every word in body text
    while (bodyStream >> temp) {
        Porter2Stemmer::stem(temp);
        if(temp == word)
            freq++;
    }

    temp = authors;
    istringstream authorStream(temp);//gets every word in body text
    while (authorStream >> temp) {
        if(temp == word)
            freq++;
    }
    return freq;
}
const string &WordInfo::getId() const {
    return id;
}

const string &WordInfo::getTitle() const {
    return title;
}

const string &WordInfo::getAuthors() const {
    return authors;
}

const string &WordInfo::getOrganizations() const {
    return organizations;
}

const string &WordInfo::getPublishedDate() const {
    return publishedDate;
}

const string &WordInfo::getSite() const {
    return site;
}

const string &WordInfo::getText() const {
    return text;
}

const AVLMap<string, int> &WordInfo::getWords() const {
    return words;
}

const int &WordInfo::getComparable() const {
    return comparable;
}

void WordInfo::setId(const string &id) {
    WordInfo::id = id;
}

void WordInfo::setTitle(const string &title) {
    WordInfo::title = title;
}

void WordInfo::setAuthors(const string &authors) {
    WordInfo::authors = authors;
}

void WordInfo::setOrganizations(const string &organizations) {
    WordInfo::organizations = organizations;
}

void WordInfo::setPublishedDate(const string &publishedDate) {
    WordInfo::publishedDate = publishedDate;
}

void WordInfo::setSite(const string &site) {
    WordInfo::site = site;
}

void WordInfo::setComparable(int comparable) {
    WordInfo::comparable = comparable;
}

void WordInfo::setText(const string &text) {
    WordInfo::text = text;
}

void WordInfo::setWords(const AVLMap<string, int> &words) {
    WordInfo::words = words;
}

void WordInfo::display() {
    cout << "\tID: " << id << endl;
    cout << "\tAuthor: " << authors << endl;
    cout << "\tTitle: " << title << endl;
    cout << "\tOrganizations: " << organizations << endl;
    words.print_inOrder();
}

void WordInfo::getShortText() {
    string temp = text;
    int count = 0;
    istringstream bodyStream(temp);
    while (bodyStream >> temp && count < 300) {
        cout << temp << " ";
        count++;
    }
}

int WordInfo::getWordsCount() {
    int count = 0;
    string temp = title;
    istringstream titleStream(temp);

    while (titleStream >> temp) {
        Porter2Stemmer::stem(temp);
        count++;
    }

    temp = organizations;
    istringstream abstractStream(temp);
    while (abstractStream >> temp) {
        Porter2Stemmer::stem(temp);
        count++;
    }

    temp = text;
    istringstream bodyStream(temp);
    while (bodyStream >> temp) {
        Porter2Stemmer::stem(temp);
        count++;
    }

    temp = authors;
    istringstream authorStream(temp);
    while (authorStream >> temp) {
        count++;
    }
    return count;
}

bool WordInfo::operator<(WordInfo &rhs) const {
return comparable < rhs.comparable;
}

bool WordInfo::operator>(WordInfo &rhs) const {
    return comparable > rhs.comparable;
}

bool WordInfo::operator==(WordInfo &rhs) const {
    return comparable == rhs.comparable;
}

WordInfo &WordInfo::operator=(WordInfo *rhs) {
    id = rhs->id;
    title = rhs->title;
    text = rhs->text;
    authors = rhs->authors;
    return *this;
}





