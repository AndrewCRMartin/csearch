COPT = -g -Wall -ansi -pedantic -D__FORT_UNDERSCORE__
FOPT = -g 
LOPTS = -g -lm 

COBJS = \
addh.o makeh.o genh.o readpgp.o \
abmpad.o adafls.o adatmstgrd.o adatmtgrd.o adccangs.o alloc.o \
allstk.o angle.o ascale.o assign_name.o atomangle.o backbone_f.o \
batch_job.o bin_search.o bondl.o c_print_atom.o cclsngdst.o ccterxyz.o \
cgen.o cgrdconsp.o cgrdinit.o cgrdncons.o cgrdnxt.o cgwrtinit.o \
cgwrtnxt.o checknatc.o checkrtf.o chkbbone.o chkchnclsr.o chkclsdst.o \
chkcntcts.o chkftres.o chmceil.o chnclsr_f.o clear_atom.o clear_atoms.o \
cnsbblist.o cnsfblist.o codes.o constatm.o constclmp.o copyfarray.o \
copyst.o cpfbest.o cpftbest.o cpintobst.o cprint1.o cpyprm.o \
csearch.o debug.o delatmfgrd.o delatmsfgrd.o die.o dispatch.o dot.o \
dststop.o dump_grid.o ecntrl.o ephi.o evaluate_f.o explcntcts.o  \
extnlims.o fill2.o fill4.o fill_grid.o fillatm_c.o fillatm_ca.o  \
fillatm_cb.o fillatm_h.o fillatm_ht1.o fillatm_n.o fillatm_o.o  \
fillbbatms.o fillbndang.o filspc.o finbbone.o finchncls.o finclsatm.o  \
finres.o finsidchn.o fixctero.o fixinitgrd.o fixnterh.o fixpdb.o  \
forscanf.o free_range.o fresrk.o fwerf.o gcd.o generate.o genic.o  \
get_atnum.o get_resnum.o getclsangle.o getclsbond.o getdate.o getgrdspc.o  \
getparam.o getparbond2.o getres.o getseg.o getstring.o gettime.o  \
gtclschngom.o gtprangclsa.o gtprangl2.o gtrbstatms.o hadd.o indexf.o  \
indexi.o init_debug.o initfcgen.o initfgener.o isctrnglst.o killspcs.o  \
ljust.o ljustpad.o lookupname.o makinb.o mapgrdtorng.o match.o  \
matom.o maxcoor.o maxf2.o maxi2.o mincoor.o minf2.o minf3.o mini2.o  \
mygetparbond.o mynextwd.o onethr.o pack2.o pad.o padspace.o padterm.o  \
parse.o patexh.o phi.o phia.o prdie.o print_atom.o print_atom1.o  \
print_atoms.o procang.o processbonds.o prochbnd.o procimps.o procnbnds.o  \
proctors.o propbbones.o prtcgncmnd.o prtdbgvars.o prtglobopt.o prtgrdsz.o  \
prtrnglst.o prtsidchn.o pscgncmnd.o rbest_f.o rdemap.o rdpepmaps.o  \
rdprocons.o rdprtitle.o readcoords.o readparams.o readpdb.o  \
readpir.o readrtf.o regrid.o rtfacceptor.o rtfangle.o rtfatom.o rtfbond.o  \
rtfbuild.o rtfdeclare.o rtfdonor.o rtfgroup.o rtfimproper.o rtfprint.o  \
rtfresidue.o rtftopology.o rtftorsion.o rtftype.o schnatm.o scnemapln.o  \
selsidetor.o setavdclp.o setchncls.o setdefs.o setrcntcts.o setrestitr.o  \
setsdbound.o setsddofrs.o setsidchn.o setsidphis.o setup_consp.o  \
setup_hbond.o setup_imove.o setup_nbond.o setup_parmno.o  \
setup_parser.o setup_status.o setupseq.o shufcombs.o sidchnall.o  \
sidchnbst.o sidchncomb.o sidchnengy.o sidchnfst.o sidchnindi.o  \
sidchnitr.o sidchnrms.o sidechain_f.o sign.o skiptitle.o sort_i.o  \
sort_ui.o sorti_perm.o srchint.o srchwd.o srwdbd.o statprn.o status_f.o  \
stread.o struppr.o termcgen.o trace.o trimic.o typeinres.o unpack2.o  \
updtnictot.o user_cgeval.o vlen.o write_status.o writepdb.o  \
wrtcoordsf.o wrtpdbrec.o xbyind.o \
terminate.o clear_sc.o  main.o

FOBJS = \
abmerf.o abmerfc.o abmerfi.o binschr.o cartx2.o clschna.o compspcgrd.o  \
cprint.o delatmfgrd1.o dwprangl.o ecchkcont.o ecsetlims.o ecsetxyzsys.o  \
fill_grid1.o filllog.o forprtatm.o fortrace.o gammln.o gammp.o gammq.o  \
gcf.o getparbond.o getuv.o gser.o gtprangl.o hbenergy.o infrls.o  \
interpa.o maxr.o merfi.o mkprolrng.o nindx.o rnhbsrch.o rnnbsrch.o  \
schdls.o srchnat1.o srchnatm1.o stuphb1.o

csearch : $(COBJS) $(FOBJS)
	gfortran -o csearch $(COBJS) $(FOBJS) $(LOPTS)


.c.o :
	cc $(COPT) -o $@ -c $<

.f.o :
	gfortran $(FOPT) -o $@ -c $<

#.f.o :
#	f2c $(FOPT) $<
#	cc -o $*.o -c $*.c

#	mv $*.c $*.d
#	sed 's/_(/(/' $*.d >$*.c
#	rm $*.d


clean :
	rm *.o

fclean :
#	delfc
#	rm *.o


