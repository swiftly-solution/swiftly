#ifndef _iquerybuilder_h
#define _iquerybuilder_h

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <any>

class IQueryBuilder;

class IQueryBuilder
{
public:
    virtual void Table(std::string tableName) = 0;
    virtual void Create(std::unordered_map<std::string, std::string> columns) = 0;
    virtual void Alter(std::map<std::string, std::string> columns) = 0;
    virtual void Drop() = 0;

    virtual void Select(std::vector<std::string> columns) = 0;
    virtual void Insert(std::map<std::string, std::string> data) = 0;
    virtual void Update(std::map<std::string, std::string> data) = 0;
    virtual void Delete() = 0;

    virtual void Where(std::string column, std::string operator_, std::string value) = 0;
    virtual void OrWhere(std::string column, std::string operator_, std::string value) = 0;
    virtual void Join(std::string table, std::string onCondition, std::string joinType = "INNER") = 0;
    virtual void OrderBy(std::vector<std::pair<std::string, std::string>> columns) = 0;
    virtual void Limit(int count) = 0;
    virtual void GroupBy(std::vector<std::string> columns) = 0;
    virtual void OnDuplicate(std::map<std::string, std::string> data) = 0;
    virtual void Having(std::string condition) = 0;
    virtual void Distinct() = 0;
    virtual void Offset(int count) = 0;
    virtual void Union(std::string query, bool all) = 0;

    virtual std::any PrepareQuery() = 0;
};

#endif