#include "SqlSelectQueryBuilder.h"

#include <iostream>
#include <map>
#include <vector>

int main(int argc, char* argv[]) {
    SqlSelectQueryBuilder query_builder;
    //query_builder.AddColumn("name").AddColumn("phone");
    std::vector<std::string> vec = {"name", "phone"};
    query_builder.AddColumns(vec);
    query_builder.AddFrom("students");
    //query_builder.AddWhere("id", "42").AddWhere("name", "John");
    std::map<std::string, std::string> mp = { {"id", "42"}, {"name", "John"} };
    query_builder.AddWhere(mp);

    std::cout << "QUERY: " << query_builder.BuildQuery() << std::endl;
                   //"SELECT name, phone FROM students WHERE id=42 AND name=John;");
}