[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/QIb6xosc)
# CS 244 Challenge Project 2 (240 points)

| Milestone           | Deadline                                                             |
| ------------------- | -------------------------------------------------------------------- |
| **Proposals due:**  | Monday, November 6 (recommended)                                     |
| **Early check-in:** | On or before Tuesday, November 20, during class time or office hours |
| **Code deadline:**  | Monday, December 4 (recommended)                                     |
| **Full project:**   | Wednesday, December 13                                               |

## Introduction
Challenge projects are an opportunity for you to propose, implement, and analyze a solution to a problem of your choosing.  This can take many forms: a simple game, a mathematical / engineering problem, a demonstration of a cybersecurity issue, or anything else that meets the requirements.  You can use a lab or exercise from this course as a starting point, or create a new project from scratch.  A command-line interface (CLI) is encouraged if applicable.  Keep in mind the limitations of command-line user interfaces when proposing your project.  Projects need to be implemented in C++ but could incorporate other tools or libraries if you are willing to do your own research.

The second challenge project is to be focused on the use of advanced data structures through the standard template library (STL).  It should also use C++ inheritance and dynamic polymorphism.  **If you complete this project successfully, it should be an effective portfolio item for you to showcase as you're starting to look for co-ops / internships.**

To meet the requirements of this project, your project must contain:
* At least four classes, including at least one application of inheritance and polymorphism
* At least two applications of any of the following containers in the standard template library, all of which have sublinear time complexity for their essential methods: ```set```, ```multiset```, ```map```, ```multimap```, ```unordered_set```, ```unordered_multiset```, ```unordered_map```, ```unordered_multimap```, ```priority_queue```.

(**Note:** The following containers do ***not*** count as they are typically implemented using linear data structures and have linear time complexity for search: ```array```, ```vector```, ```deque```, ```list```, ```forward_list```, ```stack```, and ```queue```.)

You may work alone or with *one* partner. Failure to indicate who is your partner is indistinguishable from cheating and you will both receive a zero. Ensure all code shared with your partner is private.

## Part 1: Proposal and Design (20 points)
The first checkpoint for this project is to propose and design a project that meets the requirements.
* In a text file in your GitHub repository, write a couple paragraphs describing the intended functionality of the project and which standard library containers you would use ***and why***.  In addition, describe the important algorithms that you would use.
* Then design the four (or more) classes that you will need to use to implement the proposed project.  In your GitHub repository for the project, commit a draft of the C++ header (.h) files describing the functions and variables for each class you intend to create.  **You do not need to implement these classes by Nov. 6, just write the header files.**  Make sure you indicate the inheritance relationships between classes and which functions are polymorphic (```virtual```).  You should also mark functions as ```const``` when applicable.  

It is recommended that the proposal and header files be committed to your GitHub repo by **Monday, November 6.**  If submitted on time, your instructor will try to give feedback with a quick turnaround time on these proposals.

## Part 2: Implementation (160 points)
Once you have an approved proposal and design, you can start working on implementing your project.  The rubric for your implementation is as follows:
* 10 points: check-in
* 60 points: implementation
*	40 points: tests
*	40 points: optimization
*	10 points: code style

### Check-in (10 points)
You are required to complete a check-in with the instructor on or before **Tuesday, November 20**, during which you must demonstrate that you have made significant progress on the project. This check-in is worth 10 points and will be evaluated as follows:
*	5 points for anything showing me where you’re at (even if it doesn’t work at all).
*	5 points for making substantial, visible progress on implementation.
This check-in must be completed during class time or office hours.

