#ifndef FINALPROJEXAMPLES_WORDINFO_H
#define FINALPROJEXAMPLES_WORDINFO_H
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "AVLMap.h"
#include "porter2_stemmer.h"

using namespace std;

class WordInfo {
private:
    string id;
    string title;
    string authors;
    string organizations;
    string publishedDate;
    string site;
    string text;
    int comparable;
    AVLMap<string, int> words;
public:
    WordInfo(const string& id, const string& title,
             const string& author, const string& publishedDate, const string& organizations, const string& text, const string& site, const int);
void fillAll(); //fills the AVLMap with every word in document
void fillTitle();
void fillOrganizations();
void fillText();
void fillAuthors();
bool checkOr(const vector<string>& orVector);
bool checkAnd(const vector<string>& andVector);
bool checkNot(const vector<string>& notVector);
bool checkAuthor(string author);
int checkFrequency(const string& word);
void display();
void getShortText();
int getWordsCount();
vector<string> readStopWords();
bool operator<(WordInfo &rhs) const;
bool operator>(WordInfo &rhs) const;
bool operator==(WordInfo &rhs) const;
WordInfo& operator=(WordInfo *rhs);

//getters and setters
const string &getId() const;
const string &getTitle() const;
const string &getAuthors() const;
const string &getOrganizations() const;
const string &getPublishedDate() const;
const string &getSite() const;
const string &getText() const;
const int &getComparable() const;
const AVLMap<string, int> &getWords() const;
void setId(const string &id);
void setTitle(const string &title);
void setAuthors(const string &authors);
void setOrganizations(const string &organizations);
void setPublishedDate(const string &publishedDate);
void setSite(const string &site);
void setComparable(int);
void setText(const string &);
void setWords(const AVLMap<string, int> &);
};
#endif