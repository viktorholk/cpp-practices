#include "include/database.h"
#include <iostream>
Database::Database(const char* file){
    Database::handler = sqlite3_open(file, &this->db);

    if ( !Database::handler){
        std::cout << "Can't open db.sqlite3" << std::endl;
    }
}

Database::exec(const char* sql){
    Database::handler = sqlite3_exec(Database::db, sql, Database::callback,0 , &this->errMsg);

    if (Database::handler != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", Database::messageError);
    } else {
        fprintf(stdout, "Successfully executed SQL");
    }
}

int Database::callback(void* data, int argc, char** argv, char** azColName){
    for (int i = 0; i < argc; i++){
        std::printf("%s = %s\n", azColName[i], argv[i] ? *argv : "NULL");
    }
    std::printf("\n");
    return 0;
}
Database::~Database(){
    sqlite3_close(Database::db);
}