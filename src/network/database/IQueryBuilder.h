#ifndef _iquerybuilder_h
#define _iquerybuilder_h

#include <string>
#include <vector>
#include <map>
#include <any>

class IQueryBuilder;

class IQueryBuilder
{
public:
    virtual IQueryBuilder* Table(std::string tableName) = 0;
    virtual IQueryBuilder* Create(std::map<std::string, std::string> columns) = 0;
    virtual IQueryBuilder* Alter(std::map<std::string, std::string> columns) = 0;
    virtual IQueryBuilder* Drop() = 0;

    virtual IQueryBuilder* Select(std::vector<std::string> columns) = 0;
    virtual IQueryBuilder* Insert(std::map<std::string, std::string> data) = 0;
    virtual IQueryBuilder* Update(std::map<std::string, std::string> data) = 0;
    virtual IQueryBuilder* Delete() = 0;

    virtual IQueryBuilder* Where(std::string column, std::string operator_, std::string value) = 0;
    virtual IQueryBuilder* OrWhere(std::string column, std::string operator_, std::string value) = 0;
    virtual IQueryBuilder* Join(std::string table, std::string onCondition, std::string joinType = "INNER") = 0;
    virtual IQueryBuilder* OrderBy(std::vector<std::pair<std::string, std::string>> columns) = 0;
    virtual IQueryBuilder* Limit(int count) = 0;
    virtual IQueryBuilder* GroupBy(std::vector<std::string> columns) = 0;
    virtual IQueryBuilder* OnDuplicate(std::map<std::string, std::string> data) = 0;
    virtual IQueryBuilder* Having(std::string condition) = 0;
    virtual IQueryBuilder* Distinct() = 0;
    virtual IQueryBuilder* Offset(int count) = 0;
    virtual IQueryBuilder* Union(std::string query, bool all) = 0;

    virtual std::any PrepareQuery() = 0;
};

#endif