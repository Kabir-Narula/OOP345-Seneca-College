/*
Prvalue (Pure R-value):

A prvalue, short for "pure r-value," represents a temporary value or an expression that doesn't have a memory location that you can directly access. Prvalues are often used to represent values that are calculated or produced on-the-fly, such as literals, expressions, function call results, or temporary objects. */

/*Temporary Values:
Prvalues typically represent values that are short-lived and may not have a persistent memory location.
They are often used for intermediate calculations or to provide values that are not stored in variables.
cpp */

int result = 5 + 3; // '5 + 3' is a prvalue representing the temporary res