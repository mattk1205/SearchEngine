## High-level Design of Solution



- UML class diagram, etc.
- <img width="663" alt="Screen Shot 2022-12-04 at 10 25 55 PM" src="https://user-images.githubusercontent.com/60519473/205550942-84ab4ceb-e4ac-4608-bd6a-3e11c92d90c6.png">

## Your Timeline to Finish the Project
Weekly milestones/tasks. Set out a plan at the beginning and then record when you got it done.


<img width="1023" alt="Screen Shot 2022-12-05 at 4 40 05 AM" src="https://user-images.githubusercontent.com/60519473/205621862-7e25829b-021a-4c7a-94c4-ccefaa1cfabb.png">


## Used Data Structures
Explanation of what data structures are used where. For each, state 
    - time and space complexity (Big-Oh),
    - why it is the appropriate data structure and what other data structure could have been used.

## User Documentation 
- How to use the software.
-The software will start by dipslaying a menu
-From there the user enters a number based on what they are trying to do
-They can either create a new index, write a persistance file, display persistance
- enter a search query, output search engine, stats, or clear previous index
- If the user wants to sear
- Some example queries with the results are provided below
  markets - would return all articles that contain the word markets
  social network - would contain all articles that contain social AND network
  social network PERSON::cramer - would return all articles that contain the word social and network
   - and have the entity organization of facebook that mentions cramer as a person entity
  



## Automatic Tests and Memory Tests
You need to describe test cases for:
- Tests for your AVL tree's functions:
- clear 
- insert 
- getSize 
- isEmpty()
- containsByKey 
- containsByVal 
- print_inOrder

  - Inserting a value with key
  - Inserting duplicate should not insert
  - Clearing a tree
  - Clearing an empty tree
  - Get Size of non-empty tree. isEmpty yields false
  - Get Size of empty tree should yield a true from isEmpty
  - Equals Operator
  - Printing shows copies made
  - Editing one map does not change another map, showing deep copies
  - Finding element by value and key
  - Elements not in tree are not found
  - AVLMap works with different data types
- Tests for your AVL tree for memory leaks (don't forget to test the persistence functions)
- Tests for indexer
- Tests for the complete system
