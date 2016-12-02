#include "errorcheck.h"

                    /****************************
                     * Error Checking Functions *
                     ****************************/

/**************************************************************************
 * Function: InFileExistsAndIsNotEmpty
 *
 * This function checks if a text file exists and is not empty.
 *
 * Returns: Returns a bool of whether a file exists and is not empty.
 **************************************************************************/
/**
 * @brief InFileExistsAndIsNotEmpty
 * This function
 * @param inFileName the name of the file to test
 * @return Returns whether a file exists and is not empty.
 */
bool InFileExistsAndIsNotEmpty(string inFileName) {
    ifstream inFile;
    bool existsAndNotEmpty;
    existsAndNotEmpty = false;

    inFile.open(inFileName.c_str());

    if(inFile)
    {
        if (inFile.peek() == std::ifstream::traits_type::eof()) {
            existsAndNotEmpty = false;
        }
        else {
            existsAndNotEmpty = true;
            inFile.close();
        }
    }
    else{
        existsAndNotEmpty = false;
    }

    return existsAndNotEmpty;
}
