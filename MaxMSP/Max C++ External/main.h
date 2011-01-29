/*
 *  ÇPROJECTNAMEÈ.h
 *  ÇPROJECTNAMEÈ
 *
 *  Created by ÇFULLUSERNAMEÈ on ÇDATEÈ.
 *  Copyright (C) ÇYEARÈ ÇORGANIZATIONNAMEÈ. All rights reserved.
 */
#ifndef _ÇPROJECTNAMEASIDENTIFIERÈ_h_
#define _ÇPROJECTNAMEASIDENTIFIERÈ_h_

extern "C" {
#include "ext.h"
#include "ext_obex.h"
}

class ÇPROJECTNAMEASIDENTIFIERÈ
{
public:
    ÇPROJECTNAMEASIDENTIFIERÈ() {}
    ~ÇPROJECTNAMEASIDENTIFIERÈ() {}
    
    //! Called when Max creates the object
    static void* alloc(t_symbol* s, long argc, t_atom* argv);
    
    //! Called when object is deleted
    static void free(ÇPROJECTNAMEASIDENTIFIERÈ* x);
    
    //! Inlet and outlet assistant messages
    static void assist(ÇPROJECTNAMEASIDENTIFIERÈ* x, void* b, long m, long a, char* s);
    
	t_object m_obj;
    
private:
};

#endif // _ÇPROJECTNAMEASIDENTIFIERÈ_h_