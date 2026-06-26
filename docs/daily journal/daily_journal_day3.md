Daily Development Journal

Date: 25-06-2026

Objective:
The objective of today was to improve the HashMap implementation. The main goal was to make the HashMap grow automatically when more elements are inserted. I also reorganized the project structure by separating declarations and implementations into header and .tpp files.

---

Work Completed

HashMap Rehashing
Implemented automatic rehashing when the load factor becomes greater than 0.75.
When the HashMap becomes crowded, the bucket count is doubled and all existing entries are inserted again into the new bucket array.
Example:

Bucket Count
8 → 16 → 32
This helps reduce collisions and improves performance.

---

Hash Function Support

Created hash functions for:
- int
- char
- long
- long long
- float
- double
- bool
- string

Implemented a DefaultHasher class so that different key types can be used in HashMap.

---

Project Structure

Moved declarations to header files and implementations to .tpp files.
Created separate folders:
include/
src/
test/
docs/
This made the project structure cleaner and easier to understand.

---

Problems Encountered

I was confused about how rehashing actually moves data from old buckets to new buckets.
While implementing rehashing, I was not sure whether currentSize should be updated manually or automatically.
After moving code into .tpp files, I faced compilation errors because the compiler was unable to find template implementations.
I also had some confusion regarding const and non-const versions of the get() function.

---

What I Did

I studied how load factor works and how HashMaps maintain performance by increasing the bucket count.
I traced the rehashing process step by step and verified how entries move into new buckets after recalculating hash values.
I reviewed the put() function and understood how currentSize gets updated automatically while reinserting entries.
I moved all template implementations into .tpp files and included them from the corresponding header files.
I also updated the folder structure and include paths.

---

Outcome

Successfully implemented rehashing in HashMap.
HashMap can now grow automatically when more elements are inserted.
Implemented hash support for multiple primitive data types and strings.
Project structure became cleaner after separating declarations and implementations.
Understood how templates are organized in larger C++ projects.

---

Learning

Today I learned about:

- Load Factor
- Rehashing
- Bucket Expansion
- Hash Functions
- Template Specialization
- DefaultHasher
- Header and .tpp file organization
- Template compilation

---

Next Tasks

- Complete remaining HashMap functions.
- Add more test cases.
- Improve support for custom data types.
- Review edge cases and exception handling.

---

End of Day Notes

Today I gained a much better understanding of how HashMap maintains efficiency as the number of elements increases. I also learned how rehashing works internally and why all entries must be inserted again after increasing the bucket count. Separating code into header and .tpp files also helped me understand how template-based projects are organized.