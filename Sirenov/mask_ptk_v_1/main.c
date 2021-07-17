#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



void mask_ptk(int pfi_ptk, int n_gr_skd, int mask_dgr[])
{
    if ( pfi_ptk == 1 )
    {
        mask_dgr[1] = NULL;
        mask_dgr[2] = 0;
        mask_dgr[0] = 7;
    }
    else if ( pfi_ptk == 2 )
    {
        mask_dgr[0] = NULL;
        mask_dgr[2] = 0;
        mask_dgr[1] = 7;
    }
    else if ( pfi_ptk == 3 )
    {
        mask_dgr[2] = 0;
        mask_dgr[0] = 5;
        mask_dgr[1] = 2;
    }
    else if ( pfi_ptk == 4 )
    {
        mask_dgr[0] = NULL;
        mask_dgr[1] = 0;
        mask_dgr[2] = 7;
    }
    else if ( pfi_ptk == 5 )
    {
        mask_dgr[1] = 0;
        mask_dgr[0] = 3;
        mask_dgr[2] = 4;
    }
    else if ( pfi_ptk == 6 )
    {
        mask_dgr[0] = 0;
        mask_dgr[1] = 3;
        mask_dgr[2] = 4;
    }
    else if ( pfi_ptk == 7 )
    {
        mask_dgr[0] = 1;
        mask_dgr[1] = 2;
        mask_dgr[2] = 4;
    }
    else if ( n_gr_skd == 0 )
    {
        mask_dgr[1] = NULL;
        mask_dgr[2] = 0;
        mask_dgr[0] = 7;
    }
   else if ( n_gr_skd == 1 )
    {
        mask_dgr[0] = NULL;
        mask_dgr[2] = 0;
        mask_dgr[1] = 7;
    }
    else if ( n_gr_skd == 2 )
    {
        mask_dgr[0] = NULL;
        mask_dgr[1] = 0;
        mask_dgr[2] = 7;
    }
}

