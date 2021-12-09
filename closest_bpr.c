#include <stdio.h>
#include <math.h>
#include <time.h>
float mod;
float dist, min=10000000000;
int i1,x,i2;
struct place{//make structure
    float x;
    float y;
    char *name;
};
int main() {
    struct place p[5];//array of 5 places
    struct place bpr;
    //initialize with longitude and latitudes 
    p[0].x = 18.52;    p[0].y = 73.85; p[0].name = "Pune";
    p[1].x = 17.38;    p[1].y = 78.48; p[1].name = "Hyderabad";
    p[2].x = 22.57;    p[2].y = 88.36; p[2].name = "Kolkata";
    p[3].x = 28.70;    p[3].y = 77.10; p[3].name = "Delhi";
    p[4].x = 12.97;    p[4].y = 77.59; p[4].name = "Bangalore";
    bpr.x = 19.31;    bpr.y = 84.79;
    printf("The places are:\n");  
    for(int i=0;i<5;i++){
        printf("%s [%f,%f]\n", p[i].name, p[i].x, p[i].y);
        dist = sqrt((p[i].x - bpr.x)*(p[i].x - bpr.x) + (p[i].y - bpr.y)*(p[i].y - bpr.y));//Since only places in India are considered, this formula is sufficient to find the closest place (even though the distances are not accurate) 
        if(dist<min){//determine closest to Berhampur
            min = dist;
            x=i;
        }
    }
    printf("\n%s is closest to Berhampur [%f,%f]",p[x].name, p[x].x,p[x].y);
    return 0;
}
