/*
 *  ÇPROJECTNAMEÈ.c
 *  ÇPROJECTNAMEÈ
 *
 *  Created by ÇFULLUSERNAMEÈ on ÇDATEÈ.
 *  Copyright (C) ÇYEARÈ ÇORGANIZATIONNAMEÈ. All rights reserved.
 */

#include "ext.h"
#include "ext_obex.h"

#pragma mark -
#pragma mark Object Struct
typedef struct _ÇPROJECTNAMEASIDENTIFIERÈ
{
	t_object m_obj;
} t_ÇPROJECTNAMEASIDENTIFIERÈ;

#pragma mark -
#pragma mark Function Prototypes
void* ÇPROJECTNAMEASIDENTIFIERÈ_new(t_symbol* s, long argc, t_atom* argv);
void ÇPROJECTNAMEASIDENTIFIERÈ_free(t_ÇPROJECTNAMEASIDENTIFIERÈ* x);
void ÇPROJECTNAMEASIDENTIFIERÈ_assist(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, void* b, long m, long a, char* s);

// Global class pointer
static t_class* s_ÇPROJECTNAMEASIDENTIFIERÈ_class = NULL;

#pragma mark -
#pragma mark Alloc & Free
void* ÇPROJECTNAMEASIDENTIFIERÈ_new(t_symbol* s, long argc, t_atom* argv)
{
	t_dictionary* d = object_dictionaryarg(argc, argv);
	
	if (d == NULL) {
		return NULL;
	}
	
	t_ÇPROJECTNAMEASIDENTIFIERÈ* x = (t_ÇPROJECTNAMEASIDENTIFIERÈ*) object_alloc(s_ÇPROJECTNAMEASIDENTIFIERÈ_class);
	
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

void ÇPROJECTNAMEASIDENTIFIERÈ_free(t_ÇPROJECTNAMEASIDENTIFIERÈ* x) 
{
	/* Do any deallocation needed here. */
}

#pragma mark -
#pragma mark Max Helpers
void ÇPROJECTNAMEASIDENTIFIERÈ_assist(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, void* b, long m, long a, char* s)
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
int main(void)
{
	t_class* c;
	
	c = class_new("ÇPROJECTNAMEÈ", 
                  (method)ÇPROJECTNAMEASIDENTIFIERÈ_new, 
                  (method)ÇPROJECTNAMEASIDENTIFIERÈ_free, 
                  sizeof(t_ÇPROJECTNAMEASIDENTIFIERÈ), 
                  (method)0L, A_GIMME, 0);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
	
	/* Add class methods */
	class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ_assist, "assist", A_CANT, 0);
	
	/* Add attributes */
	
	class_register(CLASS_BOX, c);
	s_ÇPROJECTNAMEASIDENTIFIERÈ_class = c;
	
	return 0;
}
