//
// Created by mattw on 11/14/2022.
//
#include "documentParser.h"

documentParser::documentParser( const string &directory) {
    testFileSystem(directory);
}

  void documentParser::testReadJsonFile(const string &fileName){
      ifstream input(fileName);
      if (!input.is_open())
        ExceptionHandling("cannot open file "+fileName);

      rapidjson::IStreamWrapper isw(input);
      rapidjson::Document d;
      d.ParseStream(isw);
      auto persons = d["entities"]["persons"].GetArray();
      string authors;
      for(auto &p: persons) {
          string auth = p["name"].GetString();
          authors += auth+", ";
      }
      auto organizations = d["entities"]["organizations"].GetArray();
      string orgs;
      for(auto &o : organizations) {
          string org = o["name"].GetString();
          orgs += org+", ";
      }
      string id = d["uuid"].GetString();
      string title = d["title"].GetString();
      string published = d["published"].GetString();
      string text = d["text"].GetString();
      string site = d["thread"]["site"].GetString();
      WordInfo doc(id, title, authors, published, orgs, text, site);
      documents.insert(doc);

      input.close();
  }

/**
 * example code for how to traverse the filesystem using std::filesystem
 * which is new for C++17.
 *
 * @param path an absolute or relative path to a folder containing files
 * you want to parse.
 */
void documentParser::testFileSystem(const string &path){

    // recursive_director_iterator used to "access" folder at parameter -path-
    // we are using the recursive iterator so it will go into subfolders.
    // see: https://en.cppreference.com/w/cpp/filesystem/recursive_directory_iterator
    auto it = filesystem::recursive_directory_iterator(path);

    // loop over all the entries.
    for (const auto &entry : it)
    {
        cout << "--- " << setw(60) << left << entry.path().string() << " ---" << endl;
        // We only want to attempt to parse files that end with .json...
        if (entry.is_regular_file() && entry.path().extension().string() == ".json")
        {
            testReadJsonFile(entry.path().string());
        }
    }
}

const string &documentParser::getFilepath() const {
    return filepath;
}

const vector<WordInfo> &documentParser::getDocuments() const {
    return documents;
}

