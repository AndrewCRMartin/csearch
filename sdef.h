#ifndef __SDEF_H__
#define __SDEF_H__

#define chain_closure_t     1
#define backbone_t          2
#define sidechain_t         3
#define write_coordinates_t 4
#define status_t            5
#define rbest_t             6
#define evaluate_t	    7
 
union dof_descriptor {
    struct chain_closure_d *chain_closure_d;
    struct backbone_d *backbone_d;
    struct sidechain_d *sidechain_d;
    struct write_coordinates_d *write_coordinates_d;
    struct status_d *status_d;
    struct rbest_d *rbest_d;
    struct evaluate_d *evaluate_d;
    };
 
typedef union dof_descriptor dof_descriptor;
 
struct dof {					/* degree of freedom */
    int dof_type;
    int iter;
    int restart_iter;
    logical ok;
    dof_descriptor *desc;
    struct atom **atoms;
    struct dof *next,*prev;
    };
 
struct chain_closure_d {
    float maxdt;
    float maxg;
    float maxevdw;
    logical cistrans;
    int startres;
    int atmind[7][3];
    float clsbond[3][3],clsangle[3][3];
    logical clscistrans[3];
    int pos_n[5],pos_ca[5],pos_c[5];
    struct atom *first_n;
    struct atom *at_n[3],*at_h[3],*at_ca[3],*at_cb[3],
		*at_cg[3],*at_cd[3],*at_c[3],*at_o[3],*at_ht1[3];
    };
 
struct backbone_d {
    int resno;
    float maxevdw;
    logical cistrans;
    logical forward;
    logical nter,cter;
    int closing_atom;
    float closing_distance;
    float maxdt;
    logical qdelta;
    float grid;
    logical tersym;
    struct atom *at_n,*at_h,*at_ca,*at_cb,*at_cg,*at_cd,*at_c,*at_o,*at_ht1;
    float omega,phi,psi;
    int ntermap;
    struct pepmap *termap;
    };
 
struct sidechain_d {
    int sideopt;
    int evalopt;
    double (*eval_func) ();
    float energy;
    int ncomb;
    int maxsideiter;
    int nresidues;
    struct sideres **residues;
    };
 
struct sideres {
    int resno;
    int nclump;
    logical special;
    float sgrid,maxevdw;
    logical vavoid,clump_symmetry;
    struct clump **clumps;
    float *beste;
    float **bestxpp,**bestypp,**bestzpp;
    int nconf;
    int natom;
    int *atomp;		/* Zero terminated list of sidchain atoms. */
    struct resphi *torsions;
    struct resphi *impropers;
    int *donors;	/* Zero terminated list of hydrogen bond donors */
    int *acceptors;	/* Zero terminated list of acceptors */
    float *refx,*refy,*refz;
    int *sidehits;
    logical changed;
    float avoidxmin,avoidxmax,avoidrmax,avoidxcenter,avoidextent,avoidvdwrmax;
    int count;		/* Keeps track of successes for ALL option */
    };
 
struct resphi {		/* Stores list of sidechain torsions */
    int nphi;
    short int *ip,*jp,*kp,*lp,*icp;
    };
 
struct clump {
    int symmetry;
    int natom;
    struct atom **atoms;
    struct atom *free_atom;
    float avoidxmin,avoidxmax,avoidrmax,avoidxcenter,avoidextent,avoidvdwrmax;
    float cur_phi,*best_phi;
    };
 
struct atom {
    int atomno;
    int ante[3];		/* construction order is 0-1-2-atomno */
    float bond;
    float angle;
    float torsion;
    float torsion_period;
    float offset;
    int cons_code;
    float avoidx,avoidr,avoidphi;
    float *rcontact;
    };
 
struct write_coordinates_d {
    int cunit;
    int maxconf;
    int nconsp;
    int *consp;
    logical use_comp;
    };
 
struct status_d {
    logical setprn;
    int callcount;
    int fileunit,filefreq;
    char *filename;
    int filemx;
    int filel;
    int file_count;
    int file_time;
    int nflush;
    int *flushfreq;
    int *flushunit;
    int *flush_time;
    };
 
struct rbest_d {
    int unit;
    int nbest;
    float maxevdw;
    int nconsp;
    int *consp;
    float energy;
    };
 
#define eval_code_rms 1
#define eval_code_energy 2
#define eval_code_user 3
 
struct evaluate_d {
    int eval_code;
    char *coorname;
    int ministl;
    char *minist;
    char *workst;
    int nconsp;
    int *consp;
    float *savedx,*savedy,*savedz;
    float *initx,*inity,*initz;
    short int *imove;
    float evaluation;
    float mineval,maxeval;
    int evalcount;
    };
 
struct pepmap {
    float omega,phi,psi;
    float energy;
    logical cisonly;
    };
/*
*   The range list data structure maintains the list of torsion angles
*   which avoid van der Waals contacts exceeding a given energy.
*   low and high in the range list are always contained within [-pi,pi].
*   The circular periodicity of the angles is processed by the code.
*
*   In order to limit the effects of numerical error, ranges are expanded
*   by range_eps.
*/
 
#define range_list_inc 100
#define range_eps 3.0e-5
struct range_list {
       int maxele,nrange;
       float *low,*high;
       };
 

#endif
