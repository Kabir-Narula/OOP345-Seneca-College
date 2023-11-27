

#pragma once
// Workshop 6 - STL Containers
// 2021/12/05 - Gideon

#ifndef SDDS_FLAGS_H
#define SDDS_FLAGS_H

namespace sdds
{
    // Options for displaying the files and directories
    enum class FormatFlags {
        LONG,     // to display in long format
    };

    // Determine the type of filesystem resource
    enum class NodeType {
        DIR,   // Directory
        FILE   // Regular File
    };

    // Options for performing a filesystem operation
    enum class OpFlags {
        RECURSIVE,  // run an operation recursively
    };
}

#endif
