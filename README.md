# Journal using C++ (PIC10C Project)

__Big Picture__
* going to start with a simple console project (can implement GUI using QT in future)
* originally wanted to connect this project with a SQL database, but attempting to use the sqlapi++ libraries proved to be too complicated 
* will instead store information in files(which will be located in the project directory), future improvements can be made to improve security

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
    

__References used__
* reading a file using delimiters
  * http://www.cplusplus.com/forum/beginner/113465/
