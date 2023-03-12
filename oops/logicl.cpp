#include "CuProlog.h"
using namespace std;

int main() {
  // Define facts and rules for a family tree
  CuProlog prolog;
  prolog += "father(john, mike).";
  prolog += "father(john, sara).";
  prolog += "mother(kate, mike).";
  prolog += "mother(kate, sara).";
  prolog += "father(mike, ann).";
  prolog += "mother(mary, ann).";
  prolog += "parent(X,Y) :- father(X,Y).";
  prolog += "parent(X,Y) :- mother(X,Y).";
  prolog += "sibling(X,Y) :- parent(Z,X), parent(Z,Y), X \\= Y.";
  prolog += "grandparent(X,Y) :- parent(X,Z), parent(Z,Y).";

  // Query the family tree
  CuProlog::Query query(prolog, "sibling(mike, sara).");
  while (query.next()) {
    cout << "Mike and Sara are siblings" << endl;
  }

  CuProlog::Query query2(prolog, "grandparent(john, ann).");
  while (query2.next()) {
    cout << "John is a grandparent of Ann" << endl;
  }

  return 0;
}
/*In this program, we use the CuProlog library to define a family tree using facts and rules in a similar way as we did in the previous Prolog example.

We then create two queries using the CuProlog::Query object. The first query asks if mike and sara are siblings, and the second query asks if john is a grandparent of ann.

The while loops iterate over the results of the queries and print a message to the console if the query is successful.

Note that the syntax for defining facts and rules in CuProlog is similar to that of Prolog, but the C++ syntax for creating queries is different.*/