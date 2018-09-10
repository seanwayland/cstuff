#include <stdio.h>



// struct to hold tuple of x,y position
struct position {
    unsigned long x;
    unsigned long y;
};

// print a 2D array with 3 values for each index
void print2DCharArray(unsigned char arr[][3], int area)
{
    printf("\nArray is now: ");
    for ( int i = 0; i < area; i++)
    {
        printf("\n");
        for (int j = 0; j<3; j++)
        {
            printf("%u ", arr[i][j]);
        }
    }
}


void print1DCharArray(unsigned char arr[], int area)
{
    printf("\nArray is now: ");
    for ( int i = 0; i < area*3; i++)
    {

        printf("%u ", arr[i]);

    }
}


/// convert a 2D position to a 1D index
/// assumes bottom left corner of image is 0,0 and index 1

unsigned long get1dIndex(unsigned long width, unsigned long x, unsigned long y) {

    return y * width + x;
}

/// inverse of 2D to 1D mapping function
/// sends back x,y values in tuple from index
void get_Position( unsigned long width, unsigned long height, int id, struct position *pos) {
    unsigned long xx = 0;
    unsigned long yy = 0;
   // struct position pos;
    xx = id / width;
    yy = id % width;
    pos->x = yy;
    pos->y = xx;
   // return pos;
}

/// converts 2D array with 3 values per index to a 1D array
void flatten2Darray(unsigned char source[][3], unsigned char dest[], int area)
{
   for (int i=0; i<area; i ++)
   {
     for (int j = 0; j <3; j++)
     {
         dest[3*i + j]= source[i][j];
     }

   }
}

/// inverse of function above. converts a 1D array back into a 2D array with 3 values per index
void unflatted1Darray(unsigned char source[], unsigned char dest[][3], int area)
{
    for ( int i = 0; i< area; i ++)
    {
        for (int j=0; j<3; j++)
        {
            dest[i][j] = source[3*i + j];
        }
    }

}

int main() {

    int AREA = 10;
    unsigned char data[AREA][3]; // 3 values for each pixel ie rgb
    unsigned char flatData[AREA*3]; // flattened data
    unsigned long image[AREA][2]; // 10 pixel indexes and their x,y values


    // lets assume an image with 2 columns and 5 rows
    //
    // 0 , 4 : 1,  4
    // 0 , 3 : 1,  3
    // 0,  2 : 1,  2
    // 0,  1 : 1 , 1
    // 0,  0 : 1,  0

    image[0][0] = 0; image [0][1] = 0; image[1][0] = 1; image [1][1] = 0;
    image[2][0] = 0; image [2][1] = 1; image[3][0] = 1; image [3][1] = 1;
    image[4][0] = 0; image [4][1] = 2; image[5][0] = 1; image [5][1] = 2;
    image[6][0] = 0; image [6][1] = 3; image[7][0] = 1; image [7][1] = 3;
    image[8][0] = 0; image [8][1] = 4; image[9][0] = 1; image [9][0] = 4;

    // how would you create an array like this from a given width and height

    // test functionaility of get position function
    // remember left lowest pixel is zero
    printf("\nexpected positions\n");
    for (int i = 0; i < 10; i++)
    {
        struct position pos;
        get_Position(2, 5, i, &pos);
        printf("x is %lu y is %lu", pos.x, pos.y);
        printf("\n");
    }

    // test functionality of index function
    printf("\nexpected indexes\n");
    for (unsigned long yy = 0; yy < 5; yy++)
    {
        for (unsigned long xx = 0; xx<2 ; xx++)
        {

            unsigned long index = get1dIndex(2,xx,yy);
            printf("i%lu ", index);
            printf("x%lu y%lu ", xx, yy);

        }
    }


    // test by inserting some values

    for ( unsigned long i =0; i< AREA; i++)
    {
        data[i][0]=(unsigned char)(1*i);
        data[i][1]=(unsigned char)(2*i);
        data[i][2]=(unsigned char)(3*i);
    }

    print2DCharArray(data, AREA);
    flatten2Darray(data,flatData,10);
    print1DCharArray(flatData,10);
    unflatted1Darray(flatData,data,10);
    print2DCharArray(data, AREA);
    


    return 0;
}