/*
 *  ÇPROJECTNAMEÈ.cpp
 *  ÇPROJECTNAMEÈ
 *
 *  Created by ÇFULLUSERNAMEÈ on ÇDATEÈ.
 *  Copyright (C) ÇYEARÈ ÇORGANIZATIONNAMEÈ. All rights reserved.
 */
#include "ÇPROJECTNAMEÈ.h"

// Global class pointer
static t_class* s_ÇPROJECTNAMEASIDENTIFIERÈ_class = NULL;

#pragma mark -
#pragma mark Alloc & Free
void* ÇPROJECTNAMEASIDENTIFIERÈ::alloc(t_symbol* s, long argc, t_atom* argv)
{
	t_dictionary* d = object_dictionaryarg(argc, argv);
	
	if (d == NULL) {
		return NULL;
	}
	
	ÇPROJECTNAMEASIDENTIFIERÈ* x = (ÇPROJECTNAMEASIDENTIFIERÈ*) object_alloc(s_ÇPROJECTNAMEASIDENTIFIERÈ_class);
	
	if (x != NULL) {
		attr_dictionary_process(x, d);
		
		/* 1. Create inlets and outlets.
		 * i.e.	floatin((t_object*)x, 1);
		 *		x->m_outlet = floatout((t_object*)x, 1);
		 *
		 * 2. Initialize member variables.
		 */
	}
	
	return x;
}

void ÇPROJECTNAMEASIDENTIFIERÈ::free(ÇPROJECTNAMEASIDENTIFIERÈ* x) 
{
	/* Do any deallocation needed here. */
    delete x;
}

#pragma mark -
#pragma mark Max Helpers
void ÇPROJECTNAMEASIDENTIFIERÈ::assist(ÇPROJECTNAMEASIDENTIFIERÈ* x, void* b, long m, long a, char* s)
{
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:
				sprintf(s, "1st Inlet");
				break;
		}
	} 
	else {
		switch (a) {
			case 0:
				sprintf(s, "1st Outlet");
				break;
		}		
	}
}

#pragma mark -
#pragma mark Main
extern "C" int main(void)
{
	t_class* c;
	
	c = class_new("ÇPROJECTNAMEÈ", 
                  (method)ÇPROJECTNAMEASIDENTIFIERÈ::alloc, 
                  (method)ÇPROJECTNAMEASIDENTIFIERÈ::free, 
                  sizeof(ÇPROJECTNAMEASIDENTIFIERÈ), 
                  (method)0L, A_GIMME, 0);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
	
	/* Add class methods */
	class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ::assist, "assist", A_CANT, 0);
	
	/* Add attributes */
	
	class_register(CLASS_BOX, c);
	s_ÇPROJECTNAMEASIDENTIFIERÈ_class = c;
	
	return 0;
}
