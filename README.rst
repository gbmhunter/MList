=====
MList
=====

---------------------------------------------------------------------------------------------
A microcontroller-friendly doubly-linked list container.
---------------------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MList.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MList

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2014-10-16
- Last Modified: 2014-10-17
- Version: v1.1.0.0
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

Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet.

Usage
=====

See the unit tests in the 'test/' directory for basic examples.
	
Changelog
=========

========= ========== =========================================================================================
Version   Date       Comment
========= ========== =========================================================================================
v1.1.0.0  2014-10-17 List::Insert() takes an iterator as an input parameter rather than a integer position, closes #2. Removed '<=' operator overload and instead implemented '!=' overload for halting iterator for loop, closes #1. Added unit test for inserting two nodes into list, closes #3. Removed unnecessary dependencies from README, closes #4.
v1.0.0.0  2014-10-16 Initial commit, basic List, ListNode and Iterator objects have been implemented with one unit test.
========= ========== =========================================================================================