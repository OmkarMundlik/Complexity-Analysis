package Lab1;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Lab1
 */
public class Lab1 {
    public void Program1() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter 10 Elements: ");
        int size = scanner.nextInt();
        int Arr[] = new int[size];

        for (int i = 0; i < size; i++) {
            Arr[i] = scanner.nextInt();
        }
        int Max = Integer.MIN_VALUE;
        for(int i=0;i<size; i++){
            Max = Math.max(Max, Arr[i]);
        }
        System.out.println("Largest Element : "+Max);
    }

    public void Program2(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter 10 numbers : ");
        int Arr[] = new int[10];

        for (int i = 0; i < 10; i++) {
            Arr[i] = scanner.nextInt();
        }
        int Max = Integer.MIN_VALUE;
        int ind = -1;
        for(int i=0;i<10; i++){
            if(Max < Arr[i]){
                Max = Arr[i];
                ind = i;
            }
        }
        Max = Integer.MIN_VALUE;
        for(int i=0;i<10; i++){
            if(i==ind) continue;
            Max = Math.max(Max, Arr[i]);
        }
        System.out.print("Second Largest Element in the Array : ");
        System.out.println(Max);
    }

    public void Program3(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Order of matrix1 (nxm)");
        int n1 = scanner.nextInt();
        int m1 = scanner.nextInt();
        System.out.println("Enter Order of matrix1 (nxm)");
        int n2 = scanner.nextInt();
        int m2 = scanner.nextInt();
        int Arr1[][] = new int[n1][m1];
        int Arr2[][] = new int[n2][m2];
        System.out.println("Enter Matrix 1 : ");
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1; j++){
                Arr1[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Enter Matrix 2 : ");
        for(int i=0;i<n2;i++){
            for(int j=0;j<m2; j++){
                Arr2[i][j] = scanner.nextInt();
            }
        }

        if(m1 != n2){
            System.out.println("Matrix Multiplication Not possible.");
            return;
        }

        int ans[][] = new int[n1][m2];

        for(int i=0;i<n1; i++){
            for(int j=0;j<m2; j++){
                for(int k=0; k<m1; k++){
                    ans[i][j] += Arr1[i][k] * Arr2[k][j];
                }
            }
        }
        System.out.println("Matrix 1 : ");
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1; j++){
                System.out.print(Arr1[i][j] + " " );
            }
            System.out.println();
        }

        System.out.println("Matrix 2 : ");
        for(int i=0;i<n2;i++){
            for(int j=0;j<m2; j++){
                System.out.print(Arr2[i][j] + " " );
            }
            System.out.println();
        }

        System.out.println("-----------------------Solution--------------------------");


        for(int i=0;i<n1; i++){
            for(int j=0;j<m2; j++){
                System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void Program4(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Order of Matrix(N)");
        int n = scanner.nextInt();
        int mat[][] = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = scanner.nextInt();
            }
        }
        System.out.println("Given Matrix : ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += mat[i][i];
        }
        System.out.println("Sum of left diagonal ELements : " + sum);
    }

    public void Program5(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Order of Matrix(N)");
        int n = scanner.nextInt();
        int mat[][] = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = scanner.nextInt();
            }
        }
        System.out.println("Given Matrix : ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("--------Lower Triangular Matrix-----------");
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Lab1 lab1 = new Lab1();
        lab1.Program1();
        // lab1.Program2();
        // lab1.Program3();
        // lab1.Program4();
        // lab1.Program5();
    }

}