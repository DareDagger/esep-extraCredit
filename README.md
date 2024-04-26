# esep-extraCredit
Enterprise Software Engineering Practices Extra Credit Assignment: Data Processing and Storage Assignment

# How to run code
1. Fork the repository and clone a local instance on your machine.
2. cd into src directory.
3. Run command "g++ -std=c++17 main.cpp InMemoryDB.cpp -o ..\bin\InMemoryDBApp.exe" if on Windows or "g++ -std=c++17 main.cpp InMemoryDB.cpp - o ../bin/InMemoryDBApp" if on Linux/macOS.
4. cd into bin directory.
5. Run command "InMemoryDBApp.exe" for Windows or  "./InMemoryDBApp" for Linux/MacOS. Additionally for Linux/macOS, if you want to make sure the file  is an executable run "chmod +x InMemoryDBApp" before running the previous command.
6. Output in terminal is the output from running the commands in Figure 2 of Assignment file.

# How to modify this assignment to become and "official" assignment?
To make this extra credit assignment official, you would need to find a way to make the project more dynamic. Depending on what language you use it can be a little challenging to create the In-Memory Database, however the assignment is relatively easy (took me ~2hrs, maybe less). By having them design a User Interface, like done in past assignments, you can ensure hard coding is never an option. This would mean all values are grader inputed (have the student design a command script to show full user interaction functionality) so the student has to account for all edge cases. Additionally having them integrate this with using a react server or something similar can make the project more challenging and fun to do. These are a few suggestions for making this project a little bit more challenging for a official assignment.