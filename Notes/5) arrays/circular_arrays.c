/*
    ! Circular arrays, also known as circular buffers or ring buffers.

    * This is a technique that allows fixed-size arrays to behave as if they are circular.
    * When you reach the end of the array, you wrap around and start again from the beginning.

    * Imagine you have a round table with 10 chairs numbered from 0 to 9. 
    * If someone sits in chair 9 and another person arrives, the next available chair is 0, 
    * because the table is circular.

    ? How does this apply to a list?

    In a list implemented with a circular array:

        - You have an array: int elems[MAX_ELEMS];
        - An integer 'start' that indicates where the list begins within the array.
        - An integer 'size' that tells you how many elements are currently in the list.

    -> Why is this useful?

    Because it allows the functions 'addr' (add to the right/end) and 'addl' (add to the left/start) 
    to operate in O(1) time, that is, constant time, without having to move all the elements in the array.

        - addr: You add the new element at position (start + size) % MAX_ELEMS, then increment 'size'.
        - addl: You decrement 'start' by 1 (modulo MAX_ELEMS), place the new value at the new 'start' position, 
          then increment 'size'.

    This approach is efficient for implementing queues, deques, and other data structures where 
    fast insertion and removal from both ends is required.

    If two elements are removed, the two oldest values inside of the circular buffer would be removed. 
    -> Circular buffers use FIFO (first in, first out) logic.
*/

/**
 * @brief Adds an element to the left (front) of the circular array list.
 *
 * If the list is full (size == MAX_ELEMS), the function does nothing.
 * Otherwise, it updates the start index in a circular manner, inserts the new element
 * at the front, and increments the size of the list.
 *
 * @param l Pointer to the circular array list structure.
 * @param x The element to be added to the front of the list.
 */

/**
 * @brief Adds an element to the right (end) of the circular array list.
 *
 * If the list is full (size == MAX_ELEMS), the function does nothing.
 * Otherwise, it calculates the correct position at the end of the list in a circular manner,
 * inserts the new element, and increments the size of the list.
 *
 * @param l Pointer to the circular array list structure.
 * @param x The element to be added to the end of the list.
 */
void addl(Lista *l, int x) {
    if (l->size == MAX_ELEMS) return; // lista llena
    l->start = (l->start - 1 + MAX_ELEMS) % MAX_ELEMS;
    l->elems[l->start] = x;
    l->size++;
}

void addr(Lista *l, int x) {
    if (l->size == MAX_ELEMS) return; // lista llena
    int pos = (l->start + l->size) % MAX_ELEMS;
    l->elems[pos] = x;
    l->size++;
}
/*
A circular buffer can be implemented using a pointer and four integers:[4]

    buffer start in memory
    buffer capacity (length)
    write to buffer index (end)
    read from buffer index (start)
    What is the "offset" in this context?

In a circular array, the offset refers to the logical position within the list.

For example:

    If you want to access the first logical element (position 0), the offset is 0.

    If you want to access the second (position 1), the offset is 1.

    And so on up to size - 1.

But since start can be at any position in the actual array (because the array is circular), to access the real array position where the logical element i is, you use:

real_pos = (start + i) % MAX_ELEMS;
*/
