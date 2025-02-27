# Questions:

    -   modularize CICD runners and containers

the problem is that each container is independent in env thus dependency issue

    -   Clang-tidy false-positive flagged

    -   gcov setup

I enter an infinite halt when installing certain dependencies

    -   Definition of good interface and implementation separation and modularization

    -   Makefile: what exactly are they, why are they everywhere

# Answers:

# Feedback:

    -   First, see if we can branch off from very first commit of root, thus that eventually we merge/rebase then squash and the commit history will be clean

    -   Second, rename Components/ to src/

    -   "put tests close to the components" (our top-level tests/ is ok) 

    -   cmake has integration for google test- use gtest_discover_tests

    -   add documentation generation

    -   can write e2e test in python-write python script, need to pretend what a user is doing-puppeter library??

    -   include all clang-tidy then only disable those that r needed 

    -   nest the header file deeper than the cc file 

    -   look at prof different calculator implementations