//
// Created by 16173 on 2022/4/19.
//

#include "Mat.h"
#include "stdlib.h"

typedef struct Mat Mat;

struct Mat *cMat(int x,int y){
    Mat *m = (Mat*) malloc(sizeof(Mat));
    float **xps = (float **)malloc(sizeof(float *)*y);
    for (int i=0;i<y;++i){
        float *xs = (float *) malloc(sizeof(float)*x);
        xps[i] = xs;
    }
    return m;
}
struct Mat *rMat(int x,int y){
    Mat *m = cMat(x,y);
    for (int i=0;i<m->y;++i){
        for (int j=0;j<m->x;++j){
            m->v[i][j] = rand()%2-1;
        }
    }
    return m;
}
struct Mat *zMat(int x,int y){
    Mat *m = cMat(x,y);
    for (int i=0;i<m->y;++i){
        for (int j=0;j<m->x;++j){
            m->v[i][j] = 0;
        }
    }
    return m;
}
struct Mat *add(struct Mat *a, struct Mat *b){
    if (a->x!=b->x){
        return NULL;
    }
    Mat *m = zMat(a->x,a->y);
    if (b->y==1){
        for (int i = 0;i<a->y;++i){
            for (int j=0;j<a->x;++j){
                m->v[i][j] = a->v[i][j] + b->v[0][j];
            }
        }
        return m;
    }
    if (b->y!=a->y){
        return NULL;
    }
    for (int i = 0;i<a->y;++i){
        for (int j=0;j<a->x;++j){
            m->v[i][j] = a->v[i][j] + b->v[0][j];
        }
    }
    return m;
}
struct Mat *mul(struct Mat *a, struct Mat *b){
    if (a->x!=b->x){
        return NULL;
    }
    Mat *m = zMat(a->x,a->y);
    if (b->y==1){
        for (int i = 0;i<a->y;++i){
            for (int j=0;j<a->x;++j){
                m->v[i][j] = a->v[i][j] * b->v[0][j];
            }
        }
        return m;
    }
    if (b->y!=a->y){
        return NULL;
    }
    for (int i = 0;i<a->y;++i){
        for (int j=0;j<a->x;++j){
            m->v[i][j] = a->v[i][j] * b->v[0][j];
        }
    }
    return m;
}
struct Mat *dot(struct Mat *a, struct Mat *b){
    if (a->y!=b->x){
        return NULL;
    }
    Mat *m = zMat(a->x,b->y);
    
}
struct Mat *nMul(struct Mat *a, float b);
struct Mat *nAdd(struct Mat *a, float b);
struct Mat *mT(struct Mat *a);

void dMat(struct Mat *a);