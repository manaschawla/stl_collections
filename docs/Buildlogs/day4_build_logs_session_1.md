Build Log – Day 3
Session 1
Date: 26-06-2026
Time: 10:45 - 1:00 PM

Goal
The goal of today's session was to improve HashMap so that it can work with user-defined classes even when the user does not provide a custom hash function.

---

Problem Encountered
- HashMap was working with primitive types and custom hashers.But, it was not clear how user-defined classes would be handled when no custom hash function was provided.

- I introduced a generic default hasher and an additional template parameter, so i had to modifyseveral HashMap function definitions accordingly.

---

What I Did

- Implemented a generic DefaultHasher for unsupported/user-defined types.
- Used byte-based hashing with reinterpret_cast to generate hash values.
- Modified HashMap to support both default hashing and user-provided hashing.
- Updated all HashMap member function definitions to use the additional template parameter.
- Tested the implementation with a Student class using both:
  - Custom hasher
  - Default hasher
- Verified that rehashing continued to work correctly after the changes.

---

Outcome

HashMap can now work with:
- Primitive data types
- Strings
- User-defined classes using default hashing
- User-defined classes using custom hash functions

