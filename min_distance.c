#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
float mod;
float dist, min=10000000000;
int i1,i2;
struct point {//make structure
    float x;
    float y;
};
int main() {
    srand(time(NULL));//seed random numbers(different points every run)
    struct point p[10];//array of 10 points
    printf("Ten randomly generated points:\n");
    for(int i=0;i<10;i++){//initialize 10 random points
        p[i].x = rand()/10000000.0;
        p[i].y = rand()/10000000.0;
        printf("Point#%d: [%f,%f]\n",i+1,p[i].x,p[i].y);
    }
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            dist = sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
            if(dist<min){//find minimum distance amongst the pairs of points
                min = dist;
                i1 = i;
                i2 = j;
            }
        }
    }
    printf("\nMinimum distance is: %f \n(between Point#%d and Point#%d)",min,i1+1,i2+1);
    return 0;
}
