# SYMBOL_TABLE
Implementing a Symbol Table using C++

A compiler records the variable names used in the source program along with its attributes and
stores it in a data structure called a symbol table.

This is a program to support implementation of a symbol table with nested scopes using a hash
table. It maintains a new symbol table for every scope and link it with the surrounding scope.
Provide functionality to insert and lookup for a variable in the current scope hash table. If the
variable entry does not exist in the current scope hash table,it looks up the value in the
surrounding scope.
