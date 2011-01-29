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
//! Called when Max creates the object
void* ÇPROJECTNAMEASIDENTIFIERÈ::alloc(t_symbol* s, long argc, t_atom* argv)
{
	ÇPROJECTNAMEASIDENTIFIERÈ* x = (ÇPROJECTNAMEASIDENTIFIERÈ*) object_alloc(s_ÇPROJECTNAMEASIDENTIFIERÈ_class);
	
	if (x != NULL) {
		/* Create inlet */
		dsp_setup(&x->m_obj, 1);
		/* Create outlet */
		outlet_new((t_object*)&x->m_obj, "signal");
        
        
        /* Initialize member variables. */
        x->gain = 1.0;
	}
	
	return x;
}

//! Called when object is deleted
void ÇPROJECTNAMEASIDENTIFIERÈ::free(ÇPROJECTNAMEASIDENTIFIERÈ* x) 
{
    dsp_free(&x->m_obj);    /* Must call this first!*/
             
    /* Do any deallocation needed here. */
}

#pragma mark -
#pragma mark Max Helpers
//! Inlet and outlet assistant messages
void ÇPROJECTNAMEASIDENTIFIERÈ::assist(ÇPROJECTNAMEASIDENTIFIERÈ* x, void* b, long m, long a, char* s)
{
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:
				sprintf(s, "(signal) input\n(float/int) gain");
				break;
		}
	} 
	else {
		switch (a) {
			case 0:
				sprintf(s, "(signal) output");
				break;
		}		
	}
}

#pragma mark -
#pragma mark DSP
//! DSP method
void ÇPROJECTNAMEASIDENTIFIERÈ::dsp(ÇPROJECTNAMEASIDENTIFIERÈ* x, t_signal** sp, short* count)
{
	/* Change here if you have more/less inlets and outlets */
	dsp_add(ÇPROJECTNAMEASIDENTIFIERÈ::perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}

//! Perform method
t_int* ÇPROJECTNAMEASIDENTIFIERÈ::perform(t_int* w)
{
    ÇPROJECTNAMEASIDENTIFIERÈ* x = (ÇPROJECTNAMEASIDENTIFIERÈ*)w[1];
    t_sample* in = (t_sample*)w[2];
    t_sample* out = (t_sample*)w[3];
    int n = (int)w[4];
    
    while (n--) {
        /* Do any signal processing here */
        *out++ = *in++ * x->gain;
    }
    
    return w + 5;
}

#pragma mark -
#pragma mark Inlets
//! Inlet received long
void ÇPROJECTNAMEASIDENTIFIERÈ::in_long(ÇPROJECTNAMEASIDENTIFIERÈ* x, long i)
{
    in_double(x, (double)i);
}

//! Inlet received double
void ÇPROJECTNAMEASIDENTIFIERÈ::in_double(ÇPROJECTNAMEASIDENTIFIERÈ* x, double f)
{
    long inlet = proxy_getinlet((t_object*)&x->m_obj);
    
    switch (inlet) {
        case 0:
            x->gain = f;
            break;
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
	
	/* Add class methods */
	class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ::assist, "assist", A_CANT, 0);
	class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ::dsp, "dsp", A_CANT, 0);
	class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ::in_long, "int", A_LONG, 0);
	class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ::in_double, "float", A_FLOAT, 0);
	
	/* Add attributes */
	
    class_dspinit(c);
	class_register(CLASS_BOX, c);
	s_ÇPROJECTNAMEASIDENTIFIERÈ_class = c;
	
	return 0;
}
