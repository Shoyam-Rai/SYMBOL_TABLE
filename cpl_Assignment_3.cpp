#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class SymbolTable {
private:
    stack<unordered_map<string, int>> scopes;

public:
    SymbolTable() {
        beginScope();
    }

    void beginScope() {
        scopes.push(unordered_map<string, int>());
    }

    void endScope() {
        if (!scopes.empty()) {
            scopes.pop();
        }
    }

    void insert(const string& variable, int value) {
        if (!scopes.empty()) {
            scopes.top()[variable] = value;
        }
    }

    int lookup(const string& variable) {
        stack<unordered_map<string, int>> tempStack = scopes;
        while (!tempStack.empty()) {
            if (tempStack.top().find(variable) != tempStack.top().end()) {
                return tempStack.top()[variable];
            }
            tempStack.pop();
        }
        return -1; 
    }
};

int main() {
    SymbolTable symbolTable;

    symbolTable.insert("a", 1);

    cout << "Value of a: " << symbolTable.lookup("a") << endl;

    symbolTable.beginScope();
    symbolTable.insert("b", 2);

    cout << "Value of b: " << symbolTable.lookup("b") << endl;

    symbolTable.beginScope();
    symbolTable.insert("a", 3);
    symbolTable.insert("c", 4);

    cout << "Value of a in nested scope: " << symbolTable.lookup("a") << endl;
    cout << "Value of b in nested scope: " << symbolTable.lookup("b") << endl;

    symbolTable.beginScope();
    symbolTable.insert("c", 5);

    cout << "Value of b in doubly nested scope: " << symbolTable.lookup("b") << endl;
    cout << "Value of a in doubly nested scope: " << symbolTable.lookup("a") << endl;
    cout << "Value of c in doubly nested scope: " << symbolTable.lookup("c") << endl;

    symbolTable.endScope();

    cout << "Value of a in nested scope: " << symbolTable.lookup("a") << endl;
    cout << "Value of c in nested scope: " << symbolTable.lookup("c") << endl;

    symbolTable.endScope();

    cout << "Value of a: " << symbolTable.lookup("a") << endl;

    return 0;
}
