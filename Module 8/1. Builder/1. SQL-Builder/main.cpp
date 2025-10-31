#include "SqlSelectQueryBuilder.h"

#include <iostream>

int main(int argc, char* argv[]) {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::cout << "QUERY: " << query_builder.BuildQuery() << std::endl;
                   //"SELECT name, phone FROM students WHERE id=42 AND name=John;");
}