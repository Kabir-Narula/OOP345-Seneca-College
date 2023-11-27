

#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include <type_traits>
#include <forward_list>

#include "Filesystem.h"
#include "Filesystem.h"
#include "Directory.h"
#include "Directory.h"
#include "File.h"
#include "File.h"
#include "Flags.h"

void printLine() {
    std::cout << "--------------------------\n";
}

void printHeader(std::string label) {
    size_t padLeft = (26 - label.length()) / 2;

    printLine();
    std::cout << std::setw(padLeft) << " " << label << std::endl;
    printLine();
}

int cout = 0;

// ws filesystem.txt
int main(int argc, char** argv) {
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    /*************************************************
     * Creating the Filesystem
     **************************************************/

    printHeader("FILESYSTEM");

    try {
        sdds::Filesystem failedFs("non-existentfile");
    }
    catch (...) {
        std::cout << "**EXPECTED EXCEPTION: Filesystem not created with invalid filename.\n" << std::endl;
    }

    if (std::is_copy_constructible<sdds::Filesystem>::value || std::is_copy_assignable<sdds::Filesystem>::value) {
        std::cout << "**EXCEPTION: Filesystem should not support copy operations.\n" << std::endl;
    }

    if ((!std::is_move_constructible<sdds::Filesystem>::value) || (!std::is_move_assignable<sdds::Filesystem>::value)) {
        std::cout << "**EXCEPTION: Filesystem should support move operations.\n" << std::endl;
    }

    sdds::Filesystem fs(argv[1]);

    std::vector<sdds::FormatFlags> fflags;

    std::vector<sdds::OpFlags> oflags;
    oflags.push_back(sdds::OpFlags::RECURSIVE);

    sdds::Directory* working_dir = fs.get_current_directory();
    working_dir->display(std::cout);

    printLine();

    /*************************************************
     * Changing directories
     **************************************************/
    printHeader("CHANGE DIR");

    fflags.push_back(sdds::FormatFlags::LONG);

    try {
        working_dir = fs.change_directory("pics");
    }
    catch (std::invalid_argument&) {
        std::cout << "**EXPECTED EXCEPTION: Couldn't change directory to invalid directory.\n" << std::endl;
    }

    working_dir = fs.change_directory("images/");
    working_dir->display(std::cout, fflags);

    printLine();

    /*************************************************
     * Finding a file in a directory
     **************************************************/
    printHeader("FIND");

    sdds::File* elephant_image = dynamic_cast<sdds::File*>(working_dir->find("elephant", oflags));
    if (!elephant_image) {
        std::cout << "**EXPECTED ERROR: File elephant not found in " << working_dir->path() << " recursively\n" << std::endl;
    }

    elephant_image = dynamic_cast<sdds::File*>(working_dir->find("elephant.png"));
    if (!elephant_image) {
        std::cout << "**EXPECTED ERROR: File elephant.png not found in " << working_dir->path() << " non-recursively\n" << std::endl;
    }

    elephant_image = dynamic_cast<sdds::File*>(working_dir->find("elephant.png", oflags));

    std::cout << elephant_image->path() << " was found in fileystem" << std::endl;

    printLine();


    /*************************************************
     * Adding a directory to another directory
     **************************************************/
    printHeader("ADD TO DIRECTORY");
    sdds::Directory* classified = new sdds::Directory("classified/");
    *classified += new sdds::File(".aliens.txt", "Are aliens real? Go to Area 51 and find out!");
    *classified += new sdds::File(".polls.txt", "Polling results for the current election are in here.");

    std::cout << "Created directory " << classified->name() << std::endl;
    classified->display(std::cout, fflags);

    working_dir = fs.change_directory();
    working_dir = fs.change_directory("documents/");
    std::cout << "\nAdding " << classified->name() << " to " << working_dir->path() << std::endl;

    *working_dir += classified;

    working_dir->display(std::cout, fflags);

    printLine();

    /*************************************************
     * Removing a directory
     **************************************************/
    printHeader("REMOVE");

    working_dir = fs.change_directory();
    std::cout << "Current size of filesystem is " << working_dir->size() << " bytes\n";
    std::cout << "Current size of documents/ is " << working_dir->find("documents/")->size() << " bytes\n\n";

    try {
        working_dir->remove("documents/");
    }
    catch (...) {
        std::cout << "**EXPECTED EXCEPTION: Trying to remove a directory without passing the recursive flag.\n\n";
    }

    working_dir->remove("documents/", oflags);

    std::cout << "After removing documents/\n";
    working_dir->display(std::cout, fflags);

    printLine();

    return cout;
}
