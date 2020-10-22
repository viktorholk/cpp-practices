#if !defined(DATABASE_H)
#define DATABASE_H
#include "sqlite/sqlite3.h"

class Database {
    public:
        static int callback(void* data, int argc, char** argv, char** azColName);

        void exec(const char* sql);

        sqlite3 *db;
        int handler;
        
        Database(const char* file);
        ~Database();

    private:
        char* messageError;

};


#endif // DATABASE_H
