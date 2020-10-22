
#include <iostream>
#include "include/database.h"


int main(){
    Database db("db.sqlite3");

    db.exec("CREATE NEW TABLE mytable (ID INT PRIMARY KEY NOT NULL, NAME VARCHAR(35) NOT NULL)");

}