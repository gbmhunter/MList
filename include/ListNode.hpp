//!
//! @file				ListNode.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-16
//! @last-modified		2014-10-17
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef M_LIST_LIST_NODE_H
#define M_LIST_LIST_NODE_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	template < typename dataT >
	class ListNode;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>		// uint8_t, uint32_t, e.t.c
#include <iostream>

//===== USER LIBRARIES =====//
#include "MAssert/api/MAssertApi.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	template < typename dataT >
	class ListNode
	{

		public:
		dataT data;

		//! @brief		Pointer to the previous list element.
		ListNode<dataT> * prevListNode;

		//! @brief		Pointer to the next list element.
		ListNode<dataT> * nextListNode;
	};

} // namespace MbeddedNinja

#endif	// #ifndef M_LIST_LIST_NODE_H

// EOF
