/*
    ! Data types vs Abstract data types

    -> data types 
    * defaines a certain domain of values
    * defines operations allowed on those values
     
    example: 
    int type: 
        - integer values 
        - operations (add, sub, mul, bitwise, etc).


    -> user defined data types

    * in contrast to primitive data types, there is a concept of user defined data types
    * the operations and values of user defined data types are not specified in the language itself but is specified by the user. 

    example:
        -structure, union and enums
    
    by using structs, we are defining our own type by combining other data types- 
*/

struct point {
    int x;
    int y;
};

/*
    -> Abstract data types

    * ADT's are like user defined data types which defines operations on values
    * using functions without specifying what is there inside the function and 
    * how the operations are perfomed. 
    
    example: stack ADT
        - A stack consists of elem ents of same type arranged in a sequential order

    Operations:
    initialize() - initializing it to be empty
    push() - insert an element into the stack
    pop() - delete an element from the stack
    isEmpty() - check if stack is empty
    isFull() - checks if stack is full

    * those are functions, doesn't say anything how c an be implemented, but we are not saying how it should be implemented

    -> ADT could be thought as a black box which hides the inner structure and design of the data type from the user. 

    example :
        - A stack ADT can be implement using arrays or linked lists 

    ! why adt?

    * just uses the interface, nothing inside
    the program which uses data strucute is called a client program
    it has accesos to the adt i.e. interface. 

    * implements the data strucuture
    the program whuch implements the data strucute is known as the implementation. 

    -> advantage 
        let say, if someone want to use the stack in the program, then he can
        simply use push and pop operations wihtout knowing its implementation 

        also, if in the future, the implementation of stack is changed
        from array to linked list, then the client program will work in the same way 
        without being affected.

    ! hides implementation from user, the only need is to work. It's abstract.

 */

/*
    ! Encapsulation in ADTs

    * Encapsulation ensures that the state of an ADT can only be accessed through its provided operations
    * It maintains a strict separation between specification (interface) and implementation (internal details)
    * This separation allows changing the implementation without modifying any code that uses the ADT

    -> Implementation approaches
        - Different programming languages provide different mechanisms for encapsulation
        - In theoretical languages, this might be done with "spec ... where" and "implement ... where" clauses
        - In C, we need to find specific techniques to achieve encapsulation

    ! ADT Methods

    * ADTs typically have three types of operations:
        - Constructors: create and initialize instances of the ADT
        - Operations: manipulate or access the ADT's state
        - Destructors: clean up resources when the ADT is no longer needed
    
    * In C implementation:
        - Procedures are implemented as void functions (functions that don't return values)
        - Functions can be used instead of procedures with output parameters to simplify code 
          and avoid extra pointers

    * Preconditions and Postconditions:
        - Unlike theoretical examples, in practice we should verify conditions when possible
        - Use assert() to check preconditions and postconditions during development
        - These checks make programs more robust
        - Assertions can be disabled in production code using the -DNDEBUG compiler flag
*/

/*
    ! Common Pitfalls in ADT Implementation

    * Function implementation errors:
        - Ensuring functions match their documented behavior (e.g., counter_is_init() should check 
          if count==0, not if the pointer is NULL)
        - Using assertions properly to validate preconditions (e.g., assert(c != NULL) before accessing c->count)
    
    * Memory management issues:
        - Always initialize pointers to NULL before use
        - Ensure proper constructor/destructor pairing
        - Avoid use-after-free bugs by not accessing ADT members after destruction
        - Store values that need to persist beyond destruction (like is_init) before calling the destructor
    
    * Encapsulation mistakes:
        - Returning direct pointers to internal structures
        - Allowing clients to modify ADT state outside of provided operations
        - Failing to check preconditions before performing operations
    
    ! Testing ADT Implementations

    * Test boundary conditions:
        - Empty/initial state
        - Full/maximum state
        - First operation after construction
        - Last operation before destruction
    
    * Test error conditions:
        - Invalid inputs
        - Operations with unmet preconditions
        - Resource exhaustion scenarios
    
    * Test correct behavior:
        - Verify each operation produces expected results
        - Ensure state changes as expected after operations
        - Check that internal invariants are maintained
    
    ! Debugging ADT Issues

    * Common symptoms and causes:
        - Segmentation faults: Often from NULL pointer dereferencing or accessing freed memory
        - Memory leaks: Forgetting to call destructors or missing free() calls
        - Incorrect behavior: Implementation doesn't match specification
    
    * Debugging techniques:
        - Print statements to trace execution flow
        - Memory checking tools (Valgrind)
        - Assertions to catch invalid states early
*/