int fdvalptk(unsigned char n_val,unsigned short *dval, int n_gr_skd, int mas_in0[], int mas_in1[], int mas_in2[])
{
    if ( n_gr_skd == 0)
    {
        *dval = mas_in0[n_val];
    }
    else if ( n_gr_skd == 1)
    {
        *dval = mas_in1[n_val];
    }
    else if ( n_gr_skd == 2)
    {
        *dval = mas_in2[n_val];
    }
    else if (n_gr_skd >= 3)
    {
        return 0;
    }
    if ( mas_in0[1] != 0x0063)
    {
        if ( (mas_in1[1] != 0x0063) && (mas_in0[n_val] == mas_in1[n_val]))
        {
            *dval = mas_in0[n_val];
            return 0;
        }
        else if ( (mas_in2[1] != 0x0063) && (mas_in0[n_val] == mas_in2[n_val]))
        {
            *dval = mas_in0[n_val];
            return 0;
        }
        else if ( mas_in1[1] != 0x0063)
        {
            if ( (mas_in2[1] != 0x0063) && (mas_in1[n_val] == mas_in2[n_val]))
            {
               *dval = mas_in1[n_val];
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else if ( mas_in1[1] != 0x0063 )
    {
        if ( (mas_in2[1] != 0x0063) && (mas_in1[n_val] == mas_in2[n_val]))
        {
           *dval = mas_in1[n_val];
            return 0;
        }
    }
    else
    {
        return 0;
    }

}

void mask_dgrd_F(int mask_dgrd[], int mask_dgr[])
{
    for ( int i = 0; i < 3; i++)
    {
        mask_dgrd[i] = mask_dgr[i];
    }
}


int main()
{
    FILE *file;
    file = fopen("output.txt", "w");
    int mask_dgr[2];
    int mas_in0[5] = {8,33,5,2,1};
    int mas_in1[5] = {9,33,5,4,2};
    int mas_in2[5] = {9,5,6,1,3};
    int mask_dgrd[4] = {0};

    while(1)
    {
    int a;
    int count = 1;

    while ( count <= 24 )
    {
        for (int n_gr_skd = 0; n_gr_skd <= 2; n_gr_skd++)
        {
            for (int pfi_ptk = 1; pfi_ptk <= 8; pfi_ptk++)
            {
                printf("TEST IS %d!\n", count);

                fprintf(file, "==================\n");

                fprintf(file, "Test case ¹ %d\n", count);

                fprintf(file, "Input data:\n");

                fprintf(file, "pfi_ptk = %d\n", pfi_ptk);

                fprintf(file, "n_gr_skd = %d\n", n_gr_skd);

                mask_ptk(pfi_ptk, n_gr_skd, mask_dgr);

                fprintf(file, "Random masks:\n");

                fprintf(file, "mask_dgr[0] = %d\n", mask_dgr[0]);

                fprintf(file, "mask_dgr[1] = %d\n", mask_dgr[1]);

                fprintf(file, "mask_dgr[2] = %d\n", mask_dgr[2]);

                fprintf(file, "Input mas:\n");

                fprintf(file, "mas_in0[0] = %d, mas_in0[1] = %d, mas_in0[2] = %d, mas_in0[3] = %d, mas_in0[4] = %d\n", mas_in0[0],mas_in0[1],mas_in0[2],mas_in0[3],mas_in0[4]);

                fprintf(file, "mas_in1[0] = %d, mas_in1[1] = %d, mas_in1[2] = %d, mas_in1[3] = %d, mas_in1[4] = %d\n", mas_in1[0],mas_in1[1],mas_in1[2],mas_in1[3],mas_in1[4]);

                fprintf(file, "mas_in2[0] = %d, mas_in2[1] = %d, mas_in2[2] = %d, mas_in2[3] = %d, mas_in2[4] = %d\n", mas_in2[0],mas_in2[1],mas_in2[2],mas_in2[3],mas_in2[4]);

                fdvalptk(2, &mask_dgr[0], n_gr_skd, mas_in0, mas_in1, mas_in2);

                fdvalptk(3, &mask_dgr[1], n_gr_skd, mas_in0, mas_in1, mas_in2);

                fdvalptk(4, &mask_dgr[2], n_gr_skd, mas_in0, mas_in1, mas_in2);

                fprintf(file, "Output data:\n");

                fprintf(file, "mask_dgr[0] = %d\n", mask_dgr[0]);

                fprintf(file, "mask_dgr[1] = %d\n", mask_dgr[1]);

                fprintf(file, "mask_dgr[2] = %d\n", mask_dgr[2]);

                int Mask_Gr_Vu = mask_dgr[n_gr_skd];

                mask_dgrd_F(mask_dgrd, mask_dgr);

                fprintf(file, "Mask_Gr_Vu = %d\n", Mask_Gr_Vu);

                fprintf(file, "mask_dgrd[0] = %d, mask_dgrd[1] = %d, mask_dgrd[2] = %d, mask_dgrd[3] = %d, mask_dgrd[4] = %d\n", mask_dgrd[0],mask_dgrd[1],mask_dgrd[2],mask_dgrd[3],mask_dgrd[4]);

                fprintf(file, "mas_in0[0] = %d, mas_in0[1] = %d, mas_in0[2] = %d, mas_in0[3] = %d, mas_in0[4] = %d\n", mas_in0[0],mas_in0[1],mas_in0[2],mas_in0[3],mas_in0[4]);

                fprintf(file, "mas_in1[0] = %d, mas_in1[1] = %d, mas_in1[2] = %d, mas_in1[3] = %d, mas_in1[4] = %d\n", mas_in1[0],mas_in1[1],mas_in1[2],mas_in1[3],mas_in1[4]);

                fprintf(file, "mas_in2[0] = %d, mas_in2[1] = %d, mas_in2[2] = %d, mas_in2[3] = %d, mas_in2[4] = %d\n", mas_in2[0],mas_in2[1],mas_in2[2],mas_in2[3],mas_in2[4]);


                /*if ( HIBYTE(mas_in0[0]) == HIBYTE(mas_in1[0]) == HIBYTE(mas_in2[0]) == 0)
                {
                    mas_in0[1] = mas_in1[1] = mas_in2[1] = 0x0063;
                    for ( int i = 2; i <= 4; i++)
                    {
                        mas_in0[i] = mas_in1[i] = mas_in2[i] = 0;
                    }
                }

                fprintf(file, "mas_in0[0] = %d, mas_in0[1] = %d, mas_in0[2] = %d, mas_in0[3] = %d, mas_in0[4] = %d\n", mas_in0[0],mas_in0[1],mas_in0[2],mas_in0[3],mas_in0[4]);

                fprintf(file, "mas_in1[0] = %d, mas_in1[1] = %d, mas_in1[2] = %d, mas_in1[3] = %d, mas_in1[4] = %d\n", mas_in1[0],mas_in1[1],mas_in1[2],mas_in1[3],mas_in1[4]);

                fprintf(file, "mas_in2[0] = %d, mas_in2[1] = %d, mas_in2[2] = %d, mas_in2[3] = %d, mas_in2[4] = %d\n", mas_in2[0],mas_in2[1],mas_in2[2],mas_in2[3],mas_in2[4]);
                */
                count ++;
            }
        }
    }

    fclose(file);
    printf("TESTS ARE OVER\n");
    scanf("%d",&a);
    }
    return 0;
}