### Implementation (60 points)
Do your best to implement the project as described in the proposal.  If you don’t think you’ll be able to implement everything in the project as planned, discuss scaling back the scope of the project with the instructor.  Your implementation will be graded on the following rubric:
*	60 points = Exemplary work exceeding expectations; fully functional program demonstrating novel or innovative solutions to non-trivial problems.
*	45 points = Work that fully meets expectations (4+ classes with inheritance + polymorphism and 2+ uses of STL containers as listed above); a functional program that is usable and demonstrates some non-trivial programming effort.
*	30 points = Solid effort was made but the program may not be fully functional, or had to be significantly scaled back in scope to something below expectations (fewer than 4 classes, missing polymorphism, or fewer than 2 uses of STL containers as listed above).
*	15 points = Attempt was made but code does not work at all; may crash when attempting basic functionality, or fails to compile altogether.

### Tests (40 points)
Your project should include some tests.  This can take the form of an alternate ```main()``` function, or you can use the C++ test framework as seen in labs.  If you don’t use the test framework, make sure your tests automatically determine and clearly report whether they passed or failed.  

Your tests will be graded on the following rubric:
*	40 points = Successfully tests all functionality with coverage of significant edge cases
*	30 points = Successfully tests critical path functionality but not edge / error cases
*	20 points = Successfully tests some but not all critical functionality
*	10 points = Attempt to write tests but most or all tests fail or are ineffective

As a rule of thumb, you should aim for **at least 10 complete test cases.**  This does not mean just writing 10 lines of code and calling them “tests.”  You may also need more tests to comprehensively test your program and receive full credit.  If you’re not sure if you have enough tests, ask the instructor.  Besides writing the tests, make sure that all of your tests pass to receive full credit!

### Optimization (40 points)
As part of this challenge project, you should optimize the efficiency of each function in the classes you designed and wrote.  This means striving for the best possible time complexity for each function in your program.  In general, you should aim for an average-case time complexity of **O(log *n*)** or better for most functions.  If the worst case is linear (or worse) and you're not sure how to do the average-case analysis, feel free to ask your instructor for help.  Similarly, if don't think you can get the time complexity below O(*n*) for a particular algorithm, discuss this with the instructor to confirm that it is indeed the case.

Your optimization will be graded on the following rubric:
*	40 points = All functions O(log *n*) or better where possible (as judged by the instructor).
*	30 points = One or more functions which unnecessarily have worse than O(log *n*) time complexity, but more applications (as judged by the instructor) of effective use of STL containers with sublinear functions as listed above.
*	20 points = At least one effective usage of STL containers to achieve sublinear time complexity, but more instances (as judged by the instructor) that have linear or worse time complexity.
*	10 points = Many functions with linear or worse time complexity, and little to no effective application of STL containers with sublinear functions as listed above.

### Code style (10 points)
Your code may also be judged based on style.  At a basic level, this simply means that you should create logically organized, well-named and well-commented code.  If the instructor can’t understand what you did, you may lose points in this category.  For full credit, you should have consistent, professional comments in your code and logical code organization.  Ask the instructor if you are not sure if your code meets this standard.

## Part 3: Analysis (60 points)
The last part of the project is to analyze the time complexity of your implementation using Big-O notation.  Choose **two functions** essential to your project that you want to analyze, **ideally a couple of the more complex ones**, making significant use of the standard library containers and possibly containing if-statements and loops.  If any functions in your project have loops, at least one of the functions that you analyze should be a function that contains a loop  (**note**: there's a good chance that a fully optimized project will not contain many explicit loops).  
For each function that you analyze **(30 points per function)**, answer the following questions:
*	What conditions will produce the best case for this function in terms of computation time?  (Or, if you think the best case and worst case are the same, explain why.)
*	What conditions will produce the worst case for this function in terms of computation time?
*	What is the best-case time complexity of this function?  Express your answer using Big-O notation, and explain how you got your answer.
*	What is the worst-case time complexity of this function?  Express your answer using Big-O notation, and explain how you got your answer.
*	As part of your analysis, you should also ***explain how use of the standard library containers offers better time complexity than using a simple array, and identify what the worse time complexity for the function would be if you had used an array as your backing data structure instead***.

In all your answers, ***make sure you clearly define n and consider potentially large values of n (even if your project was hardcoded to have n be small)***.
