#include "QueryProcessor3.h"
#include <variant>

//variant represents a type-safe union
//https://en.cppreference.com/w/cpp/utility/variant
//I will be using the helper object varinat_npos which is the index of the varient in the invalid state
string QueryProcessor3::getUserInput(){
    cout << "Please enter seach query: " << endl;
    getline(cin, query);
    query = query;
    return query;
}

string QueryProcessor3::getQuery(){
    return query;
}
double QueryProcessor3::get_Process_Time(){
    return process_time;
}



void QueryProcessor3::setBooleanFunctions(){
    //if AND is found and doesnt equal the index of varient in invalid state set bool to true 
    if(query.find("AND ") != variant_npos){
        queryHasAND = true;
    }
    if(query.find("OR ") != variant_npos){
        queryHasOR = true;
    }
    if(query.find("NOT ") != variant_npos){
        queryHasNOT= true;
    }
    if(query.find("PERSON ") != variant_npos){
        isPerson = true;
    }
    if(query.find("ORG ") != variant_npos){
        isOrgs = true;
    }
    //if the user doesnt enter AND, OR, NOT 
    //then they are seaching for a single word and this will eval to true 
    if(!queryHasAND && !queryHasOR && !queryHasOR){
        queryIsSingleWord = true;
    }

     set<WordInfo *> QueryProcessor3::retrieve_data(const AVLMap<string, WordInfo>* &wordTree, const HashMap<string, set<WordInfo *>> &personMap, const HashMap <string, set<WordInfo *>> &orgMap){
       std::chrono::time_point<std::chrono::high_resolution_clock> begin, end;
       begin = std::chrono::high_resolution_clock::now();
       set<WordInfo *> word_set;
       if(queryHasAND == true){
        set<string>iterator::iterator = words.begin();
        for(const auto& iter: )
       }

     }

void QueryProcessor3::parseQuery(string query, Index &id, Index &org, Index &person){
    istringstream ss(query);
    string word;
    vector<string> queryChoices;
    documentParser document;
    vector<WordInfo::______> results;

    chrono::time_point<chrono::high_resolution_clock> start, endl;
    start = chrono::high_resolution_clock::now();

    while(ss >> word){
        if(word != "AND" && word != "OR")
    }
}

}