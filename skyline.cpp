/* The program takes a 2-D array and a vector as input.
Then it computs the skyline form of 2-D array, multiplies it with the vector and outputs the resultant vector.
The skyline format of a matrix is given by three arrays diagoanl,mat_lower and indexes.
In diagonal array all the diagonal elements are stored.
In mat_lower all skyline elements in the lower triangle of the matrix are stored (row-wise).
And the ith component of indexes array tells where (i+1)th row of lower_mat begins.
All the elements of mat_lower from indexes[i] to indexea[i+1]-1 are the off-diagonal elements of row i+1 in increasing column order.
*/

#include <iostream>

using namespace std;

int main()
{
    int size; //stores the size of input 2-D array
    cout<<"Enter the size/order of matrix \t";
    cin>>size;
    int mat[size][size];  //create the 2-D array of required size
    cout<<"Enter elements of matrix\n";
    for(int i =0;i<size;i++)   //input elements of 2-D array
    {
        for(int j =0;j<size;j++)
        cin>>mat[i][j];
    }

    cout<<"Enter "<<size<<" elements of vector x\t";  // input elements of the vector x

    int x[size];
    for(int i =0;i<size;i++)
        cin>>x[i];

    int diagonal[size];   //The diagonal vector, also the final resultant vector
    for(int i=0;i<size;i++)
    diagonal[i]=mat[i][i];

    int no_elements=(size*size-size)/2;  //no_elements is the max number of elements that can be there in the lower triangule of the 2-D array
    int mat_lower[no_elements];   //create mat_lower vector of apt size

    int indexes[size],i_index=0;   //i_index is index into indexes array

    int t_index=0; //index into the mat_lower array, points to the next available index
    // The for loop below creates the skyline form of 2-D matrix

    for(int i=0;i<size;i++)   //for each row
    {
        int j =0;             //starting from first column
         while(mat[i][j]==0)  //skipping the zero elements in the beginning
            j++;
        for(;j<i;j++)         //store the rest of the row elements(belonging to skyline) in mat_lower
        {
            mat_lower[t_index]=mat[i][j];
            t_index++;
        }
        indexes[i_index]=t_index;  //store value of t_index in indexes array
        i_index++;
    }
    for(int i =0;i<size;i++)
        cout<<diagonal[i]<<" ";
    cout<<"\n";
    for(int i =0;i<t_index;i++)
        cout<<mat_lower[i]<<" ";
    cout<<"\n";
    for(int i =0;i<i_index;i++)
        cout<<indexes[i]<<" ";
    cout<<"\n";
//Next two for loops do the multiply operation on skyline form of 2-D array and the vector x.
    for(int i=0;i<size;i++)
    diagonal[i]*=x[i];

    int nex,ik,jcol;
    for(int k=1;k<size;k++)
    {
        nex = indexes[k]-indexes[k-1];

        for(int i =indexes[k-1],j=k-nex;i<indexes[k];i++,j++) // for the lower triangular part
        diagonal[k]+=x[j]*mat_lower[i];

        for(int i =indexes[k-1],j=k-nex;i<indexes[k];i++,j++)  //for the upper triangular part
        diagonal[j]+=mat_lower[i]*x[k];
    }
    cout<<"\n";
    for(int i=0;i<size;i++)
    cout<<diagonal[i]<<"\n";   //result
}

