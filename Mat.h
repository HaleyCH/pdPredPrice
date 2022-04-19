//
// Created by 16173 on 2022/4/19.
//

#ifndef PDPROJECT1_MAT_H
#define PDPROJECT1_MAT_H

struct Mat{
    int x;
    int y;
    float **v;
};

struct Mat *cMat(int x,int y);
struct Mat *rMat(int x,int y);
struct Mat *zMat(int x,int y);
struct Mat *add(struct Mat *a, struct Mat *b);
struct Mat *mul(struct Mat *a, struct Mat *b);
struct Mat *dot(struct Mat *a, struct Mat *b);
struct Mat *nMul(struct Mat *a, float b);
struct Mat *nAdd(struct Mat *a, float b);
struct Mat *mT(struct Mat *a);

void dMat(struct Mat *a);

#endif //PDPROJECT1_MAT_H
