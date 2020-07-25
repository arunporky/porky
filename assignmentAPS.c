//created by: Arun Kumar Nath(Gau-c-16/054)
//Date: 24/4/2020
#include<stdio.h>
#include<math.h>
// Using macros to convert degree to radian
// and call sin() and cos() as these functions
// take input in radians
#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)


int m[3][3], point[3][1], line[3][2], triangle[3][3], rectangle[3][4];
float m1[3][3];



//matrix multiplication
void multiplyMatrices(int c2) {

    int mult[3][c2];
    // Initializing elements of matrix mult to 0.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < c2; j++) {
            mult[i][j] = 0;
        }
    }

    // Multiplying first and second matrices and storing in mult.
    for (int i = 0; i < 3; ++i) {//i< no of row in matrix1
        for (int j = 0; j < c2; ++j) {//j< no of column in matrix1
            for (int k = 0; k < 3; ++k) {//k< no of column in matrix1
                if(c2 == 1){
                    mult[i][j] += m[i][k] * point[k][j];
                }else if(c2 == 2){
                    mult[i][j] += m[i][k] * line[k][j];
                }else if(c2 == 3){
                    mult[i][j] += m[i][k] * triangle[k][j];
                }else if(c2 == 4){
                    mult[i][j] += m[i][k] * rectangle[k][j];
                }
            }
        }
    }

    //display the matrices
    printf("\nM x P = P`\n\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d   ", m[i][j]);
        }
        printf("\t"); if(i==1){printf("x");} printf("\t");

        for(int k=0; k<c2; k++){
            if(c2 == 1){
                printf("%d   ", point[i][k]);
            }else if(c2 == 2){
                printf("%d   ", line[i][k]);
            }else if(c2 == 3){
                printf("%d   ", triangle[i][k]);
            }else if(c2 == 4){
                printf("%d   ", rectangle[i][k]);
            }
        }
        printf("\t");
        if(i==1){
            printf("=");
        }
        printf("\t");
        for(int x=0; x<c2; x++){
            printf("%d   ", mult[i][x]);
        }
        printf("\n");
    }

}


//matrix multiplication for rotation
void multiplyMatricesRotation(int c2) {

    float mult[3][c2];
    // Initializing elements of matrix mult to 0.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < c2; j++) {
            mult[i][j] = 0;
        }
    }


    // Multiplying first and second matrices and storing in mult.
    for (int i = 0; i < 3; ++i) {//i< no of row in matrix1
        for (int j = 0; j < c2; ++j) {//j< no of column in matrix1
            for (int k = 0; k < 3; ++k) {//k< no of column in matrix1
                if(c2 == 1){
                    mult[i][j] += m1[i][k] * point[k][j];
                }else if(c2 == 2){
                    mult[i][j] += m1[i][k] * line[k][j];
                }else if(c2 == 3){
                    mult[i][j] += m1[i][k] * triangle[k][j];
                }else if(c2 == 4){
                    mult[i][j] += m1[i][k] * rectangle[k][j];
                }
            }
        }
    }

    //display the matrices
    printf("\nM x P = P`\n\n");
    for(int i=0; i<3; i++){
        //display first matrix
        for(int j=0; j<3; j++){
            printf("%.2f   ", m1[i][j]);
        }

        if(i==1){
            printf("x");
        }
        printf("    ");

        //display second matrix
        for(int k=0; k<c2; k++){
            if(c2 == 1){
                printf("%d   ", point[i][k]);
            }else if(c2 == 2){
                printf("%d   ", line[i][k]);
            }else if(c2 == 3){
                printf("%d   ", triangle[i][k]);
            }else if(c2 == 4){
                printf("%d   ", rectangle[i][k]);
            }
        }

        if(i==1){
            printf("=");
        }
        printf("    ");

        //display third matrix
        for(int x=0; x<c2; x++){
            printf("%.2f   ", mult[i][x]);
        }
        printf("\n");
    }

}


//take inputs
void inputPoint(int c2){
    printf("\n\n[Note: give space between every x/y coordinates or use new line for every x/y coordinate. Do not use coma separator]\n");
    printf("\ninsert the coordinates of the object\n");
    for(int j=0; j<c2; j++){
        for(int i=0; i<3; i++){
            switch(c2){
            case 1:
                if(i == 2){
                    point[i][j]=1;
                }else{
                    scanf("%d", &point[i][j]);
                }
                break;
            case 2:
                if(i == 2){
                    line[i][j]=1;
                }else{
                    scanf("%d", &line[i][j]);
                }
                break;
            case 3:
                if(i == 2){
                    triangle[i][j]=1;
                }else{
                    scanf("%d", &triangle[i][j]);
                }
                break;
            case 4:
                if(i == 2){
                    rectangle[i][j]=1;
                }else{
                    scanf("%d", &rectangle[i][j]);
                }
                break;
            }

        }
    }
}


//perform translation here
void translation(){
    int tx=0, ty=0, inputType=0;
    printf("translation along X-axis\t");
    scanf("%d", &tx);
    printf("translation along Y-axis\t");
    scanf("%d", &ty);

    //creating the M matrix
    m[0][0]= m[1][1]= m[2][2]= 1;
    m[1][0]= m[0][1]= m[2][0]= m[2][1]=0;
    m[0][2]= tx;      m[1][2]= ty;

    printf("\ninput is 1:point, 2:line, 3:triangle, 4:rectangle\n");
    scanf("%d", &inputType);
    switch(inputType){
    case 1:
        inputPoint(1);
        multiplyMatrices(1);
        break;
    case 2:
        inputPoint(2);
        multiplyMatrices(2);
        break;
    case 3:
        inputPoint(3);
        multiplyMatrices(3);
        break;
    case 4:
        inputPoint(4);
        multiplyMatrices(4);
        break;
    }
}


//perform rotation here
void rotation(){
    int angle=0, inputType=0;
    printf("angle of rotation\t");
    scanf("%d", &angle);

    //creating the M matrix
    float c = COS(angle); float s= SIN(angle); float s1 = SIN(-angle);
    m1[0][0]=c; m1[0][1]=s1; m1[0][2]=0;
    m1[1][0]=s; m1[1][1]=c;  m1[1][2]=0;
    m1[2][0]=0; m1[2][1]=0;  m1[2][2]=1;

    printf("input is  2:line, 3:triangle, 4:rectangle\n");
    scanf("%d", &inputType);
    switch(inputType){
    case 2:
        inputPoint(2);
        multiplyMatricesRotation(2);
        break;
    case 3:
        inputPoint(3);
        multiplyMatricesRotation(3);
        break;
    case 4:
        inputPoint(4);
        multiplyMatricesRotation(4);
        break;
    }

}


//perform scaling here
void scaling(){
    int tx=0, ty=0, inputType=0;
    printf("scaling along X-axis\t");
    scanf("%d", &tx);
    printf("scaling along Y-axis\t");
    scanf("%d", &ty);

    //creating the M matrix
    m[0][0]=tx; m[0][1]=0;  m[0][2]=0;
    m[1][0]=0;  m[1][1]=ty; m[1][2]=0;
    m[2][0]=0;  m[2][1]=0;  m[2][2]=1;

    printf("input is  2:line, 3:triangle, 4:rectangle\n");
    scanf("%d", &inputType);
    switch(inputType){
    case 2:
        inputPoint(2);
        multiplyMatrices(2);
        break;
    case 3:
        inputPoint(3);
        multiplyMatrices(3);
        break;
    case 4:
        inputPoint(4);
        multiplyMatrices(4);
        break;
    }

}


//perform shear here
void shear(){
    int tx=0, ty=0, inputType=0;
    printf("shear along X-axis\t");
    scanf("%d", &tx);
    printf("shear along Y-axis\t");
    scanf("%d", &ty);

    //creating the M matrix
    m[0][0]=1;  m[0][1]=tx; m[0][2]=0;
    m[1][0]=ty; m[1][1]=1;  m[1][2]=0;
    m[2][0]=0;  m[2][1]=0;  m[2][2]=1;

    printf("input is  3:triangle, 4:rectangle\n");
    scanf("%d", &inputType);
    switch(inputType){
    case 3:
        inputPoint(3);
        multiplyMatrices(3);
        break;
    case 4:
        inputPoint(4);
        multiplyMatrices(4);
        break;
    }

}


//perform reflection operation
void reflection(){
    int hx=1, hy=1,i=0, inputType=0;
    printf("reflection along ==>  1:X-axis, 2:Y-axis\t");
    scanf("%d", &i);

    if(i==1){hy = -1;} else hx = -1;
    //creating the M matrix
    m[0][0]=hx; m[0][1]=0;  m[0][2]=0;
    m[1][0]=0;  m[1][1]=hy; m[1][2]=0;
    m[2][0]=0;  m[2][1]=0;  m[2][2]=1;

    printf("\ninput is 1:point, 2:line, 3:triangle, 4:rectangle\n");
    scanf("%d", &inputType);
    switch(inputType){
    case 1:
        inputPoint(1);
        multiplyMatrices(1);
        break;
    case 2:
        inputPoint(2);
        multiplyMatrices(2);
        break;
    case 3:
        inputPoint(3);
        multiplyMatrices(3);
        break;
    case 4:
        inputPoint(4);
        multiplyMatrices(4);
        break;
    }

}


//Main function to drive the code
main(){
    int type;
    printf("1:translation, 2:rotation, 3:scaling, 4:shear, 5:reflection\n");
    scanf("%d", &type);

    switch(type){
    case 1:
        translation();
        break;
    case 2:
        rotation();
        break;
    case 3:
        scaling();
        break;
    case 4:
        shear();
        break;
    case 5:
        reflection();
        break;
    }

}
