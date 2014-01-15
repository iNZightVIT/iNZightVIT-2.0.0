#ifndef R_SP_H
#define R_SP_H

#ifdef SP_XPORT
# define SP_PREFIX(name) SP_XPORT(name)
#else
# define SP_PREFIX(name) name
#endif
/* remember to touch local_stubs.c */

#include <S.h>

#ifdef USING_R
#include <R.h>
/* RSB 091203 */
#include <Rdefines.h>
#define R_OFFSET 1
/* */
#include <Rinternals.h>
#include <Rmath.h>
#else
# if (!defined(SPLUS_VERSION) || SPLUS_VERSION < 6000)
#  error("no SPLUS_VERSION >= 6.0")
# endif
# define SEXP s_object *
# define PROTECT(x) x
# define UNPROTECT(x)
# define R_UNIFORM unif_rand(S_evaluator)
# define R_NORMAL  norm_rand(S_evaluator)
# define RANDIN seed_in((long *) NULL, S_evaluator)
# define RANDOUT seed_out((long *) NULL, S_evaluator)
# define Rprintf printf
#endif

/* from insiders.c 

int pipbb(double pt1, double pt2, double *bbs);
int between(double x, double low, double up); 
SEXP insiders(SEXP n1, SEXP bbs); */

/* from pip.c */

#ifndef MIN
# define MIN(a,b) ((a)>(b)?(b):(a))
#endif
#ifndef MAX
# define MAX(a,b) ((a)>(b)?(a):(b))
#endif

#define BUFSIZE 8192

/* polygon structs: */
typedef struct {
	double		x, y;
} PLOT_POINT;

typedef struct {
	PLOT_POINT	min, max;
} MBR;

typedef struct polygon {
	MBR mbr;
	int lines;
	PLOT_POINT	*p;
    int close; /* 1 - is closed polygon */
} POLYGON;

void setup_poly_minmax(POLYGON *pl);
char InPoly(PLOT_POINT q, POLYGON *Poly);
SEXP R_point_in_polygon_sp(SEXP px, SEXP py, SEXP polx, SEXP poly);
void sarea(double *heights, int *nx, int *ny, double *w, double *h, 
	double *sa, int *bycell);
void spRFindCG( int *n, double *x, double *y, double *xc, double *yc, 
		double *area );
void sp_gcdist(double *lon1, double *lon2, double *lat1, double *lat2, 
		double *dist);
void sp_dists(double *u, double *v, double *uout, double *vout, 
		int *n, double *dists, int *lonlat);
void sp_lengths(double *u, double *v, int *n, double *lengths, int *lonlat);
SEXP sp_zerodist(SEXP pp, SEXP pncol, SEXP zero, SEXP lonlat);
SEXP pointsInBox(SEXP lb, SEXP px, SEXP py);
SEXP tList(SEXP nl, SEXP m);

/* RSB 091203 */

#define DIM     2               /* Dimension of points */
typedef double  tPointd[DIM];   /* type double point */

double  SP_PREFIX(Area2)( tPointd a, tPointd b, tPointd c );
void    SP_PREFIX(FindCG)( int n, tPointd *P, tPointd CG, double *Areasum2 );
void    SP_PREFIX(Centroid3)( tPointd p1, tPointd p2, tPointd p3, tPointd c );
void SP_PREFIX(spRFindCG_c)( SEXP n, SEXP coords, double *xc, double *yc, 
		double *area );
void SP_PREFIX(comm2comment)(char *buf, int bufsiz, int *comm, int nps);

SEXP SP_PREFIX(Polygon_c)(SEXP coords, SEXP n, SEXP hole);
SEXP SP_PREFIX(Polygons_c)(SEXP pls, SEXP ID);
SEXP SP_PREFIX(SpatialPolygons_c)(SEXP pls, SEXP pO, SEXP p4s);
SEXP SP_PREFIX(bboxCalcR_c)(SEXP pls);
SEXP SP_PREFIX(Polygon_validate_c)(SEXP obj);
SEXP SP_PREFIX(Polygons_validate_c)(SEXP obj);
SEXP SP_PREFIX(SpatialPolygons_validate_c)(SEXP obj);
SEXP SP_PREFIX(SpatialPolygons_getIDs_c)(SEXP obj);
SEXP SP_PREFIX(SpatialPolygons_plotOrder_c)(SEXP pls);
SEXP SP_PREFIX(comment2comm)(SEXP obj);
#endif
/* remember to touch local_stubs.c */

