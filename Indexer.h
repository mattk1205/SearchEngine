#include <string>
#include "WordInfo.h"
#include "documentParser.h"
#include <unordered_map>
#include <unordered_set>
#include "AVLMap.h"

class Indexer{

    using PersonName = std::string;
    using OrganizationName = std::string;
    using Keyword = std::string;

private:

    std::string filepath;
    AVLMap<Keyword, std::vector<WordInfo>> keywords;
    std::unordered_map<PersonName, std::vector<WordInfo>> personIndex;
    std::unordered_map<OrganizationName, std::vector<WordInfo>> orgIndex;

public:
    Indexer(std::string filepath);
    void addKeyword(Keyword);
    void addOrganization(OrganizationName, WordInfo);
    void addPerson(PersonName, WordInfo);
    const AVLMap<Keyword, std::vector<WordInfo>> &getKeywords() const;
    const std::unordered_map<PersonName, std::vector<WordInfo>> &getPersonIndex() const;
    const std::unordered_map<OrganizationName, std::vector<WordInfo>> &getOrgIndex() const;
    vector<WordInfo> findDocumentWordsOccurrences(Keyword string);
    vector<WordInfo> findDocumentOrganizationOccurrences(OrganizationName);
    vector<WordInfo> findDocumentPersonOccurrences(PersonName);
};