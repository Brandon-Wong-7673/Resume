#include "LazyBST.h"
#include "Faculty.h"
#include "Database.h"

int main(int argc ,char **argv){
    Database* database = new Database();

    database->addFaculty(1,"a","a","a");
    database->openDatabase();

    delete database;
    return 1;
}