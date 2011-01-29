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

#pragma mark -
#pragma mark Object Struct
typedef struct _ÇPROJECTNAMEASIDENTIFIERÈ
{
	t_pxobject m_obj;
    double gain;
} t_ÇPROJECTNAMEASIDENTIFIERÈ;

#pragma mark -
#pragma mark Function Prototypes
void* ÇPROJECTNAMEASIDENTIFIERÈ_new(t_symbol* s, long argc, t_atom* argv);
void ÇPROJECTNAMEASIDENTIFIERÈ_free(t_ÇPROJECTNAMEASIDENTIFIERÈ* x);
void ÇPROJECTNAMEASIDENTIFIERÈ_assist(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, void* b, long m, long a, char* s);
void ÇPROJECTNAMEASIDENTIFIERÈ_dsp(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, t_signal** sp, short* count);
t_int* ÇPROJECTNAMEASIDENTIFIERÈ_perform(t_int* w);
void ÇPROJECTNAMEASIDENTIFIERÈ_long(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, long i);
void ÇPROJECTNAMEASIDENTIFIERÈ_double(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, double f);

// Global class pointer
static t_class* s_ÇPROJECTNAMEASIDENTIFIERÈ_class = NULL;

#pragma mark -
#pragma mark Alloc & Free
void* ÇPROJECTNAMEASIDENTIFIERÈ_new(t_symbol* s, long argc, t_atom* argv)
{
	t_ÇPROJECTNAMEASIDENTIFIERÈ* x = (t_ÇPROJECTNAMEASIDENTIFIERÈ*) object_alloc(s_ÇPROJECTNAMEASIDENTIFIERÈ_class);
	
	if (x != NULL) {
		
		/* Create inlet */
		dsp_setup((t_pxobject*)x, 1);
		/* Create outlet */
		outlet_new((t_object*)x, "signal");
		
		/* Initialize member variables. */
        x->gain = 1.0;
	}
	
	return x;
}

void ÇPROJECTNAMEASIDENTIFIERÈ_free(t_ÇPROJECTNAMEASIDENTIFIERÈ* x) 
{
	dsp_free((t_pxobject*)x);	/* Must call this first! */
    
	/* Do any deallocation needed here. */
}

#pragma mark -
#pragma mark Max Helpers
void ÇPROJECTNAMEASIDENTIFIERÈ_assist(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, void* b, long m, long a, char* s)
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
void ÇPROJECTNAMEASIDENTIFIERÈ_dsp(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, t_signal** sp, short* count) 
{
	/* Change here if you have more/less inlets and outlets */
	dsp_add(ÇPROJECTNAMEASIDENTIFIERÈ_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}

t_int* ÇPROJECTNAMEASIDENTIFIERÈ_perform(t_int* w)
{
    t_ÇPROJECTNAMEASIDENTIFIERÈ* x = (t_ÇPROJECTNAMEASIDENTIFIERÈ*)w[1];
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
void ÇPROJECTNAMEASIDENTIFIERÈ_long(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, long i)
{
    ÇPROJECTNAMEASIDENTIFIERÈ_double(x, (double)i);
}

//! Inlet received double
void ÇPROJECTNAMEASIDENTIFIERÈ_double(t_ÇPROJECTNAMEASIDENTIFIERÈ* x, double f)
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
int main(void)
{
	t_class* c;
	
	c = class_new("ÇPROJECTNAMEÈ", 
                  (method)ÇPROJECTNAMEASIDENTIFIERÈ_new, 
                  (method)ÇPROJECTNAMEASIDENTIFIERÈ_free, 
				  sizeof(t_ÇPROJECTNAMEASIDENTIFIERÈ), 
                  (method)0L, A_GIMME, 0);
	
	/* Add class methods */
    class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ_assist, "assist", A_CANT, 0);
    class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ_dsp, "dsp", A_CANT, 0);
    class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ_long, "int", A_LONG, 0);
    class_addmethod(c, (method)ÇPROJECTNAMEASIDENTIFIERÈ_double, "float", A_FLOAT, 0);
	
	/* Add attributes */
	
	class_dspinit(c);
	class_register(CLASS_BOX, c);
	s_ÇPROJECTNAMEASIDENTIFIERÈ_class = c;
	
	return 0;
}
