//
// Created by mattw on 11/14/2022.
//

#ifndef FINALPROJEXAMPLES_DOCUMENTPARSER_H
#define FINALPROJEXAMPLES_DOCUMENTPARSER_H

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/istreamwrapper.h"
#include "AVLMap.h"
#include "WordInfo.h"

#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

//namespace fs = std::filesystem;
//using namespace rapidjson; bad if we want to use names that rapidjson might have used

class documentParser {
private:
    string filepath;
    std::vector<WordInfo> documents;
public:
    const string &getFilepath() const;

    const vector<WordInfo> &getDocuments() const;

public:
    documentParser(const string &);
    void open_dir_using_filesystem(const string &);
    void getTree();
    std::string getPath();
    void setPath(const std::string&);
    void printTree();
    vector<string> readStopWords();
    void parse(const string &);
    void getInputFiles(std::vector<std::string> &, std::string&);
    set<string> tokenize(string &);
    vector<string> readStopWords(fstream &);
    void testReadJsonFile(const string &fileName);
    void testFileSystem(const string &path);
};


class ExceptionHandling : public runtime_error{
public:
    ~ExceptionHandling() {}
    ExceptionHandling(const string err) : runtime_error(err)
    {}
};




#endif //FINALPROJEXAMPLES_DOCUMENTPARSER_H
