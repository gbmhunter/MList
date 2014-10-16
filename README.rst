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
- Last Modified: 2014-10-16
- Version: v1.0.0.0
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
<cinttypes>            C standard library   For platform agnostic printf() specifiers.
<cstdint>              C standard library   For platform agnostic fixed-width integers.
<cstdio>               C standard library   To use snprintf() for appending integers, floats and doubles to the ends of a string.
<cstring>              C standard library   For use of strlen() and strcpy().
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
v1.0.0.0  2014-10-16 Initial commit, basic List, ListNode and Iterator objects have been implemented with one unit test.
========= ========== =========================================================================================