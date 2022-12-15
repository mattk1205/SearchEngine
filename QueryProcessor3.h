#include "AVLMap.h"
#include "HashMap.h"
#include "AVL.h"
#include "WordInfo.h"
#include <sstream>
#include <unordered_set>
#include <set>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
class QueryProcessor3{
private:
    std::vector<std::string> and_search;
    std::vector<std::string> or_search;
    std::vector<std::string> not_search;
    std::string query;
    std::string org;
    std::string person;
    double process_time = 0;
    vector<string> results;



public:
    set<WordInfo *> retrieve_data(const AVLMap<string, WordInfo>* &wordTree, const HashMap <string, set<WordInfo *>> &personMap, const HashMap <string, set<WordInfo *>> &orgMap);
    void processQuery(AVLMap<string, WordInfo>*, AVLMap<string, WordInfo>*, AVLMap<string, WordInfo>*);
    double get_Process_Time();
    void rank_and_Order_Results(vector<string>&);
    AVLMap<WordInfo, pair<int, int>> parseQuery(string&);
    void tokenize(vector<string>&, string&);
    explicit QueryProcessor3(const std::string &QueryProcessor3);
    void setUnion(AVLMap<int,double> & results, AVLMap<int, double> &words);
    //used for AND and OR queries
    vector<string>findUnion(vector<string>&, vector<string>&);
    //used for NOT queries
    vector<string> dontInclude(vector<string>&, vector<string>&);
    void setBooleanFunctions();
    void vectFill();
    string getQuery();
    string getUserInput();
    bool queryHasAND;
    bool queryHasOR;
    bool queryHasNOT;
    bool queryIsSingleWord;
    bool isPerson;
    bool isOrgs;
    bool isWord;
    string qury;






};