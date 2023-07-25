#include <stdio.h>
#include <string.h>

/*The struct of tugboat, each tugboat will heve X and Y coordinates and a name and a dot product and a variable
admisible helps us to mark the tugboat if it is going to move the ship or not(0 or 1)*/
typedef struct
{
    long long int X;
    long long int Y;
    char name[100];
    long long int dotProduct;
    int admisible;

} tugboat;
/* A function to do the dot product (the projection on the path), it takes the path vector and the vector
which we are going to project it onto the path vector*/
long long int dot_product(long long int X, long long int Y, long long int Xt, long long int Yt)
{
    return (X * Xt + Y * Yt);
}
/*A function to compare the square hypotenuse of two tugboats.it returns 1 or -1 or 0*/
int distance_compare(long long int Xs, long long int Ys, long long int Xt1, long long int Yt1, long long int Xt2, long long int Yt2)
{
    /*for the first tugboat*/
    long long first_distance = (Xs - Xt1) * (Xs - Xt1) + (Ys - Yt1) * (Ys - Yt1);
    /*for the second tugboat*/
    long long second_distance = (Xs - Xt2) * (Xs - Xt2) + (Ys - Yt2) * (Ys - Yt2);
    /*compare*/
    if (first_distance > second_distance)
    {
        return 1;
    }
    if (first_distance < second_distance)
    {
        return -1;
    }
    if (first_distance == second_distance)
    {
        return 0;
    }
}
int main()
{
    long long int X_ship;
    long long int Y_ship;
    long long int X_harbor;
    long long int Y_harbor;
    int tugboatsNum;
    /*taking some input from the user*/
    scanf("%lld %lld %lld %lld", &X_ship, &Y_ship, &X_harbor, &Y_harbor);
    scanf("%d", &tugboatsNum);
    /*The array which we will use it to store the tugboats*/
    tugboat tugboats[tugboatsNum];
    long long longitude = dot_product(X_harbor - X_ship, Y_harbor - Y_ship, X_harbor - X_ship, Y_harbor - Y_ship);
    /*loop on the tugboats array. Each time we take the informations necessary from the user, do extra work and store the tugboat*/
    for (int i = 0; i < tugboatsNum; i++)
    {
        /*take input*/
        scanf("%lld %lld %s", &tugboats[i].X, &tugboats[i].Y, tugboats[i].name);
        /*calculate the dot product*/
        tugboats[i].dotProduct = dot_product(X_harbor - X_ship, Y_harbor - Y_ship, tugboats[i].X - X_ship, tugboats[i].Y - Y_ship);
        /*filter to see if the tugboat is in the right range, if it is , we set the admisible variable to 1 otherwise to 0*/
        if (tugboats[i].dotProduct < 0 || tugboats[i].dotProduct > longitude)
        {

            tugboats[i].admisible = 0;
        }
        else
        {
            tugboats[i].admisible = 1;
        }
    }
    /*a variable which will help us to switch between tugboats in sorting*/
    tugboat replace;
    /*the sorting section*/
    for (int i = 0; i < tugboatsNum; i++)
    {
        if (tugboats[i].admisible == 1)
        {

            for (int j = i + 1; j < tugboatsNum; j++)
            {
                if (tugboats[j].admisible == 1)
                {

                    if (tugboats[i].dotProduct > tugboats[j].dotProduct)
                    {
                        replace = tugboats[i];
                        tugboats[i] = tugboats[j];
                        tugboats[j] = replace;
                    }
                    if (tugboats[i].dotProduct == tugboats[j].dotProduct)
                    {
                        int cmp = distance_compare(X_ship, Y_ship, tugboats[i].X, tugboats[i].Y, tugboats[j].X, tugboats[j].Y);
                        if (cmp == 1)
                        {
                            tugboats[i].admisible = 0;
                            break;
                        }
                        if (cmp == -1)
                        {

                            tugboats[j].admisible = 0;
                        }
                        /*if the dot product and the  square hypotenuse of  a two tugboats are the same , we compare there names */
                        if (cmp == 0)
                        {
                            if (strcmp(tugboats[i].name, tugboats[j].name) < 0)
                            {
                                tugboats[j].admisible = 0;
                            }
                            else
                            {
                                tugboats[i].admisible = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    /*counting how many tugboats will help the ship*/
    int count = 0;
    for (int i = 0; i < tugboatsNum; i++)
    {
        if (tugboats[i].admisible == 1)
        {
            count++;
        }
    }
    /*printing the output*/
    printf("%d \n", count);
    for (int i = 0; i < tugboatsNum; i++)
    {
        if (tugboats[i].admisible == 1)
        {
            printf("%s\n", tugboats[i].name);
        }
    }

    return 0;
}