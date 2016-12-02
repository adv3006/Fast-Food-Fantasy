#ifndef ERRORCHECK_H_
#define ERRORCHECK_H_

/**************************************************************************
*  						 Error-Checking Header
*
* This header file lets us declare the error checking functions.
*
**************************************************************************/
#include <fstream>

using namespace std;
/**************************************************************************
*  						 Function: InFileExistsAndIsNotEmpty
*
* This function checks if a text file exists and is not empty. This is used
* to check if saved data information exists and can be properly loaded.
**************************************************************************/
/**
 * @brief InFileExistsAndIsNotEmpty
 * This function
 * @param inFileName the name of the file to test
 * @return Returns whether a file exists and is not empty.
 */
bool InFileExistsAndIsNotEmpty(string inFileName);

#endif /* ERRORCHECK_H_ */
