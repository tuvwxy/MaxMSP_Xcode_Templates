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
#include "z_dsp.h"
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
    
    //! DSP method
    static void dsp(ÇPROJECTNAMEASIDENTIFIERÈ* x, t_signal** sp, short* count);
    
    //! Perform method
    static t_int* perform(t_int* w);
    
    //! Inlet received long
    static void in_long(ÇPROJECTNAMEASIDENTIFIERÈ* x, long i);
    
    //! Inlet received double
    static void in_double(ÇPROJECTNAMEASIDENTIFIERÈ* x, double f);
    
	t_pxobject m_obj;
    
private:
    
    double gain;
};

#endif // _ÇPROJECTNAMEASIDENTIFIERÈ_h_