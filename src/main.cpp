#include "InMemoryDB.h"
#include <iostream>

int main() {
    InMemoryDB db;

    try {
        // should return null, because A doesn’t exist in the DB yet
        db.get("A");
        int* value = db.get("A");
        if (value) {
            std::cout << "A's value is: " << *value << std::endl;
        }
        else{
            std::cout << "A's value is null" << std::endl;
        }

        // should throw an error because a transaction is not in progress
        db.put("A", 5);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // starts a new transaction
        db.begin_transaction();

        // set’s value of A to 5, but its not committed yet
        db.put("A", 5);

        // should return null, because updates to A are not committed yet
        db.get("A");
        int* value = db.get("A");
        if (value) {
            std::cout << "A's value is: " << *value << std::endl;
        }
        else{
            std::cout << "A's value is null" << std::endl;
        }

        // update A’s value to 6 within the transaction
        db.put("A", 6);

        // commits the open transaction
        db.commit();

        // should return 6, that was the last value of A to be committed
        db.get("A");
        value = db.get("A");
        if (value) {
            std::cout << "A's value is: " << *value << std::endl;
        }
        else{
            std::cout << "A's value is null" << std::endl;
        }

        // throws an error, because there is no open transaction
        db.commit();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // throws an error because there is no ongoing transaction
        db.rollback();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // should return null because B does not exist in the database
        db.get("B");
        int* value = db.get("B");
        if (value) {
            std::cout << "B's value is: " << *value << std::endl;
        }
        else{
            std::cout << "B's value is null" << std::endl;
        }

        // starts a new transaction
        db.begin_transaction();

        // Set key B’s value to 10 within the transaction
        db.put("B", 10);

        // Rollback the transaction - revert any changes made to B
        db.rollback();

        // Should return null because changes to B were rolled back
        db.get("B");
        value = db.get("B");
        if (value) {
            std::cout << "B's value is: " << *value << std::endl;
        }
        else{
            std::cout << "B's value is null" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
