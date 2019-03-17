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
