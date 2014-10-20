=====
MList
=====

--------------------------------------------------------
A microcontroller-friendly doubly-linked list container.
--------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MList.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MList

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2014-10-16
- Last Modified: 2014-10-20
- Version: v1.4.3.0
- Company: mbedded.ninja
- Project: MToolkit Module
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

MList is a microcontroller-friendly doubly-linked list container.

Features:

- Embedded (microcontroller) support
- Small flash/RAM memory footprint (no depedance on any standard C++ libraries)
- Unit tests
- Doxygen-style well-documented API.
- Portability
	

Code Dependencies
=================

The following table lists all of MStrings dependencies.

====================== ==================== ======================================================================
Dependency             Delivery             Usage
====================== ==================== ======================================================================
<cstdint>              C standard library   For platform agnostic fixed-width integers.
MAssert                External module      Providing runtime safety checks against this module.
MUnitTest              External module      Framework for unit tests.
====================== ==================== ======================================================================

Example
=======

::

	#include "MList/api/MListApi/hpp"
	
	using namespace MbeddedNinja;

	int main()
	{
		// Create a new linked-list which will hold doubles
		List<double> list;
	
		// Some data to add to the list
		double myDouble1 = 5.5;
		double myDouble2 = 8.9;
	
		// Create a iterator and point it to the start of the list
		List<double>::Iterator it = list.Start();
		
		// Add some nodes to the list
		list.Insert(it, myDouble1);
		list.Insert(it, myDouble2);
	
		// Iterate through all nodes in the list and print the data
		for(it = list.Start(); it != list.End(); it++)
		{
			std::cout << "data = '" << *it << "'" << std::endl;		
		}
	}
	
	// This will print...
	// data = '5.5'
	// data = '8.9'.
	
See the unit tests in the 'test/' directory for more examples.
	
Changelog
=========

========= ========== =========================================================================================
Version   Date       Comment
========= ========== =========================================================================================
v1.4.3.0  2014-10-20 Removed the printing of data to ostream, the data object may not support the '<<' operator, closes #23.
v1.4.2.0  2014-10-20 An assert is now raised if iterator operations are called before an iterator is assigned to a list, closes #21. Refractored the List::Insert() method so that it has the same structure as List::Delete(), closes #13. Added unit tests that delete nodes from the start and the end of lists, as well as many from the middle, closes #12. Added operator overload for addition of Iterator and integer so we can increment/decrement more than one node at a time, closes #6.
v1.4.1.0  2014-10-19 Deleted BasicTests.cpp as it was no longer needed.
v1.4.0.0  2014-10-19 Assert is now raised if memory allocation fails when you create a new node, closes #10. Renamed BasicTests.cpp to InsertNodeTests.cpp, closes #16. Added postfix decrement operator overload for Iterator class, closes #17. Added basic example to README, closes #14.
v1.3.0.0  2014-10-17 Added List::NumNodes() method which returns the number of nodes in list, closes #11. Added ability to delete a node and added one unit test, closes #9.
v1.2.0.0  2014-10-17 List now supports the addition of nodes in the middle of the list, closes #8. Added unit test that inserts many nodes, closes #5. Added ability to enable/disable debug printing, closes #7.
v1.1.0.0  2014-10-17 List::Insert() takes an iterator as an input parameter rather than a integer position, closes #2. Removed '<=' operator overload and instead implemented '!=' overload for halting iterator for loop, closes #1. Added unit test for inserting two nodes into list, closes #3. Removed unnecessary dependencies from README, closes #4.
v1.0.0.0  2014-10-16 Initial commit, basic List, ListNode and Iterator objects have been implemented with one unit test.
========= ========== =========================================================================================