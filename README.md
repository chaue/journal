# Journal using C++ (PIC10C Project)

__Big Picture__
* going to start with a simple console project (can implement GUI using QT in future)
* originally wanted to connect this project with a SQL database, but attempting to use the sqlapi++ libraries proved to be too complicated
  * after downloading the library and reading the documentation, I realized the code wouldn't compile due to issues with linking the correct library files
  * after attempts at debugging, I concluded the issues were out of the scope of this class and decided to use streams instead. 
* will instead store information in files(which will be located in the project directory), future improvements can be made to improve security

__UI Ideas__
* start at intro screen and give options to write or read entries
  * take user input as a number and show respective "page" based on choice 
  * clear screen before showing new one to reduce clutter on screen?
* pages for writing and reading entries procedurally accept inputs from user 
  * after all inputs are checked and accepted, write the file and show confirmation
  * after accepting indentifier, find and read the file, or show error message
  * show a message to go back to intro screen after a key press
  
__Extras__
* option for user and password combination, which will be stored in a file and read before the UI is shown. 
* possible ways to encrypt files or password protect them?
* write files in another directory

__Update 1__
* Outlined a super basic Journal class
  * depends on an Entry class of some sort for now
* Ideas for implementation
  * Journal class to allow changes to "GUI" details
    * These details will be preserved for future uses
    * Save details in a file, which will be accessed and used to create the Journal object before starting app
  * Entry class to write or read entries?
    * Might not need the extra level of organization 
    * regular functions in the main may suffice, and can implement template functions or other tricks that way
    
__Update 2__
* "Finished" the journal.write() member function
  * Code won't compile due to LNK2019 and LNK1120 errors
  * The issue might lie in using Entry objects in the Journal object
    * Journal can't compile if Entry isn't defined first?
  * Can try moving the member function to the Entry class instead of using the Entry class through Journal
    * Essentially skipping the middle man 
    
__Update 3__
* Fixed compiling errors
  * I combined the header and cpp files for the Journal and Entry classes into the Journal class' files
  * Code compiles since classes and member functions can be declared and defined in order
    * Entry needed to be declared and defined first due to Journal requiring them
* Fixed compile error regarding the entry.operator() template function
  * It turns out to_string couldn't accept certain data types as inputs, namely strings
  * overloaded the template function with a string type (1)
* Fixed file names to include the .txt extension 
  * Realized files are written directly inside the project directory, could maybe add an option to write and store files in a preferred directory
  
__Update 4__
* Fixed logic error with cin buffer
  * After accepting an integer from the buffer, cin.clear() does not ignore the newline character
  * changed it to cin.ignore() to skip over the newline character (2)
  * quick fix for line number output when accepting text
* Fixed lack of delimiters in file input
  * faulty delimiter assignment in constructor for Entry
  
__Update 5__ 
* Looped the program and added option to quit 
 * added error handling for file reading
   * now if files do not exist(user entered a date that did not have a corresponding entry), the file is not read and the user is prompted to enter another one
* clears screen after every action(write or read) (3)
  * user can read the output before pressing enter to clear and move onto next action (4)
* Next: add user and password combinations

__Update 6__
* Added a login "system" with username and passwords
  * stores username and password combinations in login.txt
    * the user is prompted to create a login if the file is empty(i.e. first time)
  * user is prompted to log in when first starting the program (5)
    * error handling checks that the user login matches a pair on login.txt before proceeding under that username
  * password inputs are hidden from view for security (6)
  * users cannot read entries that are not written by them
* Shortcomings
  * the username password pairs are not securely stored
    * a user can directly open login.txt and view all the combinations
  * due to the current system for writing entries, there can only be one entry per day(regardless of who wrote it)
    * if one user wrote an entry on 01/01/0001, other users can no longer write an entry for that day
* Possible solutions
  * encrypting login.txt
    * the file can be encrypted after updated(and decrypted before reading/checking combinations)
  * different naming scheme for entry files
    * this might defeat the purpose of verifying username/password before reading entries however
    
__PIC10 Concepts Used__
* template functions
  * the Entries class has a template function to accept any numeric input(int, double, etc) when writing into a file
* function objects
  * the Entries class uses the () operator to accept text inputs for writing

__References used__
* SQLAPI+ documentation
  * http://www.sqlapi.com/
* Some issues with using SQLAPI+
  * checking error LNK2019
    * https://stackoverflow.com/questions/19886397/how-to-solve-the-error-lnk2019-unresolved-external-symbol-function/46673248
  * attempts to link library files
    * https://social.msdn.microsoft.com/Forums/vstudio/en-US/aa91d7f7-cc79-4b48-b852-94f7f1bd964a/how-use-install-the-sqlapi-library?forum=vcgeneral
* reading a file using delimiters
  * http://www.cplusplus.com/forum/beginner/113465/
* (1) https://stackoverflow.com/questions/40554964/c-how-to-check-if-variable-is-stdstring-type
* (2) http://www.cplusplus.com/forum/beginner/203085/
* (3) http://www.cplusplus.com/articles/4z18T05o/#Windows
* (4) https://stackoverflow.com/questions/42818899/detecting-enter-key-in-c
* (5) https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
* (6) https://stackoverflow.com/questions/6899025/hide-user-input-on-password-prompt
