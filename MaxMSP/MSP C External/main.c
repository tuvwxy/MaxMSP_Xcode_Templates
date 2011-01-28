/*
 *  ÇPROJECTNAMEÈ.c
 *  ÇPROJECTNAMEÈ
 *
 *  Created by ÇFULLUSERNAMEÈ on ÇDATEÈ.
 *  Copyright ÇYEARÈ ÇORGANIZATIONNAMEÈ. All rights reserved.
 */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"

typedef struct _ÇPROJECTNAMEASIDENTIFIERÈ
{
	t_pxobject m_obj;
} t_ÇPROJECTNAMEASIDENTIFIERÈ;

static t_class* s_ÇPROJECTNAMEASIDENTIFIERÈ_class = NULL;

void* ÇPROJECTNAMEASIDENTIFIERÈ_new(t_symbol* s, long argc, t_atom* argv)
{
	t_dictionary* d = object_dictionaryarg(argc, argv);
	
	if (d == NULL) {
		return NULL;
	}
	
	t_ÇPROJECTNAMEASIDENTIFIERÈ* x = (t_ÇPROJECTNAMEASIDENTIFIERÈ*) object_alloc(s_ÇPROJECTNAMEASIDENTIFIERÈ_class);
	
	if (x != NULL) {
		attr_dictionary_process(x, d);
		
		/* Create inlet */
		dsp_setup((t_pxobject*)x, 1);
		/* Create outlet */
		outlet_new((t_object*)x, "signal");
		
		/* Initialize member variables. */
	}
	
	return x;
}

void ÇPROJECTNAMEASIDENTIFIERÈ_free(t_ÇPROJECTNAMEASIDENTIFIERÈ* x) 
{
	/* Do any deallocation needed here. */
	dsp_free((t_pxobject*)x);	/* Must call this first! */
}

t_int* ÇPROJECTNAMEASIDENTIFIERÈ_perform(t_int* w)
{
	t_ÇPROJECTNAMEASIDENTIFIERÈ* x = (t_ÇPROJECTNAMEASIDENTIFIERÈ*)(w[1]);
	t_float* in = (t_float*)(w[2]);
	t_float* out = (t_float*)(w[3]);
	int n = (int)(w[4]);
	
	while (n--) {
		/* Do any signal processing here */
		*out++ = *in++;
	}
	
	return w + 5;
}

void ÇPROJECTNAMEASIDENTIFIERÈ_dsp(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, t_signal** sp, short* count) 
{
	/* Change here if you have more/less inlets and outlets */
	dsp_add(ÇPROJECTNAMEASIDENTIFIERÈ_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}


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

int main(void)
{
	t_class* c;
	
	c = class_new("ÇPROJECTNAMEÈ", (method)ÇPROJECTNAMEASIDENTIFIERÈ_new, (method)ÇPROJECTNAMEASIDENTIFIERÈ_free, 
				  sizeof(t_ÇPROJECTNAMEASIDENTIFIERÈ), (method)0L, A_GIMME, 0);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
	
	/* Add class methods */
    class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ_dsp, "dsp", A_CANT, 0);
    class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ_assist, "assist", A_CANT, 0);
	
	/* Add attributes */
	
	class_dspinit(c);
	class_register(CLASS_BOX, c);
	s_ÇPROJECTNAMEASIDENTIFIERÈ_class = c;
	
	return 0;
}
