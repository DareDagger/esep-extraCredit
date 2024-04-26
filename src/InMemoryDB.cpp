#include "InMemoryDB.h"

void InMemoryDB::begin_transaction() {
    if (in_transaction) {
        throw std::runtime_error("Transaction already in progress");
    }
    in_transaction = true;
    transaction_db.clear();
}

void InMemoryDB::put(const std::string& key, int value) {
    if (!in_transaction) {
        throw std::runtime_error("No transaction in progress");
    }
    transaction_db[key] = value;
}

int* InMemoryDB::get(const std::string& key) {
    /*
    if (in_transaction) {
        auto found = transaction_db.find(key);
        if (found != transaction_db.end()) {
            return &found->second;
        }
    }
    */
    auto found = main_db.find(key);
    if (found != main_db.end()) {
        return &found->second;
    }
    return nullptr;
}

void InMemoryDB::commit() {
    if (!in_transaction) {
        throw std::runtime_error("No transaction in progress");
    }
    for (const auto& kv : transaction_db) {
        main_db[kv.first] = kv.second;
    }
    in_transaction = false;
}

void InMemoryDB::rollback() {
    if (!in_transaction) {
        throw std::runtime_error("No transaction in progress");
    }
    transaction_db.clear();
    in_transaction = false;
}
