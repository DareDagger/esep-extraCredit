#ifndef INMEMORYDB_H
#define INMEMORYDB_H

#include <unordered_map>
#include <string>
#include <stdexcept>

class InMemoryDB {
public:
    void begin_transaction();
    void put(const std::string& key, int value);
    int* get(const std::string& key);
    void commit();
    void rollback();

private:
    std::unordered_map<std::string, int> main_db;
    std::unordered_map<std::string, int> transaction_db;
    bool in_transaction = false;
};

#endif // INMEMORYDB_H
