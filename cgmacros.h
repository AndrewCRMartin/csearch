#ifndef __CGMACROS_H__
#define __CGMACROS_H__

#define logical_f(x) ((x) ? f77_true : f77_false)
#define struct_alloc(structure_name) (struct structure_name *) alloc(sizeof(struct structure_name))
#define push(p,a) ((a)->next=(p), (p)=(a))
#define ref(a,i) (*((a)+(i)))
#define square(x) ((x)*(x))
#define add_double_list(head,tail,newp) {\
	(newp)->next = (newp)->prev = null; \
        if ((head) == null) (head) = (tail) = (newp); \
	else { \
	     (tail)->next = (newp); \
	     (newp)->prev = (tail); \
	     (tail) = (newp); \
	     } \
	}
 
#define join_double_lists(head1,tail1,head2,tail2) {\
	if ((head1) == null) { \
	    (head1) = (head2); \
	    (tail1) = (tail2); \
	    } \
	else if ((head2) == null) { \
	    (head2) = (head1); \
	    (tail2) = (tail1); \
	    } \
	else { \
	    (tail1)->next = (head2); \
	    (head2)->prev = (tail1); \
	    (tail1) = (tail2); \
	    (head2) = (head1); \
	    } \
	}	
 
#define swap(a,b,t) {\
        (t) = (a); \
        (a) = (b); \
        (b) = (t); \
        }
 
#define copy(acopy,a,n) {\
        int i; \
        for (i=0; i<(n); i++) (acopy)[i] = (a)[i]; \
        }
 
#define walk_atoms(f) {\
	struct dof *p; \
	struct atom *atp,**atpp; \
	for (p=dof_head; p; p=p->next) \
	    if (p->atoms) \
		for (atpp=p->atoms; (atp= *atpp); atpp++) {f} }
 
#define walk_over_clumps(clp,f) {\
        struct atom *atp,**atpp; \
        for (atpp=(clp)->atoms; (atp = *atpp); atpp++) {f}}
 
#define walk_over_sideres(srp,f) {\
        struct clump *clp,**clpp; \
        struct atom *atp,**atpp; \
        for (clpp=(srp)->clumps; (clp = *clpp); clpp++) \
	    for (atpp=clp->atoms; (atp = *atpp); atpp++) {f}}
 
#define walk_clumps(srp,f) {\
        struct clump *clp,**clpp; \
        for (clpp=(srp)->clumps; (clp = *clpp); clpp++) {f}}
 
#define walk_dofs(f) {\
        struct dof *dofp; \
        for (dofp=dof_head; dofp; dofp = dofp->next) {f}}


#endif